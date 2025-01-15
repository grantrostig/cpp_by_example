// inspired by Jon Kalb's code
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

// allows manipulation of bits in a bitset, beyond what is supplied in std::  Could be useful in brainwallet project.

namespace biterator {
template <std::size_t bitset_size>  // value
struct bitset_output_iter {
    using iterator_category = std::output_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = bool;
    bitset_output_iter(std::bitset<bitset_size> & bs, std::size_t initial_offset = 0) : bs_{ &bs }, offset_{ initial_offset } {}
    auto operator*() -> bitset_output_iter & {
        return *this;
    }
    auto operator++() -> bitset_output_iter & {
        ++offset_;
        return *this;
    }
    auto operator++(int) -> bitset_output_iter {
        ++offset_;
        return *this;
    }
    auto operator=(bool val) -> bitset_output_iter & { // this one does something
        (*bs_)[offset_] = val;  // operator precidence ()
        return *this;
    }
private:
    std::bitset<bitset_size> *bs_;
    std::size_t              offset_{0};
};

namespace detail {  // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
enum struct direction { up, down };  // TODO??: like enum class?
consteval auto direction_mask(auto start_bit = 0, auto last_bit = 7)
    requires std::is_integral_v<decltype(start_bit)> and std::is_integral_v<decltype(last_bit)> {
    if(last_bit > start_bit) return direction::up;
    return direction::down;
}
consteval auto mask_v(auto bit)
    requires std::is_integral_v<decltype(bit)> {
    uintmax_t mask_value{ 1 };
    return mask_value << bit;
}
constexpr auto increment_mask(uintmax_t &mask, direction d) {
    if(d == direction::up) {
        mask <<= 1;
    } else {
        mask >>= 1;
    }
}
template <typename Container> concept IntegralContainer = std::integral<typename Container::value_type>;
} // END detail Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

template <auto start_bit = 7, auto last_bit = 0, detail::IntegralContainer Container = std::string>
    //requires std::is_integral_v<decltype(start_bit)> and std::is_integral_v<decltype(last_bit)>  // TODO??: use concepts
    requires std::is_integral_v<decltype(start_bit)> and std::is_integral_v<decltype(last_bit)>
struct BitGetter {  // forward iterator mostly for reading as opposed to above.
    using iterator_category = std::forward_iterator_tag;
    using value_type        = bool;
    using difference_type   = std::ptrdiff_t;
    using reference         = bool const &;
    using pointer           = bool const *;
    BitGetter(                                                   ): container_{ nullptr }                                      {}
    BitGetter( Container& container                              ): container_{ &container }, cont_iter_{ begin(*container_) } {}
    BitGetter( Container& container, Container::const_iterator it): container_{ &container }, cont_iter_{ it}                  {}
    reference operator*() const {
        assert(container_ and "Dereferencing iterator with no container.");
        assert((end(*container_) != cont_iter_) and "Dereferencing past end of container");
        current_value_ = *cont_iter_ & current_mask_;
        return current_value_;
    }
    pointer operator->() const { return &operator*(); }
    BitGetter & operator++() {
        assert(container_ and "Incrementing iterator with no container.");
        assert((end(*container_) != cont_iter_) and "Incrementing past end of container");
        if(current_mask_ == last_mask_) {
            current_mask_ = start_mask_;
            ++cont_iter_;
        } else {
            increment_mask(current_mask_, direction_);
        }
        return *this;
    }
    bool operator==(BitGetter const &other) const {
        assert(((container_ == other.container_) or (not container_) or (not other.container_)) and
               ("Comparing iterators to different containers."));
        if(not other.container_) // Special case for other is end iter.
        {
            return (not container_) or (end(*container_) == cont_iter_);
        } else {
            if(not container_) // Special case for we are end iter.
            {
                return (not other.container_) or (end(*other.container_) == other.cont_iter_);
            }
        }
        return container_ == other.container_ and cont_iter_ == other.cont_iter_ and current_mask_ == other.current_mask_;
    }
    bool operator!=(BitGetter const &other) const { return !(*this == other); }
private:
    static constexpr uintmax_t         start_mask_{ detail::mask_v(start_bit) };
    static constexpr uintmax_t         last_mask_{  detail::mask_v(last_bit) };
    static constexpr detail::direction direction_{  detail::direction_mask(start_bit, last_bit) };
    Container                         *container_;
    typename Container::const_iterator cont_iter_;
    uintmax_t                          current_mask_{ start_mask_ };
    mutable bool                       current_value_{false};
};

template <auto start_bit = 0, auto last_bit = 7, detail::IntegralContainer Container = std::string>
auto begin(Container &c) {
    return BitGetter<start_bit, last_bit, Container>{ c };
}

template <auto start_bit = 0, auto last_bit = 7, detail::IntegralContainer Container = std::string>
auto end(Container &) {
    return BitGetter<start_bit, last_bit, Container>{};
}
} // End biterator namespace NNNNNNNNNNNNNNNNNNNNNNNNNN

template <std::size_t bitset_size>
decltype(auto) bitset_out(std::bitset<bitset_size> const &bs, std::ostream &os) {
    std::cout << "Bitset is:";
    for(std::size_t i{ 0 }; i < bitset_size; ++i) {
        std::cout << bs[i] << ' ';
    }
    return os << '\n';
}

// TODO??: NOT used, Jon why is it here? Some test case?
decltype(auto) vector_char_out(std::vector<char> const &v, std::ostream &os) {
    for(std::size_t i{ 0 }; i < v.size(); ++i) {
        std::cout << short(v[i]) << ' ';
    }
    return os << '\n';
}

int main() {
    std::bitset<8>    small_sink{};
    std::vector<bool> bsource{ true, true, false, false, true, true, false, false };  // size = 8
    std::copy(begin(bsource), end(bsource), biterator::bitset_output_iter<8>{ small_sink });

    std::cout<< small_sink << std::endl;
    bitset_out(small_sink, std::cout);

    std::bitset<256> big_sink{};
                             //012345678901234
    std::string      isource{ "testing testing" };
    std::copy(biterator::begin<6, 0>(isource), biterator::end<6, 0>(isource), biterator::bitset_output_iter<256>{ big_sink });
    std::cout<< big_sink << std::endl;
    bitset_out(big_sink, std::cout);
}
