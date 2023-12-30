/** Factory_Method - A Creational Pattern - Design Patterns example -- Gang of Four / book
    AKA:    Virtual_Constructor, Factory_Function??
    Intent: Define an interface for creating objects, but let subclasses decide which class to instanciate
            Factory_Method lets a class defer instanciation to subclasses.
    Not:    Abstract_Factory, Builder, Prototype, Singleton, and the generic term: factory.
    Uses:

    Related Patterns:
    Inspired by: (and possible copyright and LICENSE)
        https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-factory
    Edited by: Grant Rostig 2023
        Any additional beyond those that inspired this code is:
            Copyright (c) Grant Rostig, grantrostig.com 2023. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

    NOT PRODUCTION QUALITY CODE, it is missing proper rigor, just shows learning/teaching example, not real programming, don't copy_paste this.
 */

#include "animals.hpp"

//#include <bits/stdc++.h>
#include <iostream>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include <source_location>
// Some crude logging that prints source location, where X prints a variable, and R adds \n\r (which is usefull when tty in in RAW or CBREAK mode. Requires C++20.
  #define LOGGER_(  msg )  using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<           "."    <<endl;cout.flush();cerr.flush();
  #define LOGGER_R( msg )  using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<           ".\r\n"<<endl;cout.flush();cerr.flush();
  #define LOGGERX(  msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}."    <<endl;cout.flush();cerr.flush();
  #define LOGGERXR( msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}.\r\n"<<endl;cout.flush();cerr.flush();

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;

struct Wrong_base {
    string s_{"Definition inited"};
    Wrong_base()  {
        LOGGERX( , s_);
 //     ub_to_call_virtual_in_constructor();                    // TODO??: Won't link, but same line in string parameter constructor below does?
    }
    ~Wrong_base() =default;
    Wrong_base(string s): s_{s} {
        LOGGERX(, s_);
        ub_to_call_virtual_in_constructor();  // *** Undefined behaviour
    }
#define BAD_C_82
#ifdef  BAD_C_82
    virtual string ub_to_call_virtual_in_constructor() =0;        // BAD: C.82: Don't call virtual functions in constructors and destructors or you will get UB.
#else
    virtual string ub_to_call_virtual_in_constructor();
#endif
    virtual int f() {
        LOGGER_();
        return 42;
    };
#ifndef BAD_C_82
 // virtual int g() =0;
#endif
};
#ifndef BAD_C_82
    string Wrong_base::ub_to_call_virtual_in_constructor() {       // BAD: C.82: Don't call virtual functions in constructors and destructors
        return "Virtual in constructor";
    };
#endif

struct Wrong_derived : public Wrong_base {
    string derived_s_{"Definition inited"};
    Wrong_derived() {
        LOGGER_( ./Wrong_derived(){}; );
    };
    Wrong_derived(string derived_s): derived_s_{derived_s+";Constructor inited"} {
        derived_s_ += ";Constructor fn inited";
        LOGGERX( , derived_s_);
        ub_to_call_virtual_in_constructor();
        f();
    }
    virtual string ub_to_call_virtual_in_constructor() override final {
        derived_s_ += ";Virtual fn inited" ;
        LOGGERX("", derived_s_);
        return derived_s_;
    };
    virtual int f() override final {
        LOGGER_();
        return 142;
    };
};

class Base {
protected:  class Protected_dummy_token {  // Exists soley to disable the API user from directly constructing the object since we want to run a virtual function right after construction, but not during construction.
            public: Protected_dummy_token() { cerr << ":constructor of Base::Protected_dummy_token() is/has run."<<endl; } };
            virtual void actions_post_construction() {            // Is to be called right after construction, but not during, since it is virtual.
                                                                cerr << ":Base::actions_post_construction() starting run."<<endl; /* ... */  // TODO??: What is a good example of what should be done here?
                setup_the_object_before_use();                                    // GOOD: virtual dispatch is safe here
                                                                cerr << ":Base::actions_post_construction() has run."<<endl; /* ... */  // TODO??: What is a good example of what should be done here?
            }
public:     explicit Base( Protected_dummy_token ) {            // Construct an incompletely initialized object, the public constructor is forced to be protected due to the token which is not used otherwise.
                                                                cerr << ":constructor of Base( Protected_dummy_token ) has started running."<<endl;
                my_base_string = ";Inited in constructor"; // TODO??: What if anything is a good example of what should be done here? Note: source example expect something.
                                                                cerr << ":constructor of Base( Protected_dummy_token ) has run."<<endl;
            }
            virtual void setup_the_object_before_use() =0;  // Called f() in CppCoreGuidelines C.50
            template<class T> static std::unique_ptr<T> create_u() {        // Interface for creating unique objects
                                                                cerr << ":Base::create_u() starting run."<<endl;
                auto p { std::make_unique<T>( typename T::Protected_dummy_token{} )};  // AKA std::unique_ptr<T> p { std::make_unique<T>( typename T::Protected_dummy_token{} )};
                p->actions_post_construction(); cerr << ":Base::create_u() has run."<<endl;
                return p;
            }
            template<class T> static std::shared_ptr<T> create_s() {        // Interface for creating shared objects
                                                                cerr << ":Base::create_s() started running."<<endl;
                auto p = std::make_shared<T>( typename T::Protected_dummy_token{} );  // TODO??: why did CCG example use this '='?
                p->actions_post_construction();
                                                                cerr << ":Base::create_s() has run."<<endl;
                return p;
            }
            std::string my_base_string{"Definition inited"};
            int my_base_fn() { return 15; }
};

