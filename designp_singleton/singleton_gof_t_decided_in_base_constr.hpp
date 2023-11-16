// cppmsg.com Boost 1.0 license.
// see: GOF 1995-SS 1.Singleton; Vlissides 1998-ch2,ch3; Larman 2005-SS 26.5; Robert Martin 2002-Singleton and Monstate; Headington 1996-SS2.7 p79; Cline 1999-ch16-?;
#pragma once
#include <bits/stdc++.h>
using namespace std;

/// We did not include all the code detail of other examples.

class Singleton_gof_t_decided_in_base_constr {  // Called Maze_factory in GOF book p132
            static  Singleton_gof_t_decided_in_base_constr * _instance;
protected:          Singleton_gof_t_decided_in_base_constr()            =default;
public:     static  Singleton_gof_t_decided_in_base_constr * instance() noexcept;
            int     _my_int  {99};
};

Singleton_gof_t_decided_in_base_constr * Singleton_gof_t_decided_in_base_constr::_instance {nullptr};

class S_derived_enchanted final : public Singleton_gof_t_decided_in_base_constr {
public: std::string str         {"INIT"};
};

class S_derived_bombed    final : public Singleton_gof_t_decided_in_base_constr {
public: float       real_number {999.42};
};

Singleton_gof_t_decided_in_base_constr *  Singleton_gof_t_decided_in_base_constr::instance() noexcept {
    if ( nullptr == _instance ) {
        std::string decider_of_s_type = getenv("SHELL");  // OR this: std::string decider_of_s_type = getenv("USER");
        if (        "/bin/bash" == decider_of_s_type ) {   // Lazy initialization, on heap
            _instance = new S_derived_enchanted;
        } else if ( "/bin/sh"   == decider_of_s_type ) {
            _instance = new S_derived_bombed;
        } else {
            _instance = new Singleton_gof_t_decided_in_base_constr;  // TODO??: not sure why GOF has this option since it does nothing!, but I suppose the base Singleton could do something.
        }
    }
    return _instance;
}

void test_singleton_gof_t_decided_in_base_constr() {
    cout<< "BEGIN test_singleton_gof_t_decided_in_base_constr()"<<endl;
    Singleton_gof_t_decided_in_base_constr *    my_singleton1       { Singleton_gof_t_decided_in_base_constr::instance()};
    int                                         my_singleton1_int   { my_singleton1->_my_int};
    Singleton_gof_t_decided_in_base_constr *    my_singleton2       { Singleton_gof_t_decided_in_base_constr::instance()};
    cout << "ptr1:" << my_singleton1->_my_int << endl ;
    cout << "ptr2:" << my_singleton2->_my_int << endl ;
    cout << "int from ptr1:" << ++my_singleton1_int << endl ;
    cout << "set only int2 to 42." << endl;
    my_singleton2->_my_int = 42;
    cout << "ptr2:" << my_singleton2->_my_int << endl ;
    cout << "ptr1:" << my_singleton1->_my_int << endl ;
    cout << "Both updated, that the point of Singletons." << endl;
    cout<< "END   test_singleton_gof_t_decided_in_base_constr()"<<endl;
}
