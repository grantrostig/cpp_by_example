// cppmsg.com Boost 1.0 license.
// see: GOF 1995-SS 1.Singleton; Vlissides 1998-ch2,ch3; Larman 2005-SS 26.5; Robert Martin 2002-Singleton and Monstate; Headington 1996-SS2.7 p79; Cline 1999-ch16-?;
#pragma once
#include "../../boost-ext_ut/ut.hpp"
#include <bits/stdc++.h>
using namespace std;
//using namespace boost::ut::literals;
//using namespace boost::ut::operators::terse;
using namespace boost::ut;

/// GOF p131 under SS 2, 3rd option: "registry of singletons".
class Singleton_gof_registry;
struct Singleton_name_a_ptr {
    std::string name {"NULL"};
    Singleton_gof_registry * singleton_ptr;
};
using Registry = std::vector< Singleton_name_a_ptr >;

class Singleton_gof_registry {
                          // TODO??: why don't I need _instance as is shown in the book? Maybe because I have the registry which contains the instances?
            //static      Singleton_gof_registry *                            _instance;
            static      Registry                                            _registry;
protected:              ~Singleton_gof_registry()                                             noexcept      =default;  // TODO??: Read that it should be private but that cause compile error.
          //explicit    Singleton_gof_registry()                                                            =default;  // TODO: what if anything does explicit do here?
            explicit    Singleton_gof_registry() {                                                                     // TODO: what if anything does explicit do here?
                            cout <<"Construct base."<<endl;
                            name_COLLISION_with_derived = "name init in Singleton base constructor:";
                        }
            explicit    Singleton_gof_registry( Singleton_gof_registry const &   )                          =delete;  // TODO: what if anything does explicit do here?
            explicit    Singleton_gof_registry( Singleton_gof_registry       &&  )                          =delete;
                        Singleton_gof_registry & operator=( Singleton_gof_registry const &  ) noexcept      =delete;
                        Singleton_gof_registry & operator=( Singleton_gof_registry       && ) noexcept      =delete;
            //static      Singleton_name_a_ptr const * const  lookup(        std::string const & name );  // TODO??: why is this not private in the book?
            static      Singleton_name_a_ptr *  lookup(        std::string const & name );  // TODO??: why is this not private in the book?  Why static?
public:     static      bool                    add_singleton( std::string const & name, Singleton_gof_registry * singleton_ptr);
            static      Singleton_gof_registry *instance(      std::string const & name );
                        string                  name_COLLISION_with_derived {"singleton_got_registry_name"}; // Testing the idea of having this data member. TODO??: Is it permissable for this to be non-static?
    friend void list_registry();
};
//Singleton_gof_registry * Singleton_gof_registry::_instance   {nullptr};   // TODO??:Init is probably needed? or not because it is a fundamental type, a pointer?
Registry                 Singleton_gof_registry::_registry   {};          // TODO??:Init probably not needed.
/// Returns found already existing registered singleton_ptr OR nullptr
Singleton_name_a_ptr * Singleton_gof_registry::lookup( std::string const & name ) { cout << "lockup()."<<endl;
    Singleton_name_a_ptr * result;
    auto match_name_predicate =  [&name] (Singleton_name_a_ptr a) ->bool { cout<<"checking a name:"<< a.name<< endl; return a.name == name;};
    auto itr =  std::find_if( _registry.begin(), _registry.end(), match_name_predicate );
    if ( itr != _registry.cend() ) {
        result = itr.base(); cout << "lockup() found:" <<itr->name <<endl;
    } else
        result = nullptr;
    return result;
}
/// Adds singleton to registry Returns: True if one has just been added. False if it already exists.
bool Singleton_gof_registry::add_singleton( std::string const & name, Singleton_gof_registry * singleton_ptr) { cout << "add_singleton()."<<endl;  // TODO??: why can't I const ptr or even & ref it?
    mutex mtx;
    "lookup"_test = [] { expect( 0==0 ); };
    scoped_lock<std::mutex > lock (mtx);
    if ( auto found_n_a_p = lookup( name ); nullptr == found_n_a_p ) {
        //Singleton_name_a_ptr name_a_ptr { name, singleton_ptr };
        //_registry.push_back( name_a_ptr );                                                                      cout << "add_singleton() success of:"<<name<<endl;
        // singleton_ptr points at static memory and I'm just copying the address to vector.
        _registry.push_back( {name, singleton_ptr} );                                                            cout << "add_singleton() success of:"<<name<<endl;
        return true;
    } else return false;
};
/// Instanciates _instance
/// Returns: named registry singleton_ptr OR NULL if name is not found.
Singleton_gof_registry * Singleton_gof_registry::instance( std::string const & name ) {                     cout << "instance()."<<endl;
    Singleton_gof_registry * result {nullptr};
    { mutex mtx; scoped_lock<std::mutex> lock (mtx);
    //    if ( nullptr == _instance ) { _instance = new Singleton_gof_registry;                                   cout<< "new."<<endl;}
    }
    if ( auto found_n_a_p = lookup( name ); nullptr != found_n_a_p ) { result = found_n_a_p->singleton_ptr; cout<<"good instance()."<<endl; }
    else { result = nullptr;                                                                                cout<<"NO instance() to return."<<endl; }
    return result;
}
void list_registry(){cout<<"Registry size:"<<Singleton_gof_registry::_registry.size() << ", Members:"; for ( auto i : Singleton_gof_registry::_registry ) { cout << i.name << ", "; } cout << endl; }
class Singleton1: public Singleton_gof_registry {
public: string  name    {"Singleton1name"};
        int     my_int  {98};  // TODO??: do I need to instanciate _instance constructor, OR will the parent's class constructor be called right afterward?
        Singleton1() {  Singleton_gof_registry::add_singleton( "my_singleton1", this ); cout<<"constructor1."<<endl; }
static  Singleton1 const  * const instance( std::string const & name );  // TODO??: But I want it const!  Can't get ref to work either.
};
Singleton1 const * const Singleton1::instance( std::string const & name ) {
    Singleton_gof_registry const * singleton_gof_registry { Singleton_gof_registry::instance( name ) };
    return static_cast<Singleton1 const *>(singleton_gof_registry);
};
static Singleton1 singleton1;
class Singleton2: public Singleton_gof_registry {
public: string  name    {"Singleton2name"};
        int     my_int  {99};
        Singleton2() {  Singleton_gof_registry::add_singleton( "my_singleton2", this ); cout<<"constructor2."<<endl;}
static  Singleton2 * instance( std::string const & name );
};
Singleton2 * Singleton2::instance( std::string const & name ) {
    Singleton_gof_registry * singleton_gof_registry { Singleton_gof_registry::instance( name ) };
    return static_cast<Singleton2 *>(singleton_gof_registry);
};
static Singleton2 singleton2;
void test_singleton_gof_registry() {
    /* Ignore this for now //Singleton_gof_registry * singleton1_p      = Singleton_gof_registry::instance( "singleton1_name") ;
    //if ( nullptr == singleton1_p ) cout << "failed." << endl;
    //bool added_one     = Singleton_gof_registry::add_singleton( "singleton1_name",  singleton1_p );
    //if ( nullptr == singleton1_p ) cout << "failed." << endl;
    //Singleton_gof_registry * singleton1_p_copy = Singleton_gof_registry::instance( "singleton1_name") ;
    //if ( nullptr == singleton1_p_copy ) cout << "failed." << endl;
    //Singleton_gof_registry * singleton2_p      = Singleton_gof_registry::instance( "singleton2_name") ;
    //if ( nullptr == singleton2_p ) cout << "failed." << endl; */
    cout << "BEGIN OF TEST CASE."<<endl;
    //Singleton_gof_registry *  my_singleton_base = Singleton_gof_registry::instance( "my_singleton1");  // TODO??: this is the wrong type! It does not have the data members I want in Singleton1.

    cout << sizeof(Singleton_gof_registry)<<endl;
    cout << sizeof(Singleton1)<<endl;

    Singleton1 const *  my_singleton1 = Singleton1::instance( "my_singleton1");  // TODO??: this is the wrong type! It does not have the data members I want in Singleton1.
    //if ( nullptr == my_singleton1 ) cout << "failed." << endl;
    cout << my_singleton1->my_int <<endl;
    cout << my_singleton1->name <<endl;
    cout << my_singleton1->name_COLLISION_with_derived <<endl;

    Singleton2 *  my_singleton2 = Singleton2::instance( "my_singleton2");  // TODO??: BAD see 4 lines up ^^^^.
    if ( nullptr == my_singleton2 )
        cout << "failed." << endl;
    cout << my_singleton2->my_int << endl;
    list_registry();

    "memory_size"_test = [] {
        0_i == 1;
        int s = sizeof(Singleton_gof_registry);
        expect( 0 == s );
        expect( 0 == sizeof(Singleton_gof_registry) );
        expect( 0 == sizeof(Singleton_gof_registry) < sizeof(Singleton1));
        //expect(sum(1, 2) > 0_i and 41_i == sum(40, 2));
    };
}
