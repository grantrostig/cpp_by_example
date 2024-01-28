/** Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003
    Copyright (c) 2024 Alan Uthoff
*/
#include "Feeding_chime.h"
#include <iostream>

Feeding_chime::Feeding_chime() {
    Feeding_chime::m_timerToUpdate.insert(this);
}
Feeding_chime::~Feeding_chime() {
    this->stop();
    Feeding_chime:: m_timerToUpdate.erase(this);
}
void Feeding_chime::start(std::chrono::milliseconds interval) {
    setInterval(interval);
    start();
}
void Feeding_chime::start() {
    m_startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    m_active = true;
}
void Feeding_chime::stop() {
    m_active = false;
}
void Feeding_chime::setInterval(std::chrono::milliseconds interval) {
  m_interval = interval;
}
bool Feeding_chime::isActive() {
    return m_active;
}
void Feeding_chime::update() {
    if(m_active) {
        const auto currentTime  = std::chrono::system_clock::now();
        const auto currentTimeMil = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch());
        if((currentTimeMil.count() - m_startTime.count() ) >= m_interval.count()) {
            timeout();
            m_startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        }
    }
}
void Feeding_chime::updateAll() {
    for(auto & timer : Feeding_chime::m_timerToUpdate) {
        if(timer != nullptr) {
            timer->update();
        }
        else {
            std::cout<<"Null TImer\n";
        }
    }
}
