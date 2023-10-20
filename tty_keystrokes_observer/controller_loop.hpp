#pragma once
#include "tty_keystroke_subject.hpp"
#include "tty_keystroke_observer.hpp"
#include "tty_logger.hpp"

class Controller_loop {
public:
    Controller_loop();

    int run();
};
