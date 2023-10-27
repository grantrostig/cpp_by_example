// cppmsg.com Boost 1.0 license.
// see: GOF 1995-SS 1.Singleton; Vlissides 1998-ch2,ch3; Larman 2005-SS 26.5; Robert Martin 2002-Singleton and Monstate; Headington 1996-SS2.7 p79; Cline 1999-ch16-?;
#pragma once
#include <bits/stdc++.h>
using namespace std;

/// GOF p131 under SS 2, option: the 3rd one, we call it option "c"
class Singleton_gof_registry;
struct Singleton_name_a_ptr {
    std::string name {"NULL"};
    Singleton_gof_registry * singleton_ptr;
};
using Registry = std::vector< Singleton_name_a_ptr >;

class Singleton_gof_registry {
            static      Singleton_gof_registry *                            _instance;
            static      Registry                                            _registry;
protected:              ~Singleton_gof_registry()                                             noexcept      =default;
            explicit    Singleton_gof_registry()                                                            =default;  // TODO: what if anything does explicity do here?
            explicit    Singleton_gof_registry( Singleton_gof_registry const &   )                          =delete;  // TODO: what if anything does explicity do here?
            explicit    Singleton_gof_registry( Singleton_gof_registry       &&  )                          =delete;
                        Singleton_gof_registry & operator=( Singleton_gof_registry const &  ) noexcept      =delete;
                        Singleton_gof_registry & operator=( Singleton_gof_registry       && ) noexcept      =delete;
            static      Singleton_name_a_ptr *   lookup(        std::string const & name );  // TODO??: why is this not private?
public:     static      bool                     add_singleton( std::string const & name, Singleton_gof_registry * singleton_ptr);
            static      Singleton_gof_registry * instance(      std::string const & name );
                        string                   name_COLLISION_in_derived {"name_singleton_got_registry"};  //  Testing the idea of having this data member. TODO??: Is it permissable for this to be non-static?
    friend              void list_registry();
};

Singleton_gof_registry *               Singleton_gof_registry::_instance   {nullptr};   // Init is probably needed? or not because it is a fundamental type, a pointer?
Registry                               Singleton_gof_registry::_registry   {};          // Init probably not needed.

/// returns found already existing registered singleton_ptr or nullptr
Singleton_name_a_ptr * Singleton_gof_registry::lookup( std::string const & name ) {
    cout << "lockup()."<<endl;
    Singleton_name_a_ptr * result;
    auto match_name_predicate = [&name] (Singleton_name_a_ptr a) ->bool { cout<<"checking a name:"<< a.name<< endl; return a.name == name;};
    auto itr =  std::find_if( _registry.begin(), _registry.end(), match_name_predicate );
    if ( itr != _registry.cend() ) {
        result = itr.base();
        cout << "lockup() found:"<<itr->name <<endl;
    } else
        result = nullptr;
    return result;
}

/// Adds singleton to registry Returns: True if one has just been added. False if it already exists.
bool Singleton_gof_registry::add_singleton( std::string const & name, Singleton_gof_registry * singleton_ptr) {
    cout << "add_singleton()."<<endl;
    if ( auto found_n_a_p = lookup( name ); nullptr == found_n_a_p ) {
        Singleton_name_a_ptr name_a_ptr = { name, singleton_ptr };
        _registry.push_back( name_a_ptr );
        cout << "add_singleton() success of:"<<name<<endl;
        return true;
    } else return false;
};

/// Instanciates _instance
/// Returns: named registry singleton_ptr OR NULL if name is not found.
Singleton_gof_registry * Singleton_gof_registry::instance( std::string const & name ) {
    cout << "instance()."<<endl;
    Singleton_gof_registry * result {nullptr};
    if ( nullptr == _instance ) { _instance = new Singleton_gof_registry; cout<< "new."<<endl;}
    if ( auto found_n_a_p = lookup( name ); nullptr != found_n_a_p ) { result = found_n_a_p->singleton_ptr; cout<<"good instance()."<<endl; }
    else { result = nullptr;            cout<<"NO instance() to return."<<endl; }
    return result;
}

void list_registry() {cout<<"Registry size:"<<Singleton_gof_registry::_registry.size() << ", Members:"; for ( auto i : Singleton_gof_registry::_registry ) { cout << i.name << ", "; } cout << endl; }

class Singleton1: public Singleton_gof_registry {
public: string  name    {"Singleton1name"};
public: int     my_int  {99};  // TODO??: do I need to instanciate _instance constructor, OR will the parent's class constructor be called right afterward?
public: Singleton1() { cout<<"constructor1."<<endl; Singleton_gof_registry::add_singleton( "my_singleton1", this ); }
public: static    Singleton_gof_registry * instance( std::string const & name );
};
static Singleton1 singleton1;

class Singleton2: public Singleton_gof_registry {
public: string  name    {"Singleton2name"};
public: int     my_int  {99};
public: Singleton2() { cout<<"constructor2."<<endl; Singleton_gof_registry::add_singleton( "my_singleton2", this ); }
public: static  Singleton_gof_registry * instance( std::string const & name );
};
static Singleton2 singleton2;

void test_singleton_gof_registry() {
    //Singleton_gof_registry * singleton1_p      = Singleton_gof_registry::instance( "singleton1_name") ;
    //if ( nullptr == singleton1_p ) cout << "failed." << endl;
    //bool added_one     = Singleton_gof_registry::add_singleton( "singleton1_name",  singleton1_p );
    //if ( nullptr == singleton1_p ) cout << "failed." << endl;
    //Singleton_gof_registry * singleton1_p_copy = Singleton_gof_registry::instance( "singleton1_name") ;
    //if ( nullptr == singleton1_p_copy ) cout << "failed." << endl;
    //Singleton_gof_registry * singleton2_p      = Singleton_gof_registry::instance( "singleton2_name") ;
    //if ( nullptr == singleton2_p ) cout << "failed." << endl;
    cout << "BEGIN OF TEST CASE."<<endl;
    list_registry();

    Singleton_gof_registry *  my_singleton1 = Singleton1::instance( "my_singleton1");  // TODO??: this is the wrong type! It does not have the data members I want in Singleton1.
    if ( nullptr == my_singleton1 ) cout << "failed." << endl;
    else cout << my_singleton1->name_COLLISION_in_derived<<endl;

    //Singleton2 *  my_singleton2 = Singleton2::instance( "my_singleton2");  // TODO??: BAD see 4 lines up ^^^^.
    Singleton2 *  my_singleton2 = (Singleton2 *) Singleton2::instance( "my_singleton2");  // TODO??: BAD see 4 lines up ^^^^.
    if ( nullptr == my_singleton2 )
        cout << "failed." << endl;
    else cout << my_singleton2->my_int<<endl;

    list_registry();
}
