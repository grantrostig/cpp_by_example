// cppmsg.com Boost 1.0 license.
// see: GOF 1995-SS 1.Singleton; Vlissides 1998-ch2,ch3; Larman 2005-SS 26.5; Robert Martin 2002-Singleton and Monstate; Headington 1996-SS2.7 p79; Cline 1999-ch16-?;
#pragma once
#include <bits/stdc++.h>
using namespace std;

/// GOF p131 under SS 2, option: the 3rd one, we call it option "c"
class Singleton_gof_registry;

struct Singleton_name_a_ptr {
    std::string name;
    Singleton_gof_registry * singleton_ptr;
};

using Registry = std::vector< Singleton_name_a_ptr >;

class Singleton_gof_registry {
    //Singleton_gof_registry( std::string const name );
    static Singleton_gof_registry *                            _instance;
    static Registry                                            _registry;
protected:
    static Singleton_gof_registry * lookup(        std::string const & name );  // TODO??: why is this not private?
public:
    static bool                     add_singleton( std::string const & name, Singleton_gof_registry * singleton_ptr);
    static Singleton_gof_registry * instance(      std::string const & name );
};
Singleton_gof_registry *               Singleton_gof_registry::_instance   {nullptr};
Registry                               Singleton_gof_registry::_registry   {};

Singleton_gof_registry * Singleton_gof_registry::lookup( std::string const & name ) {
    auto found_itr { std::find_if( _registry.cbegin(), _registry.cend(), [&name](Singleton_name_a_ptr a) ->bool {return a.name == name;} )};
    if ( found_itr != _registry.cend() ) {
        return found_itr->singleton_ptr;
    }
    return nullptr;
}

bool Singleton_gof_registry::add_singleton( std::string const & name, Singleton_gof_registry * singleton_ptr) {
    if ( auto found_p = lookup( name ); nullptr != found_p ) {
        Singleton_name_a_ptr name_a_ptr = { name, singleton_ptr };
        _registry.push_back( name_a_ptr );
    }
    else return false;
    return true;
};

Singleton_gof_registry * Singleton_gof_registry::instance( std::string const & name ) {
    if ( nullptr == _instance ) {
        _instance = new Singleton_gof_registry;
    }
    auto found_itr { std::find_if( _registry.cbegin(), _registry.cend(), [&name](Singleton_name_a_ptr a) ->bool {return a.name == name;} )};
    if ( found_itr != _registry.cend() ) {
        return found_itr->singleton_ptr;
    }
    return nullptr;
}

class Singleton1: public Singleton_gof_registry {
    Singleton1() {
        Singleton_gof_registry::add_singleton( "my_singleton1", this );
    }
public: int my_int {99};
};

class Singleton2: public Singleton_gof_registry {
    Singleton2() {
        Singleton_gof_registry::add_singleton( "my_singleton1", this );
    }
public: int my_int {99};
};

void test_singleton_gof_registry() {
    Singleton1 singleton1      = Singleton_gof_registry::instance("singleton1_name") ;
    Singleton1 singleton1_copy = Singleton_gof_registry::instance("singleton1_name") ;
    Singleton2 singleton2      = Singleton_gof_registry::instance("singleton2_name") ;

}
