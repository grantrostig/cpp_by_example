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

#include <cassert>
#include <chrono>
#include <csignal>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
/************************** Begining of Example **************************************************************
    https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-factory
*/

enum class Kind {
    my_kind_of_token_1,
    my_kind_of_token_2
};

class Base {
protected:  class Token {                               // TODO??: What goes in here? Nothing? If not, show an example.
                public: Token() { cout << ":constructor of Base::Token() has run."<<endl; }
                    Kind            token_kind_as_an_enum{};
                    std::string     token_value_as_a_string{};
            };
            virtual void post_initialize() {            // Called right after construction
                /* ... */
                setup_object_before_use_Zcalled_withinZ_post_initialize();                                    // GOOD: virtual dispatch is safe
                /* ... */
            }
public:     explicit Base( Token my_token ) {           // Create an imperfectly initialized object
                cout << ":constructor of Base( Token ) has started running."<<endl;
                if (  my_token.token_kind_as_an_enum == Kind::my_kind_of_token_1 ) {};
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
            int my_base_fn() { return 51; }
            int         my_base_int{};
            std::string my_base_string{"data member inited"};
};

class Derived_1 : public Base {                           // Some derived class
protected:  class Token {
                public: Token() { cout << ":constructor of Derived_1::Token() has run."<<endl;}
            };

            template<class T>
            friend std::unique_ptr<T> Base::create_u();

public:     explicit Derived_1( Token ) : Base{ Base::Token{} } { cout << ":constructor of Derived_1( Token ) has run."<<endl;}
            void setup_object_before_use_Zcalled_withinZ_post_initialize() override {
                /* ... */
                my_derived_int = 41;  ++my_derived_int; my_derived_string = "constructed inited";
                cout << ":Derived_1::setup_object_before_use_Zcalled_withinZ_post_initialize() has run."<<endl;
            };
            int my_derived_fn() { return 541; }
            int         my_derived_int{441};
            std::string my_derived_string{"data member inted"};
};

class Derived_2 : public Base {                           // Some derived class
protected:  class Token {
                public: Token() { cout << ":constructor of Derived_2::Token() has run."<<endl;}
            };

            template<class T>
            friend std::unique_ptr<T> Base::create_u();
            /*template<class T>
            friend std::shared_ptr<T> Base::create_s();*/

        public:     explicit Derived_2( Token ) : Base{ Base::Token{} } { cout << ":constructor of Derived_2( Token ) has run."<<endl;}
            void setup_object_before_use_Zcalled_withinZ_post_initialize() override {
                /* ... */
                my_derived_int = 41;  ++my_derived_int; my_derived_string = "constructed inited";
                cout << ":Derived_2::setup_object_before_use_Zcalled_withinZ_post_initialize() has run."<<endl;
            };
            int my_derived_fn() { return 541; }
            int         my_derived_int{441};
            std::string my_derived_string{"data member inted"};
};

int main (int argc, char* arv[]) {string my_arv {*arv};cout<< "~~~ argc,argv:"<<argc<<","<<my_arv<<"."<<endl; //crash_signals_register(); //cin.exceptions( std::istream::failbit);//throw on fail of cin.
    cout << "*** Unique ptr ***"        << endl;;
    std::unique_ptr<Derived_1> uniq_ptr_1 { Derived_1::create_u<Derived_1>() };  // creating a Derived object
    cout << uniq_ptr_1.get()->my_base_int     << endl;;
    cout << uniq_ptr_1.get()->my_derived_int  << endl;;
    cout << uniq_ptr_1.get()->my_derived_fn() << endl;;
    std::unique_ptr<Derived_2> uniq_ptr_2 { Derived_2::create_u<Derived_2>() };
    cout << uniq_ptr_2.get()->my_base_int     << endl;;
    cout << uniq_ptr_2.get()->my_derived_int  << endl;;
    cout << uniq_ptr_2.get()->my_derived_fn() << endl;;

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
