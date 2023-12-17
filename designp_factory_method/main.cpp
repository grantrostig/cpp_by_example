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
// ************************** Beginning of Example **************************************************************


/* ## Bing "Definition of token"
In computer programming, a token is the smallest individual element that is meaningful to the compiler. It's a single element of a programming
language. Tokens are the building blocks of a programming language. There are five categories of tokens:

- Keywords: These are pre-defined or reserved words in a programming language. Each keyword is meant to perform a specific function in a program.
- Identifiers: These are user-defined names used for naming variables, functions, and arrays.
- Constants: These refer to the variables with fixed values.
- Strings: These are arrays of characters ended with a null character (\\0).
- Operators: These are symbols that perform operations on one or more operands.

Tokens are used in many different contexts in programming. For example, in an authentication system, a token can represent the fact that a user
is authenticated. In a programming language like C, tokens can be keywords, identifiers, constants, strings, and special symbols.
*/

enum class Kind {           // Probably entirely misunderstood.  Was thinking of parsing tokens. See above "Definition of token".
    not_set,
    my_kind_of_token_1,
    my_kind_of_token_2
};

class Base {
protected:  class Token {  // Probably entirely misunderstood reason for this. Was thinking of parsing tokens. May just be a "marker" or name "handle" for use in make_unique to specify a type?  See above "Definition of token".
            public: Token() {
                    // TODO??: Probably nothing, based on the source example, but what if anything, is a good example of what should be done here?
                    cerr << ":constructor of Base::Token() is/has run."<<endl; }
                    //Kind            token_kind_as_an_enum{Kind::not_set};
                    //std::string     token_value_as_a_string{"base::Token string data member inited"};
            };

            virtual void post_initialize() {            // Called right after construction
                /* ... */  // TODO??: What is a good example of what should be done here?
                cerr << ":Base::post_initialize() starting run."<<endl;
                setup_object_before_use_Zcalled_withinZ_post_initialize();                                    // GOOD: virtual dispatch is safe
                cerr << ":Base::post_initialize() has run."<<endl;
                /* ... */  // TODO??: What is a good example of what should be done here?
            }
public:     explicit Base( Token my_token ) {           // Create an imperfectly initialized object
                cerr << ":constructor of Base( Token ) has started running."<<endl;
                /* ... */  // TODO??: What if anything is a good example of what should be done here? Nothing except ... shown in source example.
                /* if (  my_token.token_kind_as_an_enum == Kind::my_kind_of_token_1 ) {
                    cerr << ":If within::constructor of Base( Token ) has started running."<<endl;
                }; */
                my_base_int = 11;  ++my_base_int; my_base_string = "base data member inited in constructor";  // TODO??: Is this a good example of what should be done here?
                cerr << ":constructor of Base( Token ) has run."<<endl;
            }
            virtual void setup_object_before_use_Zcalled_withinZ_post_initialize() =0;  // Called f() in CppCoreGuidelines C.50

            template<class T> static std::unique_ptr<T> create_u() {        // Interface for creating unique objects
                cerr << ":Base::create_u() starting run."<<endl;
                auto p = std::make_unique<T>( typename T::Token{} );// TODO??: What exactly does this do here: $ typename T::Token{} // specifically  Token{}
                p->post_initialize();
                cerr << ":Base::create_u() has run."<<endl;
                return p;
            }
            template<class T> static std::shared_ptr<T> create_s() {        // Interface for creating shared objects
                cerr << ":Base::create_s() started running."<<endl;
                auto p = std::make_shared<T>( typename T::Token{} );
                p->post_initialize();
                cerr << ":Base::create_s() has run."<<endl;
                return p;
            }
            int my_base_int{10};
            std::string my_base_string{"base data member inited"};
            int my_base_fn() { return 15; }
};

