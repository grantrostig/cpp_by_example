/** Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003
    Copyright (c) 2024 Alan Uthoff
*/
#pragma once
#include "../lib/fteng/signals.hpp" //fteng/signals.hpp from https://github.com/TheWisp/signals under the MIT License
#include <chrono>
#include <set>

class Feeding_chime {
static std::set<Feeding_chime *> m_timerToUpdate;  // m_ is like _
protected:
    bool m_active = false;
    std::chrono::milliseconds m_startTime;
    std::chrono::milliseconds m_interval;
    void update();
public:
    fteng::signal<void()> timeout;
    Feeding_chime();
    ~Feeding_chime();
    void start();
    void start(std::chrono::milliseconds interval);
    void stop();
    void setInterval(std::chrono::milliseconds interval);
    bool isActive();
    static void updateAll();   // probably not notify ???
};
