#include <iostream>
#include <string>
using namespace std;
namespace test_06_ns {
struct TCPConnection {
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection {
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

struct TCPConnectionFactory {
    TCPConnection operator()() { return TCPConnection(); }
};

struct UDPConnectionFactory {
    UDPConnection operator()() { return UDPConnection(); }
};

template<typename Factory, typename Connection>
concept Createable =
    requires
    (
    )
{
    //requires;
    true;
};

template<class IConnectionFactory>
void send(IConnectionFactory &conFactory) {
    auto con = conFactory();
    con.send("Hello");
}}

void test_06() { using namespace test_06_ns; cout << "START test 05" << endl;
    TCPConnectionFactory tcp_factory;
    send(tcp_factory);
    UDPConnectionFactory udp_factory;
    send(udp_factory);
    cout << "END  test 06" << endl;
}
