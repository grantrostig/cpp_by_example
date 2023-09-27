#include <iostream>
#include <cassert>

using namespace std;

#define EQUALS ==
#define ASSIGN =

/*
 * This equation defines a surface in 3 dimensions, therefore it has many solutions.
 *
 * Original question:  3 * _ * 2 * _ = 40 * _; where 5 * 8 = 40;  fill in the blanks to make the equation true.
 */

double lhs(double x, double y) {
    return 3*x * 2*y;
}

double rhs(double z) {
    return 40*z;
}

int main()
{
    const double epsilon {1e-10};  // we don't want to compare doubles for equality do we.

    double x {1};
    double y {20.0/3.0};
    double z {1};
    cout << lhs(x,y) << ", " << rhs(z) << endl;
    assert( abs( lhs(x,y) - rhs(z)) < epsilon);

    double n1 {1};
    double n2 {1};
    x ASSIGN 20*n1;
    y ASSIGN 20*n2;
    z ASSIGN 60*n1*n2;
    cout << lhs(x,y) << ", " << rhs(z) << endl;
    assert( abs( lhs(x,y) - rhs(z)) < epsilon);

    n1 ASSIGN 1;
    n2 ASSIGN 7;
    double intermediate {4*n2+1};
    x ASSIGN 20 * n1;
    y ASSIGN  5  *      intermediate;
    z ASSIGN 15  * n1 * intermediate;
    cout << lhs(x,y) << ", " << rhs(z) << endl;
    assert( abs( lhs(x,y) - rhs(z)) < epsilon);

    cout << "###" << endl;
    return 0;
}
