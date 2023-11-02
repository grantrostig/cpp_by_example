#pragma once

extern int global_scope_hpp_noInit_int   ;
extern int global_scope_hpp___Init_int {};

extern int global_scope_fn(int i) {  // extern not needed
    int local_scope_int {};
}

namespace Namespace_sc {
int namespace_scope_int {};
int namespace_scope_fn(int i) {
    int block_scope_int {};
} } // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

//extern class scope {  // not allowed event though IT IS EXTERN
class Class_scope {
public:
    int        class_scope_int {};
    int        class_scope_fn();
    static int class_scope_static_fn();
    Class_scope();
    ~Class_scope();
};

