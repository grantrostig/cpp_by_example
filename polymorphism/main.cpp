#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Base {
public:
    virtual void f() { cout<< "Base.\n"; };
};

class LastDerived1 : public Base {
public:
  void f() { cout << "1\n"; };  //
};

class Derived2 : public Base {
public:
  virtual void f() { cout << "2\n"; };
};

void show( Base & b) {
    b.f();
}

int main() {
//    Base v1 = LastDerived1();   v1.f();
//	  Base v2 = Derived2(); 		v2.f();
    Derived2 	g1 {};
    Base * 		b_ptr1;

    std::unique_ptr<Base> u_ptr1 { std::make_unique<Base>() };
    std::unique_ptr<Base> u_ptr2 { std::make_unique<Derived2>() };
    std::unique_ptr<Base> u_ptr3 { std::make_unique<LastDerived1>() };

    std::shared_ptr<Base> s_ptr1 { std::make_unique<Base>() };
    std::shared_ptr<Base> s_ptr2 { std::make_unique<Derived2>() };
    std::shared_ptr<Base> s_ptr3 { std::make_unique<LastDerived1>() };
    //s_ptr1.release();

    std::vector< std::shared_ptr<Base> > my_vec { s_ptr1, s_ptr2, s_ptr3};

    for ( auto i = my_vec.begin(); my_vec.end() != i; ++i ) {
       (*i)      ->f();  // (*i).get()->f();
    }

//    s_ptr1->f();

//    b_ptr1 = &g1;
//    b_ptr1->f();

//    show( *b_ptr1 );
//    show( g1 );

    cout << "###" << endl;
    return 0;
}
