// copyright grant rostig  Boost 1.0 license
// inspired by Stroustrup TOUR2 book
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <variant>
#include <memory>
using namespace std;

string itoa(int x) {
    basic_stringstream<char> ss {}; // aka stringstream
    ss << x;  // import and convert an int. todo: think of a clever way to break this and then check error.
    return ss.str();
}

std::variant<string,int> itoa_or_error_num(int x) {
    if (x != 42) return 99;  // a simplistic simulation of an error
    return itoa(x);
}

void return_a_variant() {
    std::variant<string,int> multi_value = itoa_or_error_num(-1);
    // TOUR2 P175.
    if ( std::holds_alternative<string>(multi_value) ) {
        cout << "itoa_or_error_num(): " << std::get<string>(multi_value) << endl;
    } else {
        cout << "itoa_or_error_num(): error num: " << std::get<int>(multi_value) << endl;
    }
    // another approach as per cppref
    string print_str {};
    // getting the variants is improved in c++20? according to TOUR2 P175.
    try {
        print_str = std::get<string>(multi_value);  // get one variant
    } catch (...) {
        print_str =  "error_num: " + itoa( std::get<int>(multi_value) ); // get other variant
    }
    cout << "itoa_or_error_num(): " << print_str << endl;
}

struct Shape { virtual void f()=0; };
struct Square :Shape { void f() override { cout << "square.f()\n"; } };
struct Circle :Shape { void f() override { cout << "circle.f()\n"; } };

void runtime_polymorphism_indirect_pointer_dispatch() {
    using U_P = unique_ptr<Shape>;
    vector<U_P> shapes;
    shapes.emplace_back(make_unique<Square>());
    shapes.emplace_back(make_unique<Circle>());
    for( auto & s:shapes ) {
        s->f();
    }
}

void runtime_polymorphism_variant_whattype_dispatch() {
    using V = std::variant<Square,Circle>;
    vector<V> shape_vs;
    shape_vs.emplace_back(Square {});
    shape_vs.emplace_back(Circle {});
    for (auto v : shape_vs) {
        if ( std::holds_alternative<Square>(v) ) {
            Square discriminated_v = std::get<Square>(v);
            discriminated_v.f();
        }
        else if (std::holds_alternative<Circle>(v)) {
            Circle discriminated_v = std::get<Circle>(v);
            discriminated_v.f();
        } // todo: could we have used a switch statement instead? No because tested value is bool? what about some constexpr strangeness?
    }
}

// Overloaded is a pattern that could have been standardized as per Stroustup.
template<class... Ts>  			// variadic ie. any number of any type are handled. Below we use only 2 in the contructor of our one object.
struct Overloaded : Ts...{ 		// inherit from all those types
    using Ts::operator()...;  	// all of those operator()s.
};

template<class... Ts>
    Overloaded(Ts...) -> Overloaded<Ts...>;  // deduction guide.  -> = returns.  todo: what returns what to whom?
                                             // explicit deduction guide (not needed as of C++20)

void runtime_polymorphism_variant_direct_dispatch() {  // faster because we don't have to dereference a function pointer.
    using V = std::variant<Square,Circle>;
    vector<V> shape_vs;
    shape_vs.emplace_back(Square {});
    shape_vs.emplace_back(Circle {});
    auto o = Overloaded
                 {
                   [] (Square & v) { v.f(); }, // to be invoked via operator() on the function object (AKA lambda) or any callable object.
                   [] (Circle & v) { v.f(); }
                 };

    for (auto v : shape_vs) {
        //std::visit( o, v );
        std::visit( Overloaded {
                   [] (Square & v) { v.f(); }, // to be invoked via operator() on the function object (AKA lambda) or any callable object.
                   [] (Circle & v) { v.f(); }
                 } , v );
    }
}

void runtime_polymorphism_variant_direct_dispatch2() {  // faster because we don't have to dereference a function pointer.
    using V = std::variant<Square,Circle>;
    vector<V> shape_vs;
    shape_vs.emplace_back(Square {});
    shape_vs.emplace_back(Circle {});
    auto o = Overloaded
                 {
                   [] (Square & v) { v.f(); }, // to be invoked via operator() on the function object (AKA lambda) or any callable object.
                   [] (Circle & v) { v.f(); }
                 };
    for (auto v : shape_vs) {
        std::visit( o, v );
    }
}

int main()
{
    runtime_polymorphism_indirect_pointer_dispatch();
    runtime_polymorphism_variant_whattype_dispatch();
    runtime_polymorphism_variant_direct_dispatch();
    return_a_variant();
    cout << "###" << endl;
    return 0;
}
