// File: linkage_bindage_demo.h
#pragma once
#include <iostream>
#include <string>

void demonstrate_no_linkage();  // Definition moved to .cpp

// Internal Linkage Examples
namespace {
// Unnamed namespace - everything here has internal linkage
int unnamed_namespace_var = 1;      // Internal linkage

void unnamed_namespace_function() { // Internal linkage
    std::cout << "Function in unnamed namespace (internal linkage)" << std::endl;
}
}

// Static entities at namespace scope have internal linkage
static int static_global_var = 2;       // Internal linkage

// Internal linkage with Internal Bindage
static constexpr int internal_bindage_const = 3;   // Internal linkage, internal bindage

// External Linkage Examples
// Regular namespace-scope declarations have external linkage
extern int external_var;                // External linkage

// Function declaration with external linkage
void external_function();               // External linkage

// Class definition - has external linkage
class LinkageExample {
public:
    // Static member with external linkage
    static int static_member;           // External linkage

    // Class methods have external linkage
    void method() const {
        std::cout << "Class method (external linkage)" << std::endl;
    }
};

// Inline function - external linkage but typically internal bindage
inline void inline_function() {         // External linkage, internal bindage
    std::cout << "Inline function (external linkage, internal bindage)" << std::endl;
}

// External linkage with External Bindage
extern const int external_bindage_const;  // External linkage, external bindage

// External linkage with Dual Bindage (header-only design)
inline constexpr int dual_bindage_const = 5;  // External linkage, dual bindage

// Template - has external linkage but typically internal bindage
template<typename T>
void template_function(T value) {       // External linkage, internal bindage
    std::cout << "Template function with value: " << value << std::endl;
}


