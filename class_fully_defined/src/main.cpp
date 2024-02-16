/** A Modern C++ class definition example
    showing all required function members:
    + constructors
    + copy, and move
    + operators - unary and binary

    Copyright (c) Grant Rostig, grantrostig.com 2023. Distributed under the Boost Software License, Version 1.0. (See accompanying
 file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt) NOT PRODUCTION QUALITY CODE, just shows learning/teaching
 example, not real programming, don't copy this style, just playing around Reminder of usefull resources:
        https://coliru.stacked-crooked.com/
        https://godbolt.org/
        https://cppinsights.io/
        https://Wandbox.org
        https://cpp.sh/
        https://quick-bench.com/
        https://arnemertz.github.io/online-compilers/
    [[maybe_unused]] int * my_new_var8 = ::new (22,int);
    Language Versions:  clan++ -std=c++2b, g++ -std=c++23 or =gnu++23
    STD Libraries: Gcc: libstdc++; Clang: libc++; Microsoft: msvc/ms stl  // TODO??: how do we link with different libraries than the
 default using gcc or clang (the exact command line text)?
    g++ -Werror -Weffc++ -Wextra -Wall -Wconversion -Wshadow -Wpedantic -Wold-style-cast -Wsign-promo -Wzero-as-null-pointer-constant
 -Wsuggest-override -Wnon-virtual-dtor \
        -Wcast-align -Woverloaded-virtual -Wunused -pedantic -Wsign-conversion -Wmisleading-indentation -Wnull-dereference
 -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough \
        -Wuseless-cast -Wsuggest-final-types -Wsuggest-final-methods -Wduplicated-cond -Wduplicated-branches -Wlogical-op
 -std=gnuc++23 \ main.cpp <OTHER>.cpp -o <A.OUT>

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

// #include "global_entities.h"
#include <bits/stdc++.h>
#include <cassert>
//#include <chrono>
#include <climits>
#include <csignal>
#include <gsl/gsl> // sudo dnf install  guidelines-support-library-devel
#include <iostream>
#include <optional>
#include <source_location>
#include <stacktrace>
#include <string>
#include <vector>
using std::cerr;
using std::cin;
using std::clog;
using std::cout;
using std::endl;
using std::string; // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

using std::cerr;
using std::cin;
using std::clog;
using std::cout;
using std::endl;
using std::string; // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

static_assert (CHAR_MIN < 0, "char is signed");
// static_assert(CHAR_MIN == 0, "char is unsigned");
#if CHAR_MIN < 0
#pragma message("char is signed")
#else
#pragma message("char is unsigned")
#endif
using Ostring   = std::optional<std::string>;
using Ochar     = std::optional<char>;
using Ointegral = std::optional<long>;
// inline constexpr char           CHAR_NULL{'\o{177}'};        // Value is unset/not-set, similar to how a SQL DB shows an unset
// field as NULL, which is different than zero length or some magic number.  Here we turn it into a magic number and hope for the
// best.
inline constexpr char CHAR_NULL{
    CHAR_MIN
}; // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic
   // number.  Here we turn it into a magic number and hope for the best.
inline constexpr signed char SCHAR_NULL{
    SCHAR_MIN
}; // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic
   // number.  Here we turn it into a magic number and hope for the best.
inline constexpr unsigned char UCHAR_NULL{
    UCHAR_MAX
}; // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic
   // number.  Here we turn it into a magic number and hope for the best.
inline constexpr std::string STRING_NULL{
    "NULL"
}; // Value is unset/not-set, similar to how a SQL DB shows an unset field as NULL, which is different than zero length or some magic
   // number.  Here we turn it into a magic number and hope for the best.

// Some crude logging that prints source location, where X prints a variable, and R adds \n\r (which is usefull when tty in in RAW or
// CBREAK mode. Requires C++20.
#define LOGGER_(msg)                                                                                                                 \
    using loc = std::source_location;                                                                                                \
    std::cout.flush ();                                                                                                              \
    std::cerr.flush ();                                                                                                              \
    std::cerr << "[" << loc::current ().file_name () << ':' << std::setw (4) << loc::current ().line () << ',' << std::setw (3)      \
              << loc::current ().column () << "]`" << loc::current ().function_name () << "`:" << #msg << "." << endl;               \
    cout.flush ();                                                                                                                   \
    cerr.flush ();
#define LOGGER_R(msg)                                                                                                                \
    using loc = std::source_location;                                                                                                \
    std::cout.flush ();                                                                                                              \
    std::cerr.flush ();                                                                                                              \
    std::cerr << "\r\n[" << loc::current ().file_name () << ':' << std::setw (4) << loc::current ().line () << ',' << std::setw (3)  \
              << loc::current ().column () << "]`" << loc::current ().function_name () << "`:" << #msg << ".\r\n"                    \
              << endl;                                                                                                               \
    cout.flush ();                                                                                                                   \
    cerr.flush ();
#define LOGGERX(msg, x)                                                                                                              \
    using loc = std::source_location;                                                                                                \
    std::cout.flush ();                                                                                                              \
    std::cerr.flush ();                                                                                                              \
    std::cerr << "[" << loc::current ().file_name () << ':' << std::setw (4) << loc::current ().line () << ',' << std::setw (3)      \
              << loc::current ().column () << "]`" << loc::current ().function_name () << "`:" << #msg << ".:{" << x << "}."         \
              << endl;                                                                                                               \
    cout.flush ();                                                                                                                   \
    cerr.flush ();
#define LOGGERXR(msg, x)                                                                                                             \
    using loc = std::source_location;                                                                                                \
    std::cout.flush ();                                                                                                              \
    std::cerr.flush ();                                                                                                              \
    std::cerr << "\r\n[" << loc::current ().file_name () << ':' << std::setw (4) << loc::current ().line () << ',' << std::setw (3)  \
              << loc::current ().column () << "]`" << loc::current ().function_name () << "`:" << #msg << ".:{" << x << "}.\r\n"     \
              << endl;                                                                                                               \
    cout.flush ();                                                                                                                   \
    cerr.flush ();

template <class... Ts> struct overloaded : Ts... {
    using Ts::operator()...;
};

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
template <typename Container> concept Insertable = requires (std::ostream & out) {
    requires not std::same_as<std::string, Container>; // OR $ std::is_same <std::string, Container>::value OR
                                                       // std::is_same_v<std::string, Container>;
    {
        out << typename Container::value_type {}
    } -> std::convertible_to<std::ostream &>; // OR just $ { out << typename Container::value_type {} };
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
template <typename Container> // template<insertable Container>        // OR these 2 lines currently being used.
requires Insertable<Container> std::ostream                                &
operator<< (std::ostream &out, Container const &c) {
    if (not c.empty ()) {
        out << "[<"; // out.width(9);  // TODO??: neither work, only space out first element. //out << std::setw(9);  // TODO??:
                     // neither work, only space out first element.
        std::copy (c.begin (), c.end (), std::ostream_iterator<typename Container::value_type> (out, ">,<"));
        out << "\b\b\b>]";
        out.width ();
        out << std::setw (0);
    } else
        out << "[CONTAINTER IS EMPTY]";
    return out;
}

namespace Detail {         // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
std::string source_loc (); // forward declaration
extern void stacktrace_register ();
void        crash_signals_register ();

/** gives a source location for printing.  Used for debugging. */
std::string
source_loc () {
    using loc = std::source_location;
    // using ts = std::to_string;  // todo??: why not?  alternative approach?
    std::string result{ "\n"s + loc::current ().file_name () + ":"s + std::to_string (loc::current ().line ()) +
                        std::to_string (loc::current ().column ()) + "]`"s + loc::current ().function_name () + "`."s };
    return result;
}

