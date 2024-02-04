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
#include "Feeding_chime.h"
#include "TimerUesr.h"
#include "fteng/signals.hpp" // theWisp/fteng/signals is NOT THREADSAFE.
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/signals2.hpp>
#include <chrono>
#include <iostream>
#include <functional>
#include <thread>
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

namespace Boost_asio_timer5 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
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
        timer1_.async_wait(boost::asio::bind_executor( strand_, boost::bind(&Printer::print1, this)));
        timer2_.async_wait(boost::asio::bind_executor( strand_, boost::bind(&Printer::print2, this)));
    }
    ~Printer() { std::cout << "Final count is " << count_ << std::endl; }
    void print1() {
        if (count_ < 10) {
            std::cout << "Timer 1: " << count_ << std::endl;
            ++count_;
            timer1_.expires_at(timer1_.expiry() + boost::asio::chrono::seconds(1));
            timer1_.async_wait(
                boost::asio::bind_executor( strand_, boost::bind(&Printer::print1, this)));
        }
    }
    void print2() {
        if (count_ < 10) {
            std::cout << "Timer 2: " << count_ << std::endl;
            ++count_;
            timer2_.expires_at(timer2_.expiry() + boost::asio::chrono::seconds(1));
            timer2_.async_wait(
                boost::asio::bind_executor(strand_, boost::bind(&Printer::print2, this)));
        }
    }
};
int test1() {
    boost::asio::io_context io;
    Printer p(io);
    boost::thread t(boost::bind(&boost::asio::io_context::run, &io));
    io.run();
    t.join();
    return 0; } } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace Boost_asio_timer4 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
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
    return 0; } } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace Boost_asio_timer3 { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
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
    return 0; } } // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace Boost_signals2_timer_asio { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN           // source: Bing

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

} // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Boost_signals2_timer_thread { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN                  // source: Bing
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

    return 0;
}

} // END namespace NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Boost_signals2_example { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
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
}} // END namespace boost_signals2_example NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Alans_example { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
void test1() {
constexpr std::chrono::milliseconds SLEEP_DURATION = 500ms;
Signal_user pet_owner_signal_user{1000ms}; //Timer user will print a message out ever second +- sleepDuration
//Feeding_chime chime_for_dog{};  Not needed??
//chime_for_dog.start();  // Does nothing??
//int i{};
while (true) {           // Run/use CPU. Or a GUI loop
    Feeding_chime::updateAll();
    std::this_thread::sleep_for(SLEEP_DURATION);
    // if ( ++i / 4 ) chime_for_dog.stop(); // Does nothing??
}
//chime_for_dog.stop();  // Does nothing?
}} // END namespace alans_example NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
namespace Grants_theWisp_examples { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN  // theWisp is NOT THREADSAFE.
void observer_slot_callback_free_fn(float delta) { std::cout << "update_fn() delta:"<<delta<<std::endl; } // A function callback
class My_slot_waiting_on_update_class { // A member function callback
public: void GOFs_update(float delta) { std::cout << "my_class::update_fn() delta:"<<delta<<std::endl; }
};
void test1() {                                           std::cout<< "START grants_theWisp_example test1. ++++++++++++++++++++++++"<<std::endl;
    // Here the Signal class does not allow us to modify it, so is NOT really a user defineable Subject to an Observer??
    fteng::signal< void(float delta) > signal_which_emmits_a_calls_update_on_know_observers{};        // A signal specifying its signature in the template parameter. which wants to connect to observers/slots??
    // Signal.connect() GOF names Subject.attach/detach().
    // TODO??: how to rename member function via "using" or Template magic?
    signal_which_emmits_a_calls_update_on_know_observers.connect( observer_slot_callback_free_fn );                          // Connects to the observer's function callback

    My_slot_waiting_on_update_class * my_slot{ new My_slot_waiting_on_update_class };
    signal_which_emmits_a_calls_update_on_know_observers.connect< &My_slot_waiting_on_update_class::GOFs_update > ( my_slot );   // Connects to the observer/slot object's callback member function

    signal_which_emmits_a_calls_update_on_know_observers.connect( [](float delta) {std::cout <<  "lambda callback 1() delta:"<<delta<<std::endl; });  // Connects to a lambda callback observer/slot
    signal_which_emmits_a_calls_update_on_know_observers.connect( [](auto &&...as) {std::cout << "lambda callback 2() ...as is NOT printed." <<std::endl; });    // Connects to a generic lambda callback observer/slot

    // Emmits the signal 42 using its function_object, but is GOF name is: notify(), ie. ~ signal_which_emmits_a_calls_update_on_know_observers.GOF_notify( 42 );
    // All attached/subscribed/connect()ed Slots get the signal 42 via their own GOF_update().
    signal_which_emmits_a_calls_update_on_know_observers( 42 );
    delete my_slot;                                      std::cout<< "END   grants_theWisp_example test1. ++++++++++++++++++++"<<std::endl;
}

class Button_with_slots{
public:
    string name_{"NULL"};
    fteng::signal< void( Button_with_slots & btn, bool down ) > pressed_signal_{};  // Signals automatically disconnect from their slots (receivers) upon destruction.
    Button_with_slots() { cout<<"Button_with_slots constructor.\n";};
    // ~Button_with_slots() { cout<<"Button_with_slots destructor.\n";};  // TODO??: why prohibited by compiler?
};
class My_special_frame {
public:
    std::vector<Button_with_slots> buttons_{};
    My_special_frame() {
        buttons_.emplace_back();                                                                            // TODO??: Is this similar? $ buttons_.emplace_back(Button_with_slots{});
        buttons_.back().pressed_signal_.connect< & My_special_frame::on_button_pressed_callback >( this );  // TODO??: Attaching button callback to frame and not?? Signal
        buttons_.back().name_ = "1st in constructor";
        Button_with_slots button2{};
        button2.pressed_signal_.connect< & My_special_frame::on_button_pressed_callback >( this );
        button2.name_ = "2st in constructor";
        //buttons_.emplace_back( button2 );
        //buttons_.push_back( button2 );

        buttons_.emplace_back();
        //buttons_.back().pressed_signal_.connect< & My_special_frame::on_button_pressed_callback >( this );
        buttons_.back().name_ = "3rd in constructor";
        cout<<"My_special_frame constructor.\n";
    }
    void add( Button_with_slots & b ) {
        buttons_.emplace_back();                                                                            // TODO??: Is this similar? $ buttons_.emplace_back(Button_with_slots{});
        buttons_.back().pressed_signal_.connect< & My_special_frame::on_button_pressed_callback >( this );  // TODO??: Attaching button callback to frame and not?? Signal
        buttons_.back().name_ = b.name_;
    }
    ~My_special_frame() { cout<<"My_special_frame destructor.\n";};
    void on_button_pressed_callback( Button_with_slots & btn, bool down) {
        //std::cout <<"on_button_pressed_callback() name_, &button, parameter:"<<btn.name_ <<","<< &btn <<","<< down<<"\n";
    }
};
void test2() {                                           std::cout<< "START grants_theWisp_example test2. ++++++++++++++++++++++++"<<std::endl;
    My_special_frame button_frame{};                                // Constructor creates several buttons
    Button_with_slots & button0{button_frame.buttons_.at(0)};       // Get handle to button to fire a signal on it below
    Button_with_slots & button1{button_frame.buttons_.at(1)};
    //Button_with_slots & button2 {button_frame.buttons_.at(2)};    // uncomment once above code is fixed.
    Button_with_slots button4{};
    button4.name_ = "button4";
    button_frame.add(button4);
    cout << "Firing signals, usually done by the class that has/is a Signal. Here we just call the funtion it would call."<<endl;
    button_frame.buttons_.front().pressed_signal_( button0, 1 );    //auto junk = button_frame.button_with_slots.back().pressed_signal;  // TODO??: what is this strange return type? We guessed it would be void because callback returns void.
    button_frame.buttons_.at(1).pressed_signal_(   button1, 0 );
    button_frame.buttons_.at(2).pressed_signal_(   button4, 0 );
    std::cout<< "END   grants_theWisp_example test2. ++++++++++++++++++++++++"<<std::endl;
}
// *** NOTE: below code is under construction
class Interval_signal {
    string              name_{"NULL"};
    int                 interval_{};
    fteng::signal< void() > strike_the_signal_{};
};
class Chime {   // A special type of clock that only chimes on an specified interval, for example every 1,0000 ms

    void chime_clock_tick() {};

    void interval_signal_callback() {
        cout << "interval_signal_callback()" << endl;
    };
};

void test3() {
    Chime chime{};

};
} // namespace grants_theWisp_examples

int main() {
    //Boost_asio_timer3::test1();
    //Boost_asio_timer4::test1();
    Boost_asio_timer5::test1();
    //Boost_signals2_timer_thread::test1();
    //Boost_signals2_timer_asio::test1();
    //Boost_signals2_example::test1();
    //Alans_example::test1();
    //Grants_theWisp_examples::test1();
    //Grants_theWisp_examples::test2();
    //Grants_theWisp_examples::test3();
    std::cout << "###" << std::endl;
    return 0;
}
