#include <iostream>
using namespace std;
// https://stackoverflow.com/questions/51615363/how-to-write-c-getters-and-setters/51616035#51616035

struct X {
    int my_int 		{33};
    //int my_int =	0;
    //int my_int = 	{};
    //X(int y): my_int{y} {};
};

//Here we return a reference to the underlying X member, which allows both sides of the call site to observe changes initiated by the other. The X member is visible to the outside world, presumably because it's identity is important. It may at first glance look like there is only the "get" side of a property, but this is not the case if X is assignable.
class Identity_semantics { 			// Identity oriented
    X x_ {101};
public:
          X & x()  		{ return x_; };		// this is a getter, NOT a setter, or is it???  Yes because return by ref !#@!!
    const X & x() const { return x_; };
};


class Value_semantics { 			// Value oriented
    X x_ {201};
public:
     X 		x() const 	{ return x_; }  			// getter
     //void 	x(X x) 		{ x_ = std::move(x); }		// setter
     void 	x(X x) 		{ x_ = x; }		// setter
};

int main() {
    X my_x {99};
    X object_of_type_X = X { 42 };
                                    cout << my_x.my_int << endl;
                                    cout << object_of_type_X.my_int << endl;
    Identity_semantics 	ref_semantics {}; 			// todo: why do these not compile? //Foo1 	f = {97}; //Foo1 	f2  {97};
                                    cout << ref_semantics.x().my_int << endl; 		//cout << f.x_ .my_int << endl;
    ref_semantics.x()   = X { 43 };
                                    cout << ref_semantics.x().my_int << endl; 		//cout << f.x_ .my_int << endl;
    Value_semantics 	val_semantics {};
                                    cout << val_semantics.x().my_int << endl; 		//cout << f.x_ .my_int << endl;
    val_semantics.x()  = X { 43 };
                                    cout << val_semantics.x().my_int << endl; 		//cout << f.x_ .my_int << endl;
    cout << "###" << endl;
    return 0;
}
