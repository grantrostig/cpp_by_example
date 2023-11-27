/* copyright ??????? or? CppMSG.com Boost 1.0 License
 * Author: ?? please fill in if you wish to be credited. :)
 * Edits: Grant Rostig

 This is an illustration of using the new C++23 "deduce this" feature as a replacement for CRTP.
 First a simple, classic CRTP example. We want to add a "print myself" feature to any type with a to_string() member function.
 Classic CRTP requires a templated base class with an API and functionality that will be accessed through a derived class
 object when the base class is templated on the derived class type.
 For our example we'll add the "print()" API to our derived classes. This will print the result of calling the to_string() member.
 We write two versions because we want to output the constness.
*/
#include <iostream>
#include <memory>
namespace CRTP {

/// The base class provides functions for the derived class.  //TODO??: Is this strictly correct?
template <class T>
struct Printable {
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
struct My_type: public Printable<My_type> {
            My_type(std::string_view sv): name{sv} {}
            auto        to_string() const -> std::string_view {return name;}
private:    std::string name;
};

auto test() -> void {
    // We create an instance of our type with a name.
    My_type mt{"CRTP meow"};
    // Our type can "print()" with no virtual funcions.
    mt.print();
    // A rare use of const_cast to *add* constness for
    // for testing purposes.
    const_cast<My_type const&>(mt).print();     // TODO??: mt is temporary const &, and on that object "view" we call print().  Correct?
}
} // end Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

/// Now let's achive the same thing using "deduced this" instead of CRTP.
namespace Deduce_this {

/// The "printable" type is no longer templated…  TODO??: what is this character??:………………
struct Printable {
    // … because the member function is now templated with an explicit "this" (called "self").
    // We only need one version becuase the constness is also deduced and we can determine this at compile time.
    template <class T>
    decltype(auto) print(this T& self, std::ostream& s = std::cout) {
        s << '[' << self.to_string();
        if constexpr (std::is_const_v<T>) {
            s << " (const)";
        }
        else {
            s << " (not const)";
        }
        s << "]\n";
        return s;
    }
};

/// The derived class is derived from the base which is no longer templated on the derived type.
/// In our example we have a name and a to_string() member function so we can demonstrate that we are able to print.
struct My_type: Printable {
    My_type(std::string_view sv): name{sv}              {}
            auto to_string() const -> std::string_view  {return name;}
private:    std::string name;
};

auto test() {
    // We create an instance of our type with a name.
    My_type mt{"deduce this meow"};
    // Our type can "print()" with no virtual funcions.
    mt.print();
    // A rare use of const_cast to *add* constness for
    // for testing purposes.
    const_cast<My_type const&>(mt).print();
}
} // end Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

auto main() -> int {
    CRTP::test();
    Deduce_this::test();
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
