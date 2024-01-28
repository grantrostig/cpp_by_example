/**     Signals                             & Slots (or, more properly, objects that occur as part of the slots ??)
AKA:    Publishers                          & Subscribers (Pub-Sub?)
        Events                              & Targets
        Callbacks with multiple targets     & Target Callback Receivers  TODO??: Do these synonyms make sense?
        Emitters                            & Target Callback Receivers  TODO??: Do these synonyms make sense?

www.boost.org/doc/libs/1_84_0/doc/html/signals2.html#id-1.3.35.3
Boost Doc states poins with '+', Grant '-'.
+   Signals represent callbacks with multiple targets, and are also called publishers or events in similar systems.
+   Signals are connected to some set of slots, which are callback receivers (also called event targets or subscribers),
    which are called when the signal is "emitted."

-   Concrete example entities, things, actions & timing: Dog, clock, chime noise, food, eating, eating shedule (where a chime rings).

-   An emmitter is one who "emits".                     Eg. a Chime from a clock??
-   The emitter "emits" WHAT1? to WHOM1?                Eg. the Sound travels to listener/reciever/recipient/target/subscriber.??
-   Once received by WHOM1,
    the emission is processed by WHOM2 in what way?     Eg. the recipient has "update" run on him which is like "waking up"???
                                                            s/he runs a function/callback,
                                                            for example, feeds the dog or cat.

+   Signals and slots are managed,
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
    Copyright (c) 2024 Alan Uthoff
*/
#include "STimer.h"
#include "TimerUesr.h"
#include <boost/signals2.hpp>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

constexpr std::chrono::milliseconds sleepDuration = 500ms;

int main() {
    TimerUser tUser{1000ms}; //Timer user will print a message out ever second +- sleepDuration
    while (true) {           // Take up time/use CPU.  Or GUI loop??
        STimer::updateAll();
        std::this_thread::sleep_for(sleepDuration);
    }

    /** **** Boost Signals example *** */





    return 0;
}
