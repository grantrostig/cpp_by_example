// Inspired by Jon Kalb on 2017-03-26, with edits by Grant Rostig over his objections.
// https://wandbox.org/permlink/vzpsHxRoMISAoL4s
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>

#include "ostream_joiner_gr.hpp"

auto main() -> int {
    std::ostream_iterator<char> sink_itr{std::cout};
    std::string const source{"source"};
    std::cout << "Original:";
    std::copy(cbegin(source), cend(source), sink_itr); std::cout << '\n';

    auto transformer{[](char c) {return static_cast<char>(std::toupper(c));}};
    auto transform_output_adapter{Ostream_detail::make_transform_output_adapter(sink_itr, transformer)};
    std::cout << "toupper():";
    std::copy(begin(source), end(source), transform_output_adapter); std::cout << '\n';

    auto infix_ostream_joiner{Ostream_detail::make_ostream_joiner(std::cout, ", ")};
    std::cout << "infix:";
    std::copy(cbegin(source), cend(source), infix_ostream_joiner); std::cout << '\n';

    auto infix_and_transformed{Ostream_detail::make_transform_output_adapter(infix_ostream_joiner, transformer)};
    std::cout << "infix transformed:";
    std::copy(cbegin(source), cend(source), infix_and_transformed); std::cout << '\n';

    std::cout << "###" << std::endl;
}
