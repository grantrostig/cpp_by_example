/** Factory_Method - A Creational Pattern - Design Pattern example -- Gang of Four / book
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

//#include <bits/stdc++.h>
#include <iostream>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include <source_location>
// Some crude logging that provides source location.
//#define LOGGER_( msg )   using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<          "."    <<endl;cout.flush();cerr.flush();
  #define LOGGER_( msg )   using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<          ".\r\n"<<endl;cout.flush();cerr.flush();
//#define LOGGERX( msg, x )using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<"},{"<<x<<"."    <<endl;cout.flush();cerr.flush();
  #define LOGGERX( msg, x )using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<"},{"<<x<<".\r\n"<<endl;cout.flush();cerr.flush();

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;

struct Wrong_base {
    string s_{"definition inited"};
    Wrong_base() =default;                      // TODO??: Why do we get warning without this line?
    Wrong_base(string s): s_{s} {
        LOGGERX("", s_);
        ub_to_call_virtual_in_constructor();
    }
    virtual void ub_to_call_virtual_in_constructor() =0;         // BAD: C.82: Don't call virtual functions in constructors and destructors
};
struct Wrong_derived : public Wrong_base {
    string derived_s_{"definition inited"};
    Wrong_derived() =default;
    Wrong_derived(string derived_s): derived_s_{derived_s+";constructor inited"} {
        derived_s_ += ";constructor fn inited ";
        LOGGERX("", derived_s_);
        ub_to_call_virtual_in_constructor();
    }
    virtual void ub_to_call_virtual_in_constructor() override final {
        derived_s_ += ";virtual function inited" ;
        LOGGERX("", derived_s_);
    };
};

class Base {
protected:  class Protected_dummy_token {  // Exists soley to disable the API user from directly constructing the object since we want to run a virtual function right after construction, but not during construction.
            public: Protected_dummy_token() {
                    cerr << ":constructor of Base::Protected_dummy_token() is/has run."<<endl; }
            };

            virtual void actions_post_construction() {            // Is to be called right after construction, but not during, since it is virtual.
                /* ... */  // TODO??: What is a good example of what should be done here?
                cerr << ":Base::actions_post_construction() starting run."<<endl;
                setup_the_object_before_use();                                    // GOOD: virtual dispatch is safe here
                cerr << ":Base::actions_post_construction() has run."<<endl;
                /* ... */  // TODO??: What is a good example of what should be done here?
            }
public:     explicit Base( Protected_dummy_token ) {           // Create an incompletely initialized object
                cerr << ":constructor of Base( Protected_dummy_token ) has started running."<<endl;
                ++my_base_int; my_base_string = "inited in constructor"; // TODO??: What if anything is a good example of what should be done here? Note: source example expect something.
                cerr << ":constructor of Base( Protected_dummy_token ) has run."<<endl;
            }
            virtual void setup_the_object_before_use() =0;  // Called f() in CppCoreGuidelines C.50

            template<class T> static std::unique_ptr<T> create_u() {        // Interface for creating unique objects
            //class Derived_1;
            //static std::unique_ptr<Derived_1> create_u() {        // Interface for creating unique objects
                cerr << ":Base::create_u() starting run."<<endl;
                auto p { std::make_unique<T>( typename T::Protected_dummy_token{} )};  // AKA std::unique_ptr<T> p { std::make_unique<T>( typename T::Protected_dummy_token{} )};
                p->actions_post_construction();
                cerr << ":Base::create_u() has run."<<endl;
                return p;
            }
            template<class T> static std::shared_ptr<T> create_s() {        // Interface for creating shared objects
                cerr << ":Base::create_s() started running."<<endl;
                auto p = std::make_shared<T>( typename T::Protected_dummy_token{} );  // TODO??: why did CCG example use this '='?
                p->actions_post_construction();
                cerr << ":Base::create_s() has run."<<endl;
                return p;
            }
            int my_base_int{10};
            std::string my_base_string{"base data member inited"};
            int my_base_fn() { return 15; }
};

class Derived_1 : public Base {    // API User derived class
protected:  class Protected_dummy_token {          // TODO??: This hides Base::Protected_dummy_token ! Was that intentional in source example?  Probably...some template magic?
               public: Protected_dummy_token() {
                   // TODO??: Probably nothing based on the source example, but what if anything, is a good example of what should be done here?
                   cerr << ":Constructor of Derived_1::Protected_dummy_token() is/has run."<<endl;
               }
               //Kind            token_kind_as_an_enum{Kind::not_set};
               //std::string     token_value_as_a_string{"Derived_1::Protected_dummy_token string data member inited"};
           };
protected:  template<class T> friend std::unique_ptr<T> Base::create_u();
            template<class T> friend std::shared_ptr<T> Base::create_s();
public:     explicit Derived_1( Protected_dummy_token ) : Base { Base::Protected_dummy_token{} } {  // TODO??: Is this :Base{} constructing the base classes' data structures? OR is it initializing member variables (with constants C.45)
                /* ... */  // TODO??: What is a good example of what should be done here?
                    cerr << ":constructor of Derived_1( Protected_dummy_token ) is/has run."<<endl;
            }
            void setup_the_object_before_use() override final {  // Called f() in CppCoreGuidelines C.50
                /* ... */  // TODO??: What is a good example of what should be done here?
                my_derived_1_int = 101;  ++my_derived_1_int; my_derived_1_string = "derived_1 data member inited in constructor";
                cerr << ":Derived_1::setup_the_object_before_use() is/has run."<<endl;  // TODO??: Is this a good example of what should be done here?
            };
            // *****  We consider this, below to be the functionality API of the class?  Not in the source example.
            int my_derived_1_int{100};
            std::string my_derived_1_string{"derived_1 data member inited"};
            int my_derived_fn() { return 150; }
};

