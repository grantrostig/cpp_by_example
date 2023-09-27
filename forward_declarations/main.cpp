// this example explores forward declarations of classes, not just functions, which is what most blog posts cover.
#include "c.h"
#include "d.h"

struct B;

struct A {
    B * a3;  // this works because it is a pointer and doesn't need to know the full structure of the object pointed too.
    B   a2;  // todo: Is it possible to make this work?  // ERROR: field has incomplete type 'B'
};

struct B {
    // A      b2 {};
    int i;
};


int main()
{
    A my_a;
    B my_b;
    C my_c;
    D my_d;
    return 0;
}
