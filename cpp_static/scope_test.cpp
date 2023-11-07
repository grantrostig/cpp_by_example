#include "scope.hpp"
#include "scope_test.hpp"
#include "global_entities.hpp"

void scope_test() {
// Global_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
    cout<<   global____________________scope_hpp_noInit_int << endl;
    LOGGERX("global___________________scope_hpp_noInit_int",global____________________scope_hpp_noInit_int);
    global________scope_fn(            11 );
    global_extern_scope_fn(            12 );




// Namespace_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS

    LOGGERX("",Namespace_scope::namespace_scope_int )
    LOGGERX("",Namespace_scope::namespace_scope_int_static)
    LOGGERX("",Namespace_scope::namespace_scope_int_const_static)
    LOGGERX("",Namespace_scope::namespace_scope_int_constexpr_static)
//  LOGGERX("",Namespace_scope::namespace_scope_int_extern)       // error due to: internal linkage.

    Namespace_scope::namespace_scope_fn(  13 );
//  LOGGERX("",Namespace_scope::namespace_scope_fn(  14 ) )
//  LOGGERX("",Namespace_scope::namespace_scope_fn::local_scope_int  )  // error due to: function is not addressable like this, class/struct would. TODO??:
//  LOGGERX("",Namespace_scope::namespace_scope_fn::namespace_scope_int_static )       // error due to: internal linkage in hpp.












    // Namespace_anonymous_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// Global_class_scope SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
    Global_class_scope global_class_scope {};
    LOGGERX("",        global_class_scope.class_scope_int           )

    LOGGERX("",Global_class_scope::class_scope_int_static           )
    LOGGERX("",Global_class_scope::class_scope_int_const_static     )
    LOGGERX("",Global_class_scope::class_scope_int_constexpr_static )

    global_class_scope.class_scope_fn( 16 );
    global_class_scope.class_scope_fn_static( 17 );
}
