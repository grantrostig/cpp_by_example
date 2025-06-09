#pragma once
#include "model.hpp"
#include "controller.hpp"
#include <xtd/forms/button>
#include <xtd/forms/label>
#include <xtd/forms/form>
// *** VIEW *** in MVC, here called a form. @grantrostig
class main_form : public xtd::forms::form {
    xtd::forms::button  button_{};
    xtd::forms::label   label_{};
    counter_model       model_{};
    counter_controller  controller_{model_}; //@grantrostig counter_controller  controller_ = counter_controller(model_);
public:
    main_form() {  // constructor
        text("MVC Example");
        controls().push_back_range({button_, label_});  // TODO??: place after settins below?
        button_.location({10, 10});
        button_.text("Incrémenter");
        button_.click += [&] { controller_.increment_counter(); };
        label_.location({10, 50});
        label_.auto_size(true);
        model_.event_a_handler_value_changed += {*this, &main_form::on_model_value_changed}; // Subscribe to model updates
        this->update_view();
    }
private:
    void update_view() {
        label_.text( xtd::ustring::format( "Valeur actuelle : {}", model_.value() ) );  // grostig
    }
    void on_model_value_changed(xtd::object& sender, const xtd::event_args& e) {
        this->update_view();
    }
};
