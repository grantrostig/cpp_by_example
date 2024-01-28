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
#include <boost/signals2.hpp>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

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
int main() {
    /** **** TheWhisp/signals example *** */
    constexpr std::chrono::milliseconds SLEEP_DURATION = 500ms;

    Signal_user pet_owner_signal_user{1000ms}; //Timer user will print a message out ever second +- sleepDuration

    Feeding_chime chime_for_dog{};
    chime_for_dog.start();
    int i{};
    while (true) {           // Run/use CPU. Or a GUI loop
        Feeding_chime::updateAll();

        std::this_thread::sleep_for(SLEEP_DURATION);
        if ( ++i > 4 ) chime_for_dog.stop();
    }
    chime_for_dog.stop();

    /** **** Boost Signals example ***

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

    std::cout << "###" << std::endl;
    return 0;
}
