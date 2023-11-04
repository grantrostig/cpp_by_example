#include "scope.hpp"

int global_______scope_hpp_noInit_int {};            // Dec REF

int global_scope_fn1(int i) {  // extern not needed
    int local_scope_int {};
    return 0;
}

int namespace_scope_fn(int i) {
    int block_scope_int {};
return 0;
}

void test_scope(){

}
