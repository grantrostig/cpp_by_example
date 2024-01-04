#include <iostream>
#include <memory>
using namespace std::literals;
namespace test_02_ns {
struct I_Connection {                         // Abstract class or Interface
    virtual ~I_Connection() = default;
    virtual void send(const char *) = 0;
};

struct TCPConnection : public I_Connection {
    void send(const char *s) override { std::cout << "TCP2: " << s << std::endl; }
};

struct UDPConnection : public I_Connection {
    void send(const char *s) override { std::cout << "UDP2: " << s << std::endl; }
};

struct I_ConnectionFactory {                  // Abstract class of Interface
    virtual ~I_ConnectionFactory() = default;
    virtual std::unique_ptr<I_Connection> make() = 0;
};

struct TCPConnectionFactory : public I_ConnectionFactory {
    //I_Connection *make() override { return std::make_unique<TCPConnection>(); }
    std::unique_ptr<I_Connection> make() override { return std::make_unique<TCPConnection>(); }
};

struct UDPConnectionFactory : public I_ConnectionFactory {
    std::unique_ptr<I_Connection> make() override { return std::unique_ptr<UDPConnection>(); }
};

//void use_factory(std::unique_ptr<I_ConnectionFactory> &i_conFactory) {
void use_factory(std::unique_ptr<I_ConnectionFactory> i_conFactory) {
    std::unique_ptr<I_Connection> i_con{i_conFactory->make()};  // static type
    i_con->send("Hello");                       // dynamic type is run
    i_con.reset(nullptr);
}}

void test_02() {  using namespace test_02_ns;
    //std::unique_ptr<I_ConnectionFactory> i_conFactory_uptr{std::make_unique<TCPConnectionFactory>()};   // static type
    std::unique_ptr<I_ConnectionFactory> i_conFactory_uptr{};   // static type
    i_conFactory_uptr = std::make_unique<TCPConnectionFactory>();   // static type

    use_factory(std::move(i_conFactory_uptr));
    //use_factory(i_conFactory_uptr);

    //i_conFactory_uptr.reset(nullptr);
 // i_conFactory_uptr.reset(new UDPConnectionFactory);                                                  // static type
    //use_factory(std::move(i_conFactory_uptr));
 // use_factory(i_conFactory_uptr);
 // i_conFactory_uptr.reset(nullptr);
}