class Derived_1 : public Base {    // API User derived class
protected:  class Token {          // TODO??: This hides Base::Token ! Was that intentional in source example?  Probably...some template magic?
                public: Token() {
                    // TODO??: Probably nothing based on the source example, but what if anything, is a good example of what should be done here?
                    cerr << ":Constructor of Derived_1::Token() started running."<<endl;
                }
                //Kind            token_kind_as_an_enum{Kind::not_set};
                //std::string     token_value_as_a_string{"Derived_1::Token string data member inited"};
            };
protected:          template<class T> friend std::unique_ptr<T> Base::create_u();
protected:          template<class T> friend std::shared_ptr<T> Base::create_s();
public:     explicit Derived_1( Token ) : Base { Base::Token{} } {  // TODO??: Is this :Base{} constructing the base classes' data structures? OR is it initializing member variables (with constants C.45)
                /* ... */  // TODO??: What is a good example of what should be done here?
                    cerr << ":constructor of Derived_1( Token ) is/has run."<<endl;
            }
            void setup_object_before_use_Zcalled_withinZ_post_initialize() override final {  // Called f() in CppCoreGuidelines C.50
                /* ... */  // TODO??: What is a good example of what should be done here?
                my_derived_1_int = 101;  ++my_derived_1_int; my_derived_1_string = "derived_1 data member inited in constructor";
                cerr << ":Derived_1::setup_object_before_use_Zcalled_withinZ_post_initialize() is/has run."<<endl;  // TODO??: Is this a good example of what should be done here?
            };
            // *****  We consider this, below to be the functionality API of the class?  Not in the source example.
            int my_derived_1_int{100};
            std::string my_derived_1_string{"derived_1 data member inited"};
            int my_derived_fn() { return 150; }
};

/* class Derived_2 : public Base {                            // User derived class
protected:  class Token {
                public: Token() {
                        cerr << ":Constructor of Derived_2::Token() started running."<<endl;
                        cerr << ":Constructor of Derived_2::Token() has run."<<endl;
                }
                Kind            token_kind_as_an_enum{Kind::not_set};
                std::string     token_value_as_a_string{"Derived_2::Token string data member inited"};
            };
            template<class T> friend std::unique_ptr<T> Base::create_u();
            template<class T> friend std::shared_ptr<T> Base::create_s();
public:     explicit Derived_2( Token ) : Base{ Base::Token{} } {
                cerr << ":Constructor of Derived_2( Token ) has run."<<endl;
            }
            void setup_object_before_use_Zcalled_withinZ_post_initialize() override final {
                my_derived_2_int = 201;  ++my_derived_2_int; my_derived_2_string = "derived_2 data member inited in constructor";
                cerr << ":Derived_2::setup_object_before_use_Zcalled_withinZ_post_initialize() has run."<<endl;
            };
            int my_derived_2_int{200};
            std::string my_derived_2_string{"derived_2 pata member inited"};
            int my_derived_fn() { return 250; }
}; */

int main (int argc, char* argv[]) { string my_argv {*argv};cerr<< "~~~ argc,argv:"<<argc<<","<<my_argv<<"."<<endl; //crash_signals_register(); //cin.exceptions( std::istream::failbit);//throw on fail of cin.
    std::unique_ptr<Derived_1> uniq_ptr_1 { Derived_1::create_u<Derived_1>() };  // creating a Derived object
    cout << ":*** Unique ptr_1 ***" << endl;;
    cout << uniq_ptr_1.get()->my_base_int        << endl;;
    cout << uniq_ptr_1.get()->my_base_string     << endl;;
    cout << uniq_ptr_1.get()->my_base_fn()       << endl;;

    cout << uniq_ptr_1.get()->my_derived_1_int   << endl;;
    cout << uniq_ptr_1.get()->my_derived_1_string<< endl;;
    cout << uniq_ptr_1.get()->my_derived_fn()    << endl;;

    /* std::unique_ptr<Derived_2> uniq_ptr_2 { Derived_2::create_u<Derived_2>() };
    cout << ":*** Unique ptr Derived_2 ***" << endl;;
    cout << uniq_ptr_2.get()->my_base_int       << endl;;
    cout << uniq_ptr_2.get()->my_derived_2_int  << endl;;
    cout << uniq_ptr_2.get()->my_derived_fn()   << endl;; */

    std::shared_ptr<Derived_1> shared_ptr_1 = Derived_1::create_s<Derived_1>();  // creating a Derived object
    cout << ":*** Shared ptr Derived_1 ***"    << endl;;
    cout << shared_ptr_1.get()->my_base_int     << endl;;
    cout << shared_ptr_1.get()->my_derived_1_int<< endl;;
    cout << shared_ptr_1.get()->my_derived_fn() << endl;;

    std::shared_ptr<Derived_1> moved_shared_ptr_1 { std::move(uniq_ptr_1) };
    cout << ":*** Unique ptr moved to Shared ptr ***"    << endl;;
    cout << moved_shared_ptr_1.get()->my_base_int     << endl;;
    cout << moved_shared_ptr_1.get()->my_derived_1_int<< endl;;
    cout << moved_shared_ptr_1.get()->my_derived_fn() << endl;;

    /* Uncomment in main_short.cpp if running of more examples is wanted.
    extern int main_long(int, char*[]);
    main_long(argc,argv);
    */

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
