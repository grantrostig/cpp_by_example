#include <iostream>
#include <memory>
using namespace std;

template<typename Concept>
struct Any_Concept : Concept {
    template<typename T>
    void operator=(T t) {
        Concept::object_base_uptr = std::make_unique< typename Concept::template object<T> >(t);
    }
};

#define MEMBER_FUNCTION(x, y)                               \
    template<typename T>                                    \
    struct x; /* forward decl and ends template d/t ";" */  \
                                                            \
    template<typename ReturnType, typename... Args>         \
    struct x<ReturnType(Args...)>  {                        \
        ReturnType y(Args... args)                          \
        {                                                   \
            return object_base_uptr->invoke(args...);       \
        }                                                   \
                                                            \
    protected:                                              \
        struct Object_base  {                               \
            virtual ~Object_base()              =default;   \
            virtual ReturnType invoke(Args...)  =0;         \
        };                                                  \
                                                            \
        template<class T>                                   \
        struct object : Object_base  {                      \
            object(T t) : t{t} {}                           \
            ReturnType invoke(Args... args) override        \
            {                                               \
                return t.y(args...);                        \
            }                                               \
                                                            \
        private:                                            \
            T t;                                            \
        };                                                  \
        std::unique_ptr<Object_base> object_base_uptr;                     \
    };

MEMBER_FUNCTION( C_must_have_send, send )

using Connection = Any_Concept< C_must_have_send< void(const char *) > >;

struct TCPConnection {
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection {
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

void test_13() { cout << "START test 13" << endl;
    Connection c;
    c = TCPConnection{};
    // Connection c2 = {TCPConnection{}};  // TODO??: Why fail when above works?
    c.send("Hello");

    c = UDPConnection{};
    c.send("Hello");
    cout << "END   test 13" << endl;
}
