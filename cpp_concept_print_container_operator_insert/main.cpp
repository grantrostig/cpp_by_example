/** NOT PRODUCTION QUALITY CODE, just shows learning/teaching example, not real programming, don't copy this style, just playing around
   Copyright Grant Rostig 2015 - 2023. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
   Reminder of usefull resources:
   https://coliru.stacked-crooked.com/
   https://godbolt.org/
   https://cppinsights.io/
   https://Wandbox.org
   https://arnemertz.github.io/online-compilers/
    //[[maybe_unused]] int * my_new_var8 = ::new (22,int);
 */
#include <bits/stdc++.h>
//#include <iostream>
//#include <csignal>
//#include <stacktrace>
//#include <source_location>
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;

/* Another approach to print, from: Josuttis
template <class T>
inline void PRINT_ELEMENTS (const T& coll, string optcstr="") {
    typename T::const_iterator pos;
    std::cout << optcstr;
    for (pos=coll.begin(); pos!=coll.end(); ++pos)
        std::cout << *pos << ' ';
    std::cout << std::endl;
}

/// Other stuff

/// Requires that a type has insertion operator
/// Concept definition - used by a template below.
template<typename Container>
concept Insertable = requires
( std::ostream & out ) {
    requires not std::same_as<std::string, Container>;  // OR $ std::is_same <std::string, Container>::value OR std::is_same_v<std::string, Container>;
    {
        out << typename Container::value_type {}
    } -> std::convertible_to<std::ostream & >;          // OR just $ { out << typename Container::value_type {} };
};

/// Prints contents of a container such as a vector of int's.
/// Concept used by Templated Function definition
template<typename Container>                            // $ template<insertable Container> OR the next 2 lines currently being used.
    requires Insertable<Container>
std::ostream &
operator<<( std::ostream & out, Container const & c) {
    if ( not c.empty()) {
        out << "Lenght:"<<c.size()<<",";
        out << "[";   //out.width(9);  // TODO??: neither work, only space out first element. //out << std::setw(9);  // TODO??: neither work, only space out first element.
        std::copy(c.begin(), c.end(), std::ostream_iterator< typename Container::value_type >( out, "," ));  // TODO??: How can we apply std::quoted before printing? Would this only help printing strings? What about printing control chars in a unsigned char?
        out << "\b]"; out.width(); out << std::setw(0);
    } else out << "[CONTAINTER IS EMPTY]";
    return out;
}

///  Concept using Function Explicit instantiations that are required to generate code for linker. TODO??: What is this again??
///  TODO??: is the only used if definition is in *.cpp file?
///  https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
///  https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
//template std::ostream & operator<<( std::ostream & , std::vector<std::string> const & );
/// Concept using Function Explicit instantiations that are required to generate code for linker.
//template std::ostream & operator<<( std::ostream & , std::deque<int>          const & );
*/

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

//static_assert(std::endian::native != std::endian::little && std::endian::native != std::endian::big , "Memory is mixed endian.");
static_assert(std::endian::native == std::endian::little, "Memory is big endian or mixed.");  // May or may not be relevant or required.
#pragma message("$$ Memory is little endian.")
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

/* Requires that a type has insertion operator
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

/* Prints contents of a container such as a vector of int's.
    Insertable Concept used by Templated Function definition.
    Older version is here for the record:
        template<class T> std::ostream & operator<<(std::ostream & out, std::vector<T> const & v) { // utility f() to print vectors
        if ( not v.empty() ) {
            out<<'['; std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", ")); out<<"\b\b]";
        }
            return out;
        }
*/

/* template<class Container>                        //template<insertable Container>        // OR these 2 lines currently being used.
    requires Insertable<Container>
std::ostream &
operator<<( std::ostream & out, Container const & c) {
    if ( not c.empty()) {
        out << "[<";   //out.width(9);  // TODO??: neither work, only space out first element. //out << std::setw(9);  // TODO??: neither work, only space out first element.
        std::copy(c.begin(), c.end(), std::ostream_iterator< typename Container::value_type >( out, ">,<" ));
        //out << "\b\b\b>]"; out.width(); out << std::setw(0);
        out << "\b\b\b>]" << " ";
    } else out << "[CONTAINTER IS EMPTY]";
    return out;
} */

