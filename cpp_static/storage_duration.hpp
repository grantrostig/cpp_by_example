#pragma once

extern int extern_storage_duration_hpp_noInit_int   ;
extern int extern_storage_duration_hpp___Init_int {};

static int static_storage_duration_hpp_noInit_int   ;
static int static_storage_duration_hpp___Init_int {};

extern int global_storage_duration_fn(int i) {  // extern not needed
    int local_storage_duration_int {};
}

namespace Namespace_sc {
int namespace_storage_duration_int {};
int namespace_storage_duration_fn(int i) {
    int block_storage_duration_int {};
} } // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

//extern class storage_duration {  // not allowed event though IT IS EXTERN
class Class_storage_duration {
public:
    int        class_storage_duration_int        {};
    static int class_storage_duration_static_int   ;
    int        class_storage_duration_fn();
    static int class_storage_duration_static_fn();
    //extern not allowed even though it is external linkage.
    Class_storage_duration();
    ~Class_storage_duration();
};

