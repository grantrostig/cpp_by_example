// Created by Jon Kalb on 2017-03-26.
// https://wandbox.org/permlink/vzpsHxRoMISAoL4s
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>

namespace JwK {
/// output_adapter() adapts an existing output iterator by
/// adding a transformation function which is applied to
/// every output value.

template <class OutputIterator, class Transformer>
class output_adapter {
    OutputIterator out_;
    Transformer trans_;
public:
    // iterator traits
    using difference_type =     typename OutputIterator::difference_type;
    using value_type =          typename OutputIterator::value_type;
    using pointer =             typename OutputIterator::pointer;
    using reference =           typename OutputIterator::reference;
    using iterator_category =   typename OutputIterator::iterator_category;

    output_adapter(OutputIterator original_iterator, Transformer trans): out_{original_iterator}, trans_{trans} {}

    template <class T>
    output_adapter& operator= (const T& value) {
        out_ = trans_(value);
        return *this;
    }
    output_adapter& operator*()     { return *this; }
    output_adapter& operator++()    { return *this; }
    output_adapter& operator++(int) { return *this; }
};

template <class OutputIterator, class Transformer> struct transform_output_adapter { // iterator traits
    using difference_type   = typename OutputIterator::difference_type;
    using value_type        = typename OutputIterator::value_type;
    using pointer           = typename OutputIterator::pointer;
    using reference         = typename OutputIterator::reference;
    using iterator_category = typename OutputIterator::iterator_category;

    transform_output_adapter(
        OutputIterator original_iterator, Transformer trans)
        : out_{ original_iterator }, trans_{ trans } {}

    template <class T>
    transform_output_adapter & operator=( const T &value) {
        out_ = trans_(value);
        return *this;
    }
    transform_output_adapter & operator*() { return *this; }
    transform_output_adapter & operator++() { return *this; }
    transform_output_adapter & operator++( int) { return *this; }
private:
    OutputIterator out_;
    Transformer    trans_;
};

template<class OutputIterator, class Transformer>
auto make_transform_output_adapter (OutputIterator out, Transformer trans)
    -> transform_output_adapter<OutputIterator, Transformer> {
    return {out, trans};
};

// Based on std::experimental::ostream_joiner<DelimT,CharT,Traits>::ostream_joiner
// https://en.cppreference.com/w/cpp/experimental/ostream_joiner
template <class DelimT, class CharT = char, class Traits = std::char_traits<CharT>> struct ostream_joiner { // iterator traits
    using difference_type   = void;
    using value_type        = void;
    using pointer           = void;
    using reference         = void;
    using iterator_category = std::output_iterator_tag;

    using char_type    = CharT;
    using traits_type  = Traits;
    using ostream_type = std::basic_ostream<CharT, Traits>;

    ostream_joiner( ostream_type &stream, DelimT const &delimiter)
        : stream_{ stream }, delimiter_{ delimiter } {}

    ostream_joiner( ostream_type &stream, DelimT &&delimiter)
        : stream_{ stream }, delimiter_{ std::move(delimiter) } {}

    ostream_joiner(const ostream_joiner &other) = default;
    ostream_joiner(ostream_joiner &&other)      = default;

    template <class T>
    ostream_joiner &
    operator=( const T &value) {
        if(first_) {
            first_ = false;
        } else {
            stream_ << delimiter_;
        }
        stream_ << value;
        return *this;
    }
    ostream_joiner &operator=(const ostream_joiner &other) = default;
    ostream_joiner &operator=(ostream_joiner &&other)      = default;
    ostream_joiner & operator*() { return *this; }
    ostream_joiner & operator++() { return *this; }
    ostream_joiner & operator++( int) { return *this; }
private:
    ostream_type &stream_;
    DelimT const  delimiter_;
    bool          first_{ true };
};

template <class DelimT, class CharT = char, class Traits = std::char_traits<CharT>>
auto make_ostream_joiner(
    std::basic_ostream<CharT, Traits> &os, DelimT &&delimiter) -> ostream_joiner<std::decay_t<DelimT>, CharT, Traits> {
    return { os, delimiter };
};
}

auto main() -> int {
    std::ostream_iterator<char> sink_itr{std::cout};
    std::string const source{"source"};
    std::cout << "Original:";
    std::copy(cbegin(source), cend(source), sink_itr); std::cout << '\n';

    auto transformer{[](char c) {return static_cast<char>(std::toupper(c));}};
    auto transform_output_adapter{JwK::make_transform_output_adapter(sink_itr, transformer)};
    std::cout << "toupper():";
    std::copy(begin(source), end(source), transform_output_adapter); std::cout << '\n';

    auto infix_ostream_joiner{JwK::make_ostream_joiner(std::cout, ", ")};
    std::cout << "infix:";
    std::copy(cbegin(source), cend(source), infix_ostream_joiner); std::cout << '\n';

    auto infix_transformed{JwK::make_transform_output_adapter(infix_ostream_joiner, transformer)};
    std::cout << "infix transformed:";
    std::copy(cbegin(source), cend(source), infix_transformed); std::cout << '\n';

    std::cout << "###" << std::endl;
}
