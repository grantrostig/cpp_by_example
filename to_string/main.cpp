#include <iostream>
#include <charconv>
#include <array>
#include <string_view>
#include <system_error>

using namespace std;

int main()
{

    cout << to_string(1.05)<< "Hello World!" << endl;
    std::array<char,20> array {};
    int   valuei {42};
    float valuef {42};
    double valued {42};
    auto [p, ec] = std::to_chars( array.data(), array.data() + array.size(), valued );

    cout << std::string_view(array.data(), p - array.data()) << "Hello World!" << endl;
    return 0;
}
