// code by Jon Kalb https://wandbox.org/permlink/R5tMMsppwL5oSTpy
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_map>

std::unordered_map<char, int> transform_values
    {
        {'T', 3},
        {'h', 3},
        {'i', 3},
        {'s', 4},
        {' ', 1},
        {'e', 1},
        {'x', 2},
        {'t', 3},
        {'.', 1}
};

std::map<char, std::tuple<int, std::vector<int>>> transform_map
    {
        {'T', {0, {1, 2, 3}}},
        {'h', {0, {4, 5, 6}}},
        {'i', {0, {7, 8}}},
        {'s', {0, {9, 10, 11, 12}}},
        {' ', {0, {13}}},
        {'e', {0, {15}}},
        {'x', {0, {16, 17}}},
        {'t', {0, {18, 19, 20}}},
        {'.', {0, {13}}}
};

auto main() -> int
{
    std::string password{"This is text."};
    std::vector<int> output(size(password));

    auto transformer{[tmap{transform_map}] (char c) mutable
                      {
                          auto& counter{get<0>(tmap[c])};
                          auto& values{get<1>(tmap[c])};
                          auto result{values[counter]};
                          ++counter;
                          //if (counter == ssize(values))  // TODO??: why did Jon type ss?
                          if (counter == size(values))
                          {
                              counter = 0;
                          }
                          return result;
                      }};

    std::transform(begin(password), end(password), begin(output), transformer);
    std::cout << "test\n";
    for (int v: output)
    {
        std::cout << v << '\n';
    }
}
