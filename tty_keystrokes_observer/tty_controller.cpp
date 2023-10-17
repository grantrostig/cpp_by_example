#include "tty_controller.hpp"
#include <iostream>

Observer::Update_ret Tty_controller::update() {
    Update_ret unused {0};
    return unused;
}

void Tty_controller::run() {
    Tty tk;
    tk.attach_observer(*this);
    tk.read_keystrokes_from_keyboard();
}

inline void Tty_controller::tk_escape() { std::cout << "ESC\n"; }  // TODO??: why are these inline?  Doing that for ::run() caused a link error!

inline void Tty_controller::tk_char(char c, bool alt) { std::cout << (alt ? "ALT+" : "") << c << '\n'; }

inline void Tty_controller::tk_del(const Modifiers &&mods) {
    print_mods(mods);
    std::cout << "DEL\n";
}

inline void Tty_controller::tk_ins(const Modifiers &&mods) {
    print_mods(mods);
    std::cout << "INS\n";
}

inline void Tty_controller::tk_home(const Modifiers &&mods) {
    print_mods(mods);
    std::cout << "HOME\n";
}

inline void Tty_controller::tk_end(const Modifiers &&mods) {
    print_mods(mods);
    std::cout << "END\n";
}

inline void Tty_controller::tk_page(Direction dir, const Modifiers &&mods) {
    print_mods(mods);

    switch (dir) {
    case Direction::u:
        std::cout << "PGUP\n";
        break;
    case Direction::d:
        std::cout << "PGDN\n";
        break;
    default:
        break;
    }
}

inline void Tty_controller::tk_arrow(Direction dir, const Modifiers &&mods) {
    print_mods(mods);
    switch (dir) {
    case Direction::u:
        std::cout << "/\\\n";
        break;
    case Direction::d:
        std::cout << "\\/\n";
        break;
    case Direction::r:
        std::cout << ">\n";
        break;
    case Direction::l:
        std::cout << "<\n";
        break;
    }
    return;
}

inline void Tty_controller::tk_center(const Modifiers &&mods) {
    print_mods(mods);
    std::cout << "CENTER\n";
}

inline void Tty_controller::tk_tab(Direction dir) {
    switch (dir) {
    case Direction::r:
        std::cout << "TAB>\n";
        break;
    case Direction::l:
        std::cout << "TAB<\n";
        break;
    default:
        break;
    }
    return;
}

inline void Tty_controller::tk_backspace(const Modifiers &&mods) {
    print_mods(mods);
    std::cout << "BS\n";
    return;
}

inline void Tty_controller::tk_enter(const Modifiers &&mods) {
    print_mods(mods);
    std::cout << "ENT\n";
    return;
}

inline void Tty_controller::tk_function(int8_t id, const Modifiers &&mods) {
    print_mods(mods);
    std::cout << "F" << static_cast<int>(id) << '\n';
    return;
}

inline void Tty_controller::tk_unhandled(uint64_t seq) {
    std::stringstream ss;
    ss << std::hex << seq;
    auto hex{ss.str()};
    std::transform(hex.begin(), hex.end(), hex.begin(), [](auto c) { return std::toupper(c); });
    std::cout << "UNKONWN: 0x" << hex << '\n';
    return;
}

inline void Tty_controller::print_mods(const Modifiers &mods) {
    //std::cout << "mod size = " << sizeof(mods) << ".\n";
    if (mods.ctrl) {
        std::cout << "CTRL+";
    }
    if (mods.alt) {
        std::cout << "ALT+";
    }
    if (mods.shift) {
        std::cout << "SHIFT+";
    }
    return;
}
