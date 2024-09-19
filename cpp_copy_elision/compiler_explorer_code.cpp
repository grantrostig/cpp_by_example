#include <string>
#include <vector>
int f(int a) {
    a++;
    return a;
}

void g() {
    int b{f(int{2})}; 
    return;
}

int main() { 
    g(); 
    return 0;
}