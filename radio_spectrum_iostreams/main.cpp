/** Copyright (c) Grant Rostig, grantrostig.com 2023. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
    NOT PRODUCTION QUALITY CODE, just shows learning/teaching example, not real programming, don't copy this style, just playing around
    Reminder of usefull resources:
        https://coliru.stacked-crooked.com/
        https://godbolt.org/
        https://cppinsights.io/
        https://Wandbox.org
        https://cpp.sh/
        https://quick-bench.com/
        https://arnemertz.github.io/online-compilers/
    [[maybe_unused]] int * my_new_var8 = ::new (22,int);
    Language Versions:  clan++ -std=c++2b, g++ -std=c++23 or =gnu++23
    STD Libraries: Gcc: libstdc++; Clang: libc++; Microsoft: msvc/ms stl  // TODO??: how do we link with different libraries than the default using gcc or clang (the exact command line text)?
    g++ -Werror -Weffc++ -Wextra -Wall -Wconversion -Wshadow -Wpedantic -Wold-style-cast -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-override -Wnon-virtual-dtor \
        -Wcast-align -Woverloaded-virtual -Wunused -pedantic -Wsign-conversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough \
        -Wuseless-cast -Wsuggest-final-types -Wsuggest-final-methods -Wduplicated-cond -Wduplicated-branches -Wlogical-op -std=gnuc++23 \
        main.cpp <OTHER>.cpp -o <A.OUT>

 SYMBOL    MEANING // for debugging purposes
 TODO:     the principal programmer needs todo.
 TODO?:	  the principal programmer is not sure about something, that should be addressed.
 TODO?:X   the X programmer is not sure about something, that should be addressed.
 TODO??:   is a question for verbal discussion at CppMSG.com meetup meetings.

 Ordering of headers as follows: re:Lakos
 + The prototype/interface header for this implementation (ie, the .h/.hh file that corresponds to this .cpp/.cc file).
 + Other headers from the same project, as needed.
 + Headers from other non-standard, non-system libraries (for example, Qt, Eigen, etc).
 + Headers from other "almost-standard" libraries (for example, Boost)
 + Standard C++ headers (for example, iostream, functional, etc.)
 + Standard C headers (for example, cstdint, dirent.h, etc.)

 define NDEBUG if asserts are NOT to be checked.  Put in *.h file not *.CPP
 #define NDEBUG
 define GR_DEBUG if we/programmer is Debugging.  Put in *.h file not *.CPP
 #define GR_DEBUG
 #ifdef GR_DEBUG
 #endif GR_DEBUG
*/
//Copyright (C) 2013 Steve Taylor (steve98654@gmail.com), Davis E. King
//License: Boost Software License.  See LICENSE.txt for full license.

//#include "global_entities.h"

#include <mp-units/compat_macros.h>
//#include <mp-units/ext/format.h>
//#include <mp-units/format.h>
#include <mp-units/ostream.h>
#include <mp-units/systems/international.h>
#include <mp-units/systems/isq.h>
#include <mp-units/systems/si.h>

//#include <dlib/numeric_constants.h>
//#include <gsl/gsl>      // sudo dnf install  guidelines-support-library-devel
//#include <bits/stdc++.h>

#include <cassert>
#include <chrono>
#include <climits>
#include <csignal>
#include <iomanip>
#include <iostream>
#include <locale>
#include <optional>
#include <source_location>
#include <span>
#include <string>
#include <string_view>
#include <stacktrace>
#include <vector>

//#include <format>
//#include <print>
//import mp_units;
//import std;

using namespace mp_units;
using namespace mp_units::si;
using namespace mp_units::si::unit_symbols; // mp_units::si::unit_symbols::
using namespace mp_units::international::unit_symbols;


using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

static_assert(std::endian::native == std::endian::little, "Memory is little endian.");
//static_assert(std::endian::native == std::endian::big,    "Memory is big endian.");
#pragma message("$$ Memory is little endian.")
static_assert(CHAR_MIN < 0, "Char is signed.");
//static_assert(CHAR_MIN == 0, "Char is unsigned.");
#if CHAR_MIN < 0
#pragma message("$$ Char is signed.")
#else
#pragma message("$$ Char is unsigned.")
#endif
#pragma message("$$ Twos Complement integer math most common, and C++ standard required since C++20.")
using Ostring       = std::optional<std::string>;
using Ochar         = std::optional<char>;
using Ointegral     = std::optional<long>;
//inline constexpr char           CHAR_NULL{'\o{177}'};        // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr char           CHAR_NULL{CHAR_MIN};        // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr signed char    SCHAR_NULL{SCHAR_MIN};       // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr unsigned char  UCHAR_NULL{UCHAR_MAX};       // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.
inline constexpr std::string    STRING_NULL{"NULL"};    // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the best.

       // Some crude logging that prints source location, where X prints a variable, and R adds \n\r (which is usefull when tty in in RAW or CBREAK mode. Requires C++20.
