// File: linkage_bindage_demo.cpp
#include "internal_linkage_component.hpp" //#include "linkage_bindage_demo.h"
#include "global_entities.hpp"
#include <iostream>

//namespace InternalComponent {
//} // namespace InternalComponent

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
