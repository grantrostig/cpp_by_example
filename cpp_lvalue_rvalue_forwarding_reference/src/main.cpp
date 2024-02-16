/** Author: Jon
    Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003 */
#include <iostream>
using std::cerr; using std::cin; using std::clog; using std::cout; using std::endl; using std::string; // using namespace std;
using namespace std::string_literals;

namespace example1 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
struct Gadget {};

struct Widget {
    auto MemberFunc () & { std::cout << "non const fn()\n"; }
    auto MemberFunc () const & { std::cout << "const fn()\n"; }

    auto MemberFunc () && = delete;
    auto MemberFunc () const && { std::cout << "const fn()\n"; }

    auto RefMemberFunc () &  { std::cout << "RefMemberFunc feature: &\n"; }
    auto RefMemberFunc () && { std::cout << "RefMemberFunc feature: &&\n"; }

    auto GetGadget () &             { return gadget_; }
    decltype (auto) GetGadget () && { return std::move (gadget_); }
private:
    Gadget gadget_;
};

void test1 () {
    Widget       w1;
    Widget const w2;

    // Widget{}.MemberFunc();
    w2.MemberFunc ();

    //  auto MemberFunc(Widget* this) {};
    //  auto ConstMemberFunc(Widget const* this) {};

    //  auto RefMemberFunc(Widget& this) &;
    //  auto RefMemberFunc(Widget&& this) &&;  {};

    w1.RefMemberFunc ();
    Widget{}.RefMemberFunc ();
} } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

int main () {
    example1::test1 ();
    cout << "###" << endl;
    return 0;
}
