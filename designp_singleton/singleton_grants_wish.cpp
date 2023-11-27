#include "singleton_grants_wish.hpp"
singleton_grants_wish::singleton_grants_wish() {  }

class Registryx {
    // vector of singletons
};

static Registryx  registryx1 {};

class Singleton1: registryx {
    // special stuff about a topic2
};

class Singleton2: registryx2 {
    // special stuff about a topic2
};

int test_singleton_grants_wish () {
    Singleton1 * singleton1 {"singleton1"};
    Singleton2 * singleton2 {"singleton2"};
}
