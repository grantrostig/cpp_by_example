#include <iostream>
namespace test_01_ns {
struct I_Connection {                         // Abstract class or Interface
    virtual ~I_Connection()         =default;
    virtual void send(const char *) =0;
};

struct TCPConnection final : public I_Connection {
    void send(const char *s) override final { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection final : public I_Connection {
    void send(const char *s) override final { std::cout << "UDP: " << s << '\n'; }
};

struct I_ConnectionFactory {                  // Abstract class of Interface
    virtual ~I_ConnectionFactory()  =default;
    virtual I_Connection *make()    =0;
};

struct TCPConnectionFactory final : public I_ConnectionFactory {
    I_Connection *make() override final { return new TCPConnection(); }
};

struct UDPConnectionFactory final : public I_ConnectionFactory {
    I_Connection *make() override final { return new UDPConnection(); }
};

void use_factory(I_ConnectionFactory *i_conFactory) {
    I_Connection *i_con{ i_conFactory->make() };  // static type
    i_con->send("Hello");                       // dynamic type is run
    delete i_con;
}}

void test_01() { using namespace test_01_ns;
    I_ConnectionFactory *i_conFactory_ptr;          // static type

    i_conFactory_ptr = new TCPConnectionFactory();  // dynamic type
    use_factory(i_conFactory_ptr);
    delete i_conFactory_ptr;

    i_conFactory_ptr = new UDPConnectionFactory();
    use_factory(i_conFactory_ptr);
    delete i_conFactory_ptr;
}
