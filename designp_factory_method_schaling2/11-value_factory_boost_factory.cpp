#include <boost/functional/value_factory.hpp>
#include <iostream>
using namespace std;
namespace test_11_ns {
struct TCPConnection { void send(const char *s) { std::cout << "TCP: " << s << '\n'; } };
struct UDPConnection { void send(const char *s) { std::cout << "UDP: " << s << '\n'; } };

using TCPConnectionFactory = boost::value_factory<TCPConnection>;
using UDPConnectionFactory = boost::value_factory<UDPConnection>;

template<class ConnectionFactory>
void send(ConnectionFactory const &conFactory) {
    auto con = conFactory();
    con.send("Hello");
    // con.~<>(); TODO??: What is it and how does it get destructed
}}

void test_11() { using namespace test_11_ns; cout << "START test 11" << endl;
    send(TCPConnectionFactory());
    send(UDPConnectionFactory());
    cout << "END   test 11" << endl;
}
