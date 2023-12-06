//module;                     // Optional keyword used to put old headers on subsequent lines, ONLY if necessary.
//#include "my_module.hpp"
//#include <iostream>

export module   My_module;  // No headers below (unless wanting only copy paste text inclusion.

//import <iostream>;        // No yet.
//import std;               // No yet.
//import std.compat;        // No yet.

export int f( int );

//module : private;  // This starts a private module fragment
export int f( int i ) {
    return 3*i;
}
// *** other stuff
//export module My_module:My_partition_XXX;

///file:        My_module-My_partition_b.cpp
//export module My_module:My_partion_b;
//...

///file:        My_module-My_partion_c.cpp
//module        My_module:My_partion_c;
//...

///file:        My_module.cpp
//export module My_module;

//import        :My_partion_c;
//export import :My_partion_b;
//...

