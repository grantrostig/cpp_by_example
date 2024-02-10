/**     Signals                             & Slots (or, more properly, objects that occur as part of the slots ??)
GOF:    Subject                             & Observer
GOF:                                        & Dependents
GOF:    Publishers                          & Subscribers (Pub-Sub)
AKA:    Broadcaster??                       & Listener??
        Events                              & Targets
        Callbacks with multiple targets     & Target Callback Receivers                          TODO??: Do these synonyms make sense?
        Emitters                            & Target having a Callback (multiple on one target?) TODO??: Do these synonyms make sense?
Boost Doc states poins with '+', Grant '-'.                              www.boost.org/doc/libs/1_84_0/doc/html/signals2.html#id-1.3.35.3

+   Signals represent callbacks with multiple targets, and are also called publishers or events in similar systems.
+   Signals are connected to some set of slots, which are callback receivers (also called event targets or subscribers),
    which are called when the signal is "emitted."

-   Concrete example entities, things, actions & timing: Dog, clock, chime noise, food, eating, eating shedule (where a chime rings).
-   An emmitter is one who "emits".                     Eg. a Chime from a clock??
-   The emitter "emits" WHAT1? to WHOM1?                Eg. the Sound travels to listener/reciever/recipient/target/subscriber.??
-   Once received by WHOM1,
    the emission is processed by WHOM2 in what way?     Eg. the recipient has "update" run on him which is like "waking up"???
                                                            s/he runs a function/callback,
                                                            for example, the dog or cat eats the food.
Data Structures: */
/* +Signals and slots are managed,
    in that signals and slots (or, more properly, objects that occur as part of the slots)
    can track connections and are capable of automatically disconnecting
    signal/slot connections when either is destroyed.
    This enables the user to make signal/slot connections without expending a great effort
    to manage the lifetimes of those connections with regard to the lifetimes of all objects involved.
+   When signals are connected to multiple slots, there is a question regarding the relationship
    between the return values of the slots and the return value of the signals.
    Boost.Signals2 allows the user to specify the manner in which multiple return values are combined.
+   Is threadsafe.

    Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003
    Copyright (c) 2003-2023 Christopher M. Kohlhoff (chris at kohlhoff dot com)
    Copyright (c) 2024 Alan Uthoff                                  */
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/signals2.hpp>
#include <chrono>
//#include <ctime>
#include <iostream>
//#include <functional>
#include <thread>
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

namespace Boost_asio_timer3 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
void print(const boost::system::error_code& /*e*/, boost::asio::steady_timer* t, int* count) {
    if (*count < 5) {
        std::cout << *count << std::endl;
        ++(*count);
        t->expires_at( t->expiry() + boost::asio::chrono::seconds(1) );
        t->async_wait( boost::bind( print, boost::asio::placeholders::error, t, count) );
    }
}
int test1() {
    boost::asio::io_context io;
    int count = 0;
    boost::asio::steady_timer t( io, boost::asio::chrono::seconds(1) );
    t.async_wait( boost::bind( print, boost::asio::placeholders::error, &t, &count));
    io.run();
    std::cout << "Final count is " << count << std::endl;
    return 0; } } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Boost_asio_timer4 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
class Printer {
    boost::asio::steady_timer timer_;
    int                       count_;
public:
    Printer(boost::asio::io_context& io) : timer_( io, boost::asio::chrono::seconds(1) ), count_(0) {
        timer_.async_wait(boost::bind(&Printer::print, this));
    }
    ~Printer() { std::cout << "Final count is " << count_ << std::endl; }
    void print() {
        if (count_ < 5) {
            std::cout << count_ << std::endl;
            ++count_;
            timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(1));
            timer_.async_wait(boost::bind(&Printer::print, this));
        }
    }
};
int test1() {
    boost::asio::io_context io;
    Printer p(io);
    io.run();
    return 0; } } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Boost_asio_timer5 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
