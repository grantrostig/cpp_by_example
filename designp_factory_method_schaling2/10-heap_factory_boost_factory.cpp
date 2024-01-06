#include <boost/functional/factory.hpp>
#include <iostream>
#include <string>

using namespace std::literals;

struct TCPConnection {
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection {
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

using TCPConnectionFactory = boost::factory<TCPConnection *>;
using UDPConnectionFactory = boost::factory<UDPConnection *>;

template<class ConnectionFactory>
void send(ConnectionFactory const & conFactory) {  // Will bind to a temporary?
//void send(ConnectionFactory && conFactory) {
    auto *con = conFactory();
    con->send("Hello");
    delete con;
}

void test_10() {
    auto x =TCPConnectionFactory();
    send(x);

    send(TCPConnectionFactory());  // temporary is good enough and ends at ";"
    send(UDPConnectionFactory());
}