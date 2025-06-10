#pragma once
#include "model.hpp"
#include "controller.hpp"
#include <xtd/forms/button>
#include <xtd/forms/label>
#include <xtd/forms/form>

class View_main_form : public xtd::forms::form {
    xtd::forms::button  button_{};
    xtd::forms::label   label_{};
    Model       model_{};
    Controller  controller_{model_};
public:
    View_main_form() {  // constructor
        this->text("MVC Example");
        this->controls().push_back_range({button_, label_});  // TODO??: place after the setters below?
        button_.location({10, 10});
        button_.text("Incrementer");
        button_.click += [&] { controller_.increment_counter(); };
        label_.location({10, 50});
        label_.auto_size(true);
        model_.event_a_handler_value_changed_ += {*this, &View_main_form::on_model_value_changed_fn}; // Subscribe to model updates
        this->update_view();
    }
private:
    void update_view() {
        label_.text( xtd::ustring::format( "Actual value: {}", model_.value() ) );  // grostig
    }
    void on_model_value_changed_fn(xtd::object& sender, const xtd::event_args& evnt_args) {
        this->update_view();
    }
};
