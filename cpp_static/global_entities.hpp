// Copyright (c) Grant Rostig, grantrostig.com, Boost 1.0 license
#pragma once
//#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <stacktrace>
#include <source_location>
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;
/* few items for debugging purposes */
// SYMBOL    MEANING
// TODO:     the principal programmer needs todo.
// TODO?:	 the principal programmer is not sure about something, that should be addressed.
// TODO?:X   the X programmer is not sure about something, that should be addressed.
// TODO??:   is a question for verbal discussion at CppMSG.com meetup meetings.
// define   NDEBUG if asserts are NOT to be checked.  Put in *.h file not *.CPP
//#define 	NDEBUG
// define   GR_DEBUG if we/programmer is Debugging.  Put in *.h file not *.CPP
//#define  	GR_DEBUG
//#ifdef   	GR_DEBUG
//#endif    GR_DEBUG
// Some crude logging that provides source location.
#define   LOGGER_( msg )   using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:{" <<#msg<<          "}."    <<endl;cout.flush();cerr.flush();
//#define LOGGER_( msg )   using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:{" <<#msg<<          "}.\r\n"<<endl;cout.flush();cerr.flush();
#define   LOGGERX( msg, x )using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:{" <<#msg<<"},{"<<x<<"}."    <<endl;cout.flush();cerr.flush();
//#define LOGGERX( msg, x )using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:{" <<#msg<<"},{"<<x<<"}.\r\n"<<endl;cout.flush();cerr.flush();

// Storage_Duration  Dynamic OR Data_Segment_LDF (true "static")
// not Scope?

// Linkage based on scope as expected BUT ALSO requires "extern" to allow external linkage, but often defaulted.
// *** Definition *** not Declaration yet....
#define EXTERN_OBJ       ?? // "extern" defaulted at namespace scope (incl.global), not permitted to specify it!?!?
#define EXTERN_FREE_FN      // "extern" defaulted at namespace scope (incl.global), not permitted to specify it!?!?
#define EXTERN_CLASS        // "extern" defaulted at namespace scope (incl.global), not permitted to specify it!?!? ALSO "struct", "enum"?, "enum class"?

#define STATIC_CLASS        // Not allowed, but members can be. (incl. FN and OBJ)
#define STATIC_OBJ          // of both fundamental type or Class.

#define STATIC_FN
#define STATIC_CLASS_FN     // FN             Can be called before instantiating a object of that class type.
#define STATIC_CLASS_OBJ    // OBJ            Can be referenced before instantiating a object of that class type. Initialized to default, or {value}

#define STATIC_FN_MARRIAGE  // FN  VAR CONST? "static" class member function only sees "static" class data members  because they are "data segment storage"

#define STATIC_HIDER_OLD    //     VAR        OLD=>BAD was used instead unnamed "namespace <<NULL>>" to force internal linkage.

/// Gives a source location for printing.  Used for debugging.
std::string source_loc();  // forward declaration
