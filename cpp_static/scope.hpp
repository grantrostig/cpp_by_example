#pragma once
extern           int global_______scope_hpp_noInit_int;            // Dec DEF
// in cpp                 int global_______scope_hpp_noInit_int;            // Dec DEF

                 //int global_______scope_hpp_noInit_int2;            // Dec REF



                 //extern           int global_______scope_hpp___Init_int      {0};    //
                 //                 int global_______scope_hpp___Init_int2     {0};    //



//extern const     int global_const_scope_hpp___Init_int      {99};   // instead of old #define MYCONST 999
//extern constexpr int global_constexpr_scope_hpp___Init_int  {99};   // instead of old #define MYCONST 999

extern int global_scope_fn(int i);  // extern not needed
     int global_scope_fn1(int i);  // extern not needed

namespace Namespace_sc {
    extern int namespace_scope_int;
           //int namespace_scope_int2;
    int namespace_scope_fn(int i);
} // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

namespace {             // anonymous
    extern int namespace_scope_int ;
           //int namespace_scope_int2 ;
}

//extern class scope {  // not allowed event though IT IS EXTERN
class Class_scope {
public:
    int        class_scope_int {};
    int        class_scope_fn( int i );
    //extern not allowed even though it is external linkage.
    Class_scope();
    ~Class_scope();
};

void test_scope();
