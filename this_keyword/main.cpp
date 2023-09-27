#include <iostream>
#include <functional>
#include <any>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

int f(int i) {
    return i;
}

int f2(int i) {
    cout << "f2 address from within: " << (long)f2 << endl;
    return i;
}

long g(long i) {
    return i;
}

string k(string s) {
    return s;
}

float h(float s) {
    return s;
}

struct row {
    long 	fn {};
    string 	label {};
    auto  my_this1 () { return this; };
    row * my_this2 () { return this; };
};

struct function1_object {
    int operator()(int j, int k) {
        cout << "within function1_object operator call." << endl;
    }
};

int main() {
    auto address_g  { g };
    auto address_f1 { k };
    auto address_f2 { &k };
    auto address_f3 { (long)k };
    auto address_f5 { (void *)k };
    auto address_f4 { k("hello") };
    std::function 	f6 = k; 		// todo: what about?? std::mem_fn, std::reference_wrapper
    std::any 		f7 = k;  		// actually want to limit variable to "any" function.

    const std::type_info & 	stuff  { typeid( h ) };  // why can't I remove the & reference modifier?? ?
    string 					stuff1 { typeid( h ).name() };
    size_t 					stuff2 { typeid( h ).hash_code() };

    //vector<long> function_handles{ (long)f2, (long)g, (long)h, (long)k };
    //vector function_handles{ (void *)f2, (void *)g, (void *)h, (void *)k };
    //vector function_handles{ (void *)f2, (void *)g, (void *)h, (void *)k };
    //vector function_handles { f2, g, h, k };
    vector function_handles{ typeid(f2).name(), typeid(f2).name(), typeid(g).name(), typeid(h).name(), typeid(k).name() };
    //vector function_handles{ typeid(f2).hash_code(), typeid(g).hash_code(), typeid(h).hash_code(), typeid(k).hash_code() };

    //if (function_handles.at(2) == reinterpret_cast<long>(h)) {
        //cout << "we have a g()." << endl;
    //}

    f2(22);

    for (auto & j : function_handles) {
        cout << j << std::endl;
/*        switch (j) {
//        case (unsigned long long) f:
//            cout << " f, " << endl;
//            break;
//        case reinterpret_cast<long> (g):
//            cout << " g, " << endl;
//            break;
//        case (void *) (g) :
//                cout << " g, " << endl;
//                break;
//        }
*/
    }
    std::cout << "###" << endl;
    return 0;
}