class Printer {
    boost::asio::strand<boost::asio::io_context::executor_type> strand_;
    boost::asio::steady_timer                                   timer1_;
    boost::asio::steady_timer                                   timer2_;
    int                                                         count_;
public:
    Printer(boost::asio::io_context &io)
        : strand_(boost::asio::make_strand(io))
        , timer1_(io, boost::asio::chrono::seconds(1))
        , timer2_(io, boost::asio::chrono::seconds(1))
        , count_(0) {
        timer1_.async_wait( boost::asio::bind_executor( strand_, boost::bind(&Printer::print1, this)));
        timer2_.async_wait( boost::asio::bind_executor( strand_, boost::bind(&Printer::print2, this)));
    }
    ~Printer() { std::cout << "Final count is " << count_ << std::endl; }
    void print1() {
        if (count_ < 10) {
            std::cout << "Timer 1: " << count_ << std::endl;
            ++count_;
            timer1_.expires_at(timer1_.expiry() + boost::asio::chrono::seconds(1));
            timer1_.async_wait( boost::asio::bind_executor( strand_, boost::bind(&Printer::print1, this)));
        }
    }
    void print2() {
        if (count_ < 10) {
            std::cout << "Timer 2: " << count_ << std::endl;
            ++count_;
            timer2_.expires_at(timer2_.expiry() + boost::asio::chrono::seconds(1));
            timer2_.async_wait( boost::asio::bind_executor(strand_, boost::bind(&Printer::print2, this)));
        }
    }
};
int test1() {
    boost::asio::io_context io;
    Printer                 p(io);

    boost::thread           t1( boost::bind( &boost::asio::io_context::run, &io));
    io.run();
    t1.join();
    return 0; } } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Boost_asio_time_t_timer_11 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
struct Asio_time_t_clock {   // A custom implementation of the Clock concept from the standard C++ library. time_t_timer.cpp (c) 2003-2022 Christopher M. Kohlhoff https://en.cppreference.com/w/cpp/chrono/c/clock
    typedef std::chrono::steady_clock::duration     duration;   // The duration type.
    typedef duration::rep                           rep;        // The duration's underlying arithmetic representation. TODO??: NOT USED?
    typedef duration::period                        period;     // The ratio representing the duration's tick period. TODO??: NOT USED?
    typedef std::chrono::time_point<Asio_time_t_clock>   time_point; // An absolute time point represented using the clock.
    static time_point now() noexcept { return time_point() + std::chrono::seconds(std::time(0)); } // Get the current time.
    static constexpr bool                           is_steady = false; // The clock is not monotonically increasing. TODO??: NOT USED?
};
/** The boost::asio::basic_waitable_timer template accepts an optional WaitTraits template parameter.
    The underlying time_t clock has one-second granularity,
    so these traits may be customised to reduce the latency between the clock ticking over and a wait operation's completion.
    When the timeout is near (less than one second away) we poll the clock more frequently to detect the time change closer to when it occurs.
    The user can select the appropriate trade off between accuracy and the increased CPU cost of polling.
    In extreme cases, a zero duration may be returned to make the timers as accurate as possible, albeit with 100% CPU usage. */
struct Asio_time_t_wait_traits {
    // *** Determine how long until the clock should be next polled to determine whether the DURATION has elapsed.
    static Asio_time_t_clock::duration
    to_wait_duration( const Asio_time_t_clock::duration& d) {
        if (d > std::chrono::seconds(1))
            return d - std::chrono::seconds(1);
        else if (d > std::chrono::seconds(0))
            return std::chrono::milliseconds(10);
        else
            return std::chrono::seconds(0);
    }
    // *** Determine how long until the clock should be next polled to determine whether the ABSOLUTE time has been reached.  // TODO??: is this overload NOT USED?
    static Asio_time_t_clock::duration
    to_wait_duration( const Asio_time_t_clock::time_point& t) {
        return to_wait_duration(t - Asio_time_t_clock::now());
    }
};
typedef boost::asio::basic_waitable_timer< Asio_time_t_clock, Asio_time_t_wait_traits > Asio_time_t_timer;  // *** KEY asio type
int test1() { try {
        boost::asio::io_context io_context;
        Asio_time_t_timer       timer(io_context);

        timer.expires_after(std::chrono::seconds(5));
        std::cout << "Starting synchronous wait.\n";
        timer.wait();
        std::cout << "Finished synchronous wait.\n";

        timer.expires_after(std::chrono::seconds(5));
        std::cout << "Starting asynchronous wait\n";
        timer.async_wait( [](const boost::system::error_code& /*error*/) { std::cout << "timeout.\n"; });
        io_context.run();
        std::cout << "Finished asynchronous wait.\n";
    }
    catch (std::exception& e) { std::cout << "Exception: " << e.what() << "\n"; }
    return 0; } } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Boost_signals2_timer_asio { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN  // source: Bing

class Timer {
    boost::asio::deadline_timer timer_;
public:
    Timer(boost::asio::io_service& io_service) : timer_(io_service) {}

    boost::signals2::signal<void()> on_timer_expired;       // Signal to be emitted on timer expiry

    void start(int seconds) {
        timer_.expires_from_now(boost::posix_time::seconds(seconds));
        //timer_.async_wait(this {
            //on_timer_expired(); // Emit the signal
        //});
    }
};

void test1() {
    boost::asio::io_service io_service;
    Timer timer(io_service);

    // Connect a slot to the signal
    //timer.on_timer_expired.connect( {
        //std::cout << "Timer expired!" << std::endl;
    //});

    timer.start(5);     // Start the timer for 5 seconds
    io_service.run();   // Start the event loop
}

} // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Boost_signals2_timer_thread { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN  // source: Bing
auto my_sleeper_l{ [ /* this */ ] (std::chrono::seconds seconds_in) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds_in));
    //on_timer_expired_();                                             // Emit the signal
}};
class Timer;
void my_sleeper_fn();
class Timer {
public:
    boost::signals2::signal<void()> on_timer_expired_; // Signal to be emitted on timer expiry
    void start(int seconds_in) {
        //WAS std::thread(this, seconds {
        //std::thread([this] (std::chrono::seconds seconds_in) {
                //std::this_thread::sleep_for(std::chrono::seconds(seconds_in));
                //on_timer_expired_();                                             // Emit the signal
            //}).detach();

        auto my_sleeper_fm_l{ [ /* this */ ] (std::chrono::seconds seconds_in) {
                //std::this_thread::sleep_for(std::chrono::seconds(seconds_in));
                //on_timer_expired_();                                             // Emit the signal
        }};

        //std::thread my_thread1{ my_sleeper_fn, this, seconds_in };
        //std::thread my_thread2{ my_sleeper_l, seconds_in };         // TODO??: Compile error: std::thread arguments must be invocable after conversion to rvalues
        //std::thread my_thread4{ my_sleeper_fm_l, seconds_in };      // TODO??: Compile error: std::thread arguments must be invocable after conversion to rvalues
        //my_thread1.detach();
    }
};

