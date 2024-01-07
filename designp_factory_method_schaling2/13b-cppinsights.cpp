/* IPV - Interface via Pure Virtual technique. */
#include <iostream>
#include <memory>
using namespace std;
namespace test_13b_ns
{
template<typename T>
class UDT_with_named_fn;
//#define INSIGHTS_USE_TEMPLATE /* First instantiated from: insights.cpp:41 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class UDT_with_named_fn<void (const char *)>
{

public:
    inline void send(const char * __args0)
    {
        return this->object_base_uptr_.operator->()->invoke(__args0);
    }


protected:
    class IPV_Object_base
    {

    public:
        inline virtual ~IPV_Object_base() noexcept = default;
        virtual void invoke(const char * __0) = 0;

        // inline constexpr IPV_Object_base() noexcept = default;
    };

    template<typename UDT_with_named_fn>
    class Object_derived;
/* First instantiated from: type_traits:1467 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
    class Object_derived<test_13b_ns::TCPConnection> : public IPV_Object_base
    {
        test_13b_ns::TCPConnection t_;

    public:
        inline Object_derived(test_13b_ns::TCPConnection t)
            : IPV_Object_base()
            , t_{test_13b_ns::TCPConnection{t}}
        {
        }

        inline virtual void invoke(const char * __args0)
        {
            return this->t_.send(__args0);
        }

        // inline virtual ~Object_derived() noexcept = default;
    };

#endif
/* First instantiated from: type_traits:1467 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
    class Object_derived<test_13b_ns::UDPConnection> : public IPV_Object_base
    {
        test_13b_ns::UDPConnection t_;

    public:
        inline Object_derived(test_13b_ns::UDPConnection t)
            : IPV_Object_base()
            , t_{test_13b_ns::UDPConnection{t}}
        {
        }

        inline virtual void invoke(const char * __args0)
        {
            return this->t_.send(__args0);
        }

        // inline virtual ~Object_derived() noexcept = default;
    };

#endif
    std::unique_ptr<IPV_Object_base, std::default_delete<IPV_Object_base> > object_base_uptr_;
public:
    // inline UDT_with_named_fn(const UDT_with_named_fn<void (const char *)> &) /* noexcept */ = delete;
    // inline UDT_with_named_fn<void (const char *)> & operator=(const UDT_with_named_fn<void (const char *)> &) /* noexcept */ = delete;
    // inline ~UDT_with_named_fn() noexcept = default;
    // inline constexpr UDT_with_named_fn() noexcept = default;
};

#endif
template<typename Return_type, typename ... Args>
class UDT_with_named_fn<Return_type (Args...)>
{

public:
    inline Return_type send(Args... args)
    {
        return this->object_base_uptr_->invoke(args... );
    }


protected:
    class IPV_Object_base
    {

    public:
        inline virtual ~IPV_Object_base() = default;
        virtual Return_type invoke(Args...) = 0;

    };

    template<typename UDT_with_named_fn>
    class Object_derived : public IPV_Object_base
    {
        UDT_with_named_fn t_;

    public:
        inline Object_derived(UDT_with_named_fn t)
            : t_{t}
        {
        }

        inline Return_type invoke(Args... args)
        {
            return this->t_.send(args... );
        }

    };

    std::unique_ptr<IPV_Object_base> object_base_uptr_;
};

using UDT_with_named_fn_parameterized = UDT_with_named_fn<void (const char *)>;
template<typename UDT_base>
class Target_Concrete_Derived_UDT : public UDT_base
{

public:
    template<typename T>
    inline void operator=(T t)
    {
        UDT_base::object_base_uptr_ = std::make_unique<typename UDT_base::template Object_derived<T> >(t);
    }
};

/* First instantiated from: insights.cpp:55 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class Target_Concrete_Derived_UDT<UDT_with_named_fn<void (const char *)> > : public UDT_with_named_fn<void (const char *)>
{

public:
    template<typename T>
    inline void operator=(T t);

/* First instantiated from: insights.cpp:56 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
    inline void operator=<TCPConnection>(TCPConnection t)
    {
        /* static_cast<UDT_with_named_fn<void (const char *)> *>(this)-> */ object_base_uptr_.operator=(std::make_unique<UDT_with_named_fn<void (const char *)>::Object_derived<TCPConnection> >(t));
    }
#endif


/* First instantiated from: insights.cpp:59 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
    inline void operator=<UDPConnection>(UDPConnection t)
    {
        /* static_cast<UDT_with_named_fn<void (const char *)> *>(this)-> */ object_base_uptr_.operator=(std::make_unique<UDT_with_named_fn<void (const char *)>::Object_derived<UDPConnection> >(t));
    }
#endif

    // inline Target_Concrete_Derived_UDT(const Target_Concrete_Derived_UDT<UDT_with_named_fn<void (const char *)> > &) /* noexcept */ = delete;
    // inline Target_Concrete_Derived_UDT<UDT_with_named_fn<void (const char *)> > & operator=(const Target_Concrete_Derived_UDT<UDT_with_named_fn<void (const char *)> > &) /* noexcept */ = delete;
    // inline constexpr Target_Concrete_Derived_UDT() noexcept = default;
    // inline ~Target_Concrete_Derived_UDT() noexcept = default;
};

#endif
using Connection = Target_Concrete_Derived_UDT<UDT_with_named_fn<void (const char *)> >;
class TCPConnection
{

public:
    inline void send(const char * s)
    {
        std::operator<<(std::operator<<(std::operator<<(std::cout, "TCP: "), s), '\n');
    }

    // inline constexpr TCPConnection(const TCPConnection &) noexcept = default;
    // inline constexpr TCPConnection(TCPConnection &&) noexcept = default;
};

class UDPConnection
{

public:
    inline void send(const char * s)
    {
        std::operator<<(std::operator<<(std::operator<<(std::cout, "UDP: "), s), '\n');
    }

    // inline constexpr UDPConnection(const UDPConnection &) noexcept = default;
    // inline constexpr UDPConnection(UDPConnection &&) noexcept = default;
};


}

void test_13b()
{
    using namespace test_13b_ns;
    std::operator<<(std::cout, "START test 13b").operator<<(std::endl);
    test_13b_ns::Target_Concrete_Derived_UDT<test_13b_ns::UDT_with_named_fn<void (const char *)> > c = test_13b_ns::Target_Concrete_Derived_UDT<test_13b_ns::UDT_with_named_fn<void (const char *)> >();
    c.operator=(test_13b_ns::TCPConnection(test_13b_ns::TCPConnection{}));
    static_cast<test_13b_ns::UDT_with_named_fn<void (const char *)>&>(c).send("Hello form TCP");
    c.operator=(test_13b_ns::UDPConnection(test_13b_ns::UDPConnection{}));
    static_cast<test_13b_ns::UDT_with_named_fn<void (const char *)>&>(c).send("Hello from UPD");
    std::operator<<(std::cout, "END   test 13b").operator<<(std::endl);
}

