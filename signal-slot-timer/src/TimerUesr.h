/** Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003
    Copyright (c) 2024 Alan Uthoff
*/
#pragma once
#include "Feeding_chime.h"
#include "../lib/fteng/signals.hpp"
#include <iostream>  //fteng/signals.hpp from https://github.com/TheWisp/signals under the MIT License

class Signal_user{
    fteng::connection           m_connectTimerSlot; //User to auto disconnect on destruction of Signal_user
    Feeding_chime                      m_timer;
    std::chrono::milliseconds   m_lastUpdate;
    void updateTimeStamp() {
        m_lastUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    }
public:
    explicit Signal_user(std::chrono::milliseconds  interval){
        m_connectTimerSlot = m_timer.timeout.connect< &Signal_user::update >( this );  // note: THIS
        updateTimeStamp();
        m_timer.start(interval);
    }
    ~Signal_user() {
        m_timer.stop();
    }
    void update(){
        const auto currentTimeMil = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        std::cout << "Update time interval:" << currentTimeMil.count() - m_lastUpdate.count() <<"ms\n";
        updateTimeStamp();
    }
};
