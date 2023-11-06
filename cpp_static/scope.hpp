#pragma once
/* extern              linkage required   in hpp
   static ie. internal linkage prohibited in hpp
   internal            linkage prohibited in hpp
   none                        prohibited in hpp, except the CONST special linkage exception */

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

namespace Namespace_sc {                    // namespace is like a class so extern is not needed or allowed.
    extern int namespace_scope_int;         // forward declartion
//  static int namespace_scope_int_static;  // static internal linkage not allowed in hpp.
//         int namespace_scope_int;         // blank is stupid here.
//         int namespace_scope_int {11};    // blank is stupid here.

    extern int namespace_scope_fn(int i);   // forward declartion TODO??: blank or extern same?
           int namespace_scope_fn(int i);   // forward declartion TODO??: blank or extern same?
} // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

//namespace { // anonymous
//    extern int namespace_scope_int ;
//           int namespace_scope_int;         // forward declartion
//    extern int namespace_scope_fn(int i);   // forward declartion
//           int namespace_scope_fn(int i);   // forward declartion
//} // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

//extern class scope {  // not allowed event though IT IS EXTERN
class Global_class_scope {
public:
           int        class_scope_int         {60};       // typical storage specifier. IT IS EXTERN
//  extern int        class_scope_int1        {63};      // extern: not allowed. IT IS EXTERN
    static int        class_scope_int_static;
//  static int        class_scope_int_static2 {61};  // init not allowed in hpp
    static const int  class_scope_int_static3 {62};  // allowed because const, but why allow static in hpp also

           int class_scope_fn( int i ); // comment in which line?? extern not allowed even though IT IS EXTERNAL linkage.
//  extern int class_scope_fn( int i ); // comment in which line?? extern not allowed even though IT IS EXTERNAL linkage.
    Global_class_scope()  =default;
    ~Global_class_scope() =default;
};
