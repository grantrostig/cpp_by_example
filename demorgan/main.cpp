#include <iostream>
#include <string>

using namespace std;
#include <iostream>

template <typename T>
class BaseT {
protected:
    T & ref_to_Derived;
public:
    BaseT() : ref_to_Derived( /* dereference */ * (static_cast< T * > ( /* ptr to Self */ this)) ) {}  // ptr to self but actually
    int getX() {
        return ref_to_Derived.getX();
    }
};

class DerivedT : BaseT< DerivedT > {
public:
    unsigned int getX() {
        // return ref_to_Derived.x;
        return x;
    }
private:
    unsigned int x {41};
// +++++++++++++++++++++++++++++++++++++++
    friend BaseT< DerivedT >;
};

class DerivedT2 : BaseT< DerivedT2 > {
public:
    unsigned int getX() {
        // return ref_to_Derived.x;
        return x+100;
    }
private:
    unsigned int x {42};

// +++++++++++++++++++++++++++++++++++++++
    friend BaseT< DerivedT2 >;
};

int main() {

    BaseT<DerivedT> 		  s2 {};
    BaseT<DerivedT2> 		  s22 {};
    std::cout << "my_BaseT : "  << s2. getX()  << std::endl;
    std::cout << "my_BaseT2 : " << s22.getX()  << std::endl;
   // s2 .getX();
    // s22.getX();

    DerivedT my_example_class;
    DerivedT my_example_class2;
    //std::cout << "my_example_class : " << my_example_class.getX()  << std::endl;
    //std::cout << "my_example_class2: " << my_example_class2.getX() << std::endl;

    DerivedT2 my_example_class22;
    DerivedT2 my_example_class23;
    //std::cout << "my_example_class : " << my_example_class.getX()  << std::endl;
    //std::cout << "my_example_class : " << my_example_class.getX()  << std::endl;
    //Self< unsigned int >      my_self;
    //std::cout << "my_self: " << my_self.getX() << std::endl;

    bool a,b;
    if (   !a || !b  )   { };
    if ( !( a && b ) ) { };
    if (   !a  && !b   )  { }; //  (!a) && (!b)
    if ( !( a  ||  b ) ) { };

    cout << "###" << endl;
    return 0;
}
