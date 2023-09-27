#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>

typedef int int32;
typedef char int8;

static void unite_arrays(int8  *output, int8  *input_1, const int8  *input_2, int32 length)
{
    int32 i = 0;

    for(i=0; i<length; i++)
    {
        output[i] = (int8)(input_1[i] ^ input_2[i]);
    }

    return;
}

static void itoa( int32 num, int8  *alpha, int32 radix )
{
    if( radix == 10 )
    {
        sprintf(alpha, "%i", num);
    }
    else if( radix == 16 )
    {
        sprintf(alpha, "%X", num);
    }
}

int8 *calculate_modified(int8 modifier, const int8  *input_1, int32 length)
{
    int8  leading[3];
    int32 i_leading;
    int8 * temp_string = NULL;
    int8 * ret;
    int32 i = 0;

    itoa(modifier/2, leading, 10);
    i_leading = atoi(leading);
    temp_string = (int8 *) malloc(8);
    ret = (int8 *) malloc(length);
    memset(temp_string, 0, 8);
    temp_string[0] = 0;

    if( (modifier+1)%2 == 0 ) {
        temp_string[0] = (int8)((i_leading<<4) + 8);
    }
    else {
        temp_string[0] = (int8)(i_leading<<4);
    }

    for(i=0; i<(length>>3); i++)
    {
        unite_arrays(ret+i*8, temp_string, input_1+i*8, 8);
    }
    free(temp_string);
    return ret;
}

// Do not change anything in main
// main only contains example input
// Change anything else
int main(int argc, char **argv)
{
    int8 data[] = {0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
                   0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
                   0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57};

    int8 *resp = calculate_modified(0x10, data, sizeof(data));
    free(resp);

    return 0;
}
