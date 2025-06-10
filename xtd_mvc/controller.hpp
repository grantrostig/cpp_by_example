#pragma once
#include "model.hpp"

class Controller {
    Model& model_ref_;  // ref points to Model, but not View?
public:
    explicit
    Controller(Model& model):model_ref_{model}{} // Constructor
    void increment_counter() { model_ref_.increment_counter(); }
};
