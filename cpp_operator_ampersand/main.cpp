/** Handling required fields with designated initializers
    Daily bit(e) of C++ #373, Forcing explicit initialization of specific fields in an aggregate when using designated initializers.
    When relying on designated initializers during aggregate initialization, it might be desirable to ensure that some fields are always explicitly initialized.
    We can use a simple wrapper that cannot be constructed from an empty initializer list to enforce initialization.
    ŠIMON TÓTH JAN 9, 2024 https://open.substack.com/pub/simontoth/p/daily-bite-of-c-handling-required?r=cwceo&utm_campaign=post&utm_medium=email
User-defined conversion function C++ language  Expressions
Enables implicit conversion or explicit conversion from a class type to another type.
    https://stackoverflow.com/questions/38180908/weird-operator-overloading-operator-t-const-noexcept-return-ptr
    https://stackoverflow.com/questions/25060413/what-is-operator-t-where-t-is-a-template-parameter-in-c
    https://en.cppreference.com/w/cpp/language/cast_operator
*/
//#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
//#include <type_traits>
using namespace std;

class Required_field_int {                                      // Similar to strong types??
    //int value2;
public: static   int value_;
public:
//         Required_field_int() = default;
//explicit Required_field_int(const int& value) : value_(value) {}       // Implicit copy construct // TODO??: Suppresses default constructors?
    Required_field_int(const int& value) {value_ = value;}       // Implicit copy construct // TODO??: Suppresses default constructors?
      // Required_field_int(const int& value) : value_(value) {}       // Implicit copy construct // TODO??: Suppresses default constructors?

    //operator       int( /*this*/ ) { cout<< "converstion operator int()."<< endl;return value_; }   // TODO??: What could this be?
//operator       int&( /*this*/ ) { cout<< "converstion operator int()."<< endl;return value_; }   // TODO??: What could this be?


//explicit operator       int&( /*this*/ ) { cout<< "converstion operator int()."<< endl;return value_; }   // TODO??: What could this be?
    //operator       int&()       { return value_; }   // TODO: Cliff says: see conversion operator.
    //operator const int&() const { return value_; }
    //operator       int*()       { return &value_; }  // TODO??: What could this be?
    //operator std::string()    { cout<< "conversion operator string()."<< endl; return to_string( value_ ).c_str(); }  // TODO??: What could this be?
    //operator std::basic_string<char>()    { cout<< "conversion operator string()."<< endl; return to_string( value_ ); }  // TODO??: What could this be?
    operator std::vector<int>()    { cout<< "conversion operator string()."<< endl; return {12} ; }  // TODO??: What could this be?
    //operator const char**()    { cout<< "conversion operator string()."<< endl; return new to_string( value_ ).c_str(); }  // TODO??: What could this be?
    //operator       <<()       { return &value_; }  // TODO??: What could this be?
};

int Required_field_int::value_ = 99;

template <typename T>
class Required_field {                                      // Similar to strong types??
    T value_;
public:
    Required_field(const T& value) : value_(value) {}       // Implicit copy construct // TODO??: Suppresses default constructors?
             operator       T()        { return value_; }   // TODO??: What could this be?

             operator       T&()       { return value_; }   // TODO: Cliff says: see conversion operator.
             operator const T&() const { return value_; }
                                                                                    //ret_val  /* & to T */ operator T&()       { return value_; }


             operator       T*()       { return &value_; }  // TODO??: What could this be?
    explicit operator const T*() const { return value_; }   // TODO??: What could this be?
                         T& ref() { return value_; };       // $ auto & r = required_field.ref();  // TODO??: What could this be?
    Required_field & operator&() { return value_; }         // see line 25  // TODO??: What could this be?
};
static_assert( not std::is_default_constructible_v< Required_field< std::string > > );  // no default construction.
static_assert(     std::is_constructible_v< Required_field< std::string >, std::string > );
struct Options1 {
    //Required_field<int> id1{};         // Won't compile
    //Required_field<int> id5 = {};      // Won't compile
    //Required_field<int> id {NOT_PRESET};
    Required_field<int> id;
//    Required_field<int> id2 {1};
 //   Required_field<int> id3 = 1;
  //  Required_field<int> id4 = {1};
    std::string label = "default 1label";
};
struct Options2 {
    int id;
    std::string label = "default 2label";
};

void takes_rfi( Required_field_int i ) {
}

int main() {                    // Required_field is not constructible from empty initializer list.
 //   takes_rfi( 23 );            // calls constructor and conversion operators.
    //takes_rfi( (int)23 );
    //takes_rfi( static_cast<Required_field_int>(23) );
    //takes_rfi( Required_field_int{23} );

    Required_field_int i{ 41 };
    //Required_field_int i_f( 41.0 );

    cout << static_cast< vector<int> > (i).at(0) << endl;        // cout << (int)(i) << endl;
    cout << (i).at(0) << endl;        // cout << (int)(i) << endl;
   // cout << static_cast<string>(i) << endl;        // cout << (int)(i) << endl;
    //cout << static_cast<int>(i) << endl;        // cout << (int)(i) << endl;
//    cout << static_cast<int *>(i) << endl;
    //cout << &i << endl;        //
    //int j{i};                                   // Implicit conversion, but dangerous
    // int j2=i;
    // int j3={i};
   // int j4(i);

    //int j2{1.0};
    //int j3{};

    //cout << ++j << endl;

    /* Required_field<int> junk{99};
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

    Options2 opt2a{ .id = 30, .label = "some 3label"}; // Won't compile.
    Options2 opt2c{};
    std::cout << ".id == " << opt2a.id << ", .label == " << std::quoted(opt2a.label) << "\n";
    std::cout << ".id == " << opt2c.id << ", .label == " << std::quoted(opt2c.label) << "\n";
    */

    cout << "###"<< endl;
    return 0;
}
