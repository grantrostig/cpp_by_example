/* used to illustrate programming and debugging helper code
 * Copyright GrantRostig.com
 * BOOST license
 */
//#include <bits/stdc++.h>  // gcc only linux only? // todo: why strange clang check error/warning???
#include <iostream>
#include <string>
#include <cassert>
#include <csignal>
#include <stacktrace>
#include <source_location>
#include <chrono>
#include <thread>
#include <unistd.h>  // todo??: something to do with sleep?  works without include.
using std::endl, std::cin, std::cout, std::cerr, std::string;

// Some crude logging that prints source location, where X prints a variable, and R adds \n\r (which is usefull when tty in in RAW or CBREAK mode. Requires C++20.
  #define LOGGER_(  msg )  using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<           "."    <<endl;cout.flush();cerr.flush();
  #define LOGGER_R( msg )  using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<           ".\r\n"<<endl;cout.flush();cerr.flush();
  #define LOGGERX(  msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}."    <<endl;cout.flush();cerr.flush();
  #define LOGGERXR( msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}.\r\n"<<endl;cout.flush();cerr.flush();

/* ISO C99 signals.
//SIGINT		2	// Interactive attention signal.
//SIGILL		4	// Illegal instruction.
//SIGABRT		6	// Abnormal termination.
//SIGFPE		8	// Erroneous arithmetic operation.
//SIGSEGV		11	// Invalid access to storage.
//SIGTERM		15	// Termination request.
// Historical signals specified by POSIX.
//SIGHUP		1	// Hangup.
//SIGQUIT		3	// Quit.
//SIGTRAP		5	// Trace/breakpoint trap.
//SIGKILL		9	// Killed.
//SIGPIPE		13	// Broken pipe.
//SIGALRM		14	// Alarm clock.
// New(er) POSIX signals (1003.1-2008, 1003.1-2013).  /
// SIGURG):		/ Urgent data is available at a socket.  /
// SIGSTOP):	/ Stop, unblockable.  /
// SIGTSTP):	/ Keyboard stop.  /
// SIGCONT):	/ Continue.  /
// SIGCHLD):	/ Child terminated or stopped.  /
// SIGTTIN):	/ Background read from control terminal.  /
// SIGTTOU):	/ Background write to control terminal.  /
// SIGPOLL):	/ Pollable event occurred (System V).  /
// SIGXCPU):	/ CPU time limit exceeded.  /
// SIGXFSZ):	/ File size limit exceeded.  /
// SIGVTALRM):	/ Virtual timer expired.  /
// SIGPROF):	/ Profiling timer expired.  /
// SIGUSR1):	/ User-defined signal 1.  /
// SIGUSR2):	/ User-defined signal 2.  /
/ Nonstandard signals found in all modern POSIX systems (including both BSD and Linux)  /
// SIGWINCH):	/ Window size change (4.3 BSD, Sun).  /
// SIGSTKFLT):	/ Stack fault (obsolete).  /
// SIGPWR):		/ Power failure imminent.  /
*/

namespace Detail {  // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
auto crash_tracer(int signal_number) -> void {
    cerr << "\n\r:CRASH_ERROR:Got signal number:" << signal_number;
    cerr << "\n\r:./stack_trace::current():" << std::stacktrace::current() <<":END CRASH_ERROR STACK_TRACE."<<endl;

    if ( bool is_want_prompt{true}; is_want_prompt ) {
        std::string reply; cout << "CRASH_ERROR: q for exit(1) or CR to continue:"; cout.flush(); cin.clear();
        getline( cin, reply );
        if ( reply == "q" )
            exit(1);
        else
            return;
    }
    else {
        /* IGNORE using namespace std::chrono_literals;
    std::chrono::duration my_duration = 2s;
    cerr << "Wait time:" << 2s << " + in variable:"<< my_duration <<endl;
    std::this_thread::sleep_for( my_duration ); // sleep(2);  // seconds
    std::this_thread::sleep_for( std::chrono_literals::s::1 ); //todo??: how to do this?
    LOGGER_LOC( my_tracer(): Now- after stacktrace documenting a catastrophic error- we need to abort().);
    */

        //std::signal( SIGABRT, SIG_DFL ); // repair normal signals in preparation for abort() // OR maybe?? $ std::signal( SIGABRT, SIG_IGN );
        std::abort(); // OR alternatively? $ std::exit(42) or teminate, or quick_exit()??
        // *** we never get here
        assert( false && "Doing something after std::abort() is ERROR.\n" );
        return;
    }
}

/** Called as we try to ABORT ) after already getting another signal from the application code.
    OR should we exit() or terminate() and not use this function?
*/
auto crash_tracer_SIGABRT(int signal_number) -> void {
    LOGGERX( "We are getting out and that generated another signal, presumably ABRT, we got signal number", signal_number);
    LOGGERX( "IGNORE THIS ONE, just shown for understanding:", std::stacktrace::current());
    LOGGER_( "This is the very end!");
    return;
}

auto crash_signals_register() -> void {
    std::signal( SIGHUP,  crash_tracer );
    std::signal( SIGINT,  crash_tracer );
    std::signal( SIGQUIT, crash_tracer );
    std::signal( SIGILL,  crash_tracer );
    std::signal( SIGTRAP, crash_tracer );
    std::signal( SIGABRT, crash_tracer_SIGABRT );
    std::signal( SIGSEGV, crash_tracer );
}
} // End Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

auto my_crashing_function(int const &i = 43) -> int {
    LOGGER_( Prior to SIGSEV (posix#11) );
    std::raise(  SIGSEGV ); // *** we never get beyond this line ***
    assert( false && "We should not get past the SIGSEV signal.\n");
    return i;
}

int main() {
    Detail::crash_signals_register();
    my_crashing_function();

    cerr << "###" << endl;
    return 0;
}
