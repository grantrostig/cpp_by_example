#include <iostream>
#include <functional>
#include <string>

int fn( int a, double b, int & c ) { return a+b+c; }

struct Fn_struct {
    std::string	name {};
    std::function<decltype(fn)> my_fn {fn}; // std::function<int (int,int&)> my_fn {};
};
struct Fn_struct2 {
    std::string	name {};
    std::function<int(int&)> my_fn {}; // std::function<int (int,int&)> my_fn {};
};
struct Fn_struct3 {
    std::string	name {};
    std::function<int()> my_fn {}; // std::function<int (int,int&)> my_fn {};
};

int main()
{ 		// https://stackoverflow.com/questions/59595616/c-how-can-we-bind-a-placeholder-to-a-reference-ref-argument-when-initializing?noredirect=1#comment105356971_59595616
    int q = 3;
    Fn_struct 	my_fn_struct1 	{ "fn(a,b)", std::function<decltype (fn)> {fn} };
    Fn_struct 	my_fn_struct2 	{ "fn(a,b)", {fn} };
    Fn_struct 	my_fn_struct3 	{ "fn(a,b)", {std::bind( fn, 1, 2.1, 3) }};
    //Fn_struct2 my_fn_struct32 { "fn(a,b)", {std::bind( fn, 1, 2.1, 3) }};  // why does this compile? seems to ignore parameters because all arguments have been satisfied?
    //Fn_struct3 my_fn_struct33 { "fn(a,b)", {std::bind( fn, 1, 2.1, 3) }};  // why does this compile?
    auto fn_a = std::bind( fn, 1, 2.1, q );
    auto fn_b = std::bind( fn, 1, 2.1, std::placeholders::_1 );
    //Fn_struct my_fn_struct4 	{"fn(a,b)", {std::bind( fn, 1, 2, std::placeholders::_1) }};  // todo: TODO why can't int b be a reference?
    Fn_struct2 	my_fn_struct42 	{ "fn(a,b)", { std::bind( fn, 1, 2, std::placeholders::_1) }};  // WORKS!
    Fn_struct 	my_fn_struct4 	{ "fn(a,b)", [] (int, double, int&) { int p_1; return fn( 1, 2.0, p_1); }};
    //Fn_struct my_fn_struct5 	{ "fn(a,b)", std::function<decltype (fn)> {fn_b} };  // todo: TODO why can't int b be a reference?

    int r = 0, d = 99;
    r = fn_a(42);
    std::cout << r << std::endl;
    r = fn_a(1,2,1000);
    std::cout << r << std::endl;

    r = fn_b(d);
    std::cout << r << std::endl;

    //r =  my_fn_struct1.my_fn(1,2,3);
    std::cout << r << std::endl;
    //r =  my_fn_struct2.my_fn(1,2,3);
    std::cout << r << std::endl;
    //r =  my_fn_struct3.my_fn(1,2,3);
    std::cout << r << std::endl;
}
