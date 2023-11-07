#pragma once
/* Scope types:         local, class, namespace, namespace.anonymous, namespace.global
   Linkage types:
    extern              linkage required   in hpp, prohibited in cpp
    static ie. internal linkage prohibited in hpp, prohibited mention in cpp, even though it is static if so in hpp.
    internal            linkage unavailabe in hpp, but can be expressed in cpp.
    ???none???          TODO??: can't remember why I mentined this?!?:prohibited in hpp, except the CONST special linkage exception */

// Global_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
  extern            int global____________________scope_hpp_noInit_int;            // extern to expose global in cpp.
//extern            int global_static_____________scope_hpp_noInit_int;            // clashes with static in cpp
//extern static     int global_static_____________scope_hpp_noInit_int;            // an extern object is already static_storage and internal_linkage.
//                  int global_static_____________scope_hpp_noInit_int;            // not allowed in hpp
//static            int global_static_____________scope_hpp_noInit_int;            // not allowed in hpp because it will be redefined in cpp, and also fails ODR.


         const      int global________const_______scope_hpp___Init_int    {89};    // instead of old #define MYCONST 99, special linkage exception to not having extern.
         constexpr  int global________constexpr___scope_hpp___Init_int    {88};    // instead of old #define MYCONST 99, special linkage exception to not having extern.
inline   constexpr  int global________constexpri__scope_hpp___Init_int    {87};    // instead of old #define MYCONST 99, special linkage exception to not having extern.
//extern const      int global_extern_const_______scope_hpp___Init_int    {86};    // instead of old #define MYCONST 99
//extern constexpr  int global_extern_constexpr___scope_hpp___Init_int    {85};    // instead of old #define MYCONST 99

extern int global_extern_scope_fn(int i);  // extern not needed?? TODO??:
       int global________scope_fn(int i);  // extern not needed?? TODO??:

// Namespace_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
namespace Namespace_scope {                    // namespace is like a class so extern is not needed or allowed.
    extern              int     namespace_scope_int;         // forward declartion
    static              int     namespace_scope_int_static;  //
//                      int     namespace_scope_int;         // blank is stupid here, because hpp is used multiple times causing ~ODR.
//                      int     namespace_scope_int {11};    // blank is stupid here, because hpp is used multiple times causing ~ODR.
    static const        int     namespace_scope_int_const_static     {72};  // allowed because initialized const.
    static constexpr    int     namespace_scope_int_constexpr_static {73};  // allowed because initialized const.

    extern int namespace_scope_fn(int i);   // forward declartion TODO??: blank or extern same?
           int namespace_scope_fn(int i);   // forward declartion TODO??: blank or extern same?
} // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

// Namespace_anon_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
namespace { // anonymous
    extern int namespace_scope_int ;
           int namespace_scope_int;         // forward declartion
    static int namespace_scope_int_static;
    extern int namespace_scope_fn(int i);   // forward declartion
           int namespace_scope_fn(int i);   // forward declartion
} // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

// Global_class_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs

//extern class Global_extern_class_scope {};    // extern: prohibited, even though IT IS EXTERN.
//static class Global_static_class_scope {};    // static: prohibited, it is not storage but a type, except it can have static data and function members, which we consider storage!?!
class Global_class_scope {
public:
                        int     class_scope_int                  {60};  // blank: storage specifier is typical. But IT IS EXTERN.
//  extern              int     class_scope_int1                 {63};  // extern: prohibited, even though IT IS EXTERN.

    static              int     class_scope_int_static;
//  static              int     class_scope_int_static2          {61};  // init of static: prohibited in hpp, must do in cpp.

    static const        int     class_scope_int_const_static     {62};  // allowed because initialized const.
    static constexpr    int     class_scope_int_constexpr_static {63};  // allowed because initialized const.

//  extern int class_scope_fn(        int i );  // extern not allowed even though IT IS EXTERNAL linkage.
           int class_scope_fn(        int i );  //
    static int class_scope_fn_static( int i );  //

    Global_class_scope()  =default;
    ~Global_class_scope() =default;
};
// ################################################################
