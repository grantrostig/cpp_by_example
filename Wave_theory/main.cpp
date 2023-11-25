#include <bits/stdc++.h>

using namespace std;

int main() {
    cout.width(9);
    cout << "3.14x:";
    cout << '\n';
    for (long var = 0; var < 200; ++var) {
        cout.width(9);
        cout << var * 3.14 << " ";
        if ( !((var+1) % 20) ) cout << "\n";
    }
    cout << "\n\n8.6x:\n";
    for (long var = 0; var < 300; ++var) {
        cout.width(9);
        cout << defaultfloat<< var * 8.6 << " ";
        if ( !(var % 20) ) cout << "\n";
    }
    cout << "\n\n51.6x:\n";
    for (long var = 0; var < 300; ++var) {
        cout.width(9);
        cout << defaultfloat<< var * 51.6 << " ";
        if ( !(var % 20) ) cout << "\n";
    }

    cout << "\n###" << endl;
    return EXIT_SUCCESS;
}
