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
        std::copy(c.begin(), c.end(), std::ostream_iterator< typename Container::value_type >( out, "," ));
        //out << "\b]"; out.width(); out << std::setw(0);
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

int main ( int argc, char* arv[] ) { string my_arv { *arv}; cout << "~~~ argc,argv:"<<argc<<","<<my_arv<<"."<<endl;
    std::string                 STRING_QQQ          {"qqq"};
    std::vector<char>           QQQ                 {STRING_QQQ.begin(),STRING_QQQ.end()};
    cout << ":QQQ is:" << QQQ << endl;
    cout << "###" << endl;
    return EXIT_SUCCESS;
}
