#include <iostream>
#include <array>
#include <functional>
using namespace std;

enum class Status_char: char16_t {  // todo: why can't I get an enum class to compile?  Value type for array<> init???
    BLUE = 0x55,
    GREEN = 'x'
};

enum class Status: int {  // todo: why can't I get an enum class to compile?  Value type for array<> init???
    BLUE = 0,
    GREEN = 1
};

template <typename T>
class Status_class {
public:
//    Status_class (int in_val) {
//        my_val = in_val;
//    }
    Status_class () {
    }
    Status_class (T in_val) {
        my_val = in_val;
    }
    T my_val = 0;
//    using value_type = T;
};

typedef enum {  // todo: why can't I get an enum class to compile?  Value type for array<> init???
//typedef enum Status_old {
    BLUE = 0,
    GREEN = 1
} Status_old;

int main()
{
    // array<int, 100> a(Status::BLUE);
    array<int, 100> a2 {};
    a2.fill(0);
    a2.fill(static_cast<int>(Status::BLUE));  // todo: compile error

    array<Status, 100> a3 {};
    a3.fill(Status::BLUE);  // todo: compile error
//    a3.fill(0);  // todo: compile error

    array<Status_old, 100> a4 {};
    a4.fill(Status_old::BLUE);  // todo: compile error
    a4.fill(static_cast<Status_old> (1));  // todo: compile error

    array<int, 100> a5 {};
    a5.fill(7);
    a5.fill(Status_old::BLUE);

    array<Status_char, 100> a6 {};
    a6.fill(Status_char::BLUE);

    array<Status_class<int>, 100> a7 {};
    Status_class<int> v_val {99};
    a7.fill(std::move(v_val));
    a7.fill(98);

    // a1.fill(std::ref(Status::BLUE));  // todo: compile error
    // a1.fill(std::move(Status::BLUE));  // todo: compile error

    cout << "###" << endl;
    return 0;
}
    // a1.fill(std::ref(Status::BLUE));  // todo: compile error
    // a1.fill(std::move(Status::BLUE));  // todo: compile error
    cout << "###" << endl;
    return 0;
}
