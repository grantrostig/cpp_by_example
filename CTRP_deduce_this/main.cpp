/* copyright CppMSG.com Boost 1.0 License
 * Author: Jon Kalb https://wandbox.org/permlink/6MC0s5wieKWSrclJ
 * Edits: Grant Rostig

 This is an illustration of using the new C++23 "deduce this" feature as a replacement for CRTP.
 First a simple, classic CRTP example. We want to add a "print myself" feature to any type with a to_string() member function.
 Classic CRTP requires a templated base class with an API and functionality that will be accessed through a derived class
 object when the base class is templated on the derived class type.
 For our example we'll add the "print()" API to our derived classes. This will print the result of calling the to_string() member.
 We write two versions because we want to output the constness. */
#include <iostream>
#include <memory>
namespace CRTP_example {

/// The base class provides functions for the derived class.  //TODO??: Is this strictly correct?
template <class T>
class Printable {
public:
    decltype(auto) print(std::ostream& s = std::cout) const {
        s << '[' << static_cast<T const*>(this)->to_string() << " (const)]\n";
        return s;
    }
    decltype(auto) print(std::ostream& s = std::cout) {
        s << '[' << static_cast<T const*>(this)->to_string() << " (not const)]\n";
        return s;
    }
};

/// The derived class is derived from the base which is templated on the derived type.
/// In our example we have a name and a to_string() member function so we can demonstrate that we are able to print.
class My_derived_type: public Printable<My_derived_type> {
            std::string name;
public:                 My_derived_type(std::string_view sv): name{sv} {}
            auto        to_string() const -> std::string_view {return name;}
};

auto test() -> void {
    My_derived_type mt{"CRTP meow"};                    // We create an instance of our type with a name.
    mt.print();                                         // Our type can "print()" with no virtual funcions.
        //const_cast<my_type const *>(&mt)->print();        // Will call the const version of print().
        //const_cast<my_type const * const>(&mt)->print();  // Will call the const version of print().
        //const_cast<my_type       * const>(&mt)->print();  // Will not call the const version of print().
    const_cast<My_derived_type const&>(mt).print();     // A rare use of const_cast to *add* constness for for testing purposes.
                                                        // TODO??: mt is temporary const &, and on that object "view" we call print().  Correct?
} } // end Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

/* Only works on clang 18.0 experimental
namespace Deduce_this_example {     /// Now let's achive the same thing using "deduced this" instead of CRTP.
/// The "printable" type is no longer templated…  TODO??: what is this character??:………………
/// … because the member function is now templated with an explicit "this" (called "self").
/// We only need one version becuase the constness is also deduced and we can determine this at compile time.
class Printable {
public:
    template <class T>
        // decltype(auto) print( this T& my_self, std::ostream& stream = std::cout ) {  // this must be 1st param. It is called "deduced this".
        // auto print(this T& self, std::ostream& s = std::cout) //(implies returning std::ostream)
        // auto& print(this T& self, std::ostream& s = std::cout)
    auto print( this T& my_this, std::ostream& stream = std::cout ) -> std::ostream & {  // "this" must be 1st param. It is called "deduced this".
        stream << '[' << my_this.to_string();
        if constexpr (std::is_const_v<T>)
            stream << " (const)";
        else
            stream << " (not const)";
        stream << "]\n";
        return stream;
    }
};

/// The derived class is derived from the base which is no longer templated on the derived type.
/// In our example we have a name and a to_string() member function so we can demonstrate that we are able to print.
class My_derived_type: Printable {
            std::string name;
public:                 My_derived_type(std::string_view sv): name{sv} {}
            auto        to_string() const -> std::string_view{return name;}
};

auto Test() {
    My_derived_type mt{"deduce this meow"};             // We create an instance of our type with a name.
    mt.print();                                 // Our type can "print()" with no virtual funcions.
    const_cast<My_derived_type const&>(mt).print();     // A rare use of const_cast to *add* constness for for testing purposes.
} } // end Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN */

namespace Temp {
template <class T>
decltype(auto) print(T const& t, std::ostream& s = std::cout) {
    s << '[' << t.to_string() << "]\n";
    return s;
}

class my_type {
         std::string    name;
public:                 my_type(std::string_view sv): name{sv} {}
         auto           to_string() const -> std::string_view  {return name;}
};

auto test() {
    my_type mt{"temp meow"};    // We create an instance of our type with a name.
    print(mt);                  // Our type can "print()" with no virtual funcions.
        // mt.print();          // This form is not enabled.
} // end Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

}
auto main() -> int {
    CRTP_example::test();
//    Deduce_this_example::test();
    Temp::test();
}

/*  TODO??: what is this?
struct cat {
    std::string name;
    auto print_name(this cat& self)] {
        if constexpr (std::is_const_v<cat&>)
            {
            std::cout << "value is const\n";
            }
        else
            {
            std::cout << "value is not const\n";
            }
        std::cout << self.name << '\n'; //all good
    }
};

struct Based {
    template<typename T>
    auto print_name(this T&& self) {
        self.print();
    }
};
*/