#define LOGGER_(  msg )  using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<           "."    <<endl;cout.flush();cerr.flush();
#define LOGGER_R( msg )  using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<           ".\r\n"<<endl;cout.flush();cerr.flush();
#define LOGGERX(  msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}."    <<endl;cout.flush();cerr.flush();
#define LOGGERXR( msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}.\r\n"<<endl;cout.flush();cerr.flush();

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };


/** Requires that a type has insertion operator
    Concept definition - used by a template below.
    Some value needs to be incorporated with above text:
///  Concept using Function Explicit instantiations that are required to generate code for linker.
///  TODO??: is the only used if definition is in *.cpp file?
///  https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
///  https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
//template std::ostream & operator<<( std::ostream & , std::vector<std::string> const & );
/// Concept using Function Explicit instantiations that are required to generate code for linker.
//template std::ostream & operator<<( std::ostream & , std::deque<int>          const & );
*/
template <typename Container>
concept Insertable = requires( std::ostream & out ) {
    requires not std::same_as<std::string, Container>;                                    // OR $ std::is_same <std::string, Container>::value OR std::is_same_v<std::string, Container>;
    { out << typename Container::value_type {} } -> std::convertible_to<std::ostream & >; // OR just $ { out << typename Container::value_type {} };
};

/** Prints contents of a container such as a vector of int's.
    Insertable Concept used by Templated Function definition
    Older version is here for the record:
    template<typename T> std::ostream & operator<<(std::ostream & out, std::vector<T> const & v) { // utility f() to print vectors
    if ( not v.empty() ) {
        out<<'['; std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", ")); out<<"\b\b]";
    }
        return out;
    }
*/
template<typename Container>                        //template<insertable Container>        // OR these 2 lines currently being used.
    requires Insertable<Container>
std::ostream &
operator<<( std::ostream & out, Container const & c) {
    if ( not c.empty()) {
        out << "[<";   //out.width(9);  // TODO??: neither work, only space out first element. //out << std::setw(9);  // TODO??: neither work, only space out first element.
        std::copy(c.begin(), c.end(), std::ostream_iterator< typename Container::value_type >( out, ">,<" ));
        //out << "\b\b\b>]"; out.width(); out << std::setw(0);
        out << "\b\b\b>]"; out.width(); out << std::setw(0) << " ";
    } else out << "[CONTAINTER IS EMPTY]";
    return out;
}

