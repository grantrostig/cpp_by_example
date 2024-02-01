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
Data Structures:


*/

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
    Copyright (c) 2024 Alan Uthoff                                  */
#include "Feeding_chime.h"
#include "TimerUesr.h"
#include "fteng/signals.hpp" // theWisp/fteng/signals is NOT THREADSAFE.
#include <boost/signals2.hpp>
#include <chrono>
#include <thread>
using std::cin; using std::cout; using std::cerr; using std::clog; using std::endl; using std::string;  // using namespace std;
using namespace std::string_literals;
using namespace std::chrono_literals;

namespace boost_signals2_example { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
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
void test() {
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

namespace alans_example { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
void test() {
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

namespace grants_theWisp_example { // NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN  // theWisp is NOT THREADSAFE.
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
    fteng::signal< void( Button_with_slots& btn, bool down ) > pressed_signal_{};
    Button_with_slots() { cout<<"Button_with_slots constructor.\n";};
    // ~Button_with_slots() { cout<<"Button_with_slots destructor.\n";};  // TODO??: why prohibited by compiler?
};
class My_special_frame {
public:
    std::vector<Button_with_slots> button_with_slots{};
    My_special_frame() {
        button_with_slots.emplace_back();   // TODO??: Is this exaclty the same? $ buttons.emplace_back(new Button{});
        button_with_slots.back().pressed_signal_.connect< & My_special_frame::on_button_pressed_callback >( this );  // attaching button callback to frame and not?? Signal
        button_with_slots.back().name_ = "1st in constructor";  // attaching button callback to frame and not?? Signal
        button_with_slots.emplace_back();   // TODO??: Is this exaclty the same? $ buttons.emplace_back(new Button{});
        button_with_slots.back().pressed_signal_.connect< & My_special_frame::on_button_pressed_callback >( this );  // attaching button callback to frame and not?? Signal
        button_with_slots.back().name_ = "2st in constructor";  // attaching button callback to frame and not?? Signal
        cout<<"My_special_frame constructor.\n";
    }
    ~My_special_frame() { cout<<"My_special_frame destructor.\n";};
    void on_button_pressed_callback( Button_with_slots & btn, bool down) {
        std::cout <<"on_button_pressed_callback():"<<btn.name_ <<","<< &btn <<","<< down<<"\n";
    }
};
void test2() {                                           std::cout<< "START grants_theWisp_example test2. ++++++++++++++++++++++++"<<std::endl;
    // is NOT really a user defineable Subject to an Observer??
    //fteng::signal< void(float delta) > signal_which_emmits_a_calls_update_on_know_observers{};        // A signal specifying its signature in the template parameter. which wants to connect to observers/slots??

    My_special_frame button_frame{};
    Button_with_slots button{};

    // Signal needs to be fired, usually done by the class that has/is a Signal. Here we just call the funtion it would call.
    //auto junk = button_frame.button_with_slots.back().pressed_signal;  // TODO??: what is this strange return type? We guessed it would be void because callback returns void.
    button_frame.button_with_slots.back().pressed_signal_( button, 1 );  // TODO??: meaning of warning, since we can init a variable with this value?

    // Signal.connect() GOF names Subject.attach/detach().
    // TODO??: how to rename member function via "using" or Template magic?
    //signal_which_emmits_a_calls_update_on_know_observers.connect( observer_slot_callback_free_fn );                          // Connects to the observer's function callback
    std::cout<< "END   grants_theWisp_example test2. ++++++++++++++++++++++++"<<std::endl;
}} // namespace grants_theWisp_example

int main() {
    //boost_signals2_example::test();
    //alans_example::test();
    //grants_theWisp_example::test1();
    grants_theWisp_example::test2();
    std::cout << "###" << std::endl;
    return 0;
}
