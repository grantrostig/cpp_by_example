#include <iostream>
#include <string>

using namespace std::literals;

namespace test_03_ns {
struct TCPConnection
{
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection
{
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};
}

void test_03() {
    using namespace test_03_ns;
    TCPConnection con;
    con.send("Hello");
    UDPConnection con2;
    con2.send("Hello");
}