/** Called as we try to ABORT ) after already getting another signal from the application code.
    OR should we exit() or terminate() and not use this function? */
auto
crash_tracer_SIGABRT (int signal_number) -> void {
    // LOGGERX( "We are getting out and that generated another signal, presumably ABRT, we got signal number", signal_number);
    // LOGGERX( "IGNORE THIS ONE, just shown for understanding:", std::stacktrace::current());
    LOGGER_ ("This is the very end!");
    return;
}

/** Prints a stack trace of crash location.  Used for debugging. */
auto
crash_tracer (int signal_number) -> void {
    cerr << "\n\r:CRASH_ERROR:Got signal number:" << signal_number;
    cerr << "\n\r:./stack_trace::current():" << std::stacktrace::current () << ":END CRASH_ERROR STACK_TRACE." << endl;

    if (bool is_want_prompt{ true }; is_want_prompt) {
        std::string reply;
        cout << "CRASH_ERROR: q for exit(1) or CR to continue:";
        cout.flush ();
        cin.clear ();
        getline (cin, reply);
        if (reply == "q") exit (1);
        else
            return;
    } else {
        /* IGNORE using namespace std::chrono_literals;
    std::chrono::duration my_duration = 2s;
    cerr << "Wait time:" << 2s << " + in variable:"<< my_duration <<endl;
    std::this_thread::sleep_for( my_duration ); // sleep(2);  // seconds
    std::this_thread::sleep_for( std::chrono_literals::s::1 ); //todo??: how to do this?
    LOGGER_LOC( my_tracer(): Now- after stacktrace documenting a catastrophic error- we need to abort().);
    */

        // std::signal( SIGABRT, SIG_DFL ); // repair normal signals in preparation for abort() // OR maybe?? $ std::signal( SIGABRT,
        // SIG_IGN );
        std::abort (); // OR alternatively? $ std::exit(42) or teminate, or quick_exit()??
        // *** we never get here
        assert (false && "Doing something after std::abort() is ERROR.\n");
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
auto
crash_signals_register () -> void {
    std::signal (SIGHUP, crash_tracer);
    std::signal (SIGINT, crash_tracer);
    std::signal (SIGQUIT, crash_tracer);
    std::signal (SIGILL, crash_tracer);
    std::signal (SIGTRAP, crash_tracer);
    std::signal (SIGABRT, crash_tracer_SIGABRT);
    std::signal (SIGSEGV, crash_tracer);
}
} // End Namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++ EXAMPLEs begin +++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/* Tips from C++ in a Nutshell:
 * P:135: POD hasn't got: user-defined constructor/destructor, copy(&move??) assignment operator
 * 			   virtual, base classes(meaning no inheritance??)
 * 			   nonstatic: private or protected members, data members that are ref
 * 	   ALSO: nonstatic data members must have a POD type, which are: fundamental, enum (enum class??),
 *           POD class (&struct??) or union, ptr to (or array of POD types).
extern "C" int stat( char * filename, struct stat * st);  // elaborated type specifier example
*/
// template <typename T>

class Base_class {
                                                            // TODO??: Place using statements in public? Currently private. Opinions on better way??
    using Uptr   = std::unique_ptr<Base_class>;
    using Vi     = std::vector<int>;                        // TODO??: is one ever required to do a typedef instead of using??
    using Vvi    = std::vector<std::vector<int> >;
    using Vvs    = std::vector<std::vector<std::string> >;
    using Uptr_v = std::vector<Uptr>;
    // *** Traits ?? ****
    int                 i_{};
    string              s_{};
    Vi                  vi_{};
    Vvi                 vvi_{};
    Vvs                 vvs_{};
    int const           i_const_{ 99 };  // Const must be inited here or on constructor. TODO??: when can we set it?? what order is respected??
    int mutable         i_mutable_{};    // Even in a const Class definition. For example as a data cache, or memoization.
    int static          i_static_;       // compiler::non-const must be init out of line. todo: what if I don't??
    int const static    i_cstatic_{};
    /*T 			    t_{};		// todo: for template doesn't compile??
    std::string 			s 			{};
    std::string static 		s_static;  		   	// non-const must be init out of line. todo: what if I don't??
    std::vector<int> 		vi 			{};
    std::vector<int> static vi_static;  		// non-const must be init out of line.
    Vvs 					vvs 		{};
    Vvs static 				vvs_static;  		// non-const must be init out of line.
    // Now for some sophisticated UML relationships - note a Base_class++ aggregate is not the same as UML aggregation, but
    confusingly similar. https://en.cppreference.com/w/cpp/language/aggregate_initialization
    https://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special
    https://softwareengineering.stackexchange.com/questions/255973/c-association-aggregation-and-composition
    https://stackoverflow.com/questions/885937/what-is-the-difference-between-association-aggregation-and-composition
    https://www.youtube.com/watch?v=B46RqPYhEys
    https://www.learncpp.com/cpp-tutorial/aggregation/
    //Base_class * 				composed_member_this 	{nullptr};  	// todo:?? or is this an aggregate?
    //Uptr 				composed_member_this_u 	{nullptr};
    //std::vector<Base_class *>	composed_members_this_v 	{nullptr};  // todo:?? put nulls in all members?
    //Uptr_v				composed_members_this_vu 	{nullptr};  // todo:?? put nulls in all members?
    */
public: // *** Things that MUST be public in general
    // Base_class() {};     			                            // Default contructor  TODO??: Do constructors have an implicit/hidden this? todo:
    Base_class () = default;                                        // TODO??: Does this and similar lines defeat other default member functions?
    // Base_class() = delete;
    // Base_class() = 0;
    Base_class (Base_class const & rhs)          : i_{rhs.i_} { i_ = rhs.i_; };     // Copy constructor  // Must be Ref and const.
    Base_class (Base_class const volatile & rhs) : i_{rhs.i_} { i_ = rhs.i_; };     // Copy constructor  // Must be Ref and const.
    Base_class (Base_class const &&rhs)          : i_{rhs.i_} { i_ = rhs.i_; };     // Move constructor  // Must be value acting as an Rvalue?

    ~Base_class () {};                                                 // Destructor default TODO:?? Are more specific destructors generally used?

    Base_class (int & i)            : i_{i} {};                   // Copy constuctor
    Base_class (int & i, int & i2)  : i_{i}, i_const_{42} {}  // ??Specialized constuctor for int using initializer list. i_const may be inited here. todo: when can we set it?? what order is respected??
    Base_class (int && i)           : i_{i} {};                   // Move constuctor


    // Conversion operators & and * // TODO??: YES they exist.  But how they work again?
    // https://github.com/cppmsg/cpp_by_example/blob/master/andrei_mapping_integral_constants_to_types/main.cpp

    // Assignment?? operator
    Base_class &
    operator= (Base_class const &rhs)  {  // Copy assignment
        i_                    = rhs.i_;
        s_                    = rhs.s_;
        vvi_                   = rhs.vvi_;
        vvs_                  = rhs.vvs_;
        //composed_member_this = composed_member_this;
        return *this;
    };
    Base_class
    operator= (Base_class rhs) {  // BAD Copy assignment
        return *this;
    };
    Base_class
    operator= (int const & rhs) {
        i_ = rhs;
        return false;
    }; // copy assignment - partial  // todo:?? return what, check all operators!

    Base_class
    operator+= (Base_class &rhs) {
        i_ + rhs.i_;
        return *this;
    }; // copy assignment - partial  // todo:?? return what?
    Base_class
    operator+= (int &rhs) {
        i_ + rhs;
        return *this;
    }; // copy assignment - partial  // todo:?? return what?
    Base_class operator+ (Base_class &rhs){ return rhs;};  // TODO??
    Base_class
    operator*= (Base_class &rhs) {
        i_ + rhs.i_;
        return *this;
    }; // copy assignment - partial  // todo:?? return what?

    // *** Unary operators *** TODO??: are there more??
    void  operator!(){};                        // todo:?? pre-fix unary
    //auto  operator!(Base_class &rhs){};                        // todo:?? pre-fix unary
    //Base_class  operator!(Base_class &rhs){};                        // todo:?? pre-fix unary
    Base_class  operator++ (int rhs){};               // pre-fix unary??
    //Base_class &operator++ (int rhs){};               // TODO??: post-fix unary??

    Base_class operator&= (Base_class rhs){};
    Base_class operator& (Base_class rhs){};
    Base_class operator&& (Base_class rhs){}; // todo: What is this even?

    bool operator<= (Base_class const &){};         // TODO??: What about spaceship operator?
    bool operator>= (Base_class const &){};         // TODO??: What about spaceship operator?
    bool operator!= (Base_class const &){};         // TODO??: What about spaceship operator?

    size_t size (){}; // todo: add nothrow, final
    void   clear (){};
    void   reset (){};
    void   capacity (){};

    void operator<< (Base_class rhs){}; // todo:?? bitshift
    void operator>> (Base_class &rhs){};
    void operator() (Base_class &rhs){};
    //void * operator new (){};

    // *** Setters and getters ***
    // *** Ordinary Member Functions ***
    //void   f () {};
    auto   f () & {};                               // TODO??: what is this?
    void   f () && {};                               // TODO??: what is this?

    // struct stat st; 			//todo:?? elaborated type specifier example  eg: struct My_type my_var, where struct is needed.
};

int Base_class::i_static_ = 77;

//    void operator <=>( Base_class const &,  Base_class const &) {};

std::ostream &operator<< (std::ostream &os, Base_class &rhs){ return os; }; // todo:?? make this work for more that <char>, the ostream typedef.
// std::basic_ostream<char, std::char_traits<char>> & operator<<( std::basic_ostream<char, std::char_traits<char>> & os,       C &
// rhs) {};  	// todo:?? more template parameters? std::basic_ostream<char, std::char_traits<char>> & operator<<(
// std::basic_ostream<char, std::char_traits<char>> & os, const C & rhs) {};  	// todo:?? more template parameters?

int
main (int argc, char *arv[]) {
    string my_arv{ *arv };
    cout << "~~~ argc, argv:" << argc << "," << my_arv << "." << endl;
    cin.exceptions (std::istream::failbit);
    Detail::crash_signals_register ();
    // struct stat st; // todo:?? elaborated type specifier example  eg: struct My_type my_var, where struct is needed.
    Base_class my_c_var;
    Base_class my_c_var2{ 323 };
    //my_c_var2.i_static_ = 123;

    cout << "###" << endl;
    return EXIT_SUCCESS;
};
