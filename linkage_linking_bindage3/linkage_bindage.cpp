// File: linkage_bindage_demo.cpp
#include "linkage_bindage.hpp" //#include "linkage_bindage_demo.h"
#include "global_entities.hpp"
#include <iostream>

/* grostig, move to cpp */
   // No Linkage Examples
void demonstrate_no_linkage() {
    // Local variables have no linkage - only visible within this function
    int local_var = 42;                 // No linkage
    // Block-scoped entities
    {
        int block_scoped = 100;         // No linkage
        std::cout << "Block-scoped variable (no linkage): " << block_scoped << std::endl;
    }
    // Function parameters have no linkage
    auto lambda = [](int param) {       // param has no linkage
        std::cout << "Function parameter (no linkage): " << param << std::endl;
    };
    lambda(local_var);
    std::cout << "Local variable (no linkage): " << local_var << std::endl;
}
/* */

// Definition for external_var declared in header
int external_var = 4;                   // External linkage, external bindage

// Definition for external_bindage_const declared in header
extern const int external_bindage_const = 10;  // External linkage, external bindage

// Definition for static class member
int LinkageExample::static_member = 6;  // External linkage, external bindage

// Implementation for external_function
void external_function() {              // External linkage, external bindage
    std::cout << "External function (external linkage, external bindage)" << std::endl;
}
