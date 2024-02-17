/** Author: Jon
    Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003 */
#include <iostream>
using std::cerr; using std::cin; using std::clog; using std::cout; using std::endl; using std::string; // using namespace std;
using namespace std::string_literals;

namespace example1 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
struct Gadget {};   // 3 constructors,
struct Widget { // not if you use ()&: auto MemberFunc () { std::cout << "non const fn() \n"; }  // lvalue ref-qualified
    auto MemberFunc () & { std::cout << "non const fn() &\n"; }  // lvalue ref-qualified
    auto MemberFunc () const & { std::cout << "const fn() &\n"; }
    //auto MemberFunc () && = delete; // https://en.cppreference.com/w/cpp/language/function  // rvalue ref-qualified, can only on temporary objs
    auto MemberFunc () && {}; // https://en.cppreference.com/w/cpp/language/function  // rvalue ref-qualified, can only on temporary objs
    auto MemberFunc () const && { std::cout << "const fn() &&\n"; }
    auto RefMemberFunc () &  { std::cout << "RefMemberFunc() feature: &\n"; }
    auto RefMemberFunc () && { std::cout << "RefMemberFunc() feature: &&\n"; }

    /* //auto MemberFunc(Widget* this) {};
    //auto ConstMemberFunc(Widget const* this) {};
    //auto RefMemberFunc(Widget& this) & {};      // impossible
    //auto RefMemberFunc(Widget&& this) &&;  {};  // impossible */
    // Why do we want ref-qualified functions? We can take resources from the temporary. ie. std::move.  constructors
    //decltype (auto) GetGadget () && { return std::move (gadget_); }

    auto get_gadget () &             { return gadget_; }  // auto deduction rule makes is drop the ref part of it.
    //Gadget get_gadget () &             { return gadget_; }  // Not RVO.
    //Gadget & get_gadget () &             { return gadget_; }  // Not RVO.  ret an lvalue reference
    //decltype (Gadget) get_gadget () && { return std::move (gadget_); }
    Gadget && get_gadget () && { return std::move (gadget_); }
    //decltype (auto) get_gadget () && { return std::move (gadget_); }  // Not RVO.
private:
    Gadget gadget_;
};

void test1 () {
    Widget       w1;
    Widget       w2;
    Widget const w2_const_lvalue; /*    Widget w3, * w2_const_lvaluex;
    //Widget w6, const w2_const_lvaluey;
    Widget w7, & w8_const_lvaluey{w1};
    Widget w4 {}, w5_const_lvalue{}; */
    Widget{}.MemberFunc();
    w2_const_lvalue.MemberFunc ();
    Widget{}.RefMemberFunc ();
    w1.RefMemberFunc ();
    w2.RefMemberFunc ();

    w1.get_gadget();            // a copy
    Gadget moved_to_obj0{ w1.get_gadget() }; // copy then moved //get ret val is a temp!!!  All functions that return values return temporary value.
    Gadget moved_to_obj1{ Widget{}.get_gadget() };  // ret a ref/alias then move. // a move!!  can't do anything
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace example2 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
struct Gadget {};   // 3 constructors,
struct Widget { // not if you use ()&: auto MemberFunc () { std::cout << "non const fn() \n"; }  // lvalue ref-qualified
    auto MemberFunc () & { std::cout << "non const fn() &\n"; }  // lvalue ref-qualified
    auto MemberFunc () const & { std::cout << "const fn() &\n"; }
    //auto MemberFunc () && = delete; // https://en.cppreference.com/w/cpp/language/function  // rvalue ref-qualified, can only on temporary objs
    auto MemberFunc () && {}; // https://en.cppreference.com/w/cpp/language/function  // rvalue ref-qualified, can only on temporary objs
    auto MemberFunc () const && { std::cout << "const fn() &&\n"; }
    auto RefMemberFunc () &  { std::cout << "RefMemberFunc() feature: &\n"; }
    auto RefMemberFunc () && { std::cout << "RefMemberFunc() feature: &&\n"; }

    /* //auto MemberFunc(Widget* this) {};
    //auto ConstMemberFunc(Widget const* this) {};
    //auto RefMemberFunc(Widget& this) & {};      // impossible
    //auto RefMemberFunc(Widget&& this) &&;  {};  // impossible */
    // Why do we want ref-qualified functions? We can take resources from the temporary. ie. std::move.  constructors
    //decltype (auto) GetGadget () && { return std::move (gadget_); }

    auto get_gadget () &             { return gadget_; }  // auto deduction rule makes is drop the ref part of it.
    //Gadget get_gadget () &             { return gadget_; }  // Not RVO.
    //Gadget & get_gadget () &             { return gadget_; }  // Not RVO.  ret an lvalue reference
    //decltype (Gadget) get_gadget () && { return std::move (gadget_); }
    Gadget && get_gadget () && { return std::move (gadget_); }
    //decltype (auto) get_gadget () && { return std::move (gadget_); }  // Not RVO.
private:
    Gadget gadget_;
};

void test1 () {
    Widget       w1;
    Widget       w2;
    Widget const w2_const_lvalue; /*    Widget w3, * w2_const_lvaluex;
    //Widget w6, const w2_const_lvaluey;
    Widget w7, & w8_const_lvaluey{w1};
    Widget w4 {}, w5_const_lvalue{}; */
    Widget{}.MemberFunc();
    w2_const_lvalue.MemberFunc ();
    Widget{}.RefMemberFunc ();
    w1.RefMemberFunc ();
    w2.RefMemberFunc ();

    w1.get_gadget();            // a copy
    Gadget moved_to_obj0{ w1.get_gadget() }; // copy then moved //get ret val is a temp!!!  All functions that return values return temporary value.
    Gadget moved_to_obj1{ Widget{}.get_gadget() };  // ret a ref/alias then move. // a move!!  can't do anything
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
int main () {
    example1::test1 ();
    cout << "###" << endl;
    return 0;
}
