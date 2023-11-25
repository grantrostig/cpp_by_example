// cppmsg.com Boost 1.0 license.
// see: GOF 1995-SS 1.Singleton; Vlissides 1998-ch2,ch3; Larman 2005-SS 26.5; Robert Martin 2002-Singleton and Monstate; Headington 1996-SS2.7 p79; Cline 1999-ch16-?;
#pragma once
//#include "../../boost-ext_ut/ut.hpp"
//using namespace boost::ut::literals; https://github.com/worthy-os/ut/tree/master#user-guide
//using namespace boost::ut::operators::terse;
//using namespace boost::ut;
//#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <mutex>
#include <algorithm>
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl;
using namespace std::string_literals;

/// More modern implementations of: Design Patterns, Gamma et al. GOF p130 under SS 2.C (2.C or 3rd option): "registry of singletons".
/// TODO??: We hope this code is good quality "production" ready and also for multithreading,
///           even if Singleton1 and Singletion2 are defined in separate compilation units.
/// TODO:   Refactor to use shared_pointer's?? and possibly ref's.
/// TODO??: Does using this GOF registry really have to be as ugly as we have implemented it and use it in the test code below?

class Singleton_gof_registry;
struct Singleton_name_a_ptr {  // "a" means "and".
    std::string              name          {"NULL"};
    Singleton_gof_registry * singleton_ptr {nullptr};
};
using Registry = std::vector<Singleton_name_a_ptr>;

class Singleton_gof_registry {
            static  Singleton_gof_registry *    _instance;
            static  Registry *                  _registry;
            static  std::once_flag              _is_registry_instanciated;
            static  std::mutex                  _static_mtx;
protected:          ~Singleton_gof_registry()                                             noexcept;
          explicit  Singleton_gof_registry();
          explicit  Singleton_gof_registry( Singleton_gof_registry const &   )                          =delete;
          explicit  Singleton_gof_registry( Singleton_gof_registry       &&  )                          =delete;
                    Singleton_gof_registry & operator=( Singleton_gof_registry const &  )               =delete;
                    Singleton_gof_registry & operator=( Singleton_gof_registry       && )               =delete;
            static  Singleton_name_a_ptr const* lookup(        std::string const & name ) noexcept;       // Invariant: Function return type should be const * const? but not allowed.
public:     static  bool                        add_singleton( std::string const & name, Singleton_gof_registry * singleton_ptr);  // Called "register" in GOF book we don't want keyword in a name.
            static  Singleton_gof_registry *    instance(      std::string const & name );
                    std::string                 _name_COLLISION_with_derived {"singleton_got_registry_name"}; // Just testing the idea of having this data member. TODO??: Is it permissable for this to be non-static?
   friend     void  list_registry();  // Just for debugging.
};
Singleton_gof_registry::Singleton_gof_registry() {
   _name_COLLISION_with_derived = "name init in Singleton base constructor:"; cout <<"Construct base."<<endl;
    //std::scoped_lock<std::mutex> lock (static_mtx);
    //if ( nullptr == _registry ) {
        //_registry = new Registry;
    //}
    auto instanciate_registry = [](){ _registry = new Registry; cout << "Instanciate registry."<< endl;};
    try { std::call_once( _is_registry_instanciated, instanciate_registry );
    } catch (...) { cerr<<"Throwing exception in Singleton constructor."; }
}
Singleton_gof_registry::~Singleton_gof_registry() noexcept {
    delete _registry;
}
/// Returns found already existing registered singleton_ptr OR nullptr
/// Precondition: mutex should already be locked by caller or other.
/// Invariant: Function should be const.
Singleton_name_a_ptr const * Singleton_gof_registry::lookup( std::string const & name ) noexcept {
    cout << "lockup my singleton()."<<endl;
    assert( nullptr != _registry && "Should already have been created and loaded.");
    // TODO??: apparently there is no way to check if this thread without undefined behavior?
    //    https://en.cppreference.com/w/cpp/thread/mutex/try_lock
    // Testing: like a cassert? but part of the testing framework?? "lookup"_test = [] { 0_ll == (long long)_registry; };
    Singleton_name_a_ptr const * result;
    auto const match_name_predicate =  [&name] (Singleton_name_a_ptr const ptr) ->bool { cout<<"checking a name:"<< ptr.name<< endl; return ptr.name == name;};
    // TODO??: can we make above line any more const?
    auto itr =  std::find_if( _registry->cbegin(), _registry->cend(), match_name_predicate );             // TODO??: can I make .begin const?
    if ( itr != _registry->cend() ) {
        result = itr.base(); cout << "lockup() found:" <<itr->name <<endl;
    } else
        result = nullptr;
    //}
    return result;
}
/// Adds singleton to registry
/// Returns:    True if one has just been added. False if it already exists.
/// Invariant:  Assumes that singletons are NEVER removed from registry.
bool Singleton_gof_registry::add_singleton( std::string const & name, Singleton_gof_registry * singleton_ptr) { cout << "add_singleton()."<<endl;  // TODO??: why can't I const ptr or even & ref it?
    bool result {false};
    { std::scoped_lock<std::mutex> lock (_static_mtx);
        if ( auto found_n_a_p = lookup( name ); nullptr == found_n_a_p ) {
            _registry->push_back( {name, singleton_ptr} );                                                            cout << "add_singleton():success for:"<<name<<endl;
            result = true;
        } else result = false;
    }
    return result;
};
/// Instanciates _instance
/// Returns: named registry singleton_ptr OR NULL if name is not found.
Singleton_gof_registry * Singleton_gof_registry::instance( std::string const & name ) {     cout << "instance()."<<endl;
    assert( nullptr != _registry && "Should already have been created and loaded.");
    Singleton_gof_registry * result {nullptr};
    { std::scoped_lock<std::mutex> lock (_static_mtx);
        if ( auto found_n_a_p = lookup( name ); nullptr != found_n_a_p ) {
               result = found_n_a_p->singleton_ptr;                                             cout<<"Good instance found()."<<endl; }
        else { result = nullptr;                                                                cout<<"No instance found ()."<<endl; }
    }
    return result;
}
/// First usable Singleton within the "registry", must be staticly instancated whether used or not.
class Singleton1: public Singleton_gof_registry {
public: std::string  _name    {"Singleton1nameINIT"};
        int          _my_int  {25};  // TODO??: do I need to instanciate _instance constructor, OR will the parent's class constructor be called right afterward?
                     Singleton1();

// *** NOTE: TODO??: I try two different ways to get return or assign the correct type to the derived Singleton, but both are ugly and require static_cast?
//static  Singleton1 const  * const instance( std::string const & name );  // TODO??: But I want it const!  Can't get ref to work either.
};
//Singleton1 const * const Singleton1::instance( std::string const & name ) {
    //Singleton_gof_registry const * const singleton_gof_registry_p { Singleton_gof_registry::instance( name ) };  // TODO??: we think this const does not fix the return type problem, correct?
    //return static_cast<Singleton1 const * const>(singleton_gof_registry_p);     // TODO??: why exactly can't I make this dynamic_cast? We do have inheritance here, but compiler says "not polymorphic"
