#pragma once
//#include <xtd/event_args>       // @grantrostig
#include <xtd/event_handler>    // @grantrostig
#include <xtd/event>

class Model : public xtd::object {
    int value_{0};
public:
    xtd::event<Model, xtd::event_handler> event_a_handler_value_changed_{};

    int  value() const {return value_;}
    void increment_counter() {
        ++value_;
        event_a_handler_value_changed_(*this, xtd::event_args::empty);
    }
};