/* class Derived_2 : public Base {                            // User derived class
protected:  class Protected_dummy_token {
                public: Protected_dummy_token() {
                        cerr << ":Constructor of Derived_2::Protected_dummy_token() started running."<<endl;
                        cerr << ":Constructor of Derived_2::Protected_dummy_token() has run."<<endl;
                }
                Kind            token_kind_as_an_enum{Kind::not_set};
                std::string     token_value_as_a_string{"Derived_2::Protected_dummy_token string data member inited"};
            };
            template<class T> friend std::unique_ptr<T> Base::create_u();
            template<class T> friend std::shared_ptr<T> Base::create_s();
public:     explicit Derived_2( Protected_dummy_token ) : Base{ Base::Protected_dummy_token{} } {
                cerr << ":Constructor of Derived_2( Protected_dummy_token ) has run."<<endl;
            }
            void setup_the_object_before_use() override final {
                my_derived_2_int = 201;  ++my_derived_2_int; my_derived_2_string = "derived_2 data member inited in constructor";
                cerr << ":Derived_2::setup_the_object_before_use() has run."<<endl;
            };
            int my_derived_2_int{200};
            std::string my_derived_2_string{"derived_2 pata member inited"};
            int my_derived_fn() { return 250; }
}; */

int main (int argc, char* argv[]) { string my_argv {*argv};cerr<< "~~~ argc,argv:"<<argc<<","<<my_argv<<"."<<endl; //crash_signals_register(); //cin.exceptions( std::istream::failbit);//throw on fail of cin.
    // std::unique_ptr<Derived_1> uniq_ptr_1  { Derived_1::create_u<Derived_1>() };  // creating a Derived object
    // auto uniq_ptr_1a { Derived_1::create_u<Derived_1>() };  // creating a Derived object
    // cout << ":*** Unique ptr_1 ***" << endl;;
    // cout << uniq_ptr_1.get()->my_base_int        << endl;;
    // cout << uniq_ptr_1.get()->my_base_string     << endl;;
    // cout << uniq_ptr_1.get()->my_base_fn()       << endl;;

    // cout << uniq_ptr_1.get()->my_derived_1_int   << endl;;
    // cout << uniq_ptr_1.get()->my_derived_1_string<< endl;;
    // cout << uniq_ptr_1.get()->my_derived_fn()    << endl;;


    Wrong_derived wd1{};
    Wrong_derived wd2{"hello"};
    //std::unique_ptr<Wrong_base>    wb_unique_ptr_a{std::unique_ptr<Wrong_base>(42)};
    std::unique_ptr<Wrong_derived> wd_unique_ptr_d{new Wrong_derived{"hello"}};
    std::unique_ptr<Wrong_derived> wb_unique_ptr_e{std::unique_ptr<Wrong_derived>()};
    auto                           wb_unique_ptr_f{std::unique_ptr<Wrong_derived>()};
    //std::unique_ptr<Wrong_derived> wd_unique_ptr_a{std::unique_ptr<Wrong_derived>("hello")};
    std::shared_ptr<Wrong_derived> wd_shared_ptr_c{std::unique_ptr<Wrong_derived>()};  // TODO??: why does this compile?
    std::shared_ptr<Wrong_derived> wd_shared_ptr_b{std::shared_ptr<Wrong_derived>()};

    //Derived_1 derived_1d{std::make_unique<Derived_1>()};
    //Derived_1 derived_1a{Derived_1::Protected_dummy_token {}};
    //int fake{};
    //Derived_1 derived_1b{ (Derived_1::Protected_dummy_token) fake {}};

    //std::unique_ptr<Derived_1> temp_uniq_ptr_1 { Derived_1::create_u<Derived_1>() };  // creating a Derived object
    //auto temp{ *temp_uniq_ptr_1 };
    //Derived_1 derived_1c{ temp };
    //cout << derived_1c.my_derived_1_int << endl;
    //cout << derived_1c.my_base_int << endl;


    /* std::unique_ptr<Derived_2> uniq_ptr_2 { Derived_2::create_u<Derived_2>() };
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
    cout << moved_shared_ptr_1.get()->my_derived_fn() << endl;; */

    /* Uncomment in main_short.cpp if running of more examples is wanted.
       and rename the main() you want
    extern int main_long(int, char*[]);
    main_long(argc,argv);
    */

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
