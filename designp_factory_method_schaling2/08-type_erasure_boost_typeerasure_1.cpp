#include <boost/type_erasure/any.hpp>
#include <boost/type_erasure/builtin.hpp>
#include <boost/type_erasure/member.hpp>
#include <functional>
#include <iostream>
using namespace std;

namespace test_08_ns {
struct TCPConnection { void send(const char *s) { std::cout << "TCP: " << s << '\n'; } };
struct UDPConnection { void send(const char *s) { std::cout << "UDP: " << s << '\n'; } };

struct TCPConnectionFactory {
    TCPConnection operator()() { return TCPConnection(); }
};

struct UDPConnectionFactory {
    UDPConnection operator()() { return UDPConnection(); }
};

template<class ConnectionFactory>
void send(ConnectionFactory &conFactory) {
    auto con = conFactory();
    con.send("Hello");
}

// Large MACRO
BOOST_TYPE_ERASURE_MEMBER((has_send), send)
using Connection = boost::type_erasure::any<
    boost::mpl::vector<has_send<void(const char *)>, boost::type_erasure::copy_constructible<>>>;
}

void test_08() { using namespace test_08_ns; cout << "START test 09" << endl;
    std::function<Connection()> con_factory;
    con_factory = TCPConnectionFactory();
    send(con_factory);
    con_factory = nullptr;

    con_factory = UDPConnectionFactory();
    send(con_factory);
    cout << "END   test 09" << endl;
}
