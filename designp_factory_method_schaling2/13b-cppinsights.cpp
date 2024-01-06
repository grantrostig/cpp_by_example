#include <iostream>
#include <memory>
using namespace std;
namespace test_13b_ns
{
template<typename Concept>
struct Any_Concept : public Concept
{
    template<typename T>
    inline void operator=(T t)
    {
        Concept::object_base_uptr = std::make_unique<typename Concept::template object<T> >(t);
    }
};

/* First instantiated from: insights.cpp:57 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct Any_Concept<C_must_have_send<void (const char *)> > : public C_must_have_send<void (const char *)>
{
    template<typename T>
    inline void operator=(T t);

/* First instantiated from: insights.cpp:58 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
    inline void operator=<TCPConnection>(TCPConnection t)
    {
        /* static_cast<C_must_have_send<void (const char *)> *>(this)-> */ object_base_uptr.operator=(std::make_unique<C_must_have_send<void (const char *)>::object<TCPConnection> >(t));
    }
#endif


/* First instantiated from: insights.cpp:62 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
    inline void operator=<UDPConnection>(UDPConnection t)
    {
        /* static_cast<C_must_have_send<void (const char *)> *>(this)-> */ object_base_uptr.operator=(std::make_unique<C_must_have_send<void (const char *)>::object<UDPConnection> >(t));
    }
#endif

    // inline Any_Concept(const Any_Concept<C_must_have_send<void (const char *)> > &) /* noexcept */ = delete;
    // inline Any_Concept<C_must_have_send<void (const char *)> > & operator=(const Any_Concept<C_must_have_send<void (const char *)> > &) /* noexcept */ = delete;
    // inline constexpr Any_Concept() noexcept = default;
    // inline ~Any_Concept() noexcept = default;
};

#endif
template<typename T>
struct C_must_have_send;
/* First instantiated from: insights.cpp:6 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct C_must_have_send<void (const char *)>
{
    inline void send(const char * __args0)
    {
        return this->object_base_uptr.operator->()->invoke(__args0);
    }


protected:
    struct Object_base
    {
        inline virtual ~Object_base() noexcept = default;
        virtual void invoke(const char * __0) = 0;

        // inline constexpr Object_base() noexcept = default;
    };

    template<class T>
    struct object;
/* First instantiated from: type_traits:1467 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
    struct object<test_13b_ns::TCPConnection> : public Object_base
    {
        inline object(test_13b_ns::TCPConnection t)
            : Object_base()
            , t{test_13b_ns::TCPConnection{t}}
        {
        }

        inline virtual void invoke(const char * __args0)
        {
            return this->t.send(__args0);
        }


    private:
        test_13b_ns::TCPConnection t;
    public:
        // inline virtual ~object() noexcept = default;
    };

#endif
/* First instantiated from: type_traits:1467 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
    struct object<test_13b_ns::UDPConnection> : public Object_base
    {
        inline object(test_13b_ns::UDPConnection t)
            : Object_base()
            , t{test_13b_ns::UDPConnection{t}}
        {
        }

        inline virtual void invoke(const char * __args0)
        {
            return this->t.send(__args0);
        }


    private:
        test_13b_ns::UDPConnection t;
    public:
        // inline virtual ~object() noexcept = default;
    };

#endif
    std::unique_ptr<Object_base, std::default_delete<Object_base> > object_base_uptr;
public:
    // inline C_must_have_send(const C_must_have_send<void (const char *)> &) /* noexcept */ = delete;
    // inline C_must_have_send<void (const char *)> & operator=(const C_must_have_send<void (const char *)> &) /* noexcept */ = delete;
    // inline ~C_must_have_send() noexcept = default;
    // inline constexpr C_must_have_send() noexcept = default;
};

#endif
template<typename ReturnType, typename ... Args>
struct C_must_have_send<ReturnType (Args...)>
{
    inline ReturnType send(Args... args)
    {
        return this->object_base_uptr->invoke(args... );
    }


protected:
    struct Object_base
    {
        inline virtual ~Object_base() = default;
        virtual ReturnType invoke(Args...) = 0;

    };

    template<class T>
    struct object : public Object_base
    {
        inline object(T t)
            : t{t}
        {
        }

        inline ReturnType invoke(Args... args)
        {
            return this->t.send(args... );
        }


    private:
        T t;
    };

    std::unique_ptr<Object_base> object_base_uptr;
};

using Connection = Any_Concept<C_must_have_send<void (const char *)> >;
struct TCPConnection
{
    inline void send(const char * s)
    {
        std::operator<<(std::operator<<(std::operator<<(std::cout, "TCP: "), s), '\n');
    }

    // inline constexpr TCPConnection(const TCPConnection &) noexcept = default;
    // inline constexpr TCPConnection(TCPConnection &&) noexcept = default;
};

struct UDPConnection
{
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
    test_13b_ns::Any_Concept<test_13b_ns::C_must_have_send<void (const char *)> > c = test_13b_ns::Any_Concept<test_13b_ns::C_must_have_send<void (const char *)> >();
    c.operator=(test_13b_ns::TCPConnection(test_13b_ns::TCPConnection{}));
    static_cast<test_13b_ns::C_must_have_send<void (const char *)>&>(c).send("Hello");
    c.operator=(test_13b_ns::UDPConnection(test_13b_ns::UDPConnection{}));
    static_cast<test_13b_ns::C_must_have_send<void (const char *)>&>(c).send("Hello");
    std::operator<<(std::cout, "END   test 13b").operator<<(std::endl);
}

