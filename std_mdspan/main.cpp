// copyright (c) Grant Rostig, grantrostig.com, Boost 1.0 license
/** NOT PRODUCTION QUALITY CODE, just shows learning/teaching example, not real programming, don't copy this style, just playing around
   Copyright Grant Rostig 2015 - 2021. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
   Reminder of usefull resources:
   https://coliru.stacked-crooked.com/
   https://godbolt.org/
   https://cppinsights.io/
   https://Wandbox.org
   https://arnemertz.github.io/online-compilers/
 */
//#include "global_entities.h"
//#include <bits/stdc++.h>
#include <iostream>
#include <csignal>
#include <stacktrace>
#include <source_location>

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;

/// define if asserts are NOT to be checked.  Put in *.h file not *.CPP
//#define 	NDEBUG
//#undef 	NDEBUG
/// define if Debugging LT.  Put in *.h file not *.CPP
#define  	GR_DEBUG
//#undef  	GR_DEBUG
//#ifdef   	GR_DEBUG
//#endif  # GR_DEBUG
/// gives a source location for printing.  Used for debugging.
#define LOGGER_( msg )   using loc = std::source_location;std::cerr<<"\n\r["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".\n";
/// gives a source location for printing.  Used for debugging.
#define LOGGERS( msg, x )using loc = std::source_location;std::cerr<<"\n\r["<<loc::current().file_name()<<':'<<std::setw(3)<<loc::current().line()<<','<<std::setw(2)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<",{"<<x<<"}.\n";
//#define LOGGER_( msg )
//#define LOGGERS( msg,x )
/// gives a source location for printing.  Used for debugging.
std::string
source_loc() {
    using loc = std::source_location;
    //using ts = std::to_string;  // todo??: why not?  alternative approach?
    std::string result {"\n"s+loc::current().file_name() +":"s +std::to_string(loc::current().line()) +std::to_string(loc::current().column())+"]`"s +loc::current().function_name()+"`."s};
    return result;
}
/// Prints a stack trace of crash location for printing.  Used for debugging.
auto crash_tracer(int const signal_number) ->void { cout << "CRASH_ERROR: signal#, stack trace:<<<" << signal_number << ">>>,<<<" << std::stacktrace::current() << "<<<END STACK TRACE.\n"; }
/// Prints a stack trace of crash location for printing.  Used for debugging.
auto crash_signals_register() -> void {    // signals that cause "terminate" and sometimes "core dump"  https://en.wikipedia.org/wiki/Signal_(IPC)
    std::signal( SIGABRT, crash_tracer );
    std::signal( SIGALRM, crash_tracer );
    std::signal( SIGBUS,  crash_tracer );
    std::signal( SIGFPE,  crash_tracer );
    std::signal( SIGHUP,  crash_tracer );
    std::signal( SIGILL,  crash_tracer );
    std::signal( SIGINT,  crash_tracer );
    std::signal( SIGKILL, crash_tracer );
    std::signal( SIGPIPE, crash_tracer );
    std::signal( SIGPOLL, crash_tracer );
    std::signal( SIGPROF, crash_tracer );
    std::signal( SIGQUIT, crash_tracer );
    std::signal( SIGSEGV, crash_tracer );
    std::signal( SIGSYS,  crash_tracer );
    std::signal( SIGTERM, crash_tracer );
    std::signal( SIGTRAP, crash_tracer );
    std::signal( SIGUSR1, crash_tracer );
    std::signal( SIGUSR2, crash_tracer );
    std::signal( SIGVTALRM, crash_tracer );
    std::signal( SIGXCPU, crash_tracer );
    std::signal( SIGXFSZ, crash_tracer );
    std::signal( SIGVTALRM, crash_tracer );
}

int main ( int argc, char* arv[] ) { string my_arv { *arv}; cout << "~~~ argc,argv:"<<argc<<","<<my_arv<<"."<<endl; crash_signals_register();

    //[[maybe_unused]] int * my_new_var8 = ::new (22,int);

    cout << "###" << endl;
    return 0;
}
