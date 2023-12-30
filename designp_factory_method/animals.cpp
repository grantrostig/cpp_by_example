#include "animals.hpp"
#include <cassert>
#include <iostream>
using namespace std;

Animal::~Animal() { }

Animal * Animal::create(Animal_type a) {
    switch (a) {
    case Animal_type::dog :
        return new Dog();
        break;
    case Animal_type::cat :
        return new Cat();
        break;
    };
    assert( false );
}

void Dog::speak() {
    cout << "Woof!" << endl;
}

void Cat::speak() {
     cout << "Meow!" << endl;
}
