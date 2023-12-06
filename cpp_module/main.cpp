/** copyright (c) Grant Rostig, grantrostig.com, Boost 1.0 license
    NOT PRODUCTION QUALITY CODE, just shows learning/teaching example, not real programming, don't copy this style, just playing around
   Copyright Grant Rostig 2015 - 2023. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
   Reminder of usefull resources:
   https://coliru.stacked-crooked.com/
   https://godbolt.org/
   https://cppinsights.io/
   https://Wandbox.org
   https://arnemertz.github.io/online-compilers/
   [[maybe_unused]] int * my_new_var8 = ::new (22,int);
 */
//#include "global_entities.h"
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <csignal>
#include <stacktrace>
#include <source_location>

using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;

import My_module;

int main ( int argc, char* arv[] ) { string my_arv { *arv}; cout << "~~~ argc,argv:"<<argc<<","<<my_arv<<"."<<endl; //crash_signals_register();
    std::string                 STRING_QQQ          {"qqq"};
    std::vector<char>           QQQ                 {STRING_QQQ.begin(),STRING_QQQ.end()};

    cout << ":i*3:" << f(3) << endl;


    cout << "###" << endl;
    return EXIT_SUCCESS;
}
