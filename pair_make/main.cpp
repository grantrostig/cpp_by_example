#include <iostream>
#include <utility>
//#include <tuple>
using std::cout, std::endl;

struct Struct1 { int s1a; int s1b; };

struct Struct2 { std::string s2; };

struct Struct3 { std::pair<Struct1,Struct2> d; };

struct Pair1 {
    std::pair<Struct1, Struct2> pair1 	    { {1,2}, {"str"}};
};

struct Pair2 {
    Struct1 a;
    Struct2 b;
    Struct3 c;
};

struct Pair3 {
    struct Struct13 { int a; int b; };
    struct Struct23 { std::string c; };
    std::pair<Struct13, Struct23> record;
};

struct Pair4 {
    struct Struct13 { int a; int b; } ab;
    struct Struct23 { std::string c; } cc;
    std::pair<Struct13, Struct23> record;
};

int main()
{
    std::pair<int,std::string>  temp1   { 1, "str"};
    std::pair<Struct1, Struct2> temp2                   { {1,2}, {"str"} };
    Pair1 						pair1 {                 { {1,2}, {"str"} } };
    Pair2 						pair2 { {1,2}, {"str"}, {{ {1,2}, {"str"} }} };
    Pair3 						pair3 					{{ {1,2}, {"str"} }};
    // Pair4 						pair4 { {1,2}, {"str"}, {{ {1,2}, {"str"} }} };  todo: TODO
    // Pair4 						pair4 { {1,2}, {"str"}, std::pair<Pair4::Struct13,Pair4::Struct23> {{ {1,2}, {"str"} }} };  todo: TODO
    cout << "###" << endl;
    return 0;
}
