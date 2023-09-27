#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:  // check on alternate solution with o(log n)?? solution : factor by mod 2
    double myPow(double x, int n) {
        if (n == 0) return 1;
        // Line 6: Char 24: runtime error: negation of -2147483648 cannot be represented in type 'int';
        //   cast to an unsigned type to negate this value to itself (solution.cpp)
        if (n < 0) {
            x = 1/x;
            long n2 = n;
            n2 = -n2;
            n = n2;
        }

        double orig_x = x;

        // Line 7: Char 37: runtime error: negation of -2147483648 cannot be represented in
        //     type 'int'; cast to an unsigned type to negate this value to itself (solution.cpp)
        for (int i = 0; i < std::abs(n) - 1; ++i) {
            x=orig_x * x;
            if (x == 0.0) return 0;
            else if (x == 1.0) return 1;
        }
        return x;
    }
};


int main()
{
    Solution s;
    cout << s.myPow(2,8) << endl;
    cout << std::pow(2,8) << endl;

    cout << s.myPow(7,0) << endl;
    cout << std::pow(7,0) << endl;

    cout << s.myPow(0,0) << endl;
    cout << std::pow(0,0) << endl;

    cout << s.myPow(1,1) << endl;
    cout << std::pow(1,1) << endl;

    cout << s.myPow(2,-8) << endl;
    cout << std::pow(2,-8) << endl;

    cout << std::pow(.00001,2147483647) << endl;
    cout << s.myPow( .00001,2147483647) << endl;

    cout << std::pow(.00001,-2147483647) << endl;
    cout << s.myPow( .00001,-2147483647) << endl;

    cout << std::pow(1,2147483647) << endl;
    cout << s.myPow( 1,2147483647) << endl;

    cout << std::pow(1,-2147483647) << endl;
    cout << s.myPow( 1,-2147483647) << endl;

    cout << "###" << endl;
    return 0;
}
