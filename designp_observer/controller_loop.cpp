#include "controller_loop.hpp"

Controller_loop::Controller_loop() { }

int Controller_loop::run() {
    int result {0};
    Tty_keystroke_observer      tty_key_observer;
    Tty_keystroke_observer      tty_logger;

    Tty_keystroke_subject       tty_subject;
    tty_subject.attach_observer( tty_key_observer );
    tty_subject.attach_observer( tty_logger );

    tty_subject.read_keystrokes_from_keyboard();
    return result;
}
