#pragma once
#include "animal_types.hpp"
#include <iostream>
//class Animal::Dog{};
//class Animal::Cat{};

enum class Animal_type { cat, dog };

class Animal {
public:
    virtual void speak(Animal_type a);

    Animal create(Animal_type a)
    {
        switch (a) {
        case Animal_type::dog:
            //return new Dog();
            break;
        case Animal_type::cat:
            //return new Cat();
            break;
        default:
            // throw new ArgumentException("Invalid animal type");
            break;
        }
    }
};
