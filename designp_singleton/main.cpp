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
    static bool                             is_constructed;     // cannot init here.
    // TODO??: Enhancement request:make this into a registry of singletons.
    static Only_one_of_UDT1                 only_one_of_udt1;   // cannot init here.
    static Only_one_of_UDT2 const * const   only_one_of_udt2;   // cannot init here.
    // TODO??: in addition let's add a shared or unique pointer to also?
protected:
    Singleton();
public:
    static Only_one_of_UDT1 & access() {        // TODO??: Could this be by value instead?  I guess not since then there would be copies??  But still access() would get the right thing, but the user might not use access and get to the values some other way??
        if ( not is_constructed ) {
            Row row                         {51,"Fifty one."};
            Only_one_of_UDT1 only_one_udt1  {41,"Fourty one.",row};
            Only_one_of_UDT2 only_one_udt2  {42,"Fourty two.",row};
            is_constructed = true;
        }
        return only_one_of_udt1;
}};
bool                            Singleton::is_constructed   {false};
Only_one_of_UDT1                Singleton::only_one_of_udt1;                // TODO??: Why exactly will it not take this:{31,"Thirty one.", {32,"Thirty two."}};
Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2 {nullptr};      // TODO??: clang told me to put nullptr here.
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2 {77};         // TODO??: rvalue not allowed.
//Only_one_of_UDT2 const * const  Singleton::only_one_of_udt2 = nullptr;    // TODO??: is using = same as {}
int main() {
    Only_one_of_UDT1    my_singleton_udt1       = Singleton::access();
    int                 my_singleton_udt_int    = my_singleton_udt1.i;
    Row                 my_singleton_udt_row    = my_singleton_udt1.row;
    cout << "Have only one of this:" << my_singleton_udt1.i <<", " << my_singleton_udt1.s <<", " << my_singleton_udt1.row.ri << endl ;

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
