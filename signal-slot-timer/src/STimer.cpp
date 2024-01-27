/** Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003
    Copyright (c) 2024 Alan Uthoff
*/
#include "STimer.h"
#include <iostream>
#include <set>

static std::set<STimer *>  m_timerToUpdate;
STimer::STimer() {
   m_timerToUpdate.insert(this);
}
STimer::~STimer() {
    this->stop();
    m_timerToUpdate.erase(this);
}
void STimer::start(std::chrono::milliseconds interval) {
    setInterval(interval);
    start();
}
void STimer::start() {
    m_startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    m_active = true;
}
void STimer::stop() {
    m_active = false;
}
void STimer::setInterval(std::chrono::milliseconds interval) {
  m_interval = interval;
}
bool STimer::isActive() {
    return m_active;
}
void STimer::update() {
    if(m_active) {
        const auto currentTime  = std::chrono::system_clock::now();
        const auto currentTimeMil = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch());
        if((currentTimeMil.count() - m_startTime.count() ) >= m_interval.count()) {
            timeout();
            m_startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        }
    }
}
void STimer::updateAll() {
    for(auto & timer : m_timerToUpdate) {
        if(timer != nullptr) {
            timer->update();
        }
        else {
            std::cout<<"Null TImer\n";
        }
    }
}
