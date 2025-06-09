#pragma once
//#include <xtd/event_args>       // @grantrostig
#include <xtd/event_handler>    // @grantrostig
#include <xtd/event>

class counter_model : public xtd::object {
    int value_ = 0;
public:
    xtd::event<counter_model, xtd::event_handler> event_a_handler_value_changed{};
    int  value() const {return value_;}
    void increment() {
        ++value_;
        event_a_handler_value_changed(*this, xtd::event_args::empty);
    }
};
