#pragma once
//#include "animal_types.hpp"
//class Animal::Dog{};
//class Animal::Cat{};

enum class Animal_type { cat, dog };

class Animal {
public:
    virtual ~Animal();  // TODO??: There are no data members! Maybe there is a vtable?? Why is this needed?  Get warning otherwise.  Derived destructors want to call?
    virtual void speak() =0;  // TODO??: why must this be =0?
    static Animal * create(Animal_type a);
};
