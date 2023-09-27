#include <iostream>
#include <string>
#include <chrono>

using namespace std;

char take_a_string_parameter( std::string s ){
    cout << "got it:" << s <<endl;
}

int main()
{
    auto a = "abc";
    auto b = "abc"s;
    take_a_string_parameter(a);
    take_a_string_parameter(b);
    take_a_string_parameter("def");
    take_a_string_parameter("def"s);
    cout << "###" << endl;
    return 0;
}
