#include <iostream>
#include <variant>
#include <functional>
#include <vector>

using namespace std;

struct A {
    int i {11};
};

struct B {
    double d {22};
};

int f1(A& a) {
    cout << a.i << endl;
    return 4;
};

int f2(A& a) {
    cout << a.i*2 << endl;
    return 5;
};

int f3(B& b) {
    cout << b.d*2 << endl;
    return 6;
};

int f4( std::variant<A, B> a_b ) {
};

// using parameters = std::variant<A &, B &>;
// using function = std::function< int (std::variant<A,B>) >;


int main()
{
    std::function< int(A&) > callable1 = f1;
    std::function< int(A&) > callable2 = f2;
    std::function< int( std::variant<A, B> ) > callable4 = f4;  // can't have A& !! todo: why not?

    A a;
    B b;
    callable1(a);
    callable2(a);
    callable4(a);
    callable4(b);

    // vector< std::function< int(parameters) >> callables;
    // callables.push_back();
    // callables.emplace_back();

    cout << "###" << endl;
    return 0;
}
