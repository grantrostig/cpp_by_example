#include <iostream>

using namespace std;

int main()
{
    cout << "test: r" << endl;
    cout << "1..Hello World!";
    cout << '\r';
    cout << "2r.Hello World!" << endl;
    cout << "test: n // does what I would expect NL CR to do!" << endl;
    cout << "1Hello World!";
    cout << '\n';
    cout << "2n.Hello World!" << endl;
    cout << "test: f // does what I would have expected a NL to do!" << endl;
    cout << "1..Hello World!";
    cout << '\f';
    cout << "2f.Hello World!" << endl;
    return 0;
}