void my_sleeper_fn( Timer & timer_in, int seconds_in) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds_in));
    //on_timer_expired_();                                                      // Emit the signal
    timer_in.on_timer_expired_();                                               // Emit the signal
}

int test1() {
    Timer timer;

    // Connect a slot to the signal
    timer.on_timer_expired_.connect( []() {
        std::cout << "Timer expired!" << std::endl;
    });

    timer.start(5);  // Start the timer for 5 seconds

    // Wait for the timer to expire
    std::this_thread::sleep_for(std::chrono::seconds(6));

    return 0; }  } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Boost_signals2_example { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
template<typename T> // Combiner which returns the maximum value returned by all slots
struct maximum {
    typedef T result_type;
    template<typename InputIterator>
    T operator()(InputIterator first, InputIterator last) const {
        // If there are no slots to call, just return the default-constructed value
        if(first == last ) return T();
        T max_value = *first++;
        while (first != last) {
            if ( max_value < *first ) max_value = *first;
            ++first;
        }
        return max_value;
    }
};
float product   (float x, float y) { return x * y; }
float quotient  (float x, float y) { return x / y; }
float sum       (float x, float y) { return x + y; }
float difference(float x, float y) { return x - y; }
/** **** Boost Signals example *** */
void test1() {
    boost::signals2::signal<float (float, float)                   > signal_default_last;

    signal_default_last.connect(&product);  // Product is one SLOT of several subscribing to an event/signal
    signal_default_last.connect(&quotient);
    signal_default_last.connect(&sum);
    signal_default_last.connect(&difference);
    std::cout << "*sig_default_last(5, 3): " << *signal_default_last(5, 3) << std::endl; // SIGNAL FIRES HERE The default combiner returns a boost::optional containing the return value of the last slot in the slot list, in this case the difference function.
    //std::cout << "*sig_default_last(5, 3): " << signal_default_last(5, 3) << std::endl; // SIGNAL FIRES HERE The default combiner returns a boost::optional containing the return value of the last slot in the slot list, in this case the difference function.

    boost::signals2::signal< float (float, float), maximum<float> > sig_max;
    sig_max.connect(&product);
    sig_max.connect(&quotient);
    sig_max.connect(&sum);
    sig_max.connect(&difference);
    std::cout << "maximum: " << sig_max(5, 3) << std::endl; // Outputs the maximum value returned by the connected slots, in this case 15 from the product function.  */
}} // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

int main() {
    Boost_asio_timer3::test1();
    Boost_asio_timer4::test1();
    Boost_asio_timer5::test1();
    Boost_asio_time_t_timer_11::test1();
    Boost_signals2_timer_thread::test1();
    Boost_signals2_timer_asio::test1();
    Boost_signals2_example::test1();
    cout << "###" << endl;
    return 0;
}
