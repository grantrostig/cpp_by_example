#include <iostream>
#include <memory>
using namespace std;

namespace test_12_ns {
template<typename T> class templated_parameterized_fn;                    // Forward decl.

template<typename Return_type, typename... Args>
class templated_parameterized_fn< Return_type( Args... ) > {
public:
    template<typename T>
    void operator=(T t) {
        c = std::make_unique<Callable_derived<T>>(t);
    }
    Return_type operator()( Args... args ) { return c->invoke( args... ); }
private:
    struct Callable_base {
        virtual ~Callable_base() = default;
        virtual Return_type invoke( Args... ) = 0;
    };
    template<class T>  // nested templated class
    struct Callable_derived : Callable_base {
        Callable_derived(T t) : t_(t) {}
        Return_type invoke( Args... args ) override { return t_( args... ); }

    private:
        T t_;
    };

    std::unique_ptr<Callable_base> c;
};

void hello() { std::cout << "Hello templated_parameterized_fn\n"; }
class Hello_fo { public: void operator()() const { std::cout << "Hello class_fo\n"; } };
} // END namespace

void test_12() { using namespace test_12_ns; cout << "START test 12" << endl;
    templated_parameterized_fn< void() > f;
    f = hello;
    f();

    f = Hello_fo();
    f();
    cout << "END   test 12" << endl;
}
