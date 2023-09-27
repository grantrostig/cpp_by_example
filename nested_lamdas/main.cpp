//#include <bits/stdc++.h>
#include <functional>
#include <iostream>
using namespace std;

// todo: how exactly is "nested" lambda important here?  sum_fo could be just a function and the same ideas would apply? correct?
int sum_fn (int num1, int num2) { return num1 + num2; };

int main() {
    int my_dummy_int {3}; 										   cout << typeid (my_dummy_int).name() << endl;
    // function object used in all other calls.
    auto sum_fo = [] (int num1, int num2) { return num1 + num2; }; cout << typeid (sum_fo).name() << endl;

    // try calling sum_fo() via a lamda versus bind
    // 1) use lambda to create a function object _fo
    std::function<int(void)> onePlusTwo_fo1 =  		[sum_fo] () { return sum_fo(1,2); }; // todo: alan said this and next are same type, looks false.
    auto 					 onePlusTwo_fo2 =  		[sum_fo] () { return sum_fo(1,2); };
    auto 					 onePlusTwo_fo3 =  		[sum_fo] () { return sum_fn(1,2); };
    //auto 					 onePlusTwo_fo4 =  		[sum_fo] () { return sum_fo(1,2,"junk"); };  // compile error illustrates why lambda has better type checking than std::bind.

    // 2) use bind to create a callable object _co
    auto 					 onePlusTwo_Bind_co1 = 	std::bind( sum_fo ,1,2);
    auto 					 onePlusTwo_Bind_co2 = 	std::bind( sum_fo ,1,2,"junk"); // this complies and runs!?!

    cout << typeid (onePlusTwo_fo1).name() << endl;
    cout << typeid (onePlusTwo_fo2).name() << endl;
    cout << typeid (onePlusTwo_fo3).name() << endl;
    cout << typeid (onePlusTwo_Bind_co1).name() << endl;
    cout << typeid (onePlusTwo_Bind_co2).name() << endl;
    cout << onePlusTwo_fo1()		<<endl;
    cout << onePlusTwo_fo2()		<<endl;
    cout << onePlusTwo_fo3()		<<endl;
    cout << onePlusTwo_Bind_co1()	<<endl;
    //cout << onePlusTwo_Bind_co2()	<<endl;
    // ========================================= 2nd set - todo: not sure of the point of these.
    auto twoPlusTwo_fo = 	 	[sum_fo] () { return sum_fo(2,2); };
    auto twoPlusTwo_Bind_co = 	std::bind(           sum_fo,2,2);
    cout << twoPlusTwo_fo()		<<endl;
    cout << twoPlusTwo_Bind_co()	<<endl;
    return 0;
}
