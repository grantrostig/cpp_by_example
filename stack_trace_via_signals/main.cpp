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

#define LOGGER_( msg )   using loc = std::source_location;std::cerr<<"["<<loc::current().file_name()<<':'<<loc::current().line()<<','<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".\n";
#define LOGGER2( msg, x )using loc = std::source_location;std::cerr<<"["<<loc::current().file_name()<<':'<<loc::current().line()<<','<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<",{"<<x<<"}.\n";

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

auto
logger_test()->void {
  [[nodiscard]] int i {99};  // todo??: how do I make sure something, in this case the running of this function, is not optimized away?
  [[maybe_unused]] int j {99};  // todo??: how do I make sure something, in this case the running of this function, is not optimized away?
  LOGGER_(.)
  LOGGER2( First line2, i )
}

auto
crash_tracer(int signal_number)->void {
    //LOGGER_LOC2( my_tracer(): Got signal number:, signal_number);
    //cerr <<"\nmy_trace:" << std::stacktrace::current();

    //using namespace std::chrono_literals;
    //std::chrono::duration my_duration = 2s;
    //cerr << "Wait time:" << 2s << " + in variable:"<< my_duration <<endl;
    //std::this_thread::sleep_for( my_duration ); // sleep(2);  // seconds
    //std::this_thread::sleep_for( std::chrono_literals::s::1 ); //todo??: how to do this?
    //LOGGER_LOC( my_tracer(): Now- after stacktrace documenting a catastrophic error- we need to abort().);

    //std::signal( SIGABRT, SIG_DFL ); // repair normal signals in preparation for abort() // OR maybe?? $ std::signal( SIGABRT, SIG_IGN );
    std::abort(); // OR alternatively? $ std::exit(42) or teminate, or quick_exit()??

    // *** we never get here
    assert( false && "Doing something after std::abort() is ERROR.\n" );
    return;
}

auto
my_tracer_SIGabort(int signal_number)->void {  // ********NEVER CALLED****** in current code
   LOGGER2( "Got signal number:", signal_number)
   cerr <<"\n";
   cerr << "my_trace:" << std::stacktrace::current();
   LOGGER_( "Doing something at end.");
    return;
}

auto
my_function(int const &i = 43)->int {
    //LOGGER_LOC( Prior to SIGSEV (posix#11) );
    std::raise(  SIGSEGV ); // *** we never get beyond this line ***
    assert(false && "We should not get past the SIGSEV signal.\n");
    return i;
}

auto
crash_signals_register()->void {
    std::signal( SIGHUP,  crash_tracer );
    std::signal( SIGINT,  crash_tracer );
    std::signal( SIGQUIT, crash_tracer );
    std::signal( SIGILL,  crash_tracer );
    std::signal( SIGTRAP, crash_tracer );
    std::signal( SIGABRT, my_tracer_SIGabort );
    std::signal( SIGSEGV, crash_tracer );
}

auto
my_assert()->void {
    assert( true && "False is not asserted to be true.");  // this provides location and line number on output.
}

int main() {
    //assert( 1 == 3 && "my output");
    //my_assert();
    //logger_test();
    crash_signals_register();
    my_function();
    cerr << "###" << endl;
    return 0;
}
