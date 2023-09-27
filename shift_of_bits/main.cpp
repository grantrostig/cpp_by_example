#include <iostream>

using namespace std;

int main()
{
    for (auto i = 7; i < 66; ++i)
    {
        cout << (i >> 3) << endl;
        cout << (i / 8 ) << endl;
    }
    cout << "###" << endl;
    return 0;
}
