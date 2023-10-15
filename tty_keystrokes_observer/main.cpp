// g++ -Werror -Weffc++ -Wextra -Wall -Wconversion -Wshadow -Wpedantic -Wold-style-cast -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-override -Wnon-virtual-dtor
// -Wcast-align -Woverloaded-virtual -Wunused -pedantic -Wsign-conversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough
// -Wuseless-cast -Wsuggest-final-types -Wsuggest-final-methods -Wduplicated-cond -Wduplicated-branches -Wlogical-op -std=c++20 Term_keys.cpp main.cpp -o tk

// clang++ -Werror -Weffc++ -Wextra -Wall -Wconversion -Wshadow -Wpedantic -Wold-style-cast -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-override -Wnon-virtual-dtor
// -Wcast-align -Woverloaded-virtual -Wunused -pedantic -Wsign-conversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough
// -std=c++20 Term_keys.cpp main.cpp -o tk

#include "tty.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

class Tty_controller : public Keystroke_events_I {
public:
  void run() {
    Tty tk;
      tk.attach_observer(*this);
    tk.read_keystrokes();
  }

  void tk_escape() override { std::cout << "ESC\n"; }

  void tk_char(char c, bool alt) override { std::cout << (alt ? "ALT+" : "") << c << '\n'; }

  void tk_del(const Modifiers &&mods) override {
    print_mods(mods);
    std::cout << "DEL\n";
  }

  void tk_ins(const Modifiers &&mods) override {
    print_mods(mods);
    std::cout << "INS\n";
  }

  void tk_home(const Modifiers &&mods) override {
    print_mods(mods);
    std::cout << "HOME\n";
  }

  void tk_end(const Modifiers &&mods) override {
    print_mods(mods);
    std::cout << "END\n";
  }

  void tk_page(Direction dir, const Modifiers &&mods) override {
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

  void tk_arrow(Direction dir, const Modifiers &&mods) override {
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

  void tk_center(const Modifiers &&mods) override {
    print_mods(mods);
    std::cout << "CENTER\n";
  }

  void tk_tab(Direction dir) override {
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

  void tk_backspace(const Modifiers &&mods) override {
    print_mods(mods);
    std::cout << "BS\n";
    return;
  }

  void tk_enter(const Modifiers &&mods) override {
    print_mods(mods);
    std::cout << "ENT\n";
    return;
  }

  void tk_function(int8_t id, const Modifiers &&mods) override {
    print_mods(mods);
    std::cout << "F" << static_cast<int>(id) << '\n';
    return;
  }

  void tk_unhandled(uint64_t seq) override {
    std::stringstream ss;
    ss << std::hex << seq;
    auto hex{ss.str()};
    std::transform(hex.begin(), hex.end(), hex.begin(), [](auto c) { return std::toupper(c); });
    std::cout << "UNKONWN: 0x" << hex << '\n';
    return;
  }

  void print_mods(const Modifiers &mods) {
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
};

int main() {
  Tty_controller tt;
  tt.run();

  return 0;
}
