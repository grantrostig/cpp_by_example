#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

//int my_naive_atoi( char * number_ascii ) {

int my_naive_atoi( string number_ascii ) {
    // Invariants
    // todo: verify that string isn't too long, and or too large, or too negative (+/-),
    //       to be expressed in a system dependent int word size.
    // todo: in char * case (not yet implemented): verify that we don't have a nullptr.
    // Assume that empty string is zero.
    // Assume radix/base ten numbers.
    // Assume no leading or trailing blanks.
    // Assume we can have one leading '-' minus for negative numbers.
    // Assuming we have no commas (USA), or periods (Europe).

    constexpr int RADIX {10}; // assuming base 10
    int result {};

    if (number_ascii.size() == 0) return 0; // or throw?

    int offset_for_negative {0};
    if (number_ascii[0] == '-') offset_for_negative = 1;

    // for (auto ch : number_ascii+(number_ascii[0] == '-' ? 1:0)) { // ERROR todo: I don't suppose we can start the range for

    for (auto ch = number_ascii.begin()+offset_for_negative; ch != number_ascii.end(); ++ch) {
        // first time through result is zero, so we only mutiply if we loop more than once, ie. have a number > nine.
        result *= RADIX;
        // extract the most significant digit
        result += static_cast<int>( *ch - 48 );
    };

    if (offset_for_negative) {
        result = -result;
    }
    return result;
}

int main()
{
 //   char number_ascii[] = "21397";
 //   my_naive_atoi(number_ascii);

    cout << atoi("21397") << endl;
    cout << my_naive_atoi("21397") << endl;

    cout << atoi("8") << endl;
    cout << my_naive_atoi("8") << endl;

    cout << atoi("0") << endl;
    cout << my_naive_atoi("0") << endl;

    cout << atoi("-1") << endl;
    cout << my_naive_atoi("-1") << endl;

    cout << atoi("-9999") << endl;
    cout << my_naive_atoi("-9999") << endl;
    cout << "###" << endl;
    return 0;
}
