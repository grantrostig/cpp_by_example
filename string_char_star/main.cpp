#include <chrono>
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl;
using namespace std::string_literals;
using namespace std::chrono_literals;

auto take_a_cstring_parameter( char *s ) {
    cout << "Got this:" << typeid(s).name() << "," << s << endl;
    return s;
}
auto take_a_char_carray_parameter( char s[99] ){ cout << "Got this:" << typeid(s).name()<<","<< s <<endl; return s; }
auto take_a_std_string_parameter(  std::string s ){ cout << "Got this:" << typeid(s).name()<<","<< s <<endl; return s; }
auto take_a_string_view_parameter( std::string_view s ){ cout << "Got this:" << typeid(s).name()<<","<< s <<endl; return s; }

int main() {
    auto a_char_star                    { "abc" };
    auto a_std_string                   { "abc"s };
    char a_carray_string[]              { "abc" };
    char a_std_array_string[]           { "abc" };
    std::string_view a_std_string_view1 { "abc" };
    std::string_view a_std_string_view2 { "abc"s };

    auto ret1cs= take_a_cstring_parameter(a_char_star);
    auto ret2cs= take_a_cstring_parameter(a_std_string);
    auto ret3cs= take_a_cstring_parameter(a_carray_string);
    auto ret4cs= take_a_cstring_parameter(a_std_array_string);
    auto ret5cs= take_a_cstring_parameter(a_std_string_view1);

    auto ret1ca= take_a_char_carray_parameter(a_char_star);
    auto ret2ca= take_a_char_carray_parameter(a_std_string);
    auto ret3ca= take_a_char_carray_parameter(a_carray_string);
    auto ret4ca= take_a_char_carray_parameter(a_std_array_string);
    auto ret5ca= take_a_char_carray_parameter(a_std_string_view1);

    auto ret1= take_a_std_string_parameter(a_char_star);
    auto ret2= take_a_std_string_parameter(a_std_string);
    auto ret3= take_a_std_string_parameter(a_carray_string);
    auto ret4= take_a_std_string_parameter(a_std_array_string);
    auto ret5= take_a_std_string_parameter(a_std_string_view1);

    auto ret1sv= take_a_string_view_parameter(a_char_star);
    auto ret2sv= take_a_string_view_parameter(a_std_string);
    auto ret3sv= take_a_string_view_parameter(a_carray_string);
    auto ret4sv= take_a_string_view_parameter(a_std_array_string);
    auto ret5sv= take_a_string_view_parameter(a_std_string_view1);

    auto ret1temp= take_a_std_string_parameter("def");
    auto ret2temp= take_a_std_string_parameter("def"s);
    auto ret1svtemp= take_a_string_view_parameter("def");
    auto ret2svtemp= take_a_string_view_parameter("def"s);

    cout << std::to_string(1.05)<<endl;
    std::array<char,20> array1{1,2,3};
    int   valuei {42};
    float valuef {42};
    double valued {42};
    auto [p, ec] = std::to_chars( array1.data(), array1.data() + array1.size(), valued );
    cout << std::string_view(array1.data(), p - array1.data()) << endl;

    cout << "###" << endl;
    return 0;
}
