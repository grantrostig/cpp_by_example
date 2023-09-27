#include <iostream>
using namespace std;

int level1();

int level2() {
    goto level1::label1;
    cout << "level2.\n";
}

int level1() {
label1: cout<< "In level1.\n";
//    goto label0;
    cout << "level1.\n";
}

int main() {
    level1();
    goto skip;
label0: cout<< "i'm back.\n";
skip: ;
    cout << "###" << endl;
    return 0;
}
