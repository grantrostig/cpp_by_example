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
class Singleton {           // NOTE: In fact since I have more than one singletons in here it is more of a registry as mentioned in GOF.
private:
    // why this bool?  well I could use std::expected, or optional, or nullptr as a flag.
    static bool                             is_initialized;     // cannot init here.
    // TODO??: Enhancement request:make this into a registry of singletons.
    static Only_one_of_UDT1                 only_one_of_udt1_instance;   // cannot init here.
    static Only_one_of_UDT2 const * const   only_one_of_udt2_instance;   // cannot init here.
    // TODO??: in addition let's add a shared or unique pointer to also?
protected:
    Singleton();
public:
    static Only_one_of_UDT1 & instance() {        // TODO??: Could this be by value instead?  I guess not since then there would be copies??  But still access() would get the right thing, but the user might not use access and get to the values some other way??
        if ( not is_initialized ) {
            Row row                         {51,"Fifty one."};
            Only_one_of_UDT1 only_one_udt1_instance  {41,"Fourty one.",row};
            is_initialized = true;
        }
        return only_one_of_udt1_instance;
}};
bool                            Singleton::is_initialized            {false};
Only_one_of_UDT1                Singleton::only_one_of_udt1_instance;                // TODO??: Why exactly will it not take this:{31,"Thirty one.", {32,"Thirty two."}};
Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2_instance {nullptr};      // TODO??: clang told me to put nullptr here.
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2 {77};                 // TODO??: rvalue not allowed.
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2 = nullptr;            // TODO??: is using = same as {}

class Singleton_subclassed : Singleton {};  // TODO??: How and why would one do this?  GOF suggests it, but for what situation, give example.
// TODO??: how would all above examples be used within multiple compilation units with regard to access and order of initializaion.

// MySingleton::MySingleton() { // TODO??: make sense of this code block below from GOF
    //...
    //Singleton::Register("MySingleton", this);
//}

int main() {
    Only_one_of_UDT1    my_singleton_udt1       = Singleton::instance();
    int                 my_singleton_udt_int    = my_singleton_udt1.i;
    Row                 my_singleton_udt_row    = my_singleton_udt1.row;
    cout << "Have only one of this:" << my_singleton_udt1.i <<", " << my_singleton_udt1.s <<", " << my_singleton_udt1.row.ri << endl ;

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
