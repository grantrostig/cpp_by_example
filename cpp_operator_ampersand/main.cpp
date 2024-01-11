/* Handling required fields with designated initializers
        Daily bit(e) of C++ #373, Forcing explicit initialization of specific fields in an aggregate when using designated initializers.
    When relying on designated initializers during aggregate initialization, it might be desirable to ensure that some fields are always explicitly initialized.
    We can use a simple wrapper that cannot be constructed from an empty initializer list to enforce initialization.
    ŠIMON TÓTH JAN 9, 2024 https://open.substack.com/pub/simontoth/p/daily-bite-of-c-handling-required?r=cwceo&utm_campaign=post&utm_medium=email

User-defined conversion function C++ language  Expressions
Enables implicit conversion or explicit conversion from a class type to another type.

*/
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

template <typename T>
class Required_field {
    T value_;
public:  // similar to strong types??
    Required_field(const T& value) : value_(value) {}   // implicit copy construct // TODO??: Suppresses default constructors?
        // https://stackoverflow.com/questions/38180908/weird-operator-overloading-operator-t-const-noexcept-return-ptr
        // https://stackoverflow.com/questions/25060413/what-is-operator-t-where-t-is-a-template-parameter-in-c
        // https://en.cppreference.com/w/cpp/language/cast_operator
             operator       T&()       { return value_; }       // TODO: Cliff says: see conversion operator.
             //ret_val  /* & to T */ operator T&()       { return value_; }
             operator const T&() const { return value_; }
             operator       T*()       { return &value_; }        // TODO??: What is this?
    explicit operator const T*() const { return value_; }        //
                         T& ref() { return value_; };   // $ auto & r = required_field.ref();
    Required_field & operator&() { return value_; }        // see line 25
};
static_assert( not std::is_default_constructible_v< Required_field< std::string > > );  // no default construction.
static_assert(     std::is_constructible_v< Required_field< std::string >, std::string > );

struct Options1 {
    //Required_field<int> id1{};         // Won't compile
    //Required_field<int> id5 = {};      // Won't compile
    //Required_field<int> id {NOT_PRESET};
    Required_field<int> id;
    Required_field<int> id2 {1};
    Required_field<int> id3 = 1;
    Required_field<int> id4 = {1};
    std::string label = "default 1label";
};

struct Options2 {
    int id;
    std::string label = "default 2label";
};

int main() {                    // Required_field is not constructible from empty initializer list.
    Required_field<int> junk{99};
    junk = 5;   // uses line 15
    int junk2{junk}; // implicit conversion
    //Required_field< std::string > my_string{"*operator"};
    Required_field< int > my_string{43};
    //auto my_star = *my_string;    //if string
    //auto my_star = *my_string;    //if int
    auto my_star = *my_string;      //if int

    // auto id;     // forces an initialization.
    Options1 opt1a{ .id = 20 }; // https://en.cppreference.com/w/cpp/language/aggregate_initialization#Designated_initializers
    //Options1 opt1X{           .label = "some 1blabel"}; // Won't compile.
    Options1 opt1b{ .id = 20, .label = "some 1blabel"};
 // Options1 opt1c{};
 // options.id == 20, options.label == "default label"
    //std::cout << ".id == " << opt1a.id << ", .label == " << std::quoted(opt1a.label) << "\n";
    //std::cout << ".id == " << opt1b.id << ", .label == " << std::quoted(opt1b.label) << "\n";
 // std::cout << ".id == " << opt1c.id << ", .label == " << std::quoted(opt1c.label) << "\n";

    Options2 opt2a{ /*.id = 30,*/ .label = "some 3label"}; // Won't compile.
    Options2 opt2c{};
    std::cout << ".id == " << opt2a.id << ", .label == " << std::quoted(opt2a.label) << "\n";
    std::cout << ".id == " << opt2c.id << ", .label == " << std::quoted(opt2c.label) << "\n";

    cout << "###"<< endl;
    return 0;
}
