#pragma once
#include <cstdint>

enum class Direction { u, d, l, r };

struct Modifiers {
    const bool ctrl  : 1; //todo??: what is : doing there?  bitfields, only in "structs"
    const bool alt   : 1;
    const bool shift : 1;
};

/// A pure virtual class acting as an conceptual "interface", being a collection of functions (tk_arrow...)
/// that represent events which consist of having read
/// a particular character from the keyboard via a tty interface which connects a terminal or xterminal to a Linux instance.
class Keystroke_events_I {
public:
    virtual      ~Keystroke_events_I() = default;
    virtual void tk_escape()                                    = 0;
    virtual void tk_char(         char,       bool)             = 0;
    virtual void tk_enter(        const Modifiers &&)           = 0;
    virtual void tk_backspace(    const Modifiers &&)           = 0;
    virtual void tk_ins(          const Modifiers &&)           = 0;
    virtual void tk_del(          const Modifiers &&)           = 0;
    virtual void tk_home(         const Modifiers &&)           = 0;
    virtual void tk_end(          const Modifiers &&)           = 0;
    virtual void tk_center(       const Modifiers &&)           = 0;
    virtual void tk_tab(          Direction)                    = 0;
    virtual void tk_arrow(        Direction, const Modifiers &&)= 0;
    virtual void tk_page(         Direction, const Modifiers &&)= 0;
    virtual void tk_function(     int8_t, const Modifiers &&)   = 0;
    virtual void tk_unhandled(    uint64_t)                     = 0;
};

