#pragma once
#include "animals.hpp"

using namespace std;
class Dog : public Animal {
public:
    void speak();
};

class Cat : public Animal {
public:
    void speak();
};
