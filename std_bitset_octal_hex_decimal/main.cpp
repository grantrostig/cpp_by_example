// from cppreference.com
#include <bitset>
#include <cassert>
#include <climits>
#include <cstddef>
#include <iostream>
#include <optional>
static_assert(CHAR_MIN < 0, "char is signed");
//static_assert(CHAR_MIN == 0, "char is unsigned");
#if CHAR_MIN < 0
#pragma message("char is signed")
#else
#pragma message("char is unsigned")
#endif
using Ostring       = std::optional<std::string>;
using Ochar         = std::optional<char>;
using Ointegral     = std::optional<long>;
//inline constexpr char           CHAR_NULL{'\177'};        // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
//inline constexpr char           CHAR_NULL{'\o{177}'};        // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr char           CHAR_NULL{CHAR_MIN};        // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr char           CHAR_NULL2{0b01111111};        // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr char           CHAR_NULL3{0x7F};        // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr char           CHAR_NULL4{'\x{7F}'};        // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr char           CHAR_NULL4{'\x7F'};        // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
static_assert(CHAR_NULL  == CHAR_NULL2, "error");
static_assert(CHAR_NULL2 == CHAR_NULL3, "error");
static_assert(CHAR_NULL3 == CHAR_NULL4, "error");

inline constexpr signed char    SCHAR_NULL{SCHAR_MIN};       // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr unsigned char  UCHAR_NULL{UCHAR_MAX};       // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr std::string    STRING_NULL{"NULL"};    // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.

int main() {
    typedef std::size_t length_t, position_t; // the hints

    // constructors:
    constexpr std::bitset<4> b1;
    constexpr std::bitset<4> b2{0xA}; // == 0B1010
    std::bitset<4> b3{"0011"};        // can also be constexpr since C++23
    std::bitset<8> b4{"ABBA", length_t(4), /*0:*/ 'A', /*1:*/ 'B'}; // == 0B0000'0110

    // bitsets can be printed out to a stream:
    std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << "; b4:" << b4 << '\n';

    // bitset supports bitwise operations:
    b3 |= 0b0100;
    assert(b3 == 0b0111);
    b3 &= 0b0011;
    assert(b3 == 0b0011);
    b3 ^= std::bitset<4>{0b1100};
    assert(b3 == 0b1111);

    // operations on the whole set:
    b3.reset();
    assert(b3 == 0);
    b3.set();
    assert(b3 == 0b1111);
    assert(b3.all() && b3.any() && !b3.none());
    b3.flip();
    assert(b3 == 0);

    // operations on individual bits:
    b3.set(position_t(1), true);
    assert(b3 == 0b0010);
    b3.set(position_t(1), false);
    assert(b3 == 0);
    b3.flip(position_t(2));
    assert(b3 == 0b0100);
    b3.reset(position_t(2));
    assert(b3 == 0);

    // subscript operator[] is supported:
    b3[2] = true;
    assert(true == b3[2]);

    // other operations:
    assert(b3.count() == 1);
    assert(b3.size() == 4);
    assert(b3.to_ullong() == 0b0100ULL);
    assert(b3.to_string() == "0100");
    std::cout << "###" << std::endl;
}
