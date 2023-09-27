/*
 * Generated as part of the password manager effort
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int f(double a) {
    cout << "f(): " << a*2 << ", ";
    return a*2.0;
}

int g(double a) {
    cout << "g(): " << a*3 << ", ";
    return a*3.0;
}

struct Menu_item {
    int 				identifier {};
    int 			 (* ptr_function)(double) {};  // a pointer to a function which accepts a double and returns an int.
    vector<Menu_item> * ptr_sub_menu {nullptr};

//    Menu_item(int id_, int (* pt_) (double), Menu_item mi_): identifier(id_), ptr_function(pt_) {
//        ptr_sub_menu = & mi_; // todo: handle the lifetime of this object
//    }

//    Menu_item(int id_, int (* pt_) (double), Menu_item * ptr_mi_): identifier(id_), ptr_function(pt_), ptr_sub_menu(ptr_mi_) {}
};

int main()
{
    vector<Menu_item> menu;
    menu.emplace_back( Menu_item {123, &f, nullptr});
    menu.emplace_back( Menu_item {124, &g, nullptr});

    vector<Menu_item> menu_super;
    menu_super.emplace_back( Menu_item {125, &f, &menu});
    menu_super.emplace_back( Menu_item {125, &g, &menu});

    cout << "test directly calling a menu: \n";
    for (auto & i : menu) {
        cout << "call: " << i.ptr_function(5) << endl;
    }
    cout << "test calling the main menu and then items of a sub menu: \n";
    for (auto & i : menu_super) {
        cout << "call: " << i.ptr_function(6) << endl;
        vector<Menu_item> sub_menu {};

        if ( i.ptr_sub_menu != nullptr ) {
            sub_menu = *(i.ptr_sub_menu);
            for (auto &j : sub_menu) {
                cout << "sub_call: " << j.ptr_function(7) << endl;
            }
        }
    }
    cout << "###" << endl;
    return 0;
}
