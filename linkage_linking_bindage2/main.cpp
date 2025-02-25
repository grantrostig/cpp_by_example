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

#include "external_linkage_component.hpp" // For External Linkage
#include "dual_bindage_component.hpp"             // For Dual Bindage
#include "no_linkage_component.cpp"    // For No Linkage - Usually header for namespaces, but for single file demo OK
#include "internal_linkage_component.cpp" // For Internal Linkage - Typically should be compiled separately

#include "global_entities.hpp"
#include "boost_headers.hpp"
#include "cpp_headers.hpp"
#include "math_grostig.hpp"
#include "ostream_joiner_gr.hpp"
#include <boost/dynamic_bitset.hpp>
#include <boost/multiprecision/cpp_int.hpp>
//#include<dlib/numeric_constants.h>
//#include <gsl/gsl>      // sudo dnf install  guidelines-support-library-devel
//#include <bits/stdc++.h>

#include <bit>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
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
using namespace ExternalComponent;
using namespace DualBindage;
using namespace NoLinkageExample;
using namespace InternalComponent;

namespace Detail {  // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN






} // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

int main(int argc, char const * arv[]) {
    string my_arv{*arv}; cout << "$$ ~~~ argc, argv:"<<argc<<","<<my_arv<<"."<<endl;
    cin.exceptions( std::istream::failbit);
    Detail::crash_signals_register();

    //LOGGER_("testing LOGGER_");
    //LOGGERX("testing LOGGER_",42);
    //Example1::test1 ();

    cout << "\n--- External Linkage and External Bindage ---" << endl;
    externalFunction(); // Calling external function (External Linkage)
    cout << "Accessing external variable from main: " << externalVariable << endl; // Accessing external variable (External Linkage)
    ExternalType externalTypeInstance; // Creating instance of ExternalType (External Bindage)
    externalTypeInstance.doExternalWork();

    cout << "\n--- Internal Linkage and Internal Bindage ---" << endl;
    callInternalStuff(); // Calling externally linked function within InternalComponent that uses internal stuff
    // Attempting to access internalFunction() directly from main would cause a compile error - Internal Linkage
    // Attempting to access internalVariable directly from main would also cause a compile error - Internal Linkage
    // InternalType internalTypeInstance; // Creating instance of InternalType would be possible if you include the cpp, but conceptually not how internal linkage is used. Best if usage is contained.

    cout << "\n--- No Linkage ---" << endl;
    demonstrateNoLinkage();


    cout << "\n--- Dual Bindage ---" << endl;
    std::unique_ptr<Shape> circle = createShape("circle");
    if (circle) {
        cout << circle->draw() << endl; // Runtime polymorphism - Dual Bindage in action: Interface is fixed (Shape), implementation is chosen at runtime.
    }
    std::unique_ptr<Shape> square = createShape("square");
    if (square) {
        cout << square->draw() << endl; // Runtime polymorphism again
    }

    cout << "Linkage controls the visibility of names across compilation units (External, Internal, No)." << endl;
    cout << "Bindage (as interpreted here in Lakos context) relates to how types and their implementations are bound or determined:" << endl;
    cout << "  - External Bindage: Types defined in headers, representation known at compile time across units." << endl;
    cout << "  - Internal Bindage: Types whose detailed implementation might be hidden or more tightly bound within a compilation unit (illustrated here conceptually with types defined in .cpp)." << endl;
    cout << "  - Dual Bindage:  Types involving interfaces and implementations where the interface is fixed (external bindage), but the concrete implementation is chosen or resolved at runtime (e.g., via polymorphism)." << endl;

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
