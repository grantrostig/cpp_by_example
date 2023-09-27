#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>

#include <iostream>
#include <bitset>
#include <cstddef>
#include <assert.h>

using std::cout, std::endl, std::cerr, std::cin;

constexpr int BITS_OF_BYTE = 		 8;
constexpr int BYTE_MASK_VALUE = 	 0xFF;
constexpr int TEMP_BITSET_8_LENGTH = 8;

typedef char         int8;  // todo: possible conversion of type from unsigned to signed!! why obfuscate the type?  May be wrong depending on CPU architecture, but probably not in this case.
typedef int  		 int32;  // why obfuscate the type?  May be wrong depending on CPU architecture.
typedef unsigned int uint32;  // why obfuscate the type?  May be wrong depending on CPU architecture.

inline unsigned long shift_add_trunc(int32 val, int32 add_val = 0) {
    assert( val > 0 );
    val <<= 4;  // val * 16
    if (add_val) val += add_val;  // in 'odd' case val + binary "1000" (8). Note: compare to zero is fast, so I don't just add.  Could benchmark this.

    // truncate all bits beyond a byte (or int8).
    std::bitset<sizeof(int32) * BITS_OF_BYTE> b_int32_val {static_cast<uint32>(val)};
                            cout << "b_val: " << b_int32_val << endl;
    b_int32_val &= BYTE_MASK_VALUE;
                            cout << "b_val: " << b_int32_val << endl;
                            cout << "(int8)ulong: "<< (int8)b_int32_val.to_ulong() << endl;
                            cout << "(char)ulong: "<< (char)b_int32_val.to_ulong() << endl;
    // OR just this:
    int8 truncator_val = (int8) val;
    int8 truncator_val2 = static_cast<int8>( val );
    assert (truncator_val == truncator_val2 == (int8)b_int32_val.to_ulong());

    return b_int32_val.to_ulong();
}

int8 *calculate_modified(int8 modifier, const int8  *data_int8_array, int32 data_int8_array_length)
{
    assert( modifier > 0 );  // todo: is char unsigned?
    assert( data_int8_array_length > 0 );
    int32 i_leading = (modifier/2)+48;

    std::bitset<TEMP_BITSET_8_LENGTH> bitmask_a;
    bitmask_a |= shift_add_trunc( i_leading, (modifier % 2 ? 8 : 0));  // if modifier is odd add 8, else add 0
    cout << "bitmask_a: " << bitmask_a << endl;

    std::bitset<TEMP_BITSET_8_LENGTH> bitmask( shift_add_trunc( i_leading, (modifier % 2 ? 8 : 0)));  // if modifier is odd add 8, else add 0
    cout << "bitmask  : " << bitmask << endl;

    struct noop {
//    if( modifier%2 ) { // modifier is odd
//        auto val = shifter_strange(i_leading, 8);
//        temp_bitset |= val;
//    }
//    else { 						// modifier is 16 even, this is only test case given below. // temp_string_ptr[0] = (int8)( i_leading << 4);  // 8*16 == 128 == 8th bit is set == -128 // retain lowest order 4 bits of i_leading/56 = 896
//        auto val = shifter_strange(i_leading, 0);
//        temp_bitset |= val;
//    }
    };

    int8 *result_string_ptr = (int8 *) calloc( data_int8_array_length, sizeof(int8) );  // implicit conversion of length is broadening, we have checked that length is not negative.
    for (int32 i=0; i < data_int8_array_length; ) {            // div by 2^3 == 8  // yields 3, so i = {0,1,2}
        i += 8;
        result_string_ptr[i] ^= (int8)bitmask.to_ulong();  // 0,8,16
    }
    return result_string_ptr;  // memory must be recovered by caller.
}

// Do not change anything in main
// main only contains example input
// Change anything else
int main(int argc, char **argv)
{
    // strange 24 tuple of 8bit data (8*24 = 192 total bits)
    // that look like the ASCII upper case alphabetics,
    // but is off/low by one unit and ends too soon with W or mayb should be X
    // {@:64,A,B,C,...,W:87}

    int8 data[] = {0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
                   0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
                   0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57};

    int8 *resp = calculate_modified(0x10, data, sizeof(data));  // 0x10 == DLE character, decimal 16,  size = 24
    free(resp);

    return 0;
}
