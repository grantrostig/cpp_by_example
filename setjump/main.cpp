#include <iostream>
#include <csetjmp>

std::jmp_buf jump_buffer;

// [[noreturn]]
void b(int count)
{
    std::cout << "b(" << count << ") begining of call.\n";
    std::longjmp(jump_buffer, count+1);  // setjmp() will return count+1
    std::cout << "end of b(" << count << ") called\n";
}

void a(int count) {
    std::cout << "a(" << count << ") before b.\n";
    b(count);
    std::cout << "end of a(" << count << ") called.\n";
}

int main()
{
    volatile int count = 0; // modified locals in setjmp scope must be volatile
    std::cout << "before if.\n";
    if (int i = setjmp(jump_buffer); i != 9) { // equality against constant expression in an if
        std::cout << "before a.\n";
        a(++count);  // This will cause setjmp() to exit
        std::cout << "last if.\n";
    } else std::cout << "else.n";
    std::cout << "###\n";
}
