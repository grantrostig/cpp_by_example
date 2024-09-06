#include "compilation_unit_2_fn.hpp"

int compare_cu_linked(void const *a, void const *b) {
//inline int compare_cu2(void const *a, void const *b) {
    double const difference{ *static_cast<double const *>(a) - *static_cast<double const *>(b) };
    if(difference > 0) return 1;
    if(difference < 0) return -1;
    return 0;
}
