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
#include <cmath>
#include <gsl/gsl> // sudo dnf install  guidelines-support-library-devel
#include <boost/dynamic_bitset.hpp>
#include <boost/multiprecision/cpp_int.hpp>
//#include<dlib/numeric_constants.h>
//#include "global_entities.h"
#include <bitset>
#include <bit>
#include <cstring>
#include <gsl/gsl> // sudo dnf install  guidelines-support-library-devel
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
#include <vector>

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

//static_assert(std::endian::native != std::endian::little && std::endian::native != std::endian::big , "Memory is mixed endian.");
static_assert(std::endian::native == std::endian::little, "Memory is big endian or mixed.");  // May or may not be relevant or required.
#pragma message("$$ Memory is little endian not mixed, not big.")
//static_assert(std::endian::native == std::endian::big,  "Memory is little endian or mixed.");

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

// TODO: Consider adding this code, which is NOT yet present: version 0.3+ of project: cpp_output_adapter

// All code below is: version 0.6 of project: cpp_concept_print_container_operator_insert
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
 ** Prints contents of a container such as a vector of int's.
    Insertable Concept used by Templated Function definition
    Older version is here for the record:
    template<typename T> std::ostream & operator<<(std::ostream & out, std::vector<T> const & v) { // utility f() to print vectors
    if ( not v.empty() ) {
        out<<'['; std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", ")); out<<"\b\b]";
    }
        return out;
    }
*/
template<typename First, typename Second, typename Third>  // this forward declaration is definitely required to compile
std::ostream & operator<<( std::ostream & out, std::tuple<First,Second,Third> const & my_tuple);

template<class First, class Second>  // Must precede Streamable
std::ostream &
operator<<( std::ostream & out, std::pair<First,Second> const & my_pair) {
    out << "PAIR_MEMBERS["; out << my_pair.first  <<","<< my_pair.second; out << "]"; return out; }

template<class First, class Second, class Third>   // Must precede Streamable
                                                  // TODO??: make it variadic. TODO??: what about something like this: std::copy(my_pair.begin(), my_pair.end(), std::ostream_iterator< typename Container::value_type >( out, ">,<" ));
std::ostream &
operator<<( std::ostream & out, std::tuple<First,Second,Third> const & my_tuple) {
    out << "TUPLE_MEMBERS["; out << std::get<0>(my_tuple) << "," << std::get<1>(my_tuple) << "," << std::get<2>(my_tuple); out << "]"; return out; }  //out << "\b\b\b>]"; out.width(); out << std::setw(0);

template <class T>
concept Streamable
    = requires( std::ostream & out_concept_parameter ) {
          { out_concept_parameter << T {} } -> std::convertible_to<std::ostream &>;   // bool concept_function definition()
      };

template <class Container>
concept Streamable_container
    = requires( std::ostream & out ) {
          requires not std::same_as<std::string, Container>;                          // bool concept_requires requirement()
          requires not std::same_as<std::string_view, Container>;
          requires     Streamable<typename Container::value_type>;
          // OLD WORKING STUFF { out << typename Container::value_type {} } -> std::convertible_to<std::ostream & >; // OR just $ { out << typename Container::value_type {} };
      };

