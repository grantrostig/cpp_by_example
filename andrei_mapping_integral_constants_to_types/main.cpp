/** Explores: Modern C++ Design -- Andrei Alexandrescu
    SS 2.4 Mapping Integral Constants to Types

    Intent: Template specialization criteria??
            Strong parameter types??
            Conversion operators??
    Uses:   ??
    Related Patterns: ??
    Inspired by: (and possible copyright and LICENSE)
    -Modern C++ Design -- Andrei Alexandrescu
    ---------------------------------------------
    Edited by: Grant Rostig 2023
        Any additional beyond those that inspired this code is:
        Copyright (c) Grant Rostig, grantrostig.com 2023. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

    NOT PRODUCTION QUALITY CODE, it is missing proper rigor, just shows learning/teaching example, not real programming, don't copy_paste this.
 */
//#include <bits/stdc++.h>
//#include <cassert>
#include <iostream>
//#include <memory>
#include <string>
#include <array>
#include <iostream>
//#include <iomanip>
//#include <source_location>
#include <boost/functional/factory.hpp>
#include <boost/functional/value_factory.hpp>
// Some crude logging that prints source location, where X prints a variable,
// and R adds \n\r (which is usefull when tty in in RAW or CBREAK mode. Requires
// C++20.
#define LOGGER_(msg)                                                           \
  using loc = std::source_location;                                            \
  std::cout.flush();                                                           \
  std::cerr.flush();                                                           \
  std::cerr << "[" << loc::current().file_name() << ':' << std::setw(4)        \
            << loc::current().line() << ',' << std::setw(3)                    \
            << loc::current().column() << "]`"                                 \
            << loc::current().function_name() << "`:" << #msg << "." << endl;  \
  cout.flush();                                                                \
  cerr.flush();
#define LOGGER_R( msg )  using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<           ".\r\n"<<endl;cout.flush();cerr.flush();
#define LOGGERX(  msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<    "["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}."    <<endl;cout.flush();cerr.flush();
#define LOGGERXR( msg, x)using loc = std::source_location;std::cout.flush();std::cerr.flush();std::cerr<<"\r\n["<<loc::current().file_name()<<':'<<std::setw(4)<<loc::current().line()<<','<<std::setw(3)<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".:{"<<x<<"}.\r\n"<<endl;cout.flush();cerr.flush();
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;

enum : int { category_a, category_b };
enum class   Category : long { a, b };


template <int V>                    // TODO??: Non-type template parameter.
struct Int2Type {
#if 1
    enum {
        value = V
    };
#else
    enum class my_required_name {
        value_c = V
    };
#endif
};

constexpr Int2Type<1> my_int2type1{};
Int2Type<2>       my_int2type2{};
static_assert( not std::is_same_v< decltype( my_int2type1 ), decltype(  my_int2type2 ) >);
//int i_it{my_int2type1};
//Int2Type<"hello"> my_int2typeHello{};

template <class T, int V>
struct SomeType2Type {              // todo??: Forgot comment meaning: new approach: const expr
#if 0
    enum how_am_i_used {            // todo??: How_am_i_used?
        value = V
    };
#else
        enum class my_required_name : char {
        value_c = V
    };
#endif
};


int main(int argc, char *argv[]) { string my_argv{*argv}; cerr << "~~~ argc,argv:" << argc << "," << my_argv << "." << endl; //crash_signals_register(); //cin.exceptions( std::istream::failbit);//throw on fail of cin.
    std::array<int,10> my_array1();     // TODO??: Non-type template parameter?  Size is known at compile time. What is the size is this array?
    std::array<int,11> my_array2();
    constexpr int my_int1{55};

    //int                         i_st{sometype2type1};
    //SomeType2Type<float,3.0>    sometype2type3f{};
    SomeType2Type<float,4>      sometype2type4f{};
    SomeType2Type<float,4>      sometype2type4fb();
    SomeType2Type<float,4>      sometype2type4fd;
    char my_char {'\xFF'};
    //static SomeType2Type<float,4>      sometype2type4fc;
    SomeType2Type<int,1>        sometype2type1{};
    SomeType2Type<float,1>        sometype2type2{};
    static_assert( not std::is_same_v< decltype( sometype2type1 ), decltype( sometype2type2 ) >);
    SomeType2Type<string,3>     sometype2typeString{};
    //SomeType2Type<string,"hello">  sometype2typeStringHello{};

    //cout<< sizeof( sometype2type4fd ) << "," << &sometype2type4fd << "," << (size_t)*reinterpret_cast<char *>( &sometype2type4fd ) << "," << /* (size_t)*reinterpret_cast<char>( sometype2type4fd ) <<*/ endl;

    struct no_space {
        [[no_unique_address]]SomeType2Type<int,44> i44;   //
        [[no_unique_address]]SomeType2Type<int,44> i45;
    };
    cout << "sizeof( no_space ):" << sizeof( no_space ) << endl;

    int some_int{32};
    switch (some_int) {
    case 8 :
    case std::to_underlying(SomeType2Type<int,11>::my_required_name::value_c) :
    //case SomeType2Type<int,4>::value:
    //case SomeType2Type<int,11>::my_required_name::value_c :
    //case my_int2type1::some_int :
    //case sometype2type1 :

    //case my_float1 :
    //case (const int) my_float2 :
    //case reinterpret_cast<int>( my_float2 ) :
    //case const_cast<int>( my_float2 ) :
    //case static_cast<int>( my_float2 ) :
    default:
        break;
    }

    cout << "###" << endl;
    return EXIT_SUCCESS;
}
