#pragma once
#include "animals.hpp"
#include <iostream>

using namespace std;

class Dog : public Animal {
public:
    virtual void speak() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    virtual void speak() override {
        cout << "Meow!" << endl;
    }
};

// class Animal_types {
// public:
//     Animal_types();
// };
