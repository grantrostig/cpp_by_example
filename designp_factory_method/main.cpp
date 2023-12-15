/** Factory_Method Design Pattern example -- Gang of Four
    AKA:
    Know Uses:

    Related Patterns:
    Inspired by: (and possible copyright and LICENSE)
        https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-factory
    Edited by: Grant Rostig 2023
        Any additional beyond those that inspired this code is:
            Copyright (c) Grant Rostig, grantrostig.com 2023. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

    NOT PRODUCTION QUALITY CODE, it is missing proper rigor, just shows learning/teaching example, not real programming, don't copy_paste this.

    Reminder of usefull resources:
        https://coliru.stacked-crooked.com/
        https://godbolt.org/
        https://cppinsights.io/
        https://Wandbox.org
        https://arnemertz.github.io/online-compilers/
    [[maybe_unused]] int * my_new_var8 = ::new (22,int);
    g++ -Werror -Weffc++ -Wextra -Wall -Wconversion -Wshadow -Wpedantic -Wold-style-cast -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-override -Wnon-virtual-dtor \
        -Wcast-align -Woverloaded-virtual -Wunused -pedantic -Wsign-conversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough \
        -Wuseless-cast -Wsuggest-final-types -Wsuggest-final-methods -Wduplicated-cond -Wduplicated-branches -Wlogical-op -std=gnuc++23 \
        main.cpp <OTHER>.cpp -o <A.OUT>
    std::string                 STRING_QQQ          {"qqq"};
    std::vector<char>           QQQ                 {STRING_QQQ.begin(),STRING_QQQ.end()};
 */

//#include <bits/stdc++.h>
//#include <gsl/gsl>      // sudo dnf install  guidelines-support-library-devel
#include <cassert>
#include <chrono>
#include <csignal>
#include <iostream>
#include <iterator>
#include <memory>
//#include <stacktrace>
#include <string>
//#include <source_location>
#include <vector>

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;
/* #define   LOGGER_( msg )   using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:{" <<#msg<<          "}."    <<endl;cout.flush();cerr.flush();
//#define LOGGER_( msg )   using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:{" <<#msg<<          "}.\r\n"<<endl;cout.flush();cerr.flush();
#define   LOGGERX( msg, x )using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:{" <<#msg<<"},{"<<x<<"}."    <<endl;cout.flush();cerr.flush();
//#define LOGGERX( msg, x )using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:{" <<#msg<<"},{"<<x<<"}.\r\n"<<endl;cout.flush();cerr.flush();

// Gives a source location for printing.  Used for debugging.
std::string source_loc();  // forward declaration
//#define NDEBUG   // define if asserts are NOT to be checked.
/// Concept definition - used by a template below.
/// Requires that a type has insertion operator
template <typename Container>
concept Insertable = requires( std::ostream & out ) {
    requires not std::same_as<std::string, Container>;                                    // OR $ std::is_same <std::string, Container>::value OR std::is_same_v<std::string, Container>;
    { out << typename Container::value_type {} } -> std::convertible_to<std::ostream & >; // OR just $ { out << typename Container::value_type {} };
};
/// Prints contents of a container such as a vector of int's.
/// Insertable Concept used by Templated Function definition
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
} */

/************************** Begining of Example **************************************************************
    https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-factory
*/

enum class Token_category {
    my_derived_1,
    my_derived_2
};

class Base {
protected:  class Token {                               // TODO??: What goes in here? Nothing? If not, show an example.
                public: Token() { cout << ":constructor of Base::Token() has run."<<endl; }
                Token_category  my_token_category{};
                std::string     my_token_string{};
            };
            virtual void post_initialize() {            // Called right after construction
                /* ... */
                setup_object_before_use_Zcalled_withinZ_post_initialize();                                    // GOOD: virtual dispatch is safe
                /* ... */
            }
public:     explicit Base( Token my_token ) {           // Create an imperfectly initialized object
                cout << ":constructor of Base( Token ) has started running."<<endl;
                if (  my_token.my_token_category == Token_category::my_derived_1 ) {};
                my_base_int = 41;  ++my_base_int; my_base_string = "constructed inited";
            }
            virtual void setup_object_before_use_Zcalled_withinZ_post_initialize() =0;

            template<class T>
            static std::unique_ptr<T> create_u() {        // Interface for creating shared objects
                cout << ":Base::create_u() has run."<<endl;
                auto p = std::make_unique<T>( typename T::Token{} );
                p->post_initialize();
                return p;
            }
            template<class T>
            static std::shared_ptr<T> create_s() {        // Interface for creating shared objects
                cout << ":Base::create_s() has run."<<endl;
                auto p = std::make_shared<T>( typename T::Token{} );
                p->post_initialize();
                return p;
            }
            int my_base_fn() { return 51; }
            int         my_base_int{};
            std::string my_base_string{"data member inited"};
};

class Derived : public Base {                           // Some derived class
protected:  class Token {
                public: Token() { cout << ":constructor of Derived::Token() has run."<<endl;}
            };

            template<class T>
            friend std::unique_ptr<T> Base::create_u();
            template<class T>
            friend std::shared_ptr<T> Base::create_s();

public:     explicit Derived( Token ) : Base{ Base::Token{} } { cout << ":constructor of Derived( Token ) has run."<<endl;}
            void setup_object_before_use_Zcalled_withinZ_post_initialize() override {
                /* ... */
                my_derived_int = 41;  ++my_derived_int; my_derived_string = "constructed inited";
                cout << ":Derived::setup_object_before_use_Zcalled_withinZ_post_initialize() has run."<<endl;
            };
            int my_derived_fn() { return 541; }
            int         my_derived_int{441};
            std::string my_derived_string{"data member inted"};
};

int main (int argc, char* arv[]) {string my_arv {*arv};cout<< "~~~ argc,argv:"<<argc<<","<<my_arv<<"."<<endl; //crash_signals_register(); //cin.exceptions( std::istream::failbit);//throw on fail of cin.
    cout << "*** Unique ptr ***"    << endl;;
    std::unique_ptr<Derived> uptr = Derived::create_u<Derived>();  // creating a Derived object
    cout << uptr.get()->my_base_int     << endl;;
    cout << uptr.get()->my_derived_int  << endl;;
    cout << uptr.get()->my_derived_fn() << endl;;


    cout << "*** Shared ptr ***"    << endl;;
    std::shared_ptr<Derived> sptr = Derived::create_s<Derived>();  // creating a Derived object
    cout << sptr.get()->my_base_int     << endl;;
    cout << sptr.get()->my_derived_int  << endl;;
    cout << sptr.get()->my_derived_fn() << endl;;

    /* cout << "*** Unique ptr moved to Shared ptr ***"    << endl;;
    std::shared_ptr<Derived> mptr { std::move(uptr) };
    cout << mptr.get()->my_base_int     << endl;;
    cout << mptr.get()->my_derived_int  << endl;;
    cout << mptr.get()->my_derived_fn() << endl;; */

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
