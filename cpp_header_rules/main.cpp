// vendor's main
#include "client_use.hpp"

#include "my_api.hpp"  //  BAD: DRY already in client_use.hpp

#include <iostream>

int main() {
    std::string main_string{};
    Vendor_api vendor_api{};
    std::cout << "Hello World!\n";
    return 0;
}
