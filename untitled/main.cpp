#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}


// Instead of using macros, or #include try a function, also consider throw, or setjump/longjump
int f( int i){
    if (i) return 1;
    return 2;
}

int check_interation_result(int i){
    int k{};
    if (i)
        return;
    else
        return (k=2);
}

int main /* menu system runner fn */ () {
    while (true) {
        int interation_result{f(1)}; // we called the menu action and it did something.
        // return check_interation_result(interation_result);
        // return TERNARY OPERATOR??check_interation_result(interation_result);
        if (check_interation_result == 1) return();
    }
}
