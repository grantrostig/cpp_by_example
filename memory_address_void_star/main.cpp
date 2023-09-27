#include <iostream>
#include <string>

using namespace std;

static   char my_char_star;

int main()
{

    // NOTE: pointer math with minus, always results in an offset of type 'long'!?!
    int my_int_variable {0};
    std::string my_string_variable {0};
    auto junk_char_star = &my_char_star;
    auto junk_char_star0 = &my_char_star - &my_char_star; junk_char_star0;
    auto junk_char_star1 = (((char *)&(my_char_star)) - ((char *)&(my_char_star)));
    auto junk_char_star2 = junk_char_star - junk_char_star; junk_char_star2;

    auto junk_int = &my_int_variable; junk_int;
    auto junk_string = &my_string_variable; junk_string;
    auto junk_string1 = &my_string_variable - (&my_int_variable); junk_string1;

    cout << "Hello World!" << endl;
    return 0;
}
