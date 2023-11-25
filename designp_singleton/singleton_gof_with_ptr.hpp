// cppmsg.com Boost 1.0 license.
// see: GOF 1995-SS 1.Singleton; Vlissides 1998-ch2,ch3; Larman 2005-SS 26.5; Robert Martin 2002-Singleton and Monstate; Headington 1996-SS2.7 p79; Cline 1999-ch16-?;
#pragma once
#include <bits/stdc++.h>
using namespace std;
/*  struct Row {
    int     ri       {99};
    string  rs       {"NULL"}; };
struct Only_one_of_UDT1 {
    int     i       {98};
    string  s       {"NULL"};
    Row     row     {};};  // should get inited values from type
struct Only_one_of_UDT2 {
    int     i       {98};
    string  s       {"NULL"};
    Row     row     {};};  // should get inited values from type */

/** Problems with approach #1 "ensuring a unique instance" according to some source that we don't recall at the moment :(
    a) More than one instance of a static object can be declared and they both access the same Singleton data instance!  How exactly?  TODO??:
    b) Static init time is too early if Singleton owns variable values known later during the run.  TODO??:
    c) Constructors are called at unknown order, so Singletons can't depend on each other.  Is this same as reference each other?  TODO??:
    gr1) No inheritance to create other unique types, so no code reuse if multiple Singletons are required? */
class Singleton_gof_with_ptr {
private:    static  Singleton_gof_with_ptr * _instance;
protected:          Singleton_gof_with_ptr()                                                noexcept    =default;
                    ~Singleton_gof_with_ptr()                                               noexcept    =default;
           explicit Singleton_gof_with_ptr(Singleton_gof_with_ptr const &   )                           =delete;
           explicit Singleton_gof_with_ptr(Singleton_gof_with_ptr       &&  )                           =delete;
                    Singleton_gof_with_ptr & operator=( Singleton_gof_with_ptr const &  )   noexcept    =delete;
                    Singleton_gof_with_ptr & operator=( Singleton_gof_with_ptr       && )   noexcept    =delete;
public:     int     _my_int {99};                               // could be protected by a getter.
            static  Singleton_gof_with_ptr * instance();
};
Singleton_gof_with_ptr * Singleton_gof_with_ptr::_instance {nullptr};
Singleton_gof_with_ptr * Singleton_gof_with_ptr::instance() {   // TODO??: this is NOT thread safe?  How would we do that with atomics, or mutex or with std::call_once?
    if ( nullptr == _instance) {
        _instance = new Singleton_gof_with_ptr;                 // Lazy initialization, on heap
    }
    return _instance;
};
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/** See same problems for Singleton_gof_with_ptr above.  TODO??: is this true?
    TODO??: how does returning a ref reduce flexibility in the use of the Singleton?  Can only be used in one c++ context? No. It is good that it can't be modified since it is const pointer??
    TODO??:NOTE: GOF doesn't mention using a ref, so this is a simple variation presented for discussion. But why didn't GOF? C++ had refs back then too!  grostig */
class Singleton_gof_with_ref {
protected:          Singleton_gof_with_ref()                                                noexcept    =default;
                    ~Singleton_gof_with_ref()                                               noexcept    =default;
           explicit Singleton_gof_with_ref( Singleton_gof_with_ref const &   )                          =delete;
           explicit Singleton_gof_with_ref( Singleton_gof_with_ref       &&  )                          =delete;
                    Singleton_gof_with_ref & operator=( Singleton_gof_with_ref const &  )   noexcept    =delete;
                    Singleton_gof_with_ref & operator=( Singleton_gof_with_ref       && )   noexcept    =delete;
public:     int     _my_int {89};                               // could be protected by a getter.
            static  Singleton_gof_with_ref & instance();
};
Singleton_gof_with_ref & Singleton_gof_with_ref::instance() {   // TODO??: since C++11, since this is a static function it is atomic??, thread safe??
    static Singleton_gof_with_ref  _instance {};                // NOT Lazy initialization, NOT on heap.
    return _instance;
};
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void test_singleton_gof_with_ptr() {
    cout<< "START test_Singleton_gof_with_ptr()" << endl;
    Singleton_gof_with_ptr *    my_singleton_ptr1   { Singleton_gof_with_ptr::instance()};
    int                         my_singleton_int    { my_singleton_ptr1->_my_int};
    Singleton_gof_with_ptr *    my_singleton_ptr2   { Singleton_gof_with_ptr::instance()};
    cout << "ptr1:" << my_singleton_ptr1->_my_int << endl ;
    cout << "ptr2:" << my_singleton_ptr2->_my_int << endl ;
    cout << "int from ptr1:" << ++my_singleton_int << endl ;
    cout << "set only int2 to 42." << endl;
    my_singleton_ptr2->_my_int = 42;
    cout << "ptr2:" << my_singleton_ptr2->_my_int << endl ;
    cout << "ptr1:" << my_singleton_ptr1->_my_int << endl ;
    cout << "Both updated, that the point of Singletons." << endl;
    my_singleton_ptr2 = my_singleton_ptr1;  // TODO??: why does this compile? I thought I =delete'd this
    Singleton_gof_with_ptr *    my_singleton_ptr3   { my_singleton_ptr1};
}

void test_singleton_gof_with_ref() {
    cout<< "test_Singleton_gof_with_ref()" << endl;
    Singleton_gof_with_ref &    my_singleton_ref1   { Singleton_gof_with_ref::instance()};
    int                         my_singleton_int    { my_singleton_ref1._my_int};
    Singleton_gof_with_ref &    my_singleton_ref2   { Singleton_gof_with_ref::instance()};
    cout << "ref1:" << my_singleton_ref1._my_int << endl ;
    cout << "ref2:" << my_singleton_ref2._my_int << endl ;
    cout << "int from ref1:" << ++my_singleton_int << endl ;
    cout << "update only int2 to 43." << endl;
    my_singleton_ref2._my_int = 43;
    cout << "ref2:" << my_singleton_ref2._my_int << endl ;
    cout << "ref1:" << my_singleton_ref1._my_int << endl ;
    cout << "Both updated, that the point of Singletons." << endl;
    //my_singleton_ref2 = my_singleton_ref1;  // not allowed and that is the point of ref singletons.

    Singleton_gof_with_ref &    my_singleton_ref3 { my_singleton_ref1 };  // TODO??: why does this compile? I thought I =delete'd this
    cout<< "END   test_Singleton_gof_with_ptr()" << endl;
}
