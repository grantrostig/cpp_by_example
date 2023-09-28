// totally not done yet!! :)
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Row {
    int my_int {99};
    string my_string {"NULL"};
};

class Cpp_static_example {
    // using std::vector:: ;
    static int                  counter_private_static;
    static std::vector< Row >   row_static_data_member;             // init not allowed for static data
public:
    static int                  inta_public_static;
    int                         intb_public_instance_var {};
    string                      my_string {};
    Row                         row_instance_var {};
    Cpp_static_example();
    Cpp_static_example( int );         // init not allowed for static data
};

