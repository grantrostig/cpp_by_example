//#pragma once  // use in .h, not here LOL

//#include <bits/stdc++.h>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string_view>

/// define if asserts are NOT to be checked.  Put in *.h file not *.CPP
//#define 	NDEBUG
/// define I'm Debugging LT.  Put in *.h file not *.CPP
//#define  	GR_DEBUG
//#ifdef   	GR_DEBUG
//#endif  # GR_DEBUG

#define LOGGER_( msg )   using loc = std::source_location;std::cerr<<"["<<loc::current().file_name()<<':'<<loc::current().line()<<','<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<".\n";
#define LOGGER2( msg, x )using loc = std::source_location;std::cerr<<"["<<loc::current().file_name()<<':'<<loc::current().line()<<','<<loc::current().column()<<"]`"<<loc::current().function_name()<<"`:" <<#msg<<",{"<<x<<"}.\n";

using std::endl, std::cin, std::cout, std::cerr, std::string;
using namespace std::string_literals;

int main() {
//    int i {};
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-value"  // todo?: is this the best way to do this, find other occurences in code to fix?
    int j {};
#pragma GCC diagnostic pop

    [[maybe_unused]] int k {};

    assert( false && "Stopping here to test it.");

    cout << "###" << endl;
    return 0;
}
