// copyright (c) Grant Rostig, grantrostig.com, Boost 1.0 license
#include "global_entities.hpp"
//#include <bits/stdc++.h>
#include <iostream>
#include <csignal>
#include <stacktrace>
#include <source_location>

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;

/* few items for debugging purposes */
/// define if asserts are NOT to be checked.  Put in *.h file not *.CPP
//#define 	NDEBUG
/// define GR is Debugging.  Put in *.h file not *.CPP
//#define  	GR_DEBUG
//#ifdef   	GR_DEBUG
//#endif  # GR_DEBUG

/// gives a source location for printing.  Used for debugging.
std::string
source_loc() {
    using loc = std::source_location;
    //using ts = std::to_string;  // todo??: why not?  alternative approach?
    std::string result {"\n"s + loc::current().file_name() + ":"s + std::to_string(loc::current().line()) + std::to_string(loc::current().column())+"]`"s + loc::current().function_name() + "`."s};
    return result;
}
