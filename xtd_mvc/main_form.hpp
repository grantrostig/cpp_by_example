#pragma once
#include "model.hpp"
#include "controller.hpp"
#include <xtd/forms/button>
#include <xtd/forms/label>
#include <xtd/forms/form>

class main_form : public xtd::forms::form {
public:
    main_form() {
        text("MVC Example");
        controls().push_back_range({button_, label_});

        button_.location({10, 10});
        button_.text("Incrémenter");
        button_.click += [&] {
            controller_.increment_counter();
        };

        label_.location({10, 50});
        label_.auto_size(true);

               // Subscribe to model updates
        model_.value_changed += {*this, &main_form::on_model_value_changed};

        update_view();
    }

private:
    void on_model_value_changed(object& sender, const xtd::event_args& e) {
        update_view();
    }

    void update_view() {
        //label_.text(xtd::string::format("Valeur actuelle : {}", model_.value()));
        label_.text(xtd::ustring::format("Valeur actuelle : {}", model_.value()));  // grostig
    }

    counter_model model_;
    counter_controller controller_ = counter_controller(model_);
    xtd::forms::button button_;
    xtd::forms::label label_;
};