//template <class T, class U>
//concept Streamable_pair =  Streamable<T> && Streamable<U>;

// concept Streamable = requires( std::ostream & out ) {

// *** We handle ostreams ***
template <class T>
concept Streamable
    = requires( std::ostream & out_concept_parameter, int my_unused_int )
{
// bool concept_function definition()
    {
        out_concept_parameter << T {}
    }
        -> std::convertible_to<std::ostream &> ; // TODO?: Correct way to show instance of a template type.  // TODO:?? REMOVE OLD idea OR just $ { out << typename Container::value_type {} };
};

template <class Container>
concept Streamable_container
    = requires( std::ostream & out )
{
// bool concept_requires requirement()
    requires not std::same_as<std::string, Container>;
// bool concept_requires requirement()
    requires     Streamable<typename Container::value_type>;
    // OLD WORKING STUFF { out << typename Container::value_type {} } -> std::convertible_to<std::ostream & >; // OR just $ { out << typename Container::value_type {} };
};

template<Streamable_container SC>    // Function Template with Typename Concept Restricted. // Similar to Value template
std::ostream &
operator<<( std::ostream & out, SC const & sc) {
    if ( not sc.empty() ) {
        out << "[<";   //out.width(9);  // TODO??: neither work, only space out first element. //out << std::setw(9);  // TODO??: neither work, only space out first element.
        std::copy(sc.begin(), sc.end(), std::ostream_iterator< typename SC::value_type >( out, ">,<" ));
        //out << "\b\b\b>]"; out.width(); out << std::setw(0);
        out << "\b\b\b>]" << " ";
    } else
        out << "[CONTAINTER IS EMPTY]";
    return out;
}

// *** We handle tuples ***
template<class First, class Second>
std::ostream &
operator<<( std::ostream & out, std::pair<First,Second> const & my_pair) {
    out << "PAIR_MEMBER[";
    out << my_pair.first  <<",";
    out << my_pair.second <<",";
                                  //std::copy(my_pair.begin(), my_pair.end(), std::ostream_iterator< typename Container::value_type >( out, ">,<" ));
                                  //out << "\b\b\b>]"; out.width(); out << std::setw(0);
    out << "]" << " ";            // TODO??:  out << "\b\b\b>]" << POP BACK IDEA << " ";
                              // TODO:? if ( not c.empty()) {
                              //} else out << "[CONTAINTER IS EMPTY]";
    return out;
}

template<class First, class Second, class Third>  // TODO??: make it variadic.
std::ostream &
operator<<( std::ostream & out, std::tuple<First,Second,Third> const & my_tuple) {
    out << "TUPLE_MEMBER[";
    out << std::get<0>(my_tuple)  <<",";
    out << std::get<1>(my_tuple)  <<",";
    out << std::get<2>(my_tuple)  <<",";
                                         //std::copy(my_pair.begin(), my_pair.end(), std::ostream_iterator< typename Container::value_type >( out, ">,<" ));
                                         //out << "\b\b\b>]"; out.width(); out << std::setw(0);
    out << "\b\b\b>]" << " ";
                              // TODO:? if ( not c.empty()) {
                              //} else out << "[CONTAINTER IS EMPTY]";
    return out;
}

int main ( int argc, char* arv[] ) { string my_arv { *arv}; cout << "~~~ argc,argv:"<<argc<<","<<my_arv<<"."<<endl;
    std::pair<int,float>              my_pair  {2, 3.3f};
    std::tuple<int,float,std::string> my_tuple {2, 3.3f, "threethreethree"s};
    //std::map<int, my_special_pair> my_map {};

    cout << my_pair.first <<", " << my_pair.second << endl;
    cout << std::get<0>(my_tuple) <<"," << std::get<1>(my_tuple) << "," << std::get<2>(my_tuple) << endl;
    cout << my_pair << endl;
    cout << my_tuple << endl;
    cout << "###" << endl;
    return EXIT_SUCCESS;
}
