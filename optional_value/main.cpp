#include <iostream>
#include <optional>

using namespace std;

int main()
{
    std::optional int_var = 2; cout << *int_var;
    std::optional int_double {2.0}; cout << *int_double;
    //std::optional int_huh {}; cout << *int_double;
    std::optional<int> my_int_opt {};
    if ( my_int_opt ) cout << "Hello World!" << endl;
    my_int_opt = 5;
    if ( my_int_opt ) cout << "Hello World!" << endl;
    my_int_opt = std::nullopt;
    if ( !my_int_opt ) cout << "Hello World!" << endl;
    return 0;
}
