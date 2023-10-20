/// Gang of Four Observer Design Pattern example.
/// AKA: Dependents, Publish-subscribe, pub-sub, pubsub, Broadcaster??.
/// Know Uses: MVC.
/// Basically event driven graphical user interfaces where there is an "invertion of contol"?  TODO??: is this all true?
/// Related Patterns: Mediator, Singleton.
/// edited by Grant Rostig 2022
// g++ -Werror -Weffc++ -Wextra -Wall -Wconversion -Wshadow -Wpedantic -Wold-style-cast -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-override -Wnon-virtual-dtor
// -Wcast-align -Woverloaded-virtual -Wunused -pedantic -Wsign-conversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough
// -Wuseless-cast -Wsuggest-final-types -Wsuggest-final-methods -Wduplicated-cond -Wduplicated-branches -Wlogical-op -std=c++20 Term_keys.cpp main.cpp -o tk

// clang++ -Werror -Weffc++ -Wextra -Wall -Wconversion -Wshadow -Wpedantic -Wold-style-cast -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-override -Wnon-virtual-dtor
// -Wcast-align -Woverloaded-virtual -Wunused -pedantic -Wsign-conversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough
// -std=c++20 Term_keys.cpp main.cpp -o tk

#include "tty_keystroke_observer.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int main() {
    Tty_keystroke_observer tt;
    tt.run();

    return 0;
}
