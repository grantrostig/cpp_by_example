#pragma once
//#include "animal_types.hpp"
#include <iostream>
//class Animal::Dog{};
//class Animal::Cat{};

enum class Animal_type { cat, dog };

class Animal {
public:
    virtual void speak() =0;  // TODO??: why must this be =0?
    static Animal * create(Animal_type a);
};
