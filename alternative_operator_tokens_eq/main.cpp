#include <cstdlib>
#include <iostream>
#include <functional>
using  std::cout,std::endl;
constexpr bool eq(int a,int b) {return a == b;}
bool eq2(int a,int b) {return a == b;}
int main() {
    // if ( 1 !not_equal_to 1) cout << "equal"<< endl;  todo: why can't I do this?
    // if ( 1  ! != 1) cout << "equal"<< endl;  todo: why can't I do this?
    if ( !(1  != 1) ) cout << "equal"<< std::endl;
    if ( 1 not_eq 2) cout << "not equal"<< endl;
    if ( 1 != 2) cout << "not equal"<< endl;
    if ( 1 not_eq 1) ; else cout << "equal"<< endl;
    if ( ! (1 not_eq 1) ) cout << "equal"<< endl;
    // #define  "x EQ y"   x == y
    // #define {.EQ.} ==

    #define EQ ==
    if ( (1 EQ 1) ) cout << "equal EQ"<< endl;
    if ( (1 == 1) ) cout << "equal EQ"<< endl;

    int m = std::min(1,2);
    //int z = min(1,2);
    //int o = MIN(1,2);
    //int n = equal(1,2);
    #define eq(a,b)     ( { __typeof__ (a) _a = (a);  __typeof__ (b) _b = (b);  _a == _b ? true : false; } )
    #define eq2(a,b)    ( { __typeof__ (a) _a = (a);  __typeof__ (b) _b = (b);  _a == _b; } )
    #define eq3(a,b)    ( a == b )
    #define eq4(a,b)    a == b  // probably a very bad idea!
    if ( eq(1,1)  ) cout << "equal eq"<< endl;
    if ( eq2(1,1) ) cout << "equal eq2"<< endl;
    if ( eq3(1,1) ) cout << "equal eq3"<< endl;
    if ( eq4(1,1) ) cout << "equal eq4"<< endl;

    std::vector<int> numbers1 {10,20,30,40,50};
    std::vector<int> numbers2 {20,20,30,20,20,234,23423423,234234};
    auto pt = std::mismatch (numbers1.begin(), numbers1.end() , numbers2.begin(), std::equal_to());
    std::cout << "The first different elements are respectively:" << *(pt.first) << "," << *pt.second << '\n';
    int p {1}, q {2};
    std::string j {"1"}, k {"2"};
    bool my_bool = std::not_equal_to<std::string>() (j,k);
    cout << my_bool << endl;
    my_bool = std::not_equal_to() (p,q);
    cout << my_bool << endl;
    cout << "###" << endl;
}
