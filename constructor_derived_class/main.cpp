#include <iostream>
#include <string>
using namespace std;

class Super_class {
public:
    int a {-99};
    std::string s  	{"orig"};
    Super_class ()  {
        cout << "super_class()\n";
    }
    Super_class (int a_, std::string s_): a(a_), s(s_) {
        cout << "super_class( int, string)\n";
    }  // TODO why can't this be decalared virtual?
    // Super_class (int a_ ,string s_): a(a_), s(s_) {}
    // virtual ~Super_class() {}
};

class Sub_class : Super_class {
public:
    double c;
//    Sub_class( double c_ ): c(c_) {
//        Super_class ( 2, "Sub_class" );
//        Super_class { 2, "Sub_class" };
//    }
    Sub_class( int a_, string s_, double c_ ): c(c_) {
        a = a_;
        s = s_;
        cout << "a: " << a << "s: "<< s << endl;
    }
    //Sub_class( Super_class sc, double c_ ): c(c_) {
        //cout << "a: " << sc.a << "s: "<< sc.s << endl;
        // Super_class { sc };
        //this->a = 42;
        //s= "in code.";
    //}
};

int main()  {

   // Super_class sc1 (1, "super_class" );
   // Super_class sc2 {1, "super_class" };
   // Sub_class sb1 (1, "sub-class", 12);
    Sub_class sb2 {1, "sub-class", 12};
   // Super_class my_temp { 1, "temp"};
   // Sub_class   junk    { my_temp, 1.2 };

    cout << "###" << endl;
    return 0;
}
