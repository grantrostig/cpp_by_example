// cppmsg.com Boost 1.0 license.
// see: GOF 1995-SS 1.Singleton; Vlissides 1998-ch2,ch3; Larman 2005-SS 26.5; Robert Martin 2002-Singleton and Monstate; Headington 1996-SS2.7 p79; Cline 1999-ch16-?;
#include <bits/stdc++.h>
using namespace std;
struct Row {
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

//    /* static Singleton *    _instance;   // cannot init here. */

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

//    /* static Singleton * instance() {        // TODO??: Could this be by value instead?  I guess not since then there would be copies??  But still access() would get the right thing, but the user might not use access and get to the values some other way??
//        if ( not is_initialized ) {
//            //Row row                                     {51,"Fifty one."};
//            //Only_one_of_UDT1 only_one_udt1_instance     {41,"Fourty one.",row};
//            _instance = new Singleton;
//            _instance->my_int = 67;
//            is_initialized = true; }
//        return _instance;
//    }*/
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

template <typename T>
class SingletonBaseTref {           // NOTE: In fact since I have more than one singletons in here it is more of a registry as mentioned in GOF.
protected:
    SingletonBaseTref() noexcept = default;
public:
    SingletonBaseTref(SingletonBaseTref const &   )                         = delete;
    SingletonBaseTref(SingletonBaseTref       &&  )                         = delete;
    virtual ~SingletonBaseTref()                                        = default;
    SingletonBaseTref & operator=( SingletonBaseTref const &  ) noexcept    = delete;
    SingletonBaseTref & operator=( SingletonBaseTref       && ) noexcept    = delete;
    SingletonBaseTref & operator()()                                    = delete;     // Redundant since it isn't rule of 5/6.
    static T & instance() {        // TODO??: Could this be by value instead?  I guess not since then there would be copies??  But still access() would get the right thing, but the user might not use access and get to the values some other way??
        static T _instance;
        return   _instance;
    };
};

class STr_derived final : public SingletonBaseTref< STr_derived > {  // CRTP TODO??: how does modern c++ obviate this approach?
    //friend SingletonBase SingletonBase<Singleton_subclassed>::instance();
public:
    int my_int {69};
};

//Only_one_of_UDT1                Singleton::only_one_of_udt1_instance;                // TODO??: Why exactly will it not take this:{31,"Thirty one.", {32,"Thirty two."}};
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2_instance {nullptr};      // TODO??: clang told me to put nullptr here.
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2 {77};                 // TODO??: rvalue not allowed.
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2 = nullptr;            // TODO??: is using = same as {}


// TODO??: how would all above examples be used within multiple compilation units with regard to access and order of initializaion.

// MySingleton::MySingleton() { // TODO??: make sense of this code block below from GOF
    //...
    //Singleton::Register("MySingleton", this);
//}
int main() {
    //Singleton    *       my_singleton       = Singleton::instance();
    //Singleton            & my_singleton                 = Singleton::instance();
    STr_derived & str_derived   = STr_derived::instance();
    STr_derived & str_derived2  = STr_derived::instance();

    //int                 my_singleton_udt_int    = my_singleton_udt1.i;
    //Row                 my_singleton_udt_row    = my_singleton_udt1.row;
    //cout << "Have only one of this:" << my_singleton_udt1.i <<", " << my_singleton_udt1.s <<", " << my_singleton_udt1.row.ri << endl ;
    cout << "Have only one of this:" << str_derived.my_int << endl ;
    cout << "###" << endl;
    return EXIT_SUCCESS;
}
