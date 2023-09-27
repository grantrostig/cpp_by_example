#include <iostream>

using namespace std;

int main()
{
    int a,b {99};
    switch ( int i = ( b += 55555,3); i = 3*i) {
    //switch ( int i = ( b += 55555,3); int a = 3*i) {
    case (1):
    case (2):
        cout << "case2\n";
        break;
    default:
        cout << i << ", " << a <<endl;
    }
    cout << b << endl;
    cout << "###" << endl;
    return 0;
}
