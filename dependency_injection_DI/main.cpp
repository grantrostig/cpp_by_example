// https://medium.com/@simontoth/daily-bit-e-of-c-dependency-injection-fdcdd14ecdee
// https://www.bogotobogo.com/DesignPatterns/Dependency_Injection_Design_Pattern_Inversion_Of_Control_IoC.php

// Decouple the construction of your class from the construction of its dependencies.
// What is, and how is this related to "Dependency Inversion" Principle?
// Code should depend on Abstractions.
// - Decoupling our lower level implementations from each other.
// - Makes easier to read, modify and re-use.
// Dependency injection container helps
//  - find dependencies to use
//  - has it been created yet?  else create it and then return it?? See video: https://www.youtube.com/watch?v=IKD2-MAkXyQ
//  - is this the same thing as "IoC Container"?


#include <memory>
#include <iostream>
using namespace std;

struct IService { // Base interface
    virtual void make_important_call() =0;  // pure virtual??
};

struct FakeService : public IService { // Fake implementation for testing
    void make_important_call() final override { std::cout << "Fake Service.\n"; }
};

struct ProductionService : public IService { // Real implementation
    void make_important_call() final override { std::cout << "Production Service.\n"; }
};

class MyClass {
         std::unique_ptr< IService> dependency_;
public:  MyClass( std::unique_ptr< IService > iservice) : dependency_ { std::move( iservice )} {} // Inject dependency
         void operate() { dependency_->make_important_call(); }
};

void test_service() {
    MyClass m { std::make_unique<ProductionService>()}; // In production code:
    m.operate();
    MyClass n { std::make_unique<FakeService>()}; // In test code:
    n.operate();
}
int main() { cout << "~~~" <<endl;
    test_service();

    cout << "###" <<endl;
}
