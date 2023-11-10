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

// Linkage
// Storage_Duration
// not Scope?
#define EXTERN_CLASS
#define EXTERN_OBJ
#define EXTERN_FN

#define STATIC_CLASS    // Not allowed, but members can be.
#define STATIC_OBJ      // of both fundamental type or Class.

#define STATIC_FN
#define STATIC_CLASS_FN
#define STATIC_CLASS_OBJ

/// Gives a source location for printing.  Used for debugging.
std::string source_loc();  // forward declaration