template<Streamable_container SC>    // Function Template with typename concept being restricted to SC in this case. Similar to Value template
std::ostream &
operator<<( std::ostream & out, SC const & sc) { LOGGER_()
    if ( not sc.empty() ) {
        out << "[";                    //out.width(9);  // TODO??: neither work, only space out first element. //out << std::setw(9);  // TODO??: neither work, only space out first element.
        // TODO??: why compile error on?: std::copy(sc.begin(), sc.end(), std::ostream_iterator< typename SC::value_type >( out, ">,<" ));
        for( bool first{true}; auto const &i : sc) { // this works, but why not compile std::copy?
            if(first) { out << "<" << i; first = false; }
            else      { out << ">,<" << i; }
        }
        out << ">]" << " ";             // out.width(); out << std::setw(0);
    } else
        out << "[CONTAINTER IS EMPTY]";
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

namespace Example1 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN std::bitset construction and chunking into 5, 6, 8 bit divided chunks
const std::array<std::string, 3> DICTIONARY_WORDS { "abandon", "ability", "zone" };

void print_bitset(std::bitset<132> bs, int count) {
    for (int i{bs.size()-1}; i >= 0 ; --i ) {
        LOGGER_();
        //cout << "index:" << i <<":";
        //cout << bs[i];
        cout << bs.test(i);
        if ( i !=0 && i%count ==0 ) cout << "'";
    }
    cout << "." << endl;
}

void print_bitset_mem_addrs(std::bitset<132> bs, int count) {
    LOGGER_();
    //auto ptr_msb_begin{&(bs.data())};
    auto ptr_msb_begin{&bs};
    auto ptr_lsb_end{(&bs)+1};
    //auto ptr_lsb_end_plus_one{&(bs.)+1};
    auto ptr_lsb_end_plus_one{&(bs)+1};
    cout << "$$ sizeof bs: "<< sizeof(bs) << endl;
    cout << "$$ &bs: "<< ptr_msb_begin << endl;
    cout << "$$ &bs_lsb: "<< ptr_lsb_end << endl;
    cout << "$$ &bs_lsb_plus_one: "<< ptr_lsb_end_plus_one << endl;
    cout << "$$ &bs.to_string(): "<< bs.to_string() << endl;
    for ( int i{bs.size()-1}; i >= 0 ; --i ) {
        //cout << "index:" << i <<":";
        //cout << bs[i];
        //cout << bs.test(i);
        //if ( i !=0 && i%count ==0 ) cout << "'";
    }
    cout << "." << endl;
}

struct Counter {
    std::array<uint8_t, 32> words_single_char{
                                               '@',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                                    //  std::rand()/ ((RAND_MAX + 1u) / 256),
                                               'A',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'B',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'C',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'Z',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '[',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '\\',
                                                     // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               ']',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '^',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '_',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '\'',
                                                     // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'a',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'b',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'c',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'z',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '{',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '|',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '}',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '~',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W' };
    //  '.' };  // or more chars, they will simply be ignored
};

void test1 () {                     std::cout<< "START                Example1 test1. ++++++++++++++++++++++++"<<std::endl;
    std::srand(std::time(nullptr)); // use current time as seed for random generator

    Counter counter{};
    cout<< "$$ W is bits: 101 0111.\n"; cout<< "$$ Counter.words_.size(): " << counter.words_single_char.size() << ", list: " << counter.words_single_char << endl;

           // *** Construct binary key ***
           // using  Bits6_ut = struct { uint8_t bits6_ :6; };
           // struct Bits6_st          { uint8_t bits6_ :6; };
    std::bitset<132> chars_bits{};

    for ( size_t i{0}; i < chars_bits.size()/6; ++i) {
        if (i != 0 ) chars_bits  <<= 6;
        std::bitset<6>   char_bits6{counter.words_single_char.at(i)};  // TODO??: I cutoff 2 bits, but no warning??
        std::bitset<132> char_bits132{char_bits6.to_ulong()};
        chars_bits |= char_bits132;                                          //chars_bits |= char_bits6;  // TODO??: Strange error message with &bits6_ut ?
        //cout << "$$ Counter, bits: " <<std::setw(3)<< i <<",";
        //print_bitset(chars_bits,6);
    }
    print_bitset_mem_addrs(chars_bits,6);
    print_bitset(chars_bits,6);

           // *** Decode binary key to full words vector ***
    std::vector<std::string> result_full_words{};
    std::bitset<132>         mask_ones_6_of_132{   "111111"};
    std::bitset<132>         mask_ones_7th_of_132{"1000000"};
    std::bitset<132>         chars_bits_temp{chars_bits};

    for (size_t i = 0; i < 22; ++i) {  // get char, fix char, use char to lookup word, add to words

        std::bitset<132> bits_6_of_132{ chars_bits_temp & mask_ones_6_of_132};      // Grab one 6 bit char
        std::bitset<132> bits_7_of_132{ bits_6_of_132   | mask_ones_7th_of_132};    // Add top bit, ie. the 7th to make it US ASCII.

        size_t index {static_cast<size_t>(bits_7_of_132.to_ulong())};                // Convert US ASCII bits to an integer index.  TODO??: Why did I cast this, when apparently not needed.
        size_t index2{                    bits_7_of_132.to_ulong() };                // Convert US ASCII bits to an integer index.
        cout<< index2 << ", ";
        std::string word{DICTIONARY_WORDS.at(index)};
        result_full_words.push_back(word);
        chars_bits_temp >>= 6;
        // print_bitset(bits_6_of_132,8);
        // print_bitset(bits_7_of_132,8);
        // cout << "$$ Loop_i, index, word, size:\n";
        // cout << i <<","<< index<<","<<word << "," << full_words.size()<<endl;
        // print_bitset(chars_bits_temp, 6);
    }
    cout << endl;
    cout << "$$ Words after, size: " << result_full_words.size() <<", "<< result_full_words << endl;
    std::cout<< "END                  Example1 test1. ++++++++++++++++++++++++"<<std::endl;
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace Example2 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN packed struct as alternative to std::bitset example
struct Key_strange_alt { bool wide_bits :132 {1}; };

#pragma pack(1)
struct Key {  // POD plain old data,
    uint8_t  char01 :6 {0x3F};
    uint8_t  char02 :6 {0x3F};  //uint8_t  char02 :6 {0b1111'1111};
    uint8_t  char03 :6 {0x3F};  //uint8_t  char05 :6 {0b0001'1111};
    uint8_t  char04 :6 {0x3F};  //uint8_t  char03 :6 {0b0001'1111};
    uint8_t  char05 :6 {0x3F};  //uint8_t  char04 :6 {0b1111'1111};
    uint8_t  char06 :6 {0x3F};
    uint8_t  char07 :6 {0x3F};
    uint8_t  char08 :6 {0x3F};
    uint8_t  char09 :6 {0x3F};
    uint8_t  char10 :6 {0x3F};
    uint8_t  :4;                // filler for 64 bits
    // int f(){return};  // UDT
};
#pragma pack()
// TODO??: What about alignas() and depreciated: "std::aligned_storage"?
//uint128_t test128;
void test1 () {                     std::cout<< "START                Example2 test1. ++++++++++++++++++++++++"<<std::endl;
    Key key1;  //Key key2{}; Key key3{0};
    cout << "$$ Size Key:"<< sizeof(Key) << endl;
    cout << "$$ Size ull:"<< sizeof(unsigned long long) << endl;
    cout << "$$ Size ld:"<<  sizeof(long double) << endl;
    //cout << "$$ Size :"<<  sizeof(std::float128_t) << endl;

    std::bitset<72> bitset1{ * reinterpret_cast<unsigned long long *>(&key1) };
    std::bitset<72> bitset2{ std::bit_cast<unsigned long long>(key1) };
    //std::bitset<72> bitset3{ * reinterpret_cast<long double *>(&key1) };
    //std::bitset<72> bitset4{ std::bit_cast<long double>(key1) };

    cout << "$$ bitset1: "<< bitset1 << endl;
    cout << "$$ bitset2: "<< bitset2 << endl;

           //cout << bs.to_ullong() << endl;
    cout << "$$ std::hex:" << std::hex << bitset1.to_ullong() << endl;
    cout << "$$ std::hex:" << std::hex << bitset2.to_ullong() << endl;

    cout << std::setbase(6);
    cout << (int)key1.char01 << (int)key1.char02  << (int)key1.char03  << (int)key1.char04  << (int)key1.char05  << (int)key1.char06 <<  endl;
    cout << (int)key1.char07 << (int)key1.char08  << (int)key1.char09  << (int)key1.char10  << endl;

    cout << std::setbase(8);
    //cout << std::setbase(16) << (int)key1.char01 << (int)key1.char02  << (int)key1.char03  << (int)key1.char04  << (int)key1.char05  << (int)key1.char06 <<  endl;
    //cout << std::setbase(16) << (long)key1.char01 << (long)key1.char02  << (long)key1.char03  << (long)key1.char04  << (long)key1.char05  << (long)key1.char06 <<  endl;
    //cout << std::hex        << key1.char01 << key1.char02  << key1.char03  << key1.char04  << key1.char05  << key1.char06 <<  endl;

    std::cout<< "END                  Example2 test1. ++++++++++++++++++++++++"<<std::endl;
}
} // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace Example4 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN boost dynamic_bitset as alternative to std::bitset example
struct Counter {
    std::array<uint8_t, 32> words_single_char{
                                               '@',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                                    //  std::rand()/ ((RAND_MAX + 1u) / 256),
                                               'A',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'B',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'C',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'Z',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '[',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '\\',
                                                     // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               ']',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '^',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '_',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '\'',
                                                     // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'a',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'b',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'c',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'z',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '{',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '|',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '}',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '~',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W' };
    //  '.' };  // or more chars, they will simply be ignored
};
void test1 () {                     std::cout<< "START                Example4 test1. ++++++++++++++++++++++++"<<std::endl;
    // boost::dynamic_bitset<std::byte> chars_bits{7ul};   // TODO??:
    // boost::dynamic_bitset<int8_t>  chars_bits2{7ul};   // TODO??:
    //boost::dynamic_bitset<> chars_bits{7ul};
    // using Bits_6_t = std::bitset<6>;  // not usable.
    boost::dynamic_bitset<uint8_t> chars_bits{7ul}; // 0000111
    boost::dynamic_bitset<uint8_t> chars_bits2{0ul};
    std::bitset<6> bits_6{0b0'000'001};
    uint8_t byte_with_bits_6_of_8 {static_cast<uint8_t>(bits_6.to_ulong())};
    uint8_t byte_with_bits_6_of_8a{0b0'000'001};
    uint8_t byte_with_bits_6_of_8b{0b0'000'011};
    uint8_t byte_with_bits_6_of_8c{0b0'000'101};

    /* chars_bits.at(1) = 1;
    // chars_bits <<= 1;
    // Counter counter{};
    // cout<< "$$ W is bits: 101 0111.\n"; cout<< "$$ Counter.words_.size(): " << counter.words_single_char.size() << ", list: " << counter.words_single_char << endl;
    // cout<< "$$ char_bits.size(): " << chars_bits.size() <<", content: "<< chars_bits << endl;
    // cout<< "$$ sizeof(char_bits) in bytes: " << sizeof(chars_bits)<< endl;

     // // *** Construct binary key ***
     // auto junk {chars_bits << counter.words_single_char.at(1)}; cout<< "$$ junk.size(): " << junk.size() <<", content: "<< junk << endl;
     // for ( size_t i{0}; i < counter.words_single_char.size(); ++i) {
     //     if (i != 0 ) chars_bits  <<= 1;
     //     chars_bits <<= 1;
     //     //chars_bits <<= counter.words_single_char.at(1);
     //     cout<< "$$ in loop, char_bits.size(): " << chars_bits.size() <<", content:"<< chars_bits <<":"<< endl;
     // } */
    //chars_bits.append(bits_6_t);

    chars_bits2.append(byte_with_bits_6_of_8a);
    chars_bits2.append(byte_with_bits_6_of_8b);
    chars_bits2.append(byte_with_bits_6_of_8c);
    cout << "$$ byte,bits:" << (int)byte_with_bits_6_of_8 <<";"<< chars_bits2 << endl;

           //std::reverse(); //for ( 1;; ) { ; };
    boost::dynamic_bitset<uint8_t> chars_bits_transformed{8*3};
    do {
        size_t i{chars_bits2.size()};
        if (i != 0 ) chars_bits_transformed  <<= 1;
        chars_bits_transformed.set(0, chars_bits2.at(i-1));
        chars_bits_transformed <<= 1;
        //chars_bits_transformed |= chars_bits2[i-1];
        chars_bits2.pop_back();
    }
    while ( chars_bits2.size() > 0 );

    cout << "$$ bits_transformed:" << chars_bits_transformed << endl;

           // *** Decode binary key to full words vector ***

    std::cout<< "END                  Example4 test1. ++++++++++++++++++++++++"<<std::endl;
}
} // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace Example5 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN boost multiprecision as alternative to std::bitset example
struct Counter {
    std::array<uint8_t, 32> words_single_char{
                                               '@',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                                    //  std::rand()/ ((RAND_MAX + 1u) / 256),
                                               'A',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'B',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'C',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'Z',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '[',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '\\',
                                                     // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               ']',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '^',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '_',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '\'',
                                                     // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'a',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'b',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'c',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'z',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '{',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '|',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '}',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               '~',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W',
                                                    // static_cast<uint8_t> ( std::rand()/ ((RAND_MAX + 1u) / 256)),
                                               'W' };
    //  '.' };  // or more chars, they will simply be ignored
};
void test1 () {                     std::cout<< "START                Example4 test1. ++++++++++++++++++++++++"<<std::endl;
    // boost::dynamic_bitset<std::byte> chars_bits{7ul};   // TODO??:
    // boost::dynamic_bitset<int8_t>  chars_bits2{7ul};   // TODO??:
    //boost::dynamic_bitset<> chars_bits{7ul};
    // using Bits_6_t = std::bitset<6>;  // not usable.
    boost::dynamic_bitset<uint8_t> chars_bits{7ul}; // 0000111
    boost::dynamic_bitset<uint8_t> chars_bits2{0ul};
    std::bitset<6> bits_6{0b0'000'001};
    uint8_t byte_with_bits_6_of_8 {static_cast<uint8_t>(bits_6.to_ulong())};
    uint8_t byte_with_bits_6_of_8a{0b0'000'001};
    uint8_t byte_with_bits_6_of_8b{0b0'000'011};
    uint8_t byte_with_bits_6_of_8c{0b0'000'101};

    /* chars_bits.at(1) = 1;
    // chars_bits <<= 1;
    // Counter counter{};
    // cout<< "$$ W is bits: 101 0111.\n"; cout<< "$$ Counter.words_.size(): " << counter.words_single_char.size() << ", list: " << counter.words_single_char << endl;
    // cout<< "$$ char_bits.size(): " << chars_bits.size() <<", content: "<< chars_bits << endl;
    // cout<< "$$ sizeof(char_bits) in bytes: " << sizeof(chars_bits)<< endl;

     // // *** Construct binary key ***
     // auto junk {chars_bits << counter.words_single_char.at(1)}; cout<< "$$ junk.size(): " << junk.size() <<", content: "<< junk << endl;
     // for ( size_t i{0}; i < counter.words_single_char.size(); ++i) {
     //     if (i != 0 ) chars_bits  <<= 1;
     //     chars_bits <<= 1;
     //     //chars_bits <<= counter.words_single_char.at(1);
     //     cout<< "$$ in loop, char_bits.size(): " << chars_bits.size() <<", content:"<< chars_bits <<":"<< endl;
     // } */
    //chars_bits.append(bits_6_t);
    chars_bits2.append(byte_with_bits_6_of_8a);
    chars_bits2.append(byte_with_bits_6_of_8b);
    chars_bits2.append(byte_with_bits_6_of_8c);
    cout << "$$ byte,bits:" << (int)byte_with_bits_6_of_8 <<";"<< chars_bits2 << endl;

           //std::reverse(); //for ( 1;; ) { ; };
    boost::dynamic_bitset<uint8_t> chars_bits_transformed{8*3};
    do {
        size_t i{chars_bits2.size()};
        if (i != 0 ) chars_bits_transformed  <<= 1;
        chars_bits_transformed.set(0, chars_bits2.at(i-1));
        chars_bits_transformed <<= 1;
        //chars_bits_transformed |= chars_bits2[i-1];
        chars_bits2.pop_back();
    }
    while ( chars_bits2.size() > 0 );

    cout << "$$ bits_transformed:" << chars_bits_transformed << endl;

           // *** Decode binary key to full words vector ***

    std::cout<< "END                  Example4 test1. ++++++++++++++++++++++++"<<std::endl;
}
} // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

int main(int argc, char const * arv[]) { string my_arv{*arv}; cout << "~~~ argc, argv:"<<argc<<","<<my_arv<<"."<<endl; cin.exceptions( std::istream::failbit); Detail::crash_signals_register();
    std::string                 STRING_QQQ          {"qqq"};
    std::vector<char>           QQQ                 {STRING_QQQ.begin(),STRING_QQQ.end()};
    Example1::test1 ();
    Example2::test1();
    //Example3::test1();
    Example4::test1();
    Example5::test1();
    cout << "###" << endl;
    return EXIT_SUCCESS;
}
