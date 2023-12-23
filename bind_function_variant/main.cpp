/*
 * Generated as part of the password manager effort
 * see: menu_system_visit for subsequent work.
 */
#include <iostream>
#include <vector>
#include <functional>
#include <variant>
#include <any>
using  std::cout,std::endl;
struct State { int a {2}; int b {3}; };

struct Callable_any {
    std::string name;
    std::any action;
};

struct Callable_variant {
    std::string name;
    std::variant<   std::function<int()>
                    ,
                    std::function<int(int)>
                    ,
                    std::function<int(int &)>
                    ,
                    std::function<int(double)>
                    ,
                    std::function<int(State &)>
                    ,
                    std::function<int(State &, double)>
                > action;
};

int f(int &   i)            { cout << "fn_f :"<< i << endl; return 1; }
int g(State & s)            { cout << "fn_g :"<< s.a << endl; return 1; }
int h(State & s, double d)  { cout << "fn_h :"<< s.a <<", "<< d << endl; return 1; }

int main()
{
    State s;
    double dv = 99.99;
    Callable_variant a  {"a",  std::function<int(State,double)>()};
    Callable_variant b  {"b",  std::function<int(double)>()};
    Callable_variant e  {"e",  std::function<int()>()};
    Callable_variant e2 {"e2", std::function<int(int)>()};
    Callable_variant c  {"c",  &h};
    Callable_variant c2 {"c2", &g};
    Callable_variant c3 {"c3", &f};

    //  https://stackoverflow.com/questions/57709430/stdbind-to-a-stdvariant-containing-multiple-stdfunction-types

    Callable_variant f2 {"f", (std::function<int(double)>)                std::bind( h, s, std::placeholders::_1 )};
    Callable_variant j  {"j",  static_cast<std::function<int(double)>>   (std::bind( h, s, std::placeholders::_1 ))};
    Callable_variant d  {"d",  std::function<int()>                      {std::bind( h, s, dv )}};
    Callable_variant g  {"g",  std::function<int()>                      {std::bind( h, std::ref(s), 99.99 )}};
    Callable_variant h2 {"h",  std::function<int(State &, double)>       {std::bind( h, std::placeholders::_1, std::placeholders::_2 )}};
    Callable_variant i2 {"i",  std::function<int(int)>                   {std::bind( f, 1 )}};
    Callable_variant i3 {"i2", std::function<int(int &)>                 {std::bind( f, std::placeholders::_1 )}};

    cout << "###" << endl;
    return 0;
}
