#pragma once
// Storage Duration of: ******* Objects only *******  TODO??: where a function is not an object?
// using keywords: extern & static & thread_local & automatic & dynamic
// Below are in contect of Storage_Duration ONLY!! not linkage context!!
// extern          === object is REF only
// static          === object is DEF and in TU instanciated
// thread_local    === object is DEF and TU instanciated TODO??
// automatic & dynamic

                        // NAMESPACE-GLOBAL
static          int     static_storage_duration_hpp_noInit_int         ;
static          int     static_storage_duration_hpp___Init_int       {}; // in cpp TODO??:
       const    int     static_const_storage_duration_hpp_noInit_int {}; // is STATIC because CONST !!!

                        // not-static is "extern" with keyword optional
extern          int     extern_storage_duration_hpp_noInit_int         ;
extern          int     extern_storage_duration_hpp___Init_int       {};             // in cpp??

extern const    int     extern_const_storage_duration_hpp___Init_int   ; // in cpp TODO??: does this even exist due to the "const"?
extern const    int     extern_const_storage_duration_hpp___Init_int {}; // in cpp TODO??: does this even exist due to the "const"?

static int sf(int i) {  //
                        // LOCAL
    static      int     static_local_storage_duration_int {};   // Only one copy in data area.
    extern      int     extern_local_storage_duration_int   ;
                int     local_storage_duration_int {};
    return 0;
}

extern int ef(int i) {  // extern not needed
                        // LOCAL
    static      int     static_local_storage_duration_int {};
    extern      int     extern_local_storage_duration_int   ;
                int     local_storage_duration_int {};
    return 0;
}

namespace Namespace_sc {
                        // NAMESPACE
int namespace_storage_duration_int {};
int nf(int i) {
    static      int     static_local_storage_duration_int {};
    extern      int     extern_local_storage_duration_int   ;
    int                 block_storage_duration_int {};
    return 0;
} } // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

//extern class storage_duration {  // not allowed event though IT IS EXTERN
class Class_storage_duration {
public:
                    // CLASS
    int        class_storage_duration_int        {};
    static int class_storage_duration_static_int   ;

                    // DYNAMIC
           int *    dynamic_storage_duration________int { new int };
    static int *    dynamic_storage_duration_static_int;  // apparently no init needed?  because it's a poiner?

    int        class_storage_duration_fn();
    static int class_storage_duration_static_fn();
    //extern not allowed even though it is external linkage.
    Class_storage_duration();
    ~Class_storage_duration();
};
// in cpp because static: int * Class_storage_duration::dynamic_storage_duration_static_int {new int};
