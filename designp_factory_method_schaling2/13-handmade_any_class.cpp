#include <iostream>
#include <memory>
using namespace std;

template<typename Concept>
struct any : Concept {
    template<typename T>
    void operator=(T t) {
        Concept::o = std::make_unique< typename Concept::template object<T> >(t);
    }
};

#define MEMBER_FUNCTION(x, y) \
    template<typename T> \
    struct x; /* forward decl and ends template b/c ; */ \
    template<typename ReturnType, typename... Args> \
    struct x<ReturnType(Args...)>  { \
        ReturnType y(Args... args) \
        { \
            return o->invoke(args...); \
        } \
\
    protected: \
        struct object_base  { \
            virtual ~object_base() = default; \
            virtual ReturnType invoke(Args...) = 0; \
        }; \
        template<class T> \
        struct object : object_base  { \
            object(T t) \
                : t(t) \
            {} \
            ReturnType invoke(Args... args) override \
            { \
                return t.y(args...); \
            } \
\
        private: \
            T t; \
        }; \
        std::unique_ptr<object_base> o; \
    };

struct TCPConnection {
    void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};
struct UDPConnection {
    void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

MEMBER_FUNCTION( C_must_have_send, send )

using Connection = any< C_must_have_send< void(const char *) > >;

void test_13() { cout << "END  test 13" << endl;
    Connection c;
    c = TCPConnection{};
    c.send("Hello");

    c = UDPConnection{};
    c.send("Hello");
    cout << "END  test 13" << endl;
}
