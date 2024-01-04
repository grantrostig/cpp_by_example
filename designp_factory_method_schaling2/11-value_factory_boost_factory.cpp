#include <boost/functional/value_factory.hpp>
#include <iostream>
#include <string>

using namespace std::literals;

struct TCPConnection
{
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection
{
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

using TCPConnectionFactory = boost::value_factory<TCPConnection>;
using UDPConnectionFactory = boost::value_factory<UDPConnection>;

template<class ConnectionFactory>
void send(ConnectionFactory &conFactory) {
    auto con = conFactory();
    con.send("Hello");
}

void test_11() {
    send(TCPConnectionFactory());
    send(UDPConnectionFactory());
}
