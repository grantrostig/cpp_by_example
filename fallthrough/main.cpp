#include <iostream>
using namespace std;

int c(int);

int a(const int a1) {
    srand(a1);
    int a2 {12};
    while (a2%5 != 0 ) {
        a2 = rand()%17;
        switch (a2) {
        case 0:
            cout << "0\n";
            return 0;
        case 11:  // DIFFERENT from c()!!
            cout << "1\n";
            a(a2*2);
            return a2*2;
        case 2:
            cout << "2\n";
            b(2);
            break;
        case 6:
            cout << "6\n";
            break;
        case 8:
            cout << "8\n";
            continue;
        case 16:
            cout << "16\n";
            c(a2);
            break;
        case 14:
            cout << "14\n";
            break;
        default:
            cout << "other\n";
            continue;
        }
    }
    return 3;
}

int b(const int a1) {
    srand(a1);
    int a2 {12};
    while (a2%5 != 0 ) {
        a2 = rand()%17;
        switch (a2) {
        case 0:
            cout << "0\n";
            return 0;
        case 21:  // DIFFERENT!!
            cout << "1\n";
            a(a2*2);
            return a2*2;
        case 2:
            cout << "2\n";
            b(2);
            break;
        case 6:
            cout << "6\n";
            break;
        case 8:
            cout << "8\n";
            continue;
        case 16:
            cout << "16\n";
            a(a2); // DIFFERENT
            break;
        case 14:
            cout << "14\n";
            break;
        default:
            cout << "other\n";
            continue;
        }
    }
    return 3;
}

int c(const int a1) {
    srand(a1);
    int a2 {12};
    while (a2%5 != 0 ) {
        a2 = rand()%17;
        switch (a2) {
        case 0:
            cout << "0\n";
            return 0;
        case 1:
            cout << "1\n";
            a(a2*2);
            return a2*2;
        case 2:
            cout << "2\n";
            b(2);
            break;
        case 6:
            cout << "6\n";
            break;
        case 8:
            cout << "8\n";
            continue;
        case 16:
            cout << "16\n";
            c(a2);
            break;
        case 14:
            cout << "14\n";
            break;
        default:
            cout << "other\n";
            continue;
        }
    }
    return 3;
}

int main() {
    cout << c(42) << endl;
    cout << "###" << endl;
}
