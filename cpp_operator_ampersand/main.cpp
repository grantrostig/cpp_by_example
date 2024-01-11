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
using namespace std;

template <typename T>
struct RequiredField {
    RequiredField(const T& value) : value_(value) {}    // TODO??: Suppresses default constructors?
    operator       T&()       { return value_; }        // https://stackoverflow.com/questions/38180908/weird-operator-overloading-operator-t-const-noexcept-return-ptr
                                                        // https://stackoverflow.com/questions/25060413/what-is-operator-t-where-t-is-a-template-parameter-in-c
    operator const T&() const { return value_; }        // https://en.cppreference.com/w/cpp/language/cast_operator
explicit operator       T*()       { return value_; }        // TODO??: What is this?
explicit operator const T*() const { return value_; }        //
    T value_;
};

struct Options1 {
    //RequiredField<int> id1{};         // Won't compile
    //RequiredField<int> id5 = {};      // Won't compile
    RequiredField<int> id;
    RequiredField<int> id2 {1};
    RequiredField<int> id3 = 1;
    RequiredField<int> id4 = {1};
    std::string label = "default 1label";
};

struct Options2 {
    int id;
    std::string label = "default 2label";
};

int main() {                    // RequiredField is not constructible from empty initializer list.
    Options1 opt1a{ .id = 20 };
    // Options1 opt1X{           .label = "some 1blabel"}; // Won't compile.
    Options1 opt1b{ .id = 20, .label = "some 1blabel"};
 // Options1 opt1c{};
 // options.id == 20, options.label == "default label"
    std::cout << ".id == " << opt1a.id << ", .label == " << std::quoted(opt1a.label) << "\n";
    std::cout << ".id == " << opt1b.id << ", .label == " << std::quoted(opt1b.label) << "\n";
 // std::cout << ".id == " << opt1c.id << ", .label == " << std::quoted(opt1c.label) << "\n";

    Options2 opt2a{ /*.id = 30,*/ .label = "some 3label"}; // Won't compile.
    Options2 opt2c{};
    std::cout << ".id == " << opt2a.id << ", .label == " << std::quoted(opt2a.label) << "\n";
    std::cout << ".id == " << opt2c.id << ", .label == " << std::quoted(opt2c.label) << "\n";

    cout << "###"<< endl;
    return 0;
}