class Derived_1 : public Base {    // API User derived class
protected:  class Protected_dummy_token {          // TODO??: This hides Base::Protected_dummy_token ! Was that intentional in source example?  Probably...some template magic?
               public: Protected_dummy_token() {
                   // TODO??: Probably nothing based on the source example, but what if anything, is a good example of what should be done here?
                   cerr << ":Constructor of Derived_1::Protected_dummy_token() is/has run."<<endl;
               }
           };
protected:  template<class T> friend std::unique_ptr<T> Base::create_u();
            template<class T> friend std::shared_ptr<T> Base::create_s();
public:     explicit Derived_1( Protected_dummy_token ) : Base { Base::Protected_dummy_token{} } {  // TODO??: Is this :Base{} constructing the base classes' data structures? OR is it initializing member variables (with constants C.45)
                                                                /* ... */  // TODO??: What is a good example of what should be done here?
                cerr << ":constructor of Derived_1( Protected_dummy_token ) is/has run."<<endl;
            }
            void setup_the_object_before_use() override final {  // Called f() in CppCoreGuidelines C.50
                                                                /* ... */  // TODO??: What is a good example of what should be done here?
                my_derived_1_string += ";Setup";
                                                                cerr << ":Derived_1::setup_the_object_before_use() is/has run."<<endl;  // TODO??: Is this a good example of what should be done here?
            };
            // *****  We consider this, below to be the functionality API of the class?  This is not present in the source example.
            std::string my_derived_1_string{"Definition inited"};
            int my_derived_fn() { return 150; }
};

int main (int argc, char* argv[]) { string my_argv {*argv};cerr<< "~~~ argc,argv:"<<argc<<","<<my_argv<<"."<<endl; //crash_signals_register(); //cin.exceptions( std::istream::failbit);//throw on fail of cin.

    //Animal a;  // TODO??: fails because pure virtual? or no constructor?  What would be required to fix it?
    Animal * dog_ptr = Animal::create(Animal_type::dog); // https://stackoverflow.com/questions/307352/g-undefined-reference-to-typeinfo
    dog_ptr->speak();
    Animal::create(Animal_type::cat)->speak();
    delete dog_ptr;

    LOGGER_( ./Wrong_derived wd1{}; );
    Wrong_derived wd1{};
    LOGGERX( wd1.s_;,        wd1.s_ );
    LOGGERX( wd1.derived_s_, wd1.derived_s_ );
    LOGGERX(./wd1.ub_to_call_virtual_in_constructor()
            , wd1.ub_to_call_virtual_in_constructor());
    LOGGERX(./wd1.f()
            , wd1.f() );

    Wrong_derived wd2{"argument1"};
    std::unique_ptr<Wrong_derived> wd_unique_ptr_d{new Wrong_derived{"argument1"}};         // TODO??: Note warning.
    std::unique_ptr<Wrong_derived> wb_unique_ptr_e{std::unique_ptr<Wrong_derived>()};
    auto                           wb_unique_ptr_f{std::unique_ptr<Wrong_derived>()};

//  std::unique_ptr<Wrong_derived> wd_unique_ptr_a{std::unique_ptr<Wrong_derived>("hello")};
//  std::unique_ptr<Wrong_derived> wd_unique_ptr_h{std::unique_ptr<Wrong_derived>(){"hello"};
 // std::unique_ptr<Wrong_derived> wd_unique_ptr_g{std::unique_ptr<Wrong_derived>()("hello")};

/*  std::unique_ptr<Derived_1> uniq_ptr_1  { Derived_1::create_u<Derived_1>() };  // creating a Derived object
    auto uniq_ptr_1a { Derived_1::create_u<Derived_1>() };  // creating a Derived object
    cout << ":*** Unique ptr_1 ***" << endl;;
    cout << uniq_ptr_1.get()->my_base_string     << endl;
    cout << uniq_ptr_1.get()->my_base_fn()       << endl;
    cout << uniq_ptr_1.get()->my_derived_1_string<< endl;
    cout << uniq_ptr_1.get()->my_derived_fn()    << endl;

    Derived_1 derived_1d{std::make_unique<Derived_1>()};
    Derived_1 derived_1a{Derived_1::Protected_dummy_token {}};
    int fake{};
    Derived_1 derived_1b{ (Derived_1::Protected_dummy_token) fake {}};

    std::unique_ptr<Derived_1> temp_uniq_ptr_1 { Derived_1::create_u<Derived_1>() };  // creating a Derived object
    auto temp{ *temp_uniq_ptr_1 };
    Derived_1 derived_1c{ temp };
    cout << derived_1c.my_derived_1_int << endl;
    cout << derived_1c.my_base_int << endl;

    std::unique_ptr<Derived_2> uniq_ptr_2 { Derived_2::create_u<Derived_2>() };
    cout << ":*** Unique ptr Derived_2 ***" << endl;;
    cout << uniq_ptr_2.get()->my_base_int       << endl;;
    cout << uniq_ptr_2.get()->my_derived_2_int  << endl;;
    cout << uniq_ptr_2.get()->my_derived_fn()   << endl;;

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
 */

 /* Uncomment in main_shortened.cpp if running of that code is also wanted. And, or, rename the main() you want
    extern int main_not_shortened(int, char*[]);
    main_not_shortened(argc,argv);
    */

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
