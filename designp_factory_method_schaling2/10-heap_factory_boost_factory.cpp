#include <boost/functional/factory.hpp>
#include <iostream>
using namespace std;

namespace test_10_ns {
struct TCPConnection { void send(const char *s) { std::cout << "TCP: " << s << '\n'; } };
struct UDPConnection { void send(const char *s) { std::cout << "UDP: " << s << '\n'; } };

// NOT value, but ptr // TODO??: What sort of pointer and where is it?
using TCPConnectionFactory = boost::factory<TCPConnection *>;
using UDPConnectionFactory = boost::factory<UDPConnection *>;

template<class ConnectionFactory>
void send(ConnectionFactory const & conFactory) {   // Will bind to a temporary if it is const.
// OR THIS: $ void send(ConnectionFactory && conFactory) {
    auto *con_factory_ptr = conFactory();
    con_factory_ptr->send("Hello");

    delete con_factory_ptr;                                     // TODO??: What is deleted and what not?
}}

void test_10() { using namespace test_10_ns; cout << "START test 10" << endl;
    // OR THIS: $ send(TCPConnectionFactory());  // temporary is good enough and ends at ";"
    boost::factory<TCPConnection *> boost_factory{TCPConnectionFactory()};
    send(boost_factory);

    send( UDPConnectionFactory() );
    cout << "END   test 10" << endl;
}
