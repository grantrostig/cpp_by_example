/* Generated as part of Grant's password manager effort to show
 * how to load a data record, or struct or data row
 */
#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <memory>
#include <optional>
using namespace std;

struct Data_struct {
    int		a 	{-99};
    string 	b 	{"uninitialized."}; };

struct Data_location_ptr {
    int 	* a {};
    string 	* b {}; };

struct Data_location_ref_base {
    int	     base_1{-1};
             Data_location_ref_base() =default;
    explicit Data_location_ref_base( int & base_1_, string & b_ ) : base_1(base_1_) {} };

struct Data_location_ref : public Data_location_ref_base {
    int &       a;
    string &    b;
    explicit    Data_location_ref( int & a_, string & b_ ) : a(a_), b(b_) {
       base_1 = 22;
       cout << "Data_location_ref() &a: "<< &a <<endl;
       cout << "Data_location_ref()  a: "<<  a <<endl; }
};
//struct Data_struct_optional {
//    optional<int>		a 	{-98};
//    optional<string> 	b 	{"uninitialized optional."};};

//struct Data_location_optional_raw_ptr {
//    optional<int> 	 	* a {};
//    optional<string>  	* b {};};

//struct Data_location_optional_ref{
//    optional<int>		& a;
//    optional<string >	& b;};

int main()  {	// *** Conventional/Direct Data ***

    // raw pointer to conventional data
    Data_struct 		    direct_struct_raw_ptr       {1,"raw_ptr"};
    cout << "&a     : "<<  &direct_struct_raw_ptr.a	<<endl;
    cout << "a      : "<<   direct_struct_raw_ptr.a	<<endl;
    Data_location_ptr       direct_location_raw_ptr     { &direct_struct_raw_ptr.a, &direct_struct_raw_ptr.b };
    cout << "&direct_location_raw_ptr.a ptr : "<< &direct_location_raw_ptr.a <<endl;
    cout << " direct_location_raw_ptr.a ptr : "<<  direct_location_raw_ptr.a <<endl;
    cout << "*direct_location_raw_ptr.a ptr : "<< *direct_location_raw_ptr.a <<endl;

    // ref to conventional data
    Data_struct 		    ref____struct_raw_ptr       {1,"raw_ptr"};
    cout << "&a     : "<<  &ref____struct_raw_ptr.a	<<endl;
    cout << "a      : "<<   ref____struct_raw_ptr.a	<<endl;
    // Data_location_ptr	ref____location_raw_ptr	    { &ref____struct_raw_ptr.a, &ref____struct_raw_ptr.b };
    Data_location_ref	    ref____location_raw_ptr		{  ref____struct_raw_ptr.a,  ref____struct_raw_ptr.b };
    Data_location_ref	    ref____location_raw_ptr2	{  ref____struct_raw_ptr.a,  ref____struct_raw_ptr.b };
    cout << "&ref____location_raw_ptr.a ptr : "<<
                           &ref____location_raw_ptr.a <<endl;
    cout << " ref____location_raw_ptr.a ptr : "<<
                            ref____location_raw_ptr.a <<endl;
    // no indirection allowed: cout << "*ref____location_raw_ptr.a ptr : "<< *ref____location_raw_ptr.a 	<<endl;

    ref____struct_raw_ptr.a =                           10;
    cout << "&a     : "<<  &ref____struct_raw_ptr.a		<<endl;
    cout << "a      : "<<   ref____struct_raw_ptr.a		<<endl;
    cout << "&ref____location_raw_ptr.a ptr : "<<
                           &ref____location_raw_ptr.a		<<endl;
    cout << " ref____location_raw_ptr.a ptr : "<<
                            ref____location_raw_ptr.a 	<<endl;

    // no indirection allowed: cout << "*ref____location_raw_ptr.a ptr : "<< *ref____location_raw_ptr.a 	<<endl;

    /* *** NOTE: BELOW NEEDS RE_WORK *** Optional Data ***
    // raw pointer to optional data
    Data_struct_optional 				ds_optional_raw_ptr 	{2,"raw_ptr_optional"};
    Data_location_optional_raw_ptr	    dl_optional_raw_ptr		{ &ds_optional_raw_ptr.a, &ds_optional_raw_ptr.b };
    cout << "ptr    : "<<  dl_optional_raw_ptr.a          	<< ", "<<  dl_optional_raw_ptr.b         <<endl;
    cout << "ptr    : "<<  dl_optional_raw_ptr.a->value() 	<< ", "<<  dl_optional_raw_ptr.b->value()<<endl;

    // ref to optional data
    Data_struct_optional 				ds_optional_ref 	    {4,"ref_optional"};
    Data_location_optional_ref	        dl_optional_ref		    { ds_optional_ref.a, ds_optional_ref.b };
    cout << "can't get address of these ones.\n";
    cout << "opt_ref: "<<  dl_optional_ref.a.value_or(-9999)<< ", "<<  dl_optional_ref.b.value_or("NULL") <<endl;
    dl_optional_ref.a = 44;
    dl_optional_ref.b = "44.more"; 						           // todo: TODO why can't I use +=?
    cout << "opt_ref: "<<  dl_optional_ref.a.value_or(-9999)<< ", "<<  dl_optional_ref.b.value_or("NULL") <<endl;
    dl_optional_ref.a = {};
    dl_optional_ref.b = {};
    cout << "opt_ref: "<<  dl_optional_ref.a.value_or(-9999)<< ", "<<  dl_optional_ref.b.value_or("NULL") <<endl;
    */
    cout << "###" << endl;
    return 0;
}
