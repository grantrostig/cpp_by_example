// cppmsg.com Boost 1.0 license.
// see: GOF 1995-SS 1.Singleton; Vlissides 1998-ch2,ch3; Larman 2005-SS 26.5; Robert Martin 2002-Singleton and Monstate; Headington 1996-SS2.7 p79; Cline 1999-ch16-?;https://vladris.com/blog/2017/07/10/singletons.html 
#include "singleton_gof_with_ptr.hpp"
#include "singleton_gof_t_decided_in_base_constr.hpp"

#include "singleton_derived_t_ref.hpp"
//#include "singleton_gof_t_derived_link_time.hpp"
#include "singleton_gof_registry.hpp"

#include <bits/stdc++.h>
using namespace std;

/*  struct Row {  //ignore these ravings for now
    int     ri       {99};
    string  rs       {"NULL"}; };
struct Only_one_of_UDT1 {
    int     i       {98};
    string  s       {"NULL"};
    Row     row     {};};  // should get inited values from type
struct Only_one_of_UDT2 {
    int     i       {98};
    string  s       {"NULL"};
    Row     row     {};};  // should get inited values from type

//class Singleton {           // NOTE: In fact since I have more than one singletons in here it is more of a registry as mentioned in GOF.
//private:
//    // why this bool?  well I could use std::expected, or optional, or nullptr as a flag.
//    static bool                             is_initialized;     // cannot init here.
//    // TODO??: Enhancement request:make this into a registry of singletons.
//    //Only_one_of_UDT1 const *                only_one_of_udt1_instance;   // cannot init here.
//    //Only_one_of_UDT2 const * const   only_one_of_udt2_instance;   // cannot init here.
//    // TODO??: in addition let's add a shared or unique pointer to also?

//     static Singleton *    _instance;   // cannot init here.

//protected:
//    Singleton() = default;
//    //Singleton const & singleton( Singleton s ) {
//    //Singleton singleton( Singleton s ) {
//public:
//    int my_int {66};
//    Singleton (Singleton const & s ) = delete;
//    virtual ~Singleton() = default;
//    Singleton & operator=( Singleton const & s ) =delete;

//    static Singleton & instance() {
//        static Singleton _instance;
//        return _instance;
//    }

//    ** static Singleton * instance() {        // TODO??: Could this be by value instead?  I guess not since then there would be copies??  But still access() would get the right thing, but the user might not use access and get to the values some other way??
//        if ( not is_initialized ) {
//            //Row row                                     {51,"Fifty one."};
//            //Only_one_of_UDT1 only_one_udt1_instance     {41,"Fourty one.",row};
//            _instance = new Singleton;
//            _instance->my_int = 67;
//            is_initialized = true; }
//        return _instance;
//    }*****
//};
//bool                            Singleton::is_initialized            {false};

//class Singleton {           // NOTE: In fact since I have more than one singletons in here it is more of a registry as mentioned in GOF.
//private:
//    Singleton() = default;
//protected:
//public:
//    int        my_int {66};
//    Singleton (Singleton const & s ) = delete;
//    virtual ~Singleton() = default;
//    Singleton & operator=( Singleton const & s ) =delete;
//    static Singleton & instance() {
//        static Singleton _instance;
//        return _instance;
//    }
//};

//Only_one_of_UDT1                Singleton::only_one_of_udt1_instance;                // TODO??: Why exactly will it not take this:{31,"Thirty one.", {32,"Thirty two."}};
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2_instance {nullptr};      // TODO??: clang told me to put nullptr here.
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2 {77};                 // TODO??: rvalue not allowed.
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2 = nullptr;            // TODO??: is using = same as {}


// TODO??: how would all above examples be used within multiple compilation units with regard to access and order of initializaion.

// MySingleton::MySingleton() { // TODO??: make sense of this code block below from GOF
    //...
    //Singleton::Register("MySingleton", this);
//} */

int main() {
    test_Singleton_gof_with_ptr();
    test_Singleton_gof_with_ref();
    test_singleton_gof_t_decided_in_base_constr();

    //test_singleton_gof_t_derived_link_time();  // not finished, don't undserstand
    test_singleton_gof_registry();

    test_singleton_derived_t_ref();

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