//};
Singleton1::Singleton1() { Singleton_gof_registry::add_singleton( "my_singleton1", this ); cout<<"constructor1."<<endl; }

/// Another usable Singleton within the "registry", must be staticly instancated whether used or not.
class Singleton2: public Singleton_gof_registry {
public: std::string  _name    {"Singleton2nameINIT"};
    int              _my_int  {35};
                     Singleton2();                       // {  Singleton_gof_registry::add_singleton( "my_singleton2", this ); cout<<"constructor2."<<endl;}
static  Singleton2 * instance( std::string const & name );
};
Singleton2::Singleton2() { Singleton_gof_registry::add_singleton( "my_singleton2", this ); cout<<"constructor2."<<endl; }
Singleton2 * Singleton2::instance( std::string const & name ) {
    Singleton_gof_registry * singleton_gof_registry_p { Singleton_gof_registry::instance( name ) };
    return static_cast<Singleton2 *>(singleton_gof_registry_p);
};

Singleton_gof_registry * Singleton_gof_registry::_instance                {nullptr};
Registry *               Singleton_gof_registry::_registry                {nullptr};
std::once_flag           Singleton_gof_registry::_is_registry_instanciated {};
std::mutex               Singleton_gof_registry::_static_mtx               {};
static Singleton1        singleton1_hidden_from_linker                    {};  // Allocates memory in .data segment instead of on heap via new().
static Singleton2        singleton2_hidden_from_linker                    {};

void list_registry(){cout<<"Registry # members:"<<Singleton_gof_registry::_registry->size() << ", Members:"; for ( auto i : *Singleton_gof_registry::_registry ) { cout << i.name << ", "; } cout << endl; }

void test_singleton_gof_registry() {
    cout << "BEGIN OF TEST CASE."<<endl;
    cout << sizeof(Singleton_gof_registry)<<endl;
    cout << sizeof(Singleton1)<<endl;
    list_registry();

    //Singleton1 const *  my_singleton1 = Singleton1::instance( "my_singleton1");  // TODO??: A nicer appearing return value than equivalent example below in Singleton2.
    Singleton1 * const  my_singleton1 = static_cast<Singleton1 * const>(Singleton1::instance( "my_singleton1"));  // TODO??: this is the wrong type! It does not have the data members I want in Singleton1.
    assert( not (nullptr == my_singleton1) );
    cout << "my_singleton1->my_int:" <<                     my_singleton1->_my_int <<endl;
    cout << "my_singleton1->name:" <<                       my_singleton1->_name <<endl;
    cout << "my_singleton1->name_COLLISION_with_derived:"<< my_singleton1->_name_COLLISION_with_derived <<endl;

    Singleton2 * const my_singleton2 = Singleton2::instance( "my_singleton2");  // TODO??:
    assert( not (nullptr == my_singleton2) );
    cout << "my_singleton2->my_int:" <<                     my_singleton2->_my_int <<endl;
    cout << "my_singleton2->name:" <<                       my_singleton2->_name <<endl;
    cout << "my_singleton2->name_COLLISION_with_derived:"<< my_singleton2->_name_COLLISION_with_derived <<endl;
    cout << "my_singleton2->my_int: set to 41." <<endl;
    my_singleton2->_my_int = 41;
    cout << "my_singleton2->my_int:" <<                     my_singleton2->_my_int <<endl;
    cout << "my_singleton1->my_int:" <<                     my_singleton1->_my_int <<endl;

    Singleton2 * my_singletonB = Singleton2::instance( "my_singleton2");  // TODO??:
    assert( not (nullptr == my_singletonB) );
    cout << "my_singletonB->my_int:" <<                     my_singletonB->_my_int <<endl;

    //Singleton1 * my_singleton3 = Singleton2::instance( "my_singleton2"); // fails as it should.

    list_registry();

    //"main"_test = [] { 0_i == 0; };
}
