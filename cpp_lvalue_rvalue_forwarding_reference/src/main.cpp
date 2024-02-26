/** Author of examples Jon, Marc
    Edited by: Grant Rostig
    Author of example2::  Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003 */
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
using std::cerr; using std::cin; using std::clog; using std::cout; using std::endl; using std::string; // using namespace std;
using namespace std::string_literals;

namespace Example1 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
class Gadget {};                       // default has 3 constructors.
class Widget {
    Gadget gadget_;
public:             // Pre C++11
    void f()        { std::cout << "non const fn() &\n"; } // lvalue ref-qualified
    void f() const  { std::cout << "const fn() &\n"; }

    /* // Post C++11, reference qualifiers, AKA ref-qualification, on member functions are also supported via: & and &&.
    // Related to handling of the implicit self variable, the class instanciation the function is being called on,
    // is either an lvalue or rvalue.
    // Why do we want ref-qualified functions? We can take resources from the temporary of the rvalue. ie. with std::move.

    // https://en.cppreference.com/w/cpp/language/function  // rvalue ref-qualified, only allowed on temporary objects.
    // https://en.cppreference.com/w/cpp/language/member_functions >>>>>>>>>>>>>>>
    // Member functions with ref-qualifier: An implicit object member function can be declared with no ref-qualifier, with an lvalue
    // ref-qualifier (the token & after the parameter list) or the rvalue ref-qualifier (the token && after the parameter list).
    // During overload resolution, an implicit object member function with a cv-qualifier sequence of class X is treated as follows:
    // + no ref-qualifier: the implicit object parameter has type lvalue reference to cv-qualified X and is additionally allowed to
    // bind rvalue implied object argument
    // + lvalue ref-qualifier: the implicit object parameter has type lvalue reference to cv-qualified X
    // + rvalue ref-qualifier: the implicit object parameter has type rvalue reference to cv-qualified X
    //
    // struct S {
    //  void f() &  { std::cout << "lvalue\n"; }
    //  void f() && { std::cout << "rvalue\n"; }
    // };
    //
    // int main() {
    //  S s;
    //  s.f();            // prints "lvalue"
    //  std::move(s).f(); // prints "rvalue"
    //  S{}.f();          // prints "rvalue"
    // }
    // Note: unlike cv-qualification, ref-qualification does not change the properties of the this pointer: within an rvalue
    // ref-qualified function, *this remains an lvalue expression. <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    // https://en.cppreference.com/w/cpp/language/operator_member_access  // TODO??: not sure the three references to && relate or not?? */
    auto lvalue_ref_qualified() &         { std::cout << "lvalue_ref_qualified\n"; }
    auto lvalue_ref_qualified() const &   { std::cout << "const lvalue_ref_qualified\n"; }
    auto rvalue_ref_qualified() &&        { std::cout << "rvalue_ref_qualified\n"; }
    auto rvalue_ref_qualified() const &&  { std::cout << "const rvalue_ref_qualified\n"; }

    /* //auto MemberFunc(Widget* this) {};
    //auto ConstMemberFunc(Widget const* this) {};
    //auto RefMemberFunc(Widget& this) & {};      // impossible
    //auto RefMemberFunc(Widget&& this) &&;  {};  // impossible */

    // decltype (auto) GetGadget () && { return std::move (gadget_); }

    auto get_gadget () &                { return gadget_; } // auto deduction rule makes is drop the ref part of it.
 // Gadget get_gadget () &              { return gadget_; }  // Not RVO.
 // Gadget & get_gadget () &            { return gadget_; }  // Not RVO.  ret an lvalue reference

    decltype (auto) get_gadget () &&    { return std::move (gadget_); } // Not RVO.
 // decltype (Gadget) get_gadget () &&  { return std::move (gadget_); }
 // Gadget && get_gadget () &&          { return std::move (gadget_); }
};


