// cppmsg.com Boost 1.0 license.
// see: GOF 1995-SS 1.Singleton; Vlissides 1998-ch2,ch3; Larman 2005-SS 26.5; Robert Martin 2002-Singleton and Monstate; Headington 1996-SS2.7 p79; Cline 1999-ch16-?;
#pragma once
#include <bits/stdc++.h>
using namespace std;

class Singleton_gof_sample_code {  // Called Maze_factory in GOF book p132
            static  Singleton_gof_sample_code* _instance;
protected:          Singleton_gof_sample_code() = default;
public:     static  Singleton_gof_sample_code* Instance() noexcept;
                    int         _my_int  {99};
};
Singleton_gof_sample_code* Singleton_gof_sample_code::_instance {nullptr};

//class S_derived_enchanted;  // TODO??: incomplete size, so foward delaration does not work for new()?  What if I gave it a size? Then I can't add functions to it later/below?
//class S_derived_bombed;     // Is it really this complicated? https://stackoverflow.com/questions/553682/when-can-i-use-a-forward-declaration

class S_derived_enchanted final : public Singleton_gof_sample_code {
public:             std::string str     {"NULL"};
};

class S_derived_bombed    final : public Singleton_gof_sample_code {
public:             float       real_number  {999.42};
};

Singleton_gof_sample_code *  Singleton_gof_sample_code::Instance() noexcept {
    if ( nullptr == _instance ) {
        std::string decider_of_s_type = getenv("SHELL");  // OR this: std::string decider_of_s_type = getenv("USER");
        if ( "/bin/bash" == decider_of_s_type ) {
            _instance = new S_derived_enchanted;
        } else if ( "/bin/sh" == decider_of_s_type ) {
            _instance = new S_derived_bombed;
        } else {
            _instance = new Singleton_gof_sample_code;  // TODO??: not sure why GOF has this option since it does nothing!, but I suppose the base Singleton could do something.
        }
    }
    return _instance;
}

void test_singleton_gof_sample_code() {
    cout<< "test_singleton_gof_sample_code()"<<endl;
    Singleton_gof_sample_code *     my_singleton1   { Singleton_gof_sample_code::Instance()};
    int                             my_singleton1_int    { my_singleton1->_my_int};
    Singleton_gof_sample_code *     my_singleton2   { Singleton_gof_sample_code::Instance()};
    cout << "ptr1:" << my_singleton1->_my_int << endl ;
    cout << "ptr2:" << my_singleton2->_my_int << endl ;
    cout << "int from ptr1:" << ++my_singleton1_int << endl ;
    cout << "set only int2 to 42." << endl;
    my_singleton2->_my_int = 42;
    cout << "ptr2:" << my_singleton2->_my_int << endl ;
    cout << "ptr1:" << my_singleton1->_my_int << endl ;
    cout << "BAD 1 was not updated but shows it was, or is that the point of Singletons?" << endl;
    my_singleton2 = my_singleton1;  // TODO??: why does this compile? I thought I =delete'd this
    Singleton_gof_sample_code *    my_singleton3   { my_singleton1};
}
