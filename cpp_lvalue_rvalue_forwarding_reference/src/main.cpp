/** Author of examples Jon, Marc
    Edited by: Grant Rostig
    Author of example2::  Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003 */
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

    // Post C++11, ref-qualification on member functions are supported. Related to handling of the implicit self variable.
    // Why do we want ref-qualified functions? We can take resources from the temporary. ie. std::move.  constructors
    auto lvalue_ref_qualified() &         { std::cout << "lvalue_ref_qualified\n"; }
    auto lvalue_ref_qualified() const &   { std::cout << "const lvalue_ref_qualified\n"; }
    auto rvalue_ref_qualified() &&        { std::cout << "rvalue_ref_qualified\n"; }
    auto rvalue_ref_qualified() const &&  { std::cout << "const rvalue_ref_qualified\n"; }

 // auto member_func () && = delete;                                 // https://en.cppreference.com/w/cpp/language/function  // rvalue ref-qualified, can only on temporary objs

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

void test1 () { // Jon
    Widget       w1_lvalue;
    Widget const w1_const_lvalue;
    Widget *     w1_const_lvalue_ptr{nullptr};
    Widget &     w1_const_lvalue_ref{w1_lvalue};

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
 // return str_builder.str();               // calls std::string std::ostringstream::str() const &
 // OR
 // return std::move(str_builder).str();    // calls std::string std::ostringstream::str() &&
    /* similar to: $ return static_cast<std::ostringstream&&>(str_builder).str();
       similar to: $ return static_cast<typename std::remove_reference<std::ostringstream&>::type&&>(str_builder).str();
       gcc's impl:
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
