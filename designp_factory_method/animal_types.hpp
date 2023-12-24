#pragma once
#include "animals.hpp"
#include <iostream>

using namespace std;
class Dog : public Animal {
public:
    void speak();
};

class Cat : public Animal {
public:
    void speak();
};
