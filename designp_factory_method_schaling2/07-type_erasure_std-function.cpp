#include <functional>
#include <iostream>
#include <memory>
using namespace std;

namespace test_07_ns {
class Connection {
public:
    virtual ~Connection()           =default;
    virtual void send(const char *) =0;
};

class TCPConnection : public Connection {
public:
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

class UDPConnection : public Connection {
public:
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

class TCPConnectionFactory {
public:
    std::unique_ptr<Connection> operator()() {
        return std::unique_ptr<Connection>(new TCPConnection);
    }
};

class UDPConnectionFactory {
public:
    std::unique_ptr<Connection> operator()() {
        return std::unique_ptr<Connection>(new UDPConnection);
    }
};

// Type erasure?
template<class ConnectionFactory>
void send(ConnectionFactory &conFactory) {
    auto con = conFactory();
    con->send("Hello");
}}

void test_07() { using namespace test_07_ns; cout << "START test 07" << endl;
    std::function<std::unique_ptr<Connection>()> con_factory;
    con_factory = TCPConnectionFactory();
    send(con_factory);

    con_factory = nullptr;  // TODO??: Does this release most/all memory?
    // con_factory.target( TCPConnectionFactory());  // TODO: review what target() does.

    con_factory = UDPConnectionFactory();
    send(con_factory);

    // factory.~YYYY();  // TODO??: what is destructor?
    cout << "END   test 07" << endl;
}
