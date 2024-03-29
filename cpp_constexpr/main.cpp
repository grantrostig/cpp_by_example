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

    define NDEBUG if asserts are NOT to be checked.  Put in *.h file not *.CPP
    #define NDEBUG
    define GR_DEBUG if we/programmer is Debugging.  Put in *.h file not *.CPP
    #define GR_DEBUG
    #ifdef GR_DEBUG
    #endif GR_DEBUG
 */

//#include "global_entities.h"
#include <gsl/gsl>      // sudo dnf install  guidelines-support-library-devel
//#include <bits/stdc++.h>
#include <cassert>
#include <chrono>
#include <climits>
#include <csignal>
#include <iostream>
#include <optional>
#include <source_location>
#include <string>
#include <stacktrace>
#include <type_traits>
#include <utility>
#include <vector>
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

static_assert(CHAR_MIN < 0, "char is signed");
//static_assert(CHAR_MIN == 0, "char is unsigned");
#if CHAR_MIN < 0
    #pragma message("char is signed")
#else
    #pragma message("char is unsigned")
#endif
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
        out << "\b\b\b>]"; out.width(); out << std::setw(0);
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

namespace ExampleP08 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
/** Using consteval to make constexpr execute at compile-time C++20.
 The downside of consteval functions is that such functions can’t evaluate at runtime, making them less flexible than constexpr
functions, which can do either. Therefore, it would still be useful to have a convenient way to force constexpr functions to
evaluate at compile-time (even when the return value is being used where a constant expression is not required), so that we could
have compile-time evaluation when possible, and runtime evaluation when we can’t.
 Consteval functions provides a way to make this happen, using a neat helper function:
 Uses abbreviated function template (C++20) and `auto` return type to make this function work with any type of value
 We cover auto return types in lesson 10.9 -- Type deduction for functions.
 We cover abbreviated function templates (auto parameters) in lesson 11.8 -- Function templates with multiple template types.
*/
consteval auto compileTime (auto value) {
    static_assert(std::is_constant_evaluated());
    return value;
}

constexpr int greater(int x, int y)  {
    static_assert(std::is_constant_evaluated());
    return (x > y ? x : y);
}

