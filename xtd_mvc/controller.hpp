#pragma once
#include "model.hpp"

class counter_controller {
    counter_model& model_ref_;  // ref points to Model, but not View?
public:
    explicit
    counter_controller(counter_model& model):model_ref_{model}{} // Constructor
    void increment_counter() { model_ref_.increment(); }
};
