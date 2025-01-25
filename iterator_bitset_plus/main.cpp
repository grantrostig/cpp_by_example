// Boost 1.0 license
// Inspired by Jon Kalb's code
// Allows manipulation of bits in a bitset, beyond what is supplied in std::  Could be useful in brainwallet project.
#include <algorithm>
#include <bitset>
#include <cassert>
#include <concepts>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
#include <type_traits>
#include <vector>

namespace Bitset2 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Detail {  // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
enum struct Direction { Up, Down };  // TODO??: like enum class?
// A mask is a binary pattern that can be applied to a set of bits to either select or alter specific portions of those bits.
consteval auto direction(auto start_bit = 0, auto last_bit = 7)
    // TODO??: also: requires bitset like thing?
    requires std::is_integral_v<decltype(start_bit)> and std::is_integral_v<decltype(last_bit)> {
    if(last_bit > start_bit) return Direction::Up;
    return Direction::Down;
}
consteval auto mask_v(auto bit)
    requires std::is_integral_v<decltype(bit)> {
    uintmax_t mask_value{ 1 };
    return mask_value << bit;
}
constexpr auto increment_mask(uintmax_t &mask, Direction d) {
    if(d == Direction::Up) { mask <<= 1; } else { mask >>= 1; }
}
template <typename Container> concept Integral_container = std::integral<typename Container::value_type>;

template <std::size_t bitset_size>
decltype(auto) bitset_out(std::bitset<bitset_size> const &bs, std::ostream &os) {
    std::cout << "$$ std::bitset output starting with bit_0:";
    for(std::size_t i{ 0 }; i < bitset_size; ++i) {
        std::cout << bs[i]; // << ' ';
    }
    return os << '\n';
}
decltype(auto) vector_char_out(std::vector<char> const &v, std::ostream &os) {  // TODO??: NOT used, Jon why is it here? Some test case?
    for(std::size_t i{ 0 }; i < v.size(); ++i) {
        std::cout << short(v[i]) << ' ';
    }
    return os << '\n';
}

} // END Detail Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

template <std::size_t bitset_size>  // value
struct Bitset_output_itr {
    using iterator_category = std::output_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = bool;
    Bitset_output_itr(std::bitset<bitset_size> & bs, std::size_t initial_offset = 0) : bs_{ &bs }, offset_{ initial_offset } {}
    auto operator*() -> Bitset_output_itr & { return *this; }
    auto operator++()    -> Bitset_output_itr & { ++offset_; return *this; }
    auto operator++(int) -> Bitset_output_itr   { ++offset_; return *this; }
    auto operator=(bool val) -> Bitset_output_itr & { // TODO??: strange comment? "this one does something"
        (*bs_)[offset_] = val;  // operator precidence ()
        return *this;
    }
private:
    std::bitset<bitset_size> *bs_;
    std::size_t              offset_{0};
};


template <auto start_bit = 7, auto last_bit = 0, Detail::Integral_container Container = std::string>  // TODO??: why is 7 start rather than 0?
    //requires std::is_integral_v<decltype(start_bit)> and std::is_integral_v<decltype(last_bit)>  // TODO??: use concepts
    requires std::is_integral_v<decltype(start_bit)> and std::is_integral_v<decltype(last_bit)>
struct Bitset_forward_iter {  // forward iterator mostly for reading as opposed to above.
    using iterator_category = std::forward_iterator_tag;
    using value_type        = bool;
    using difference_type   = std::ptrdiff_t;
    using reference         = bool const &;
    using pointer           = bool const *;
    Bitset_forward_iter(                                                   ): container_{ nullptr }                                      {}
    Bitset_forward_iter( Container& container                              ): container_{ &container }, cont_iter_{ begin(*container_) } {}
    Bitset_forward_iter( Container& container, Container::const_iterator it): container_{ &container }, cont_iter_{ it}                  {}
    reference operator*() const {
        assert(container_ and "Dereferencing iterator with no container.");
        assert((end(*container_) != cont_iter_) and "Dereferencing past end of container");
        current_value_ = *cont_iter_ & current_mask_;
        return current_value_;
    }
    pointer operator->() const { return &operator*(); }
    Bitset_forward_iter & operator++() {
        assert(container_ and "Incrementing iterator with no container.");
        assert((end(*container_) != cont_iter_) and "Incrementing past end of container");
        if(current_mask_ == last_mask_) {  // TODO??: What is this case? overflow? wrap around?
            current_mask_ = start_mask_;
            ++cont_iter_;
        } else {
            increment_mask(current_mask_, direction_);
        }
        return *this;
    }
    bool operator==(Bitset_forward_iter const &other) const {
        assert(((container_ == other.container_) or (not container_) or (not other.container_)) and ("Comparing iterators to different containers."));
        if(not other.container_) {  // Special case for other is end iter. // TODO??: what!?!?!
            return (not container_) or (end(*container_) == cont_iter_);
        } else {
            if(not container_) {    // Special case for we are end iter.
                return (not other.container_) or (end(*other.container_) == other.cont_iter_);
            }
        }
        return container_ == other.container_ and cont_iter_ == other.cont_iter_ and current_mask_ == other.current_mask_;
    }
    bool operator!=(Bitset_forward_iter const &other) const { return !(*this == other); }
private:
    static constexpr uintmax_t         start_mask_  { Detail::mask_v(start_bit) };
    static constexpr uintmax_t         last_mask_   { Detail::mask_v(last_bit) };
    static constexpr Detail::Direction direction_   { Detail::direction(start_bit, last_bit) };
    Container                         *container_;
    typename Container::const_iterator cont_iter_;
    uintmax_t                          current_mask_{ start_mask_ };
    mutable bool                       current_value_{false};
};

template <auto start_bit = 0, auto last_bit = 7, Detail::Integral_container Container = std::string>
auto begin(Container &c) { return Bitset_forward_iter<start_bit, last_bit, Container>{ c }; }

template <auto start_bit = 0, auto last_bit = 7, Detail::Integral_container Container = std::string>
auto end(Container &)    { return Bitset_forward_iter<start_bit, last_bit, Container>{}; }  // TODO??: is this really true, what if bitset is larger than passed start_bit, end_bit?

} // End biterator namespace NNNNNNNNNNNNNNNNNNNNNNNNNN

int main() {
    std::vector<bool> binary_source{ true, true, false, false, true, true, false, false };  // size = 8
    std::string       string_source{ "testing testing" }; //012345678901234
    std::bitset<8>    small_sink{};
    std::bitset<256>  big_sink{};

    std::copy(begin(binary_source), end(binary_source), Bitset2::Bitset_output_itr<8>{ small_sink });
    std::cout<< "$$ small_sink:"<< small_sink << std::endl;
    Bitset2::Detail::bitset_out(small_sink, std::cout);

    std::copy(Bitset2::begin<6, 0>(string_source), Bitset2::end<6, 0>(string_source), Bitset2::Bitset_output_itr<256>{ big_sink });
    std::cout<< "\n$$ big_sink:"<< big_sink << std::endl;
    Bitset2::Detail::bitset_out(big_sink, std::cout);
}