void test1 () { std::cout<< "START                ExampleP08 test1. ++++++++++++++++++++++++"<<std::endl;
    std::cout << greater(5, 6) << '\n';              // may or may not execute at compile-time
    std::cout << compileTime(greater(5, 6)) << '\n'; // will execute at compile-time
    int x { 5 };
    std::cout << greater(x, 6) << '\n';              // we can still call the constexpr version at runtime if we wish

    std::cout<< "END                  ExampleP08 test1. ++++++++++++++++++++++++"<<std::endl;
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace ExampleNM1 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
// Constexpr/consteval function parameters are not constexpr (but can be used as arguments to other constexpr functions)
constexpr int goo(int c) {
    static_assert(std::is_constant_evaluated());
    return c; }

//constexpr std::pair<int,bool> foo(int b) {
constexpr int foo(int b) {
    //static_assert(std::is_constant_evaluated());
    //assert(std::is_constant_evaluated());
    //constexpr int b2 { b }; // compile error: b is not a constant expression within foo()
    return goo(b);          // okay: b can still be used as argument to constexpr function goo()
    //return { goo(b),std::is_constant_evaluated() };
}

void test1 () { std::cout<< "START                ExampleNM1 test1. ++++++++++++++++++++++++"<<std::endl;
    constexpr int a { 5 };
    int           b { rand() };
    //constexpr auto bar1{ foo(a) };
    //auto bar3 = foo(b);

    //std::cout << "=" << foo << endl; // okay: constant expression a can be used as argument to constexpr function foo()
    //std::cout << "foo(a)=" << bar1.first << "," << bar1.second << endl; // okay: constant expression a can be used as argument to constexpr function foo()
    //std::cout << "foo(b)=" << bar3.first << "," << bar3.second << endl; // okay: constant expression a can be used as argument to constexpr function foo()
    std::cout<< "END                  ExampleNM1 test1. ++++++++++++++++++++++++"<<std::endl;
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace ExampleJonsTake { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
//

constexpr auto factorial(int val)
{
    if (val == 0) return 1;
    return val * factorial( val - 1);
}

constexpr auto factorial2(int val)
{
    if (val == 0) return 1;
    return val * factorial( val - 1);
}

constexpr auto factorial3(int i)
{
	int f{1};
	for (int j{2}; j <= i; ++j)
	{
		f *= j;
	}

	return f;
}

// vishal
constexpr auto factorial(int val){
    auto result{ 1 };
    std::vector<int> v(val+1);
    v[0] = 1;
    std::iota(v.begin(), v.end(), 1);

    //for (int i{1}; i< (val +1); ++i)
    for (auto i : std::ranges::iota_view{ 1, val +1})
        result *= i;
    return result;
}


template <std::size_t...Is>
constexpr auto factorial4_impl(std::index_sequence<Is...>)
{
	return (1 * ... * (Is + 1));
}

template <std::size_t I>
constexpr auto factorial4()
{
	return factorial4_impl(std::make_index_sequence<I>());
}

constexpr auto call_factorial(int val) {
    auto ice{std::is_constant_evaluated()? 1: -1};
    //int r {rand()};
    std::vector<int> v{1,323,33};
    v.push_back(val);
    v.push_back(ice*val);
    //v.push_back(rand());
    return factorial(val) * ice * v[1];
}


void test1 () { std::cout<< "START                ExampleJonsTake test1. ++++++++++++++++++++++++"<<std::endl;
    //auto myValue{call_factorial(6)};
    constexpr auto myValue{call_factorial(6)};
    //std::array<int, call_factorial(6)> myValues;
    //std::cout << sizeof(myValues) << "\n";
    std::cout << "myValue: " << myValue << "\n";

	static_assert(factorial3(6) == 720);
	static_assert(factorial3(1) == 1);
    static_assert(factorial4<1>() == 1);
	static_assert(factorial4<6>() == 720);
    static_assert(factorial4<10>() == 3628800);

    std::cout<< "END                  ExampleJonsTake test1. ++++++++++++++++++++++++"<<std::endl;
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace ExampleP10 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
/** Constexpr/consteval function parameters are not constexpr (but can be used as arguments to other constexpr functions)
 OBVIOUS: The parameters of a constexpr function are not constexpr (and thus cannot be used in constant expressions). Such parameters can be
declared as const (in which case they are treated as runtime constants), but not constexpr. This is because a constexpr function can
be evaluated at runtime (which wouldn’t be possible if the parameters were compile-time constants).
  However, an exception is made in one case: a constexpr function can pass those parameters as arguments to another constexpr function, and that subsequent
constexpr function can be resolved at compile-time. This allows constexpr functions to still be resolved at compile-time when they
call other constexpr functions (including themselves recursively).
  Perhaps surprisingly, the parameters of a consteval function are
not considered to be constexpr within the function either (even though consteval functions can only be evaluated at compile-time).
This decision was made for the sake of consistency.
*/
constexpr int goo(int c) {
    //static_assert(std::is_constant_evaluated());
    //if (std::is_constant_evaluated()) cout << "WHAT\n";
    //else cout << "Who\n.";
    return c;
}

constexpr int foo(int b) {
    //static_assert(std::is_constant_evaluated());
    //if ( std::is_constant_evaluated() ) cout << "WHAT\n";
 // constexpr int b2 { b }; // compile error: b is not a constant expression within foo()
    return goo(b);          // okay: b can still be used as argument to constexpr function goo()
}

//constinit int e { 5 };
void test1 () { std::cout<< "START                ExampleP10 test1. ++++++++++++++++++++++++"<<std::endl;
    constexpr int a { 5 };
    std::cout << foo(a) << endl; // okay: constant expression a can be used as argument to constexpr function foo()

 // const     int c { 5 };
 // static constinit int d { 5 };  // B constinit int f { 5 };
 // int           b { rand() };
 // std::cout << foo(b) << endl; //
 // std::cout << foo(c) << endl; //
 // std::cout << foo(3) << endl; //
    std::cout<< "END                  ExampleP10 test1. ++++++++++++++++++++++++"<<std::endl;
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace ExampleP12 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
/** Can a constexpr function call a non-constexpr function?
    The answer is yes, but only when the constexpr function is being evaluated in a non-constant context. A non-constexpr function may not
    be called when a constexpr function is evaluating in a constant context (because then the constexpr function wouldn’t be able to
    produce a compile-time constant value).
*/
constexpr int someConstexprFcn(){
    return 1212;
}
int someNonConstexprFcn(){
    return 121212;
}
constexpr int someFunction() {
    if (std::is_constant_evaluated()) // if compile-time evaluation
        return someConstexprFcn();    // calculate some value at compile time
    else                              // runtime evaluation
        return someNonConstexprFcn(); // calculate some value at runtime
}

constexpr int someFunction(bool b) {
    if (b)
        return someConstexprFcn();
    else
        return someNonConstexprFcn();
}

void test1 () { std::cout<< "START                ExampleP12 test1. ++++++++++++++++++++++++"<<std::endl;
    int i12 { someFunction(12) };
    int i13 { someFunction(13) };
    std::cout<< "END                  ExampleP12 test1. ++++++++++++++++++++++++"<<std::endl;
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

int main(int argc, char* arv[]) { string my_arv{*arv}; cout << "~~~ argc, argv:"<<argc<<","<<my_arv<<"."<<endl; cin.exceptions( std::istream::failbit); Detail::crash_signals_register();
    //if (not std::is_constant_evaluated()) cout << "WHAT\n";  // TODO??: can we output via constexpr?  iostreams is not??
    //ExampleP08::test1 ();
    //ExampleP10::test1 ();
    //ExampleP12::test1 ();
    ExampleJonsTake::test1 ();
    cout << "###" << endl;
    return EXIT_SUCCESS;
}
