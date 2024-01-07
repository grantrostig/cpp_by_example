#include <iostream>
using namespace std;

namespace test_03_ns {
struct TCPConnection {
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection {
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
}; }

// No design pattern
void test_03() { using namespace test_03_ns; cout << "Start test 03" << endl;
    TCPConnection con;
    con.send("TCP Hello");
    UDPConnection con2;
    con2.send("UDP Hello");
    cout << "END  test 03" << endl;
}
