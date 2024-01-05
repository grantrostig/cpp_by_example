#include <cassert>
#include <iostream>
#include <memory>
#include <utility>
using namespace std;
namespace test_02_ns {
struct I_Connection {                               // Abstract class or Interface
    virtual ~I_Connection()                         =default;
    virtual void send(const char *)                 =0;
};

struct TCPConnection final : public I_Connection {
    void send(const char *s) override final { cout << "TCP2: " << s << endl; }
};

struct UDPConnection final : public I_Connection {
    void send(const char *s) override final { cout << "UDP2: " << s << endl; }
};

struct I_ConnectionFactory {                        // Abstract class of Interface
    virtual ~I_ConnectionFactory()                  =default;
    virtual unique_ptr<I_Connection> make()    =0;
};

struct TCPConnectionFactory final : public I_ConnectionFactory {
    unique_ptr<I_Connection> make() override final { return make_unique<TCPConnection>(); }   // TODO??: RVO? Moved?
};

struct UDPConnectionFactory final : public I_ConnectionFactory {
    unique_ptr<I_Connection> make() override final { return unique_ptr<UDPConnection>(); }    // TODO??: Does this non-make elide one new()?
};

//#define PASS_BY_REF
#ifdef PASS_BY_REF
void use_factory(I_ConnectionFactory &i_conFactory) {
    std::unique_ptr<I_Connection> i_con = i_conFactory.make();  // static type
#else
void use_factory(std::unique_ptr<I_ConnectionFactory> i_conFactory) {
    std::unique_ptr<I_Connection> i_con{i_conFactory->make()};  // static type
#endif
    i_con->send("Hello");                       // dynamic type is run
    //i_con.reset(nullptr);
}

#ifdef PASS_BY_REF
    void use_factory2(I_ConnectionFactory &i_conFactory) {
    std::unique_ptr<I_Connection> i_con = i_conFactory.make();  // static type
#else
    void use_factory2(std::unique_ptr<I_ConnectionFactory> i_conFactory) {
    std::unique_ptr<I_Connection> i_con{i_conFactory->make()};  // static type
#endif
    i_con->send("Bye");                       					// dynamic type is run
    i_con.reset(nullptr);
}

auto use_factory_rtn(std::unique_ptr<I_ConnectionFactory> i_conFactory) {
    std::unique_ptr<I_Connection> i_con{i_conFactory->make()};  // static type
    i_con->send("RETURN_HELLO");                       			// dynamic type is run
    return i_conFactory;
}}

void test_02() {  using namespace test_02_ns;
    std::unique_ptr<I_ConnectionFactory> i_conFactory_uptr{};   		// static type, but NULL
    i_conFactory_uptr = std::make_unique<TCPConnectionFactory>();   	// static type, loaded.
                        // OR JUST: unique_ptr<I_ConnectionFactory> i_conFactory_uptr{make_unique<TCPConnectionFactory>()};
    //i_conFactory_uptr.reset( std::make_unique<TCPConnectionFactory>() );// TODO??: Why? FAIL static type, loaded.
    i_conFactory_uptr.reset(new TCPConnectionFactory);                  // static type, loaded

    #ifdef PASS_BY_REF
    use_factory(*i_conFactory_uptr);	// We didn't pass the pointer, or ownership, just the value, which is a covariant factory class
    use_factory2(*i_conFactory_uptr);
    #else
    //use_factory(std::move(i_conFactory_uptr));
    //i_conFactory_uptr = use_factory_rtn(std::move(i_conFactory_uptr));
    //i_conFactory_uptr = use_factory_rtn(i_conFactory_uptr);			// FAILS because we can't copy it.
    assert(i_conFactory_uptr.get());
    use_factory2(std::move(i_conFactory_uptr));
    #endif

    std::unique_ptr<I_ConnectionFactory> i_conFactory_uptr_md{std::make_unique<TCPConnectionFactory>()};   // static type
    #ifdef PASS_BY_REF
    use_factory(*i_conFactory_uptr_md);
    #else
    use_factory(std::move(i_conFactory_uptr_md));
    #endif

    i_conFactory_uptr.reset(nullptr);
    i_conFactory_uptr.reset(new UDPConnectionFactory);                                                  // static type
    //use_factory(std::move(i_conFactory_uptr));
 // use_factory(i_conFactory_uptr);
 // i_conFactory_uptr.reset(nullptr);
//void use_factory(unique_ptr<I_ConnectionFactory> &i_conFactory) {
}


