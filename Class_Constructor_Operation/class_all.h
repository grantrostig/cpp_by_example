// Copyright Grant Rostig 2019 -- released to the Public Domain
// thanks to material derived from cpprefence.com and TC++PL 2ed by Stroustop
// https://en.cppreference.com/w/cpp/language/operator_assignment
// https://en.cppreference.com/w/cpp/language/operators

// A sample / example class header for C++17, with some syntax for future C++20

// NOTE: This is example file is UNDER CONSTRUCTION, not finished.
// Why do this?  Because I could not find it on the internet or in my many books, and I don't like "left as a exercise for the reader" in books.
// I wanted it all in one place to use for copy-paste'ing

#ifndef CLASS_ALL_H
#define CLASS_ALL_H
#include <ostream>
#include <istream>
#include <new>
#include <new>

class T2{}; // T2 could also be of the type T  below

class T {
// ========== Copy assignment operators
T& operator=( T );
T& operator=( const T& );
// T & operator=( const T& )=default;
// T & operator=( const T& )=delete;

// ========== Move assignment operator
T & operator=( T && );
// T & operator=( T && )=default;
// T & operator=( T && )=delete;

// ========== Member Function class definition
//       2nd line is: Non-Member Function class definition

// simple assignment
T& operator=(const T2& b);

// addition assignment
T& operator+=(const T2& b);         // todo: if this is defined, does compiler generate: T operator+(T,T); ?  And would this also work for other types by using implicit convertions?
// T& operator+=(T& a, const T2& b);

// subtraction assignment
T& operator-=(const T2& b);
// T& operator-=(T& a, const T2& b);

// multiplication assignment
T& operator*=(const T2& b);
// T& operator*=(T& a, const T2& b);

// division assignment
T& operator/=(const T2& b);
// T& operator/=(T& a, const T2& b);

// modulo assignment
T& operator%=(const T2& b);
// T& operator%=(T& a, const T2& b);

// bitwise AND assignment
T& operator&=(const T2& b);
// T& operator&=(T& a, const T2& b);

// bitwise OR assignment
T& operator!=(const T2& b);
// T& operator!=(T& a, const T2& b);

// bitwise XOR assignment
T& operator^=(const T2& b);
// T& operator^=(T& a, const T2& b);

// bitwise left shift assignment
T& operator<<=(const T2& b);
// T& operator<<=(T& a, const T2& b);

// bitwise right shift assignment
T& operator>>=(const T2& b);
// T& operator>>=(T& a, const T2& b);

// ========== Operator Overloading ==========

/* general rules

   // Expression
   // As member function
   // As non-member function
   // example

 @a
 (a).operator@ ( )
 operator@ (a)
 !std::cin                 // calls   std::cin.operator!()

 a@b
 (a).operator@ (b)
 operator@ (a, b)
 std::cout << 42;          // calls  std::cout.operator<<(42)

 a=b
 (a).operator= (b)
 cannot be non-member
 std::string s; s = "abc"; // calls  s.operator=("abc")

 a(b...)
 (a).operator()(b...)
 cannot be non-member
 std::random_device r; auto n = r();  // calls  r.operator()()

 a[b]
 (a).operator[](b)
 cannot be non-member
 std::map<int, int> m; m[1] = 2;      // calls   m.operator[](1)

 a->
 (a).operator-> ( )
 cannot be non-member
 auto p = std::make_unique<S>(); p->bar() // calls   p.operator->()

 a@
 (a).operator@ (0)
 operator@ (a, 0)
 std::vector<int>::iterator i = v.begin(); i++ // calls   i.operator++(0)

        Above in this table @ is a placeholder representing all matching operators:
        all prefix operators in @a,
        all postfix operators other than -> in a@,
        all infix operators other than = in a@b
*/

// ========== Increment and decrement, prefix? and postfix? todo: terminology?
T& operator++();
T  operator++(int);
T& operator--();
T  operator--(int);

// ========== Binary (2 operands) arithmetic operators

friend
// friends defined inside class body are inline and are hidden from non-ADL lookup. todo: what is non-ADL lookup?
T operator+(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend  // todo: why is T not a ref?
T operator-(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend
T operator*(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend
T operator/(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend
T operator%(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend
T operator&(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend
T operator|(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend
T operator^(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend
T operator<<(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend
T operator>>(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`

// ========== unary arithmetic operators
T operator-();
T operator+();

// ========== Relational operators (AKA comparison operators? )
friend
inline bool operator< (const T& lhs, const T& rhs);  // Typically, once operator< is provided, the other relational operators are implemented in terms of operator<. NOTE: When three-way comparison (such as std::memcmp or std::string::compare) is provided, all six relational operators may be expressed through that!!k
friend
inline bool operator> (const T& lhs, const T& rhs);
friend
inline bool operator<=(const T& lhs, const T& rhs);
friend
inline bool operator>=(const T& lhs, const T& rhs);
friend
inline bool operator==(const T& lhs, const T& rhs);  // Likewise, the inequality operator is typically implemented in terms of operator==:
friend
inline bool operator!=(const T& lhs, const T& rhs);

// NOTE: C++20 - All six relational operators are automatically generated by the compiler if the three-way comparison
//       operator operator<=> is defined, and that operator, in turn, is generated by the compiler if it is defined as defaulted:
//       auto operator<=>( const T& );  // c++20 AKA spaceship operator

// ========== Array subscript operator
// If the value type is known to be a built-in type, the const variant should return by value.
// Where direct access to the elements of the container is not wanted or not possible or distinguishing between
// lvalue c[i] = v; and rvalue v = c[i]; usage, operator[] may return a proxy. see for example std::bitset::operator[].
// To provide multidimensional array access semantics, e.g. to implement a 3D array access a[i][j][k] = x;,
// operator[] has to return a reference to a 2D plane, which has to have its own operator[] which returns
// a reference to a 1D row, which has to have operator[] which returns a reference to the element.
// To avoid this complexity, some libraries opt for overloading operator() instead,
// so that 3D access expressions have the Fortran-like syntax a(i, j, k) = x;

      T& operator[](std::size_t idx);
const T& operator[](std::size_t idx) const;

// ========== Bitwise arithmetic operators

// User-defined classes and enumerations that implement the requirements of BitmaskType are required to overload the bitwise arithmetic operators operator&, operator|, operator^, operator~, operator&=, operator|=, and operator^=, and may optionally overload the shift operators operator<< operator>>, operator>>=, and operator<<=. The canonical implementations usually follow the pattern for binary arithmetic operators described above.
T operator~(); // bitwise unary NOT

// ========== Boolean operators (AKA logical? operators)  todo:
// The boolean logic operators, operator&& and operator||. Unlike the built-in versions, the overloads cannot implement short-circuit evaluation. Also unlike the built-in versions, they do not sequence their left operand before the right one. (until C++17) In the standard library, these operators are only overloaded for std::valarray.
friend
T operator&&(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`
friend
T operator||(T lhs, const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`

// ========== Boolean negation operator
// The operator operator! is commonly overloaded by the user-defined classes that are intended to be used in boolean contexts.
// Such classes also provide a user-defined conversion function explicit operator bool() (see std::basic_ios for the standard library example),
// and the expected behavior of operator! is to return the value opposite of operator bool.
friend  // todo: this is always be defined within the class?
T operator!(const T& rhs); // passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references todo: wouldn't one need to also return T&?`

// ========== Stream extraction and insertion
friend
std::ostream& operator<<(std::ostream& os, const T& obj);
friend
std::istream& operator>>(std::istream& is, T& obj);

// ========== Function call operator
void operator()(int n);

// ========== Rarely overloaded operators
// address-of operator: operator&
// If the unary & is applied to an lvalue of incomplete type and the complete type declares an overloaded operator&, the behavior is undefined (until C++11) it is unspecified whether the operator has the built-in meaning or the operator function is called (since C++11). Because this operator may be overloaded, generic libraries use std::addressof to obtain addresses of objects of user-defined types. The best known example of a canonical overloaded operator& is the Microsoft class CComPtr. An example of its use in EDSL can be found in boost.spirit.

// comma operator: operator,
// Unlike the built-in version, the overloads do not sequence their left operand before the right one. (until C++17) Because this operator may be overloaded, generic libraries use expressions such as a,void(),b instead of a,b to sequence execution of expressions of user-defined types. The boost library uses operator, in boost.assign, boost.spirit, and other libraries. The database access library SOCI also overloads operator,.

// member access through pointer to member: operator->*
// There are no specific downsides to overloading this operator, but it is rarely used in practice. It was suggested that it could be part of smart pointer interface, and in fact is used in that capacity by actors in boost.phoenix. It is more common in EDSLs such as cpp.react.

// ========== operator new, operator new[] // todo: are these typically member functions?
// replaceable allocation functions // [[nodiscard]] (since c++20)
void* operator new  ( std::size_t count );
void* operator new[]( std::size_t count );
void* operator new  ( std::size_t count, std::align_val_t al); // 	(since C++17)
void* operator new[]( std::size_t count, std::align_val_t al); // 	(since C++17)

// replaceable non-throwing allocation functions
void* operator new  ( std::size_t count, const std::nothrow_t& tag);
void* operator new[]( std::size_t count, const std::nothrow_t& tag);
void* operator new  ( std::size_t count, std::align_val_t al, const std::nothrow_t&); // (since C++17)
void* operator new[]( std::size_t count, std::align_val_t al, const std::nothrow_t&); // (since C++17)

// non-allocating placement allocation functions
void* operator new  ( std::size_t count, void* ptr );
void* operator new[]( std::size_t count, void* ptr );

// user-defined placement allocation functions
void* operator new  ( std::size_t count, /*user-defined-args*/... );
void* operator new[]( std::size_t count, /*user-defined-args*/... );
void* operator new  ( std::size_t count, std::align_val_t al, /*user-defined-args*/... ); // (since C++17)
void* operator new[]( std::size_t count, std::align_val_t al, /*user-defined-args*/... ); // (since C++17)

/* todo: how are these different from the above first two sections and called out this way here: https://en.cppreference.com/w/cpp/memory/new/operator_new
// class-specific allocation functions // todo: are these typically member functions? different somehow from above?
void* operator new  ( std::size_t count );
void* operator new[]( std::size_t count );
void* operator new  ( std::size_t count, std::align_val_t al ); // (since C++17)
void* operator new[]( std::size_t count, std::align_val_t al ); // (since C++17)

// class-specific placement allocation functions
void* operator new  ( std::size_t count, ... );
void* operator new[]( std::size_t count, ... );
void* operator new  ( std::size_t count, std::align_val_t al, ... ); // (since C++17)
void* operator new[]( std::size_t count, std::align_val_t al, ... ); // (since C++17)
*/

// ========== operator delete, operator delete[]
// replaceable usual deallocation functions
void operator delete  ( void* ptr );
void operator delete[]( void* ptr );
void operator delete  ( void* ptr, std::align_val_t al ); // (since C++17)
void operator delete[]( void* ptr, std::align_val_t al ); // 	(since C++17)
void operator delete  ( void* ptr, std::size_t sz ); // 	(since C++14)
void operator delete[]( void* ptr, std::size_t sz ); // 	(since C++14)
void operator delete  ( void* ptr, std::size_t sz, std::align_val_t al ); // 	(since C++17)
void operator delete[]( void* ptr, std::size_t sz, std::align_val_t al ); // 	(since C++17)

// replaceable placement deallocation functions
void operator delete  ( void* ptr, const std::nothrow_t& tag );
void operator delete[]( void* ptr, const std::nothrow_t& tag );
void operator delete  ( void* ptr, std::align_val_t al, const std::nothrow_t& tag ); // 	(since C++17)
void operator delete[]( void* ptr, std::align_val_t al, const std::nothrow_t& tag ); // 	(since C++17)

// non-allocating placement deallocation functions
void operator delete  ( void* ptr, void* place );
void operator delete[]( void* ptr, void* place );

// user-defined placement deallocation functions
void operator delete  ( void* ptr, /*args*/... );
void operator delete[]( void* ptr, /*args*/... );

/* // class-specific usual deallocation functionshow are these different from the above first few sections and called out this way here: https://en.cppreference.com/w/cpp/memory/new/operator_delete
void T::operator delete  ( void* ptr );
void T::operator delete[]( void* ptr );
void T::operator delete  ( void* ptr, std::align_val_t al ); // 	(since C++17)
void T::operator delete[]( void* ptr, std::align_val_t al ); // 	(since C++17)
void T::operator delete  ( void* ptr, std::size_t sz );
void T::operator delete[]( void* ptr, std::size_t sz );
void T::operator delete  ( void* ptr, std::size_t sz, std::align_val_t al ); // 	(since C++17)
void T::operator delete[]( void* ptr, std::size_t sz, std::align_val_t al ); // 	(since C++17)

// class-specific placement deallocation functions
void T::operator delete  ( void* ptr, ... );
void T::operator delete[]( void* ptr, ... );

// class-specific destroying deallocation functions // all	(since C++20)
void T::operator delete(T* ptr, std::destroying_delete_t);                                // 	(since C++20)
void T::operator delete(T* ptr, std::destroying_delete_t,  std::align_val_t);             // 	(since C++20)
void T::operator delete(T* ptr, std::destroying_delete_t, std::size_t);                   // 	(since C++20)
void T::operator delete(T* ptr, std::destroying_delete_t, std::size_t, std::align_val_t); // 	(since C++20)
*/

};

// ========== user-defined literals                     // constexpr allowed, UDL's can not be in a class definition. https://en.cppreference.com/w/cpp/language/user_literal
T operator""_my_ud_literal( unsigned long long int );
T operator""_my_ud_literal( long double );
T operator""_my_ud_literal( char );
T operator""_my_ud_literal( const char * );
T operator""_my_ud_literal( const char32_t * , size_t);

#endif // CLASS_ALL_H
