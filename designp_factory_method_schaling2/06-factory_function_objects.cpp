#include <iostream>
#include <string>

using namespace std::literals;

namespace test_06_ns {
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
    TCPConnection operator()() { return TCPConnection(); }
};

struct UDPConnectionFactory
{
    UDPConnection operator()() { return UDPConnection(); }
};

template<class ConnectionFactory>
void send(ConnectionFactory &conFactory)
{
    auto con = conFactory();
    con.send("Hello");
}
}

void test_06() {
    using namespace test_06_ns;
    TCPConnectionFactory tcp_factory;
    send(tcp_factory);
    //delete tcp_factory;
    UDPConnectionFactory udp_factory;
    send(udp_factory);
}
