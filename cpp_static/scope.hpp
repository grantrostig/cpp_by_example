#pragma once

// Namespace_Global_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
  extern            int global____________________scope_cpp_noInit_int;            // extern to expose a global in a cpp.
  extern const      int global________const_______scope_cpp_noInit_int;            //
  extern            int global_static_____________scope_cpp_noInit_int;            //
// what about inline in an extern reference?
//extern static     int global_static_____________scope_cpp_noInit_int;            // clashes with cpp, an extern object is already static_storage in another file and has internal_linkage.

         const      int global________const_______scope_hpp___Init_int    {89};    // instead of old #define MYCONST 99, special linkage exception to not having extern.
  static const      int global_static_const_______scope_hpp___Init_int    {84};    // instead of old #define MYCONST 99, special linkage exception to not having extern. TODO??: does static do anything here at all? NO?
         constexpr  int global________constexpr___scope_hpp___Init_int    {88};    // instead of old #define MYCONST 99, special linkage exception to not having extern.
  inline constexpr  int global________constexpri__scope_hpp___Init_int    {87};    // instead of old #define MYCONST 99, special linkage exception to not having extern.
//extern const      int global_extern_const_______scope_hpp___Init_int    {8 };    // instead of old #define MYCONST 99, but doesn't make sense since it doesn't refer to an external to this file object.
//extern constexpr  int global_extern_constexpr___scope_hpp___Init_int    {8 };    // instead of old #define MYCONST 99, but doesn't make sense since it doesn't refer to an external to this file object.
//                  int global_static_____________scope_hpp_noInit_int;            // not allowed in hpp because it will be redefined in cpp, and also fails ODR.
//static            int global_static_____________scope_hpp_noInit_int;            // not allowed in hpp because it will be redefined in cpp, and also fails ODR.
  extern int global_extern_scope_fn(int i);  // extern not needed?? TODO??:
         int global________scope_fn(int i);  // extern not needed?? TODO??:

// Namespace_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
namespace Namespace_scope {                    // namespace is like a class so extern is not needed or allowed.
  extern            int namespace_scope_int;         // forward declartion
  static            int namespace_scope_int_static;  //
//                  int namespace_scope_int;         // blank is stupid here, because hpp is used multiple times causing ~ODR.
//                  int namespace_scope_int {11};    // blank is stupid here, because hpp is used multiple times causing ~ODR.
  static const      int namespace_scope_int_const_static     {72};  // allowed because initialized const.
  static constexpr  int namespace_scope_int_constexpr_static {73};  // allowed because initialized const.
  extern int namespace_scope_fn(int i);   // forward declartion TODO??: blank or extern same?
         int namespace_scope_fn(int i);   // forward declartion TODO??: blank or extern same?
} // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

// Namespace_Unnamed_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
namespace { // unnamed
  extern            int namespace_unnamed_scope_int_hblanks;
  extern            int namespace_unnamed_scope_int_cblanks;
                    int namespace_unnamed_scope_int;         // forward declartion
  static            int namespace_unnamed_scope_int_hstatic;
  extern int namespace_unnamed_scope_fn(int i);     // forward declartion?? TODO??:
//       int namespace_unnamed_scope_fn(int i);     // has impl             TODO??: strange warning about being static when I don't specify static!!?!
         int namespace_unnamed_scope_fn2(int i);    // has impl             TODO??: strange warning about being static when I don't specify static!!?!
} // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

// Global_class_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs

//extern class Global_extern_class_scope {};    // extern: prohibited, even though IT IS EXTERN.
//static class Global_static_class_scope {};    // static: prohibited, it is not storage but a type, except it can have static data and function members, which we consider storage!?!
class Global_class_scope {
public:
                    int class_scope_int                  {60};  // blank: storage specifier is typical. But IT IS EXTERN.
//extern            int class_scope_int1                 {63};  // extern: prohibited, even though IT IS EXTERN.

  static            int class_scope_int_static;
//static            int class_scope_int_static2          {61};  // init of static: prohibited in hpp, must do in cpp.

  static const      int class_scope_int_const_static     {62};  // allowed because initialized const.
  static constexpr  int class_scope_int_constexpr_static {63};  // allowed because initialized const.

//extern int class_scope_fn(        int i );  // extern not allowed even though IT IS EXTERNAL linkage.
         int class_scope_fn(        int i );  //
  static int class_scope_fn_static( int i );  //

  Global_class_scope()  =default;
  ~Global_class_scope() =default;
};
// ################################################################
