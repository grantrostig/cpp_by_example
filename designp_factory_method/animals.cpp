#include "animals.hpp"
#include "animal_types.hpp"
#include <cassert>

//Animals::Animals() {}

//Animal Animal::create(int a)
Animal::~Animal() {

}

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
