#include <iostream>

using namespace std;

void my_function() {
    static int a {2};
    a++;
    cout << a << endl;
}

int main()
{
    my_function();
    my_function();
    my_function();
    my_function();
    my_function();
    cout << "Hello World!" << endl;
    return 0;
}
