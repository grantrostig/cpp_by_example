#include <iostream>
#include <string>
using namespace std;
namespace test_04_ns {
struct TCPConnection {
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection {
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

TCPConnection make_tcp_connection() {
    return TCPConnection();
}

UDPConnection make_udp_connection() {
    return UDPConnection();
}

template<class ConnectionFactory>
void send(ConnectionFactory &conFactory) {
    auto con = conFactory();
    con.send("Hello");
}}

void test_04() { using namespace test_04_ns; cout << "START test 04" << endl;
    send(make_tcp_connection);
    send(make_udp_connection);
    cout << "END  test 04" << endl;
}
