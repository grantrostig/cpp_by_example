#include <iostream>
#include <type_traits>

template <class T>
struct Number { T n; };

struct B {
   int my_b_int;
};

struct R : B {
   double my_r_double;
};

//template <class T, class U>
//Number< typename std::common_type<T, U>::type >

template <class T, class U>
Number< std::common_type_t< T,U > >
operator+(const Number<T>& lhs, const Number<U>& rhs) {
    return {lhs.n + rhs.n};
}

template <class T, class U>
//Number< double >
Number< int >
operator-(const Number<T>& lhs, const Number<U>& rhs) {
    return {lhs.n - rhs.n};
}

int main()
{
    Number<int>    i1 = {1}, i2 = {2};
    Number<double> d1 = {2.3}, d2 = {3.5};
    auto ret3 = i1+d2;
    auto ret4 = d1+i2;

    auto ret1 = i1-i2;
    auto ret2 = i1-d2;
    auto ret5 = d1-i2;
    std::cout << "i1+i2: " << (i1 + i2).n << "\n i1+d2: " << (i1 + d2).n << '\n'
              << "d1+i2: " << (d1 + i2).n << "\n d1+d2: " << (d1 + d2).n << '\n';
    std::cout << "i1-i2: " << (i1 - i2).n << "\n i1-d2: " << (i1 - d2).n << '\n'
              << "d1-i2: " << (d1 - i2).n << "\n d1-d2: " << (d1 - d2).n << '\n';
}
