#include <iostream>
#include <span>
#include <cassert>
using namespace std;

template<typename Container>
int sum3(const Container& c) {
    return c[0] + c[1] + c[2];  // how to guarantee it has three elements?
}

int sum3span(const std::span<int,3>& c) {
    //assert(c.size() >=3);
    return c[0] + c[1] + c[2];
}

int main() {
    int ar[] = {1, 2, 3};
    int r {sum3(ar)};
    int rs {sum3span(ar)};

    int a=2, b=3;
    int& aref=a;  // Let's see if refs generate the same assembly code
    int& bref=b;
    int answer1 = a+b;
    int answer2 = aref + bref;

    return answer2;
}
