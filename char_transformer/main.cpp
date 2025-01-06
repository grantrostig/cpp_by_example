// Requirements, Design, and Edited by Grant Rostig
// Code by Jon Kalb https://wandbox.org/permlink/R5tMMsppwL5oSTpy
// boost 1.0 license
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_map>

// All code below is: version 0.3 of project: char_transformer
std::map<char, std::tuple<int, std::vector<int>>> transform_map {
   //   char, pair of: counter, vector of replacement values for the transformed key char
        {'a', {0, {1, 2, 3}}},
        {'b', {0, {4, 5, 6}}},
        {'c', {0, {7, 8}}},
        {'d', {0, {9, 10, 11, 12}}},
        {' ', {0, {13}}},
        {'.', {0, {1,14}}}
};

auto main() -> int {
    std::string         text{" abcd. abcd."};
    std::vector<int>    output(size(text));
    auto transformer{ [tmap{transform_map}] (char c) mutable { // replace char with one of a vector of numbers, incrementing the index to find replacement value.
                          auto& counter{get<0>(tmap[c])};  // is incremented between invocations per key/data entry // TODO??: making this a ref somehow preserves the value similar to "static"?
                          auto  values{get<1>(tmap[c])};
                          auto  result{values[counter]};
                          ++counter;
                          if (counter == ssize(values)) { // signed size // Rap around when we have used all of them?
                              counter = 0;
                          }
                          return result;
                      }};
    std::transform(begin(text), end(text), begin(output), transformer);
    std::cout << "size(password):" <<     size(text) << std::endl;
    std::cout << "size(transform_map)" << size(transform_map) << std::endl;
    std::cout << "size(output)" << size(output) << std::endl;
    for (int v: output) { std::cout << v << ','; }
    std::cout << std::endl;
}
