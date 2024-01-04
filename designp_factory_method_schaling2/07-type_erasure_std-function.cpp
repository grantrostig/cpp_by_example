#include <functional>
#include <iostream>
#include <memory>
#include <string>

using namespace std::literals;

namespace test_07_ns {
struct Connection
{
    virtual ~Connection() = default;
    virtual void send(const char *) = 0;
};

struct TCPConnection : public Connection
{
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection : public Connection
{
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

struct TCPConnectionFactory
{
    std::unique_ptr<Connection> operator()()
    {
        return std::unique_ptr<Connection>(new TCPConnection);
    }
};

struct UDPConnectionFactory
{
    std::unique_ptr<Connection> operator()()
    {
        return std::unique_ptr<Connection>(new UDPConnection);
    }
};

template<class ConnectionFactory>
void send(ConnectionFactory &conFactory)
{
    auto con = conFactory();
    con->send("Hello");
}
}

void test_07()
{
    using namespace test_07_ns;
    std::function<std::unique_ptr<Connection>()> factory;
    factory = TCPConnectionFactory();
    send(factory);
    factory = nullptr;
    factory = UDPConnectionFactory();
    send(factory);
}
