/** Copyright (c) Grant Rostig, grantrostig.com 2023. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
    NOT PRODUCTION QUALITY CODE, just shows learning/teaching example, not real programming, don't copy this style, just playing around
    Subject: Demonstrates virtual functions and the use of a pure virtual function, =0, to create an Abstract Type (AKA interface)

    SYMBOL    MEANING // for debugging purposes
    TODO:     the principal programmer needs todo.
    TODO?:	  the principal programmer is not sure about something, that should be addressed.
    TODO?:X   the X programmer is not sure about something, that should be addressed.
    TODO??:   is a question for verbal discussion at CppMSG.com meetup meetings.

    define NDEBUG if asserts are NOT to be checked.  Put in *.h file not *.CPP
    #define NDEBUG
    define GR_DEBUG if we/programmer is Debugging.  Put in *.h file not *.CPP
    #define GR_DEBUG
    #ifdef GR_DEBUG
    #endif GR_DEBUG
 */
//#include <bits/stdc++.h>
//#include <gsl/gsl>      // sudo dnf install  guidelines-support-library-devel
#include <chrono>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <csignal>
#include <source_location>
#include <stacktrace>

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;
#define LOGGER_(  msg )  using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<           "."    <<endl;cout.flush();cerr.flush();
#define LOGGER_R( msg )  using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<           ".\r\n"<<endl;cout.flush();cerr.flush();
#define LOGGERX(  msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}."    <<endl;cout.flush();cerr.flush();
#define LOGGERXR( msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}.\r\n"<<endl;cout.flush();cerr.flush();

// Gives a source location for printing.  Used for debugging.
std::string source_loc();           // forward declaration
extern void stacktrace_register();
void crash_signals_register();

/** Requires that a type has insertion operator
    Concept definition - used by a template below.
    Some value needs to be incorporated with above text:
///  Concept using Function Explicit instantiations that are required to generate code for linker.
///  TODO??: is the only used if definition is in *.cpp file?
///  https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
///  https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
//template std::ostream & operator<<( std::ostream & , std::vector<std::string> const & );
/// Concept using Function Explicit instantiations that are required to generate code for linker.
//template std::ostream & operator<<( std::ostream & , std::deque<int>          const & );
*/
template <typename Container>
concept Insertable = requires( std::ostream & out ) {
    requires not std::same_as<std::string, Container>;                                    // OR $ std::is_same <std::string, Container>::value OR std::is_same_v<std::string, Container>;
    { out << typename Container::value_type {} } -> std::convertible_to<std::ostream & >; // OR just $ { out << typename Container::value_type {} };
};

/** Prints contents of a container such as a vector of int's.
    Insertable Concept used by Templated Function definition
    Older version is here for the record:
    template<typename T> std::ostream & operator<<(std::ostream & out, std::vector<T> const & v) { // utility f() to print vectors
    if ( not v.empty() ) {
        out<<'['; std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", ")); out<<"\b\b]";
    }
        return out;
    }
*/
template<typename Container>                        //template<insertable Container>        // OR these 2 lines currently being used.
    requires Insertable<Container>
std::ostream &
operator<<( std::ostream & out, Container const & c) {
    if ( not c.empty()) {
        out << "[<";   //out.width(9);  // TODO??: neither work, only space out first element. //out << std::setw(9);  // TODO??: neither work, only space out first element.
        std::copy(c.begin(), c.end(), std::ostream_iterator< typename Container::value_type >( out, ">,<" ));
        out << "\b\b\b>]"; out.width(); out << std::setw(0);
    } else out << "[CONTAINTER IS EMPTY]";
    return out;
}
namespace Detail {  // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
} // End Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

class Base {
public:
    virtual ~Base();
    //virtual ~Base() {};
    virtual int v() =0;     // =0 ONLY makes whole class an abstract class (similar to the concept of an interface).
    int f();
};
Base::~Base() {};           // NOTE: Required because is is a destructor.
int Base::v() { return 99; };
int Base::f() { return 42; }

class Derived : public Base {
public:
    virtual ~Derived();  // calls destructors sequentially up to the base.
    virtual int v() override ;
};

Derived::~Derived() {}; // Required because is is a destructor.
int Derived::v() {
    int r = Base::v();  // A call into the base.
    return r + 999; };

class Derived2 : public Base {
public:
    //virtual ~Derived2();
    //        ~Derived2();
    virtual int v() override ;
};
//Derived2::~Derived2() {}; // Required because is is a destructor.
int Derived2::v() { return 599; };

int main ( int argc, char* arv[] ) { string my_arv { *arv}; cout << "~~~ argc,argv:"<<argc<<","<<my_arv<<"."<<endl; //crash_signals_register(); cin.exceptions( std::istream::failbit);  // throw on fail of cin.
    //Base b{};
    //b.v();
    Derived d{};
    d.v();
    Derived2 d2{};
    d2.v();
    d.Base::v();
    d.f();
    cout << "###" << endl;
    return EXIT_SUCCESS;
}