void test1 () { // Jon and Grant
    int lvalue; lvalue=22;    // 22 is Rvalue::PRvalue, use-case 1 // PRvalue === { no identity && is moveable }, AKA Temporary, therefore going away, and has no name.
    sqrt(22);       // Rvalue use-case 2
    (22+24);        // Rvalue
    // &(22+24);    // Error
    // *(decltype(nullptr))(22+24);    // Error, trying to trick compiler into a clever error message.
    "23"s;          // Rvalue // TODO??: why no warning at all?
    "23"s+"25"s;    // Rvalue // TODO??: why no expression warning?
    //"23"+"25";    // Error
    Widget{};       // Rvalue
    new Widget{};   // Rvalue

    Widget       w1_lvalue;                 // Lvalue === { has identity && not moveable } AKA Variable, holding memory, within scope beyond this statement line.  TODO??: is this precisely correct?
    Widget const w1_const_lvalue;
    Widget *     w1_const_lvalue_ptr{nullptr};
    Widget &     w1_const_lvalue_ref{w1_lvalue};

    std::move(lvalue);                 // Xvalue === { has identity && is moveable } AKA
    std::move(w1_lvalue);                 // Xvalue === { has identity && is moveable } AKA

    w1_lvalue       .lvalue_ref_qualified();
    w1_const_lvalue .lvalue_ref_qualified();
    Widget{}        .lvalue_ref_qualified();

    w1_lvalue       .rvalue_ref_qualified();
    w1_const_lvalue .rvalue_ref_qualified();
    Widget{}        .rvalue_ref_qualified();

    w1.get_gadget();                                // a copy
    Gadget moved_to_obj0{ w1.get_gadget() };        // copy then moved //get ret val is a temp!!!  All functions that return values return temporary value.
    Gadget moved_to_obj1{ Widget{}.get_gadget() };  // ret a ref/alias then move. // a move!!  can't do anything
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace Example2 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
void test1 () {  // Jon
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Example3 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
void test1 () {  // Marc
        struct Foo{} f1;
        static_assert(std::is_same  <Foo,   decltype( f1            )>::value);
        static_assert(std::is_same_v<Foo&,  decltype( (f1)          )>);
        static_assert(std::is_same_v<Foo&&, decltype( std::move(f1) )>);
        static_assert(std::is_same_v<Foo*,  decltype( new Foo       )>);
        auto c1{ [&]() -> auto              { return std::move(f1); } };  // TODO??: what is the point? && is stripped??  Does "auto" also make a difference?
        auto c2{ [&]() -> decltype( auto )  { return std::move(f1); } };  // TODO??: what is the point? && is NOT stripped??
        static_assert(std::is_same_v<Foo,   decltype( c1()          )>);
        static_assert(std::is_same_v<Foo&&, decltype( c2()          )>);
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Example4 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
std::string build_greeting(std::string const& subject) {
    std::ostringstream str_builder{};
    str_builder << "Hello" << ", " << subject;
    // Call: $ std::string std::ostringstream::str() const &
 // return str_builder.str();
 // OR
    // Call: $ std::string std::ostringstream::str() &&
 // return std::move(str_builder).str();
 // return static_cast<                                 std::ostringstream&&           >(str_builder).str();
 // return static_cast< typename std::remove_reference< std::ostringstream&  >::type&& >(str_builder).str();

 /* Simon Toth:
std::move is an unconditional xvalue cast, typically denoting that the state of the object being cast is no longer required and can be consumed during the expression evaluation.
    chatGPT:
std::move is a cast that produces an rvalue-reference to an object, enabling move semantics. It allows efficient transfer of resources from one object to another. When you use std::move(x), you’re allowing the compiler to cannibalize x. It’s commonly used in constructors, operator methods, and standard-library algorithms to move resources instead of copying them12.
    Gemini:
std::move is not technically a cast itself, but it behaves similarly to an rvalue reference cast in specific contexts. Here's a breakdown:
 **Functionality:**
  * `std::move` is a function from the `<utility>` header in C++.
  * Its primary purpose is to **convert an lvalue (expression referring to a named variable) to an rvalue (expression that evaluates to a temporary value)**.
  * This conversion enables functions and operations to **potentially transfer ownership** of resources held by the lvalue, allowing for efficient move semantics.
 **Behavior:**
  * When applied to an rvalue, `std::move` has no effect, as rvalues are already treated as temporary expressions.
  * When applied to an lvalue of a movable type, `std::move` creates an **rvalue reference** to the lvalue, indicating that the object's resources can be moved from.
  * This rvalue reference can then be used in contexts where rvalues are expected, such as function arguments expecting to receive ownership of the object.
 **Comparison to Casts:**
  * While `std::move` might resemble an rvalue reference cast at times, it has some key differences:
      * **Clarity:** `std::move` explicitly conveys the intent to potentially move the object, improving code readability.
      * **Safety:** Using `std::move` avoids potential misuse of casts, which can lead to unintended consequences if not used carefully.
 **In essence, `std::move` is a safer and more expressive alternative to an rvalue reference cast in the context of move semantics.**

 GCC's std::move impl:
    template<typename _Tp>
    _GLIBCXX_NODISCARD
    constexpr typename std::remove_reference<_Tp>::type&&
    move(_Tp&& __t) noexcept
    { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); } */
}
void test1 () {  // Marc
    std::string greeting1{build_greeting("world")};
    std::cout << greeting1 << std::endl;

    std::string greeting2{build_greeting("Grant")};  // TODO??: Marc, why second example? Supposed to be different?
    std::cout << greeting2 << std::endl;
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

int main () {
    Example1::test1 ();
    Example2::test1 ();
    Example3::test1 ();
    Example4::test1 ();

    cout << "###" << endl;
    return 0;
}
