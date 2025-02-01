// Boost 1.0 license
// Inspired by Jon Kalb's code
// Allows manipulation of bits in a bitset, beyond what is supplied in std::  Could be useful in brainwallet project.

#include <bitset>
#include <cassert>
#include <iostream>

namespace biterator { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace detail {
enum struct Direction { Up, Down, Neither};
// A mask is a binary pattern that can be applied to a set of bits to either select or alter specific portions of those bits.
consteval auto direction(auto start_bit = 0, auto last_bit = 7)
    requires std::is_same_v<decltype(start_bit),decltype(last_bit)> and
    std::is_integral_v<decltype(start_bit)> and std::is_integral_v<decltype(last_bit)> {
    if (last_bit == start_bit) return Direction::Neither;
    if (last_bit > start_bit) return Direction::Up;
    return Direction::Down;
}
consteval auto make_mask(auto bit_position)
    requires std::is_integral_v<decltype(bit_position)> {
    uintmax_t mask_value{ 1 };
    return mask_value << bit_position;
}
constexpr auto increment_mask(uintmax_t &mask, Direction d) {
    if (d == Direction::Up) { mask <<= 1; } else if (d == Direction::Down) { mask >>= 1; }
    // Direction::neither is a no-op.
}

} // END detail Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

template <typename Container> concept Integral_container = std::integral<typename Container::value_type>;

/*
    Bitset_output_iter is an output iterator that writes a bit at time into an std::bitset.
    Note that it starts with the most significant bit and writes to the least significant bit.
*/
template <std::size_t bitset_size>  // value
struct Bitset_output_iter {
    using iterator_category = std::output_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = bool;
    Bitset_output_iter(std::bitset<bitset_size> & bs, std::size_t initial_offset = 0) : bs_{ &bs }, offset_{ bitset_size - initial_offset - 1} {}
    auto operator*() -> Bitset_output_iter & { return *this; }
    auto operator++()    -> Bitset_output_iter & { --offset_; return *this; }
    auto operator++(int) -> Bitset_output_iter   { --offset_; return *this; }
    auto operator=(bool val) -> Bitset_output_iter & {
        (*bs_)[offset_] = val;
        return *this;
    }
private:
    std::bitset<bitset_size> *bs_;
    std::size_t              offset_;
};

/*
    Bitsource_forward_iter is an forward iterator that reads bits from a source container of integral values (an Integral_container).
    The caller specifies a range of bits of each source value.
*/

template <auto start_bit = 6, auto last_bit = 0, Integral_container Container = std::string>
    requires std::is_integral_v<decltype(start_bit)> and std::is_integral_v<decltype(last_bit)>
struct Bitsource_forward_iter {  // forward iterator for reading an Integral_container.
    using iterator_category = std::forward_iterator_tag;
    using value_type        = bool;
    using difference_type   = std::ptrdiff_t;
    using reference         = bool const &;
    using pointer           = bool const *;
    Bitsource_forward_iter(                                                   ): container_{ nullptr }                                      {}
    Bitsource_forward_iter( Container& container                              ): container_{ &container }, cont_iter_{ begin(*container_) } {}
    Bitsource_forward_iter( Container& container, Container::const_iterator it): container_{ &container }, cont_iter_{ it}                  {}
    reference operator*() const {
        assert(container_ and "Dereferencing iterator with no container.");
        assert((end(*container_) != cont_iter_) and "Dereferencing past end of container");
        current_value_ = *cont_iter_ & current_mask_;
        return current_value_;
    }
    pointer operator->() const { return &operator*(); }
    Bitsource_forward_iter & operator++() {
        assert(container_ and "Incrementing iterator with no container.");
        assert((end(*container_) != cont_iter_) and "Incrementing past end of container");
        if (current_mask_ == last_mask_) {
            current_mask_ = start_mask_;
            ++cont_iter_;
        } else {
            increment_mask(current_mask_, direction_);
        }
        return *this;
    }
    bool operator==(Bitsource_forward_iter const &other) const {
        assert(((container_ == other.container_) or (not container_) or (not other.container_)) and ("Comparing iterators to different containers."));
        if (not other.container_) {  // Special case for other is end iter. // TODO??: what!?!?!
            return (not container_) or (end(*container_) == cont_iter_);
        } else {
            if (not container_) {    // Special case for we are end iter.
                return (not other.container_) or (end(*other.container_) == other.cont_iter_);
            }
        }
        return container_ == other.container_ and cont_iter_ == other.cont_iter_ and current_mask_ == other.current_mask_;
    }
    bool operator!=(Bitsource_forward_iter const &other) const { return !(*this == other); }
private:
    static constexpr uintmax_t         start_mask_  { detail::make_mask(start_bit) };
    static constexpr uintmax_t         last_mask_   { detail::make_mask(last_bit) };
    static constexpr detail::Direction direction_   { detail::direction(start_bit, last_bit) };
    Container                         *container_;
    typename Container::const_iterator cont_iter_;
    uintmax_t                          current_mask_{ start_mask_ };
    mutable bool                       current_value_{false};
};

template <auto start_bit = 0, auto last_bit = 7, Integral_container Container = std::string>
auto begin(Container &c) { return Bitsource_forward_iter<start_bit, last_bit, Container>{ c }; }

template <auto start_bit = 0, auto last_bit = 7, Integral_container Container = std::string>
auto end(Container &)    { return Bitsource_forward_iter<start_bit, last_bit, Container>{}; }

} // End biterator namespace NNNNNNNNNNNNNNNNNNNNNNNNNN
