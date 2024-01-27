/** Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003
    Copyright (c) 2024 Alan Uthoff
*/
#pragma once
#include "STimer.h"
#include "../lib/fteng/signals.hpp"
#include <iostream>  //fteng/signals.hpp from https://github.com/TheWisp/signals under the MIT License

class TimerUser{
    fteng::connection           m_connectTimerSlot; //User to auto disconnect on destruction of TimerUser
    STimer                      m_timer;
    std::chrono::milliseconds   m_lastUpdate;
    void updateTimeStamp() {
        m_lastUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    }
public:
    explicit TimerUser(std::chrono::milliseconds  interval){
        m_connectTimerSlot = m_timer.timeout.connect< &TimerUser::onTimerExpired >( this );  // note: THIS
        updateTimeStamp();
        m_timer.start(interval);
    }
    ~TimerUser() {
        m_timer.stop();
    }
    void onTimerExpired(){
        const auto currentTimeMil = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        std::cout << "Timer Expired delta:" << currentTimeMil.count() - m_lastUpdate.count() <<"ms\n";
        updateTimeStamp();
    }
};
