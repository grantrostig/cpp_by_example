#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

//char * my_naive_itoa( int num ) {

string my_naive_itoa( int num ) {
    constexpr int RADIX {10};
    constexpr int ASCII_VAL_0 {48};

    if (num == 0) return "0";
    std::string string_digits {};
    bool negative_sign {};
    if (num < 0) {  // todo: math question: these statements may not be true of a negative RADIX?
        negative_sign = true;
        num = std::abs(num);
    }
    do {
        // extract one digit, which is the remainder
        std::div_t div_result {};
        div_result = std::div( num, RADIX );
        // auto [quotient, remainder] = std::div( num, RADIX );  // Since C++11, result is well defined if either operand is negative
        // int q = num / RADIX;
        // int r = num % RADIX;

        // convert integer remainder to ASCII integer to char to string and then insert digit into the result
        std::string digit { static_cast<char>( div_result.rem + ASCII_VAL_0 ) };
        string_digits.insert( 0, digit );
                            // string_digits.insert( 0, to_string(static_cast<char>( std::abs(remainder) + ASCII_val_0))) ;
                            // reversed_digits += static_cast<char>( remainder + ASCII_val_0 );
        num = div_result.quot;
    } while (num != 0);

    if (negative_sign) {
        string_digits.insert( 0, "-");
    }
    return string_digits;
}

int main()
{
    cout << to_string(21397) << endl;
    cout << my_naive_itoa(21397) << endl;

    cout << to_string(8) << endl;
    cout << my_naive_itoa(8) << endl;

    cout << to_string(0) << endl;
    cout << my_naive_itoa(0) << endl;

    cout << to_string(-1) << endl;
    cout << my_naive_itoa(-1) << endl;

    cout << to_string(-9999) << endl;
    cout << my_naive_itoa(-9999) << endl;
    cout << "###" << endl;
    return 0;
}