namespace Detail {  // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
std::string source_loc();           // forward declaration
extern void stacktrace_register();
void crash_signals_register();

/** gives a source location for printing.  Used for debugging. */
std::string
source_loc() {
    using loc = std::source_location;
    //using ts = std::to_string;  // todo??: why not?  alternative approach?
    std::string result {"\n"s+loc::current().file_name() +":"s +std::to_string(loc::current().line()) +std::to_string(loc::current().column())+"]`"s +loc::current().function_name()+"`."s};
    return result;
}

/** Called as we try to ABORT ) after already getting another signal from the application code.
    OR should we exit() or terminate() and not use this function? */
auto crash_tracer_SIGABRT(int signal_number) -> void {
    //LOGGERX( "We are getting out and that generated another signal, presumably ABRT, we got signal number", signal_number);
    //LOGGERX( "IGNORE THIS ONE, just shown for understanding:", std::stacktrace::current());
    LOGGER_( "This is the very end!");
    return;
}

/** Prints a stack trace of crash location.  Used for debugging. */
auto crash_tracer(int signal_number) -> void {
    cerr << "\n\r:CRASH_ERROR:Got signal number:" << signal_number;
    //cerr << "\n\r:./stack_trace::current():" << std::stacktrace::current() <<":END CRASH_ERROR STACK_TRACE."<<endl;

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
/** signals that cause "terminate" and sometimes "core dump"  https://en.wikipedia.org/wiki/Signal_(IPC)
   We define here all the signal names listed in POSIX (1003.1-2008);
   as of 1003.1-2013, no additional signals have been added by POSIX.
   We also define here signal names that historically exist in every
   real-world POSIX variant (e.g. SIGWINCH).
   Signals in the 1-15 range are defined with their historical numbers.
   For other signals, we use the BSD numbers.
   There are two unallocated signal numbers in the 1-31 range: 7 and 29.
   Signal number 0 is reserved for use as kill(pid, 0), to test whether
   a process exists without sending it a signal.
 ISO C99 signals.
#define	SIGINT		2	 Interactive attention signal.
#define	SIGILL		4	 Illegal instruction.
#define	SIGABRT		6	 Abnormal termination.
#define	SIGFPE		8	 Erroneous arithmetic operation.
#define	SIGSEGV		11	 Invalid access to storage.
#define	SIGTERM		15	 Termination request.
 Historical signals specified by POSIX.
#define	SIGHUP		1	 Hangup.
#define	SIGQUIT		3	 Quit.
#define	SIGTRAP		5	 Trace/breakpoint trap.
#define	SIGKILL		9	 Killed.
#define	SIGPIPE		13	 Broken pipe.
#define	SIGALRM		14	 Alarm clock.
 Adjustments and additions to the signal number constants for most Linux systems.
#define SIGSTKFLT	16	 Stack fault (obsolete).
#define SIGPWR		30	 Power failure imminent.
 Historical signals specified by POSIX.
#define SIGBUS		 7	 Bus error.
#define SIGSYS		31	 Bad system call.
 New(er) POSIX signals (1003.1-2008, 1003.1-2013).
#define SIGURG		23	 Urgent data is available at a socket.
#define SIGSTOP		19	 Stop, unblockable.
#define SIGTSTP		20	 Keyboard stop.
#define SIGCONT		18	 Continue.
#define SIGCHLD		17	 Child terminated or stopped.
#define SIGTTIN		21	 Background read from control terminal.
#define SIGTTOU		22	 Background write to control terminal.
#define SIGPOLL		29	 Pollable event occurred (System V).
#define SIGXFSZ		25	 File size limit exceeded.
#define SIGXCPU		24	 CPU time limit exceeded.
#define SIGVTALRM	26	 Virtual timer expired.
#define SIGPROF		27	 Profiling timer expired.
#define SIGUSR1		10	 User-defined signal 1.
#define SIGUSR2		12	 User-defined signal 2.
 Nonstandard signals found in all modern POSIX systems
   (including both BSD and Linux).
#define SIGWINCH	28	 Window size change (4.3 BSD, Sun).
 Archaic names for compatibility.
#define SIGIO		SIGPOLL	 I/O now possible (4.2 BSD).
#define SIGIOT		SIGABRT	 IOT instruction, abort() on a PDP-11.
#define SIGCLD		SIGCHLD	 Old System V name
#define __SIGRTMIN	32
#define __SIGRTMAX	64
*/
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

// ++++++++++++++++ EXAMPLEs begin ++++++++++++++++++++++++++++++++++++++++++++++++++++++++

enum FCC_HAM_class {
//enum class FCC_HAM_class {  // TODO??: Won't print via cout easily.
    Technician,
    General,
    Extra
};

std::chrono::year_month_day constexpr fcc_revision_date_default{2024y, std::chrono::September, 18d};

struct Frequency_row {
    std::string                         band_name{};
    std::string                         band_plan_name{};
    quantity<second, double>            time_period_per_cycle_begin{0*second};  // should be very small time unit //?? std::chrono::duration<int, std::kilo>   period_per_cycle{3}; // 3000 seconds
    quantity<second, double>            time_period_per_cycle_end{0*si::second};
    quantity<hertz, double>             frequency_begin{40*si::kilo<hertz>};   // todo??: grostig thinks this is: cycles/second, but it might be just 1/second) //?? quantity<isq::frequency>  frequency{3*second};
    //quantity<si::kilo<hertz>,double>    frequency_end{42*si::hertz};          // todo??: grostig thinks this is: cycles/second)  //?? quantity<isq::frequency>  frequency{3*second};
    quantity<hertz, double>             frequency_end{42*si::hertz};       // todo??: grostig thinks this is: cycles/second)  //?? quantity<isq::frequency>  frequency{3*second};
    quantity<metre, double>             wavelength_begin{0*cm};                 // quantity<si::centi<m>>              wavelength_begin{0*cm};
    quantity<metre, double>             wavelength_end{0*nm};                   // quantity<si::nano<metre>>           wavelength_end{0*nm};
    FCC_HAM_class                       fcc_ham_class{};
    string                              band_restictions{};
    std::chrono::year_month_day         fcc_revision_date{};

    //std::ostream operator<<() {};
};
/* d = vt;                  distance = velocity * t;
// distance =               m (meters)
// time =                   sec (seconds)
// velocity =               m/sec, in this use case we use "c" the speed of light in vacumm.
// The time "Period" of a "Cycle" of a sine wave.
// Period in sec = time between period of a radio wave.  // Not used: Period in m = meters between period of a radio wave.
// Period/Cycle in sec      sec AKA sec/cycle which is more proper in our view.
// Frequency f in Hz        Hz 1/sec AKA cycles/sec  kHz or kC (cycles, now obsolete)
// Wavelenght = Lambda in meters or cm or mm    AKA m/cycle */
std::vector<Frequency_row> frequency_rows {
    {"444 Band",  "CW"  , 0*si::second,     0*si::second
                        , 2*si::hertz,            5'600'000*si::hertz
                        , 0*si::metre,      0*si::metre
                        , FCC_HAM_class::General, "Normal, 1500W, 2.8kHz BW.", {2024y, std::chrono::September,19d}},
    {"444 Band2", "CW"  , 0*si::second,     0*si::second
                        , 1*si::hertz,      5*si::kilo<hertz>
                        , 0*si::metre,      0*si::metre
                        , FCC_HAM_class::General, "Normal, 100W, 500Hz", {2024y, std::chrono::September,19d}}
};
// ++++++++++++++++ EXAMPLEs begin ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
namespace Example1 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
void calculate( Frequency_row & i ) {
    auto junk_sec                   = 1 / i.frequency_begin;  // TODO??: why not?: i.time_period_per_cycle_end   = mp_units::inverse( i.frequency_end);  // TODO??: wants a dimension

    quantity<si::nano<second>,double> junk_sec1      = 1 / i.frequency_begin;  // TODO??: why not?: i.time_period_per_cycle_end   = mp_units::inverse( i.frequency_end);  // TODO??: wants a dimension
    quantity<si::second,double> junk_sec2      = 1 / i.frequency_begin;  // TODO??: why not?: i.time_period_per_cycle_end   = mp_units::inverse( i.frequency_end);  // TODO??: wants a dimension

    cout << "junk_sec :" << junk_sec <<endl;
    cout << "junk_sec1:" << junk_sec1 <<endl;
    cout << "junk_sec2:" << junk_sec2 <<endl;

    i.time_period_per_cycle_begin   = 1 / i.frequency_begin;  // TODO??: why not?: i.time_period_per_cycle_end   = mp_units::inverse( i.frequency_end);  // TODO??: wants a dimension
    i.time_period_per_cycle_end     = 1 / i.frequency_end;
    i.wavelength_begin              = (1. / i.frequency_begin) * si2019::speed_of_light_in_vacuum ;
    i.wavelength_end                = (1. / i.frequency_end) * si2019::speed_of_light_in_vacuum ;
};
void test1 () {
    std::cout<< "START                Example1 test1. ++++++++++++++++++++++++"<<std::endl;
    for (auto & i:frequency_rows) { calculate(i); };

    std::locale loc_orig{};                 // No commas at thousands.
    cout << "locale_orig:" << loc_orig.name() <<", ";
    std::locale loc{std::locale("en_US")};  // Has commas at thousands.
    cout << "locale:     " << loc.name() <<", "<< endl; // l.global() << endl;
    cout.imbue(loc);

    auto const      default_precision{std::cout.precision()};  // https://en.cppreference.com/w/cpp/io/manip/setprecision
    auto constexpr  max_precision{std::numeric_limits<long double>::digits10 + 1};

    for (auto const & i:frequency_rows) {
            cout
             << std::setprecision(8)
             << std::setw(10)
             << i.band_name <<" - "
             << std::setw(10)
             << i.band_plan_name <<"; "
             << std::setw(18)
             << i.frequency_begin             <<" - "
             << std::setw(18)
             << i.frequency_end <<"; "
             << std::setw(18)
             << i.wavelength_begin <<" - "
             << std::setw(18)
             << i.wavelength_end <<"; "

             << std::setprecision(default_precision)
             << i.band_restictions <<"; "
             << i.fcc_ham_class <<"; "
             << i.fcc_revision_date <<"; "
             << std::setprecision(8)
             << std::setw(14)
             << i.time_period_per_cycle_begin <<" - "
             << std::setw(14)
             << i.time_period_per_cycle_end
             << std::setprecision(default_precision)
             << endl;
    }
    //for (auto & i:frequency_rows) { cout << i << endl; }
    //cout << frequency_rows << endl; }
    std::cout << "END                  Example1 test1. ++++++++++++++++++++++++"<<std::endl;
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

int main(int argc, char const * arv[]) { string my_arv{*arv}; cout << "~~~ argc, argv:"<<argc<<","<<my_arv<<"."<<endl; cin.exceptions( std::istream::failbit); Detail::crash_signals_register();
    Example1::test1 ();
    cout << "###" << endl;
    return EXIT_SUCCESS;
}
