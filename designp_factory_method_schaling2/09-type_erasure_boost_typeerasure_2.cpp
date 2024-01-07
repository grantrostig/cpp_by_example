#include <boost/type_erasure/any.hpp>
#include <boost/type_erasure/builtin.hpp>
#include <boost/type_erasure/member.hpp>
#include <boost/type_erasure/relaxed.hpp>
#include <iostream>
using namespace std;

namespace test_09_ns {
struct TCPConnection { void send(const char *s) { std::cout << "TCP: " << s << '\n'; } };

struct UDPConnection { void send(const char *s) { std::cout << "UDP: " << s << '\n'; } };

struct TCPConnectionFactory { TCPConnection make() { return TCPConnection(); } };

struct UDPConnectionFactory { UDPConnection make() { return UDPConnection(); } };

template<class ConnectionFactory>
void send(ConnectionFactory &conFactory) {
    auto con = conFactory.make();
    con.send("Hello");
}

// Large MACRO
//BOOST_TYPE_ERASURE_MEMBER((has_send), send)   // TODO??: Why the ()s
BOOST_TYPE_ERASURE_MEMBER( has_send , send)
using Connection = boost::type_erasure::any<
    boost::mpl::vector< has_send< void(const char *)>,
                        boost::type_erasure::copy_constructible<>
                       >
    >;

// Large MACRO
BOOST_TYPE_ERASURE_MEMBER((has_make), make)
using ConnectionFactory = boost::type_erasure::any<
    boost::mpl::vector< has_make< Connection() >,
                        boost::type_erasure::copy_constructible<>,
                        boost::type_erasure::relaxed
                       >
    >;
}

void test_09() { using namespace test_09_ns; cout << "START test 09" << endl;
    ConnectionFactory con_factory;
    con_factory = TCPConnectionFactory();
    send(con_factory);
    //delete con_factory;
    //con_factory.kkkkk;

    con_factory = UDPConnectionFactory();
    send(con_factory);
    cout << "END   test 09" << endl;
}
