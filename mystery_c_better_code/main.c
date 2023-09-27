#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>

#include <assert.h>

typedef int  int32;  // why obfuscate the type?  May be wrong depending on CPU architecture.
typedef char int8;  // todo: possible conversion of type from unsigned to signed!! why obfuscate the type?  May be wrong depending on CPU architecture, but probably not in this case.

#define TEMP_STRING_LENGTH 8

static void xor_char_star(int8  *output, int8  *input_1, const int8  *input_2,
                         int32 length /* always 8 */)  // todo: why static?
{
    int32 i = 0;
    for ( i=0; i<length /* 8 */; i++ ) {
        output[i] = (int8)(input_1[i] ^ input_2[i]);  // int8 XOR for leftmost bit (zero origin) 7, 15 ..., 63  (check 8*8 = 64 bits)
    }
    return;
}

// Interger to Ascii?
static void itoa( int32 num, int8 /* should be 'char*' ? */ *target_string, int32 radix )  // todo: why static?
// Pre-Condition: We should/need to verify that num can fit into "alpha", but we have no length of the char[].
{
    if ( radix == 10 ) {
        sprintf(target_string, "%i", num);  // WARNING: note possible overflow is num takes more than 2 digits with the terminating NULL.  This is not a problem with the test data below.
    }
    else if ( radix == 16 ) {  // WARNING: This code branch is not excecuted based on test case below!
        sprintf(target_string, "%X", num);
    }
}

int8 *calculate_modified(int8 modifier, const int8  *input_1, int32 input_1_length)
{
    assert( input_1_length > 0 );

    // strange convert from number to string and back to integer
    // (modifier/2)+48;
    int8 leading_char_array_of_3[] = {0,0,0};  // char[]
    itoa( modifier/2, leading_char_array_of_3, 10 );
    int32 i_leading = atoi( leading_char_array_of_3 ); // return value is: decimal 56, 0x38, '8', which is 8 + 48 == 56

    int8 * temp_string_ptr = (int8 *) malloc( TEMP_STRING_LENGTH );  // WARNING: was magic number of 8.  // todo: change to calloc().
    memset(temp_string_ptr, 0, TEMP_STRING_LENGTH);

    if( (modifier+1)%2 == 0 ) {  // modifier is odd
        temp_string_ptr[0] = (int8)((i_leading << 4) + 8); // i*(2^4 == 16)// 8*16 == 128 == 2^7 // 128+8 overflows signed, but fits in to unsigned char.
    }
    else { 						 // modifier is even
        temp_string_ptr[0] = (int8)( i_leading << 4);
    }

    int8 * return_string_ptr = (int8 *) malloc( input_1_length );  // implicit conversion of length is broadening, we have checked that lenght is not negative.
    memset(return_string_ptr, 0, input_1_length);
    for (int32 i=0; i < (input_1_length >> 3); i++) {
        xor_char_star(return_string_ptr+i*8, temp_string_ptr, input_1+i*8, 8);  // todo: WARNING: assuming knowledge of operator precedence, converted to using parens for clarity
    }
    free(temp_string_ptr);     // not leaking this memory
    return return_string_ptr;  // memory must be recovered by caller.
}

// Do not change anything in main
// main only contains example input
// Change anything else
int main(int argc, char **argv)
{ 	// strange 24 tuple of 8bit data (8*24 = 192 total bits)
    // that look like the ASCII upper case alphabetics,
    // but is off/low by one unit and ends too soon with W or mayb should be X
    // {@:64,A,B,C,...,W:87}

    int8 data[] = {0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
                   0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
                   0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57};

    int8 *resp = calculate_modified(0x10, data, sizeof(data));  // 0x10 == DLE character, decimal 16
    free(resp);

    return 0;
}
