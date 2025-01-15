// license boost 1.0
#include <iostream>

// const return value.

// Scott's approach Book:Effective 3ed., Page:18  : delete RVALUE assignement and move constructors, ie LVALUE only.
// In cpp03 c++ and beyond: !const allows: + modify a temp in place for subsequent use.
// In modern c++          : defeats std::move and also (ie. otherwise moving).
// modern way for Scott's approach Book:Effective V3, Page:?19?  : delete RVALUE assignement and move constructors, ie LVALUE only.

struct Rational {
    Rational() = default;
    Rational(int ){};
    //Rational & operator=(Rational const & ) & { return *this; };  // new in c++11
    Rational & operator=(Rational const & ) { return *this; };
};

Rational const
operator*(Rational const & lhs, Rational const & rhs ) {
 auto result = lhs * rhs;
 return result;
}

int main() {
    int      my_int         { (2+7) = 9 };
    Rational my_rational    { ( Rational{2} * Rational{7} ) = Rational{9} };

    std::cout << "###" << std::endl;
    return 0;
}
