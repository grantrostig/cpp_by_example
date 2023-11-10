#include "global_entities.hpp"
#include "scope.hpp"
/* extern stupid     in cpp
   static solely     in cpp
   none   solely     in cpp */

// Global_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
                    int global____________________scope_cpp_noInit_int {97};  // not internal because have extern in hpp.
                    int global__________const_____scope_cpp_noInit_int {95};
  static            int global___static___________scope_cpp_noInit_int {96};  // TODO??: so what does static do here if anything?

  static            int internal_static___________scope_hpp_noInit_int {98};
//extern            int global_static_____________scope_hpp_noInit_int {99};  // extern: can't init in cpp
  extern            int global_static_____________scope_hpp_noInit_int;       // extern: here does nothing, TODO??: except maybe forward declare object?
  extern            int global_static_____________scope_hpp_noInit_int {99};  // extern: here does nothing, except maybe forward declare object? TODO??: init generates a warning, why? why not illegal?
//static            int global_static_____________scope_hpp_noInit_int {99};
int global_extern_scope_fn(int i) {  // extern not needed
    LOGGERX("",i)
    int local_scope_int {};
    return i;
}
int global________scope_fn(int i) {  // extern not needed
    LOGGERX("",i)
    int local_scope_int {};
    return i;
}

// Namespace_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
namespace Namespace_scope { // NamespaceNNNNNNNNNNNNNNNNNNNNNN
            int namespace_scope_int             {21};   // global linkage, with extern in hpp.  TODO??: is this on stack or bss?
    static  int namespace_scope_int_static2;            // static is internal linkage, so not visible outside this cpp.
    extern  int namespace_scope_int_extern;             // extern: here does nothing, TODO??: except maybe forward declare object?
int namespace_scope_fn(int i) {
        LOGGERX("",22)
                int local_scope_int {23};
        static  int local_scope_int_static {24};          // interal only.
    return i;
}
} // End NampespaceNNNNNNNNNNNNNNNNNNNNNN


// Namespace_unnamed_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
namespace { // unnamed NamespaceNNNNNNNNNNNNNNNNNNNNNN
        int namespace_unnamed_scope_int_cblanks             {25};   // global linkage, with extern in hpp.  TODO??: is this on stack or bss?
static  int namespace_unnamed_scope_int_cstatic;             // static is internal linkage, so not visible outside this cpp.
extern  int namespace_unnamed_scope_int_extern;             // extern: here does nothing, TODO??: except maybe forward declare object?
int namespace_unnamed_scope_fn(int i) {                 // has extern in hpp
    LOGGERX("",26)
    int local_scope_int {27};
    static  int local_scope_int_static {28};          // interal only.
    return i;
}
int namespace_unnamed_scope_fn2(int i) {                // blank storage_duration, but seems to be static anyway?  TODO??:
    LOGGERX("",29)
    int local_scope_int {30};
    static  int local_scope_int_static {31};          // interal only.
    return i;
}
} // End NampespaceNNNNNNNNNNNNNNNNNNNNNN

// Global_class_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs
         int        Global_class_scope::class_scope_int_static         {32};    // static is internal linkage, so not visible outside this cpp.
//extern int        Global_class_scope:;class_scope_int_extern;                 // extern: here not allowed.
//       int        Global_class_scope::class_scope_int                {31};    // init is done in class hpp for non-static.

int Global_class_scope::class_scope_fn(int i) {
    LOGGERX("",37)
    int         local_scope_int {33};
    static  int local_scope_int_static {34};    // interal only.
    return i;
}
int Global_class_scope::class_scope_fn_static(int i) {
    LOGGERX("",38)
    int         local_scope_int {35};
    static  int local_scope_int_static {36};            // ??
    return i;
}
