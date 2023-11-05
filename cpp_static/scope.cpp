#include "global_entities.hpp""
#include "scope.hpp"
/* extern stupid     in cpp
   static solely     in cpp
   none   solely     in cpp */

                    int global____________________scope_hpp_noInit_int {99};  // not internal because have extern in hpp.
  static            int internal_static___________scope_hpp_noInit_int {99};

//extern            int global_static_____________scope_hpp_noInit_int {99};  // extern: can't init in cpp
  extern            int global_static_____________scope_hpp_noInit_int;       // extern: here does nothing, TODO??: except maybe forward declare object?
  extern            int global_static_____________scope_hpp_noInit_int {99};  // extern here does nothing, except maybe forward declare object? TODO??: init generates a warning, why? why not illegal?
//static            int global_static_____________scope_hpp_noInit_int {99};

int global_extern_scope_fn(int i) {  // extern not needed
    LOGGERX("",i)
    int local_scope_int {};
    return 0;
}

int global________scope_fn(int i) {  // extern not needed
    LOGGERX("",i)
    int local_scope_int {};
    return 0;
}
namespace Namespace_sc {
       int namespace_scope_int {11};  // global linkage,  TODO??: is this on stack or bss?
static int namespace_scope_int1;  // static is internal linkage, so not visible outside this cpp.
int namespace_scope_fn(int i) {
    LOGGERX("",i)
    int local_scope_int {};
    return 0;
}}

