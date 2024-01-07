/* IPV means: Interface via Pure Virtual technique. */
#include <iostream>
#include <memory>
using namespace std;
namespace test_13_ns {

#define MEMBER_FN_GENERATOR( UDT_with_one_fn, member_fn_name ) \
    template<typename T> class UDT_with_one_fn; /* Forward Decl and ENDs template with ";" */ \
                                                            \
    template<typename Return_type, typename... Args>        \
    class UDT_with_one_fn< Return_type( Args... ) > {       \
    public:                                                 \
        Return_type member_fn_name( Args... args ) {        \
            return object_base_uptr_->invoke( args... );    \
        }                                                   \
                                                            \
    protected:                                              \
        class IPV_Object_base  {                            \
        public:                                             \
            virtual ~IPV_Object_base()            =default; \
            virtual Return_type invoke( Args... )  =0;      \
        };                                                  \
                                                            \
        template<typename UDT_with_one_fn> /* TODO??: Should this typename have a different name? Is it seperable? */                 \
        class Object_derived : public IPV_Object_base  {    \
            UDT_with_one_fn t_;                             \
        public:                                             \
            Object_derived(UDT_with_one_fn t) : t_{t} {}    \
            Return_type invoke( Args... args ) override {   \
                return t_.member_fn_name( args... );        \
            }                                               \
        };                                                  \
                                                            \
        std::unique_ptr<IPV_Object_base> object_base_uptr_; /* can we make this private with using friend? Would that better? */ \
    }; // END template. // END Macro.

MEMBER_FN_GENERATOR( UDT_with_named_fn, send )
using UDT_with_named_fn_parameterized = UDT_with_named_fn< void(const char *) >;

template<typename UDT_base>
class Target_Concrete_Derived_UDT : public UDT_base {                     // TODO??: Where is assignment used?
public: template<typename T>
    void operator=(T t) {
        UDT_base::object_base_uptr_ = std::make_unique<
            typename UDT_base::template Object_derived<T>    // Dynamic uptr. // TODO??: what are "template" & "::template" here?
        >( t );
    }
}; // END template.
using Connection = Target_Concrete_Derived_UDT< UDT_with_named_fn_parameterized >;

class TCPConnection { public: void send(const char *s) { std::cout << "TCP: " << s << '\n'; } };
class UDPConnection { public: void send(const char *s) { std::cout << "UDP: " << s << '\n'; } };}

void test_13() { using namespace test_13_ns; cout << "START test 13" << endl;
    Connection c;
    c = TCPConnection{}; // TODO??: Why fail when other works, a constructor missing? $ Connection c2 = {TCPConnection{}};
    c.send("Hello form TCP");

    c = UDPConnection{};
    c.send("Hello from UPD");

    cout << "END   test 13" << endl;
}
