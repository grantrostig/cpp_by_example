#include <iostream>
#include <string>

using namespace std::literals;

namespace test_05_ns {
struct TCPConnection
{
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection
{
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

struct TCPConnectionFactory
{
    TCPConnection make() { return TCPConnection(); }
};

struct UDPConnectionFactory
{
    UDPConnection make() { return UDPConnection(); }
};

template<class ConnectionFactory>
void send(ConnectionFactory &conFactory)
{
    auto con = conFactory.make();
    con.send("Hello");
}
}

void test_05() {
    using namespace test_05_ns;
    TCPConnectionFactory tcp_factory;
    send(tcp_factory);
    //delete tcp_factory;
    UDPConnectionFactory udp_factory;
    send(udp_factory);
}
