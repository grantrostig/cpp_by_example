/** Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003
    Copyright (c) 2024 Alan Uthoff
*/
#pragma once
#include "../lib/fteng/signals.hpp" //fteng/signals.hpp from https://github.com/TheWisp/signals under the MIT License
#include <cassert>
#include <chrono>
#include <iostream>
#include <set>
class Feeding_chime {
static std::set<Feeding_chime *> feeding_chimes_ptr_set_to_update_;
protected:
    bool                      active_{false};    // TODO??: ERROR? never used for any real task?
    std::chrono::milliseconds startTime_{};
    std::chrono::milliseconds interval_{};
    void update() {
        if ( active_ ) {
            std::cout << "update( active_ ).\n";
            const auto temp_currentTime{std::chrono::system_clock::now()};
            const auto temp_currentTimeMil{std::chrono::duration_cast<std::chrono::milliseconds>(
                temp_currentTime.time_since_epoch())};
            if ((temp_currentTimeMil.count() - startTime_.count()) >= interval_.count()) {
                chime_timeout_signal();
                startTime_ = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch());
            }
        } else
            std::cout << "update( not active_ ).\n";
    }
public:
    fteng::signal<void()> chime_timeout_signal{};  // TODO??: Should NOT be public, signal for fuction that returns void.

    Feeding_chime() {
        Feeding_chime::feeding_chimes_ptr_set_to_update_.insert(this);
    }
    ~Feeding_chime() {
        this->stop();
        feeding_chimes_ptr_set_to_update_.erase(this);
    }
    void setInterval(std::chrono::milliseconds interval) { interval_ = interval; }
    void start() {
        startTime_ = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
        active_ = true;
    }
    void start(std::chrono::milliseconds interval) {
        setInterval(interval);
        start();
    }
    void stop() {
        std::cout << "Feeding_chime.stop()" << std::endl;
        active_ = false;
    }
    bool isActive() { return active_; }

    static void updateAll() {
        for (auto &chime : feeding_chimes_ptr_set_to_update_) {
            chime->update(); // if ( chime != nullptr) { chime->update(); } else assert(false);
        }
    }
};

