/*
 * Demonstrates ambiguity on function and lambda signatures,
 * and maybe ADL?  Generated as part of password manager programing effort.
*/
#include <iostream>
#include <functional>
#include <string>

using namespace std;

 void f(std::function<int(double)>);  // these cause ambiguity
 void f(std::function<int(int)>);  // these cause ambiguity
 void h(std::function<int(int)>);  // these cause ambiguity
 // void f(std::function<int(float)>);  // these cause ambiguity
 // double f(std::function<int(int)>);  // these cause ambiguity
 // void f(std::function<int(std::string)>);  // different enough!

 void h(std::function<double(int)>);  // this return signature still causes ambiguity

int main()
{
    // https://app.slack.com/client/T21Q22G66/C21PKDHSL/thread/C21PKDHSL-1569120091.301300
    // https://cpplang.slack.com/archives/C21PKDHSL/p1569121028308700?thread_ts=1569120091.301300&cid=C21PKDHSL

    f( [] (int) ->int { return 0; });
//    f([](float){ return 0; });
//    f([](std::string){ return 0; });

    h( [] (int) ->double { return 0; });  // return type does not differentiate.

    std::function g = [](){ return 0; };  // apparently this type deduction works.
    cout << "###" << endl;
    return 0;
}
