/** Edited by: Grant Rostig
    Boost Software License - Version 1.0 - August 17th, 2003
    Copyright (c) 2024 Alan Uthoff
*/
#pragma once
#include "Feeding_chime.h"
#include "../lib/fteng/signals.hpp"  // github.com/TheWisp/signals under the MIT License
#include <iostream>

class Signal_user{
    std::chrono::milliseconds   last_update_{};
    Feeding_chime               timer_{};
    fteng::connection           connection_chime_timer_slot_{};  //User to auto disconnect on destruction of Signal_user
public:
    explicit Signal_user(std::chrono::milliseconds interval) {
        last_update_                  = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        connection_chime_timer_slot_  = timer_.chime_timeout_signal.connect< &Signal_user::touch_last_update >( this );  // note: THIS  >>>>>>> see definition.
        timer_.start(interval);
    }
    ~Signal_user() { timer_.stop(); }

    void touch_last_update(){
        const auto temp_now{std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())};
        std::cout << "Update time interval:" << temp_now.count() - last_update_.count() <<"ms\n";
        last_update_= temp_now;
    }
};
