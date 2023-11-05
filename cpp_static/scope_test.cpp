#include "scope.hpp"
#include "scope_test.hpp"
#include "global_entities.hpp"

void scope_test() {
    cout<<   global____________________scope_hpp_noInit_int << endl;
    LOGGERX("global___________________scope_hpp_noInit_int",global____________________scope_hpp_noInit_int);

    global________scope_fn(            11 );
    global_extern_scope_fn(            11 );

    LOGGERX("",Namespace_sc::namespace_scope_int)
//  LOGGERX("",Namespace_sc::namespace_scope_int_static)       // internal linkage.
    LOGGERX("",Namespace_sc::namespace_scope_fn(  11 ))

}
