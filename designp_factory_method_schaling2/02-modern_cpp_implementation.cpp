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
    virtual unique_ptr<I_Connection> make()         =0;
};

struct TCPConnectionFactory final : public I_ConnectionFactory {
    unique_ptr<I_Connection> make() override final { return make_unique<TCPConnection>(); }   // TODO??: RVO? Moved?
};

struct UDPConnectionFactory final : public I_ConnectionFactory {
    unique_ptr<I_Connection> make() override final { return unique_ptr<UDPConnection>(); }    // TODO??: Does this non-make elide one new()?
};

#define PASS_BY_REF
#ifdef PASS_BY_REF
  void use_factory_hello(I_ConnectionFactory &i_conFactory) {
    unique_ptr<I_Connection> i_con = i_conFactory.make();  // static type
    i_con->send("Hello");                       // dynamic type is run
  }
  void use_factory_bye(                I_ConnectionFactory & i_conFactory) {
    unique_ptr<I_Connection> i_con = i_conFactory.make();  // static type
    i_con->send("Bye");                       					// dynamic type is run
  }
#else
  void use_factory_hello(unique_ptr<I_ConnectionFactory> i_conFactory) {
    unique_ptr<I_Connection> i_con{  i_conFactory->make() };  // static type
    i_con->send("Hello");                       // dynamic type is run
  }
  void use_factory_bye(unique_ptr<I_ConnectionFactory>  i_conFactory) {
    unique_ptr<I_Connection> i_con { i_conFactory->make() };  // static type
    i_con->send("Bye");                       					// dynamic type is run
  }
#endif

auto use_factory_return_it(unique_ptr<I_ConnectionFactory> i_conFactory) {
    unique_ptr<I_Connection> i_con{i_conFactory->make()};  // static type
    i_con->send("RETURN_HELLO");                       			// dynamic type is run
    return i_conFactory;
}}

void test_02() {  using namespace test_02_ns;
    unique_ptr<I_ConnectionFactory> i_conFactory_uptr{};   		// static type, but NULL
    i_conFactory_uptr = make_unique<TCPConnectionFactory>();   	// static type, loaded.
                        // OR JUST: unique_ptr<I_ConnectionFactory> i_conFactory_uptr{make_unique<TCPConnectionFactory>()};

    //i_conFactory_uptr.reset( make_unique<TCPConnectionFactory>() );// TODO??: Why? FAIL static type, loaded.
    i_conFactory_uptr.reset(new TCPConnectionFactory);                  // static type, loaded

    #ifdef PASS_BY_REF
    use_factory_hello(*i_conFactory_uptr);	// We didn't pass the pointer, or ownership, just the value, which is a covariant factory class
    use_factory_bye(*i_conFactory_uptr);
    #else
    //use_factory_hello(move(i_conFactory_uptr));
    i_conFactory_uptr = use_factory_return_it(move(i_conFactory_uptr));
                                // i_conFactory_uptr = use_factory_return_it(i_conFactory_uptr);			// FAILS because we can't copy it.
    assert(i_conFactory_uptr.get());
    use_factory_bye(move(i_conFactory_uptr));
    #endif

    unique_ptr<I_ConnectionFactory> i_conFactory_uptr_md{make_unique<TCPConnectionFactory>()};   // static type
    #ifdef PASS_BY_REF
    use_factory_hello(*i_conFactory_uptr_md);
    #else
    use_factory_hello(move(i_conFactory_uptr_md));
    #endif

    i_conFactory_uptr.reset(nullptr);
    i_conFactory_uptr.reset(new UDPConnectionFactory);                                                  // static type
    use_factory_hello(move(i_conFactory_uptr));
    use_factory_hello(i_conFactory_uptr);
    i_conFactory_uptr.reset(nullptr);
}


