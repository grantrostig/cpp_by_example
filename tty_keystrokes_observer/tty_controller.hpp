#pragma once
#include "observer.hpp"
#include "tty.hpp"

/// The tty_contoller is a GOF "Observer" of the "Subject" which in this case is "tty".
/// instead of of the subject calling update()
class Tty_controller : public Observer, public Keystroke_events_I {
public:
            // Base class members.
    Update_ret update()                                 override;  // Not used in this example, instead the below event fn's are used.
    void tk_escape()                                    override;
    void tk_char(       char            c, bool alt)    override;
    void tk_del(        const Modifiers &&mods)         override;
    void tk_ins(        const Modifiers &&mods)         override;
    void tk_home(       const Modifiers &&mods)         override;
    void tk_end(        const Modifiers &&mods)         override;
    void tk_page(             Direction dir, const Modifiers &&mods) override;
    void tk_arrow(            Direction dir, const Modifiers &&mods) override;
    void tk_center(     const Modifiers &&mods)         override;
    void tk_tab(              Direction dir)            override;
    void tk_backspace(  const Modifiers &&mods)         override;
    void tk_enter(      const Modifiers &&mods)         override;
    void tk_function(         int8_t    id, const Modifiers &&mods) override;
    void tk_unhandled(        uint64_t  seq)            override;
            // Derived class members.
    void run();
    void print_mods(    const Modifiers &mods);
};

