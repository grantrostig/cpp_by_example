#include <iostream>
#include <string>
using namespace std;
namespace test_05_ns {
struct TCPConnection {
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection {
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

struct TCPConnectionFactory {
    TCPConnection make() { return TCPConnection(); }
};

struct UDPConnectionFactory {
    UDPConnection make() { return UDPConnection(); }
};

template<class ConnectionFactory>
void send(ConnectionFactory &conFactory) {
    auto con = conFactory.make();
    con.send("Hello");
}}

void test_05() { using namespace test_05_ns; cout << "STARTtest 05" << endl;
    TCPConnectionFactory tcp_factory;
    send(tcp_factory);
    tcp_factory.~TCPConnectionFactory();

    UDPConnectionFactory udp_factory;
    udp_factory.~UDPConnectionFactory();
    send(udp_factory);
    cout << "END  test 05" << endl;
}
