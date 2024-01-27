/** Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003
    Copyright (c) 2024 Alan Uthoff
*/
#include "STimer.h"
#include "TimerUesr.h"
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
    return 0;
}
