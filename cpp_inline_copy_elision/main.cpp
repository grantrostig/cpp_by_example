/* copyright (c) 2024 Grant Rostig based on work by Jon Kalb / Boost 1.0 license

Inlining:
qsort vs std::sort and talk about function call elision

As-if rule and compiler order preferences.

Calls to template functions with function pointer
Calls to template functions with inlined function objects
Calls to template functions with lambdas

Do we ever pass large objects by value?

Do we every return large objects? (That would be better for const correctness.)

Copy elisions
passing temporaries.
RVO
*/
#include "compilation_unit_2_fn.hpp"
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <random>

using std::cout; using std::endl;
constexpr int item_count{2'000'000};    // Large number, based on system memory size limitations.
double original_data[item_count];       // C lang array used by both languages, to illustrate C++ optimization beyond C lang.
double sortable_data[item_count];
//int loop_counter_less_fn{};
//int loop_counter_compare_fn{};
//int loop_counter_compare_non_branching_fn{};

struct Timer {
    using Clock =  std::chrono::high_resolution_clock;
    //using Second = std::chrono::duration< double, std::ratio<1>>;  // TODO??: remove magic number. Why was it double?? Is that correct?
    using time_unit = std::chrono::milliseconds;
    std::chrono::time_point<Clock> beginning_{};
public:
    Timer(): beginning_{Clock::now()} {}
    void reset() { beginning_ = Clock::now(); }
    auto elapsed() const {                                  // TODO??: Why was it double?? now long??  is auto required here for different_units?
        return std::chrono::duration_cast<time_unit>(Clock::now() - beginning_).count();
    }
};
Timer t{};
auto elapsed {Timer{}.elapsed()};

template <class T, unsigned int N>                          // TODO??: implement contracts: requires std::is_floating_point<T>{};
void random_float_fill(T (&data)[N]) {                                              // TODO??later: why not these? void random_float_fill(T &(data[N])) { //void random_float_fill(T &data[N]) { //void random_float_fill(T data[N]) {
    std::mt19937 my_generator{ std::random_device{}() };                            // TODO??later: why {}() not shown on cppref //std::random_device my_random_device{}; std::mt19937 my_generator{ my_random_device() };
    std::uniform_real_distribution<T> my_distribution{      // TODO??: real for array of double, what about array of int?
        std::numeric_limits<T>::min(),
        std::numeric_limits<T>::max()
    };
    std::ranges::generate( data, [&my_distribution, &my_generator]() { return my_distribution(my_generator); });
}

inline bool less_fn_sort(double const & a, double const & b) {
    bool const result{ a < b };
    return result;
}

inline int compare(void const *a, void const *b) {  // ERROR: double difference_new{ *(double*)a <=> *(double*)b };  // TODO??: doesn't work for c array.
    double const difference{ *static_cast<double const *>(a) - *static_cast<double const *>(b) };
    if(difference > 0) return 1;
    if(difference < 0) return -1;
    return 0;
}

inline int compare_non_branching(void const *a, void const *b) {  // Optimization: No branching so can be pipelined? better?
    int result {( *static_cast<double const *>(a) > *static_cast<double const *>(b) )
              - ( *static_cast<double const *>(a) < *static_cast<double const *>(b) )};  // TODO??: See comment at end below for overflow concerns!!
    return result;
}

extern int compare_cu_linked(void const *, void const *);

void prepare_for_sort() {
    assert( not std::is_sorted( std::begin(original_data),  std::end(original_data) ));
    /*
    // cout<<endl; for (double i:original_data) { cout <<i<< ", "; }; cout <<endl;
    // std::copy( std::begin(original_data), std::end(original_data), std::ostream_iterator<double>( std::cout, ", " ));  // TODo?? Is there another simpler way?

           // *** Some old, new, and probably bad ways to copy a C array :) ***
    memcpy( sortable_data, original_data, item_count*sizeof(double));  // C lang
    assert( std::equal(std::begin(original_data), std::end(original_data), std::begin(sortable_data)));
    for( unsigned long i{}; i<item_count; ++i ) sortable_data[i] = original_data[i];  // C lang
    assert( std::equal(std::begin(original_data), std::end(original_data), std::begin(sortable_data)));
    long j{0};
    for( double i : original_data ) {  // C++ "range for" misapplied!?
        sortable_data[j++] = i;
    }
    assert( std::equal(std::begin(original_data), std::end(original_data), std::begin(sortable_data)));
    std::copy(std::begin(original_data), std::end(original_data), std::begin(sortable_data));  // [begin,end) end one beyond value ~ sentinel
    assert( std::equal(std::begin(original_data), std::end(original_data), std::begin(sortable_data)));
    */
    std::ranges::copy( original_data, sortable_data);
    assert( std::equal(std::begin(original_data), std::end(original_data), std::begin(sortable_data)));
    t.reset();
}

inline void post_sort() {
    elapsed = t.elapsed();
    assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) ));
    assert( not std::is_sorted( std::begin(original_data),  std::end(original_data), less_fn_sort ));
}

int main() {
    random_float_fill(original_data);
    prepare_for_sort();
    qsort(sortable_data, item_count, sizeof(double), compare);  // C lang sort using a quick sort variant TODO??: prove it.
    post_sort();
    std::cout << "$$C lang qsort() compare:                   " << elapsed << endl;

    prepare_for_sort();
    qsort(sortable_data, item_count, sizeof(double), compare_cu_linked);
    post_sort();
    std::cout << "$$C lang qsort() compare_cu_linked:         " << elapsed << endl;

    prepare_for_sort();
    qsort(sortable_data, item_count, sizeof(double), compare_cu_inline);
    post_sort();
    std::cout << "$$C lang qsort() compare_cu_inline:         " << elapsed << endl;

    prepare_for_sort();
    std::qsort(sortable_data, item_count, sizeof(double), compare);
    post_sort();
    std::cout << "$$C lang std::qsort() compare:              " << elapsed << endl;

    prepare_for_sort();
    std::qsort(sortable_data, item_count, sizeof(double), compare_non_branching);
    post_sort();
    std::cout << "$$C lang std::qsort() compare_non_branch:   " << elapsed << endl;

    prepare_for_sort();
    std::sort(std::begin(sortable_data), std::end(sortable_data), less_fn_sort);  // C++ sort using a quick sort variant TODO??: prove it.
    post_sort();
    std::cout << "$$C++ std::sort() less_double_fn:           " << elapsed << endl;

    prepare_for_sort();
    std::sort(std::begin(sortable_data), std::end(sortable_data), std::less<double>{} );
    post_sort();
    std::cout << "$$C++ std::sort() std::less<double>:        " << elapsed << "\n";

    prepare_for_sort();
    std::ranges::sort(sortable_data, less_fn_sort);
    post_sort();
    std::cout << "$$C++ std::ranges::sort() less_double_fn:   " << elapsed << endl;

    prepare_for_sort();
    std::ranges::sort(sortable_data);
    post_sort();
    std::cout << "$$C++ std::ranges::sort():                  " << elapsed << endl;

    prepare_for_sort(); //t.reset();
    std::ranges::sort(sortable_data, std::ranges::less() );
    /*  Other approaches to try:
    //std::ranges::sort(sortable_data, [](double a, double b){return a<b;} );
    //struct { bool operator()(double a, double b) const { return a < b; } } custom_less;
    //std::ranges::sort(sortable_data, custom_less);
    */
    post_sort();
    std::cout << "$$std::ranges::sort() std::ranges::less()   " << elapsed << "\n"; //std::cout << "C++ std::!ranges::sort() std::less<double>" << elapsed_here << "\n";
    std::cout << "###"<<endl;
}

// ******** Balance of commented code/text is various items of potential interest and followup. *********
/* Chat GPT type respones:
>>GNU g++'s implementation of std::sort uses a hybrid sorting algorithm, not just quicksort. Here's a breakdown:
1. Primary algorithm: Introsort
   std::sort in GNU's libstdc++ primarily uses introsort, which is a hybrid sorting algorithm.

2. Components of Introsort:
   - Quicksort: Used as the main sorting method.
   - Heapsort: Used as a fallback if quicksort's recursion depth exceeds a certain limit.
   - Insertion sort: Used for small subarrays (typically less than 16 elements).

3. How it works:
   - The algorithm starts with quicksort.
   - If the recursion depth exceeds a threshold (usually 2*log2(N), where N is the number of elements), it switches to heapsort.
   - For small subarrays, it uses insertion sort, which is more efficient for small datasets.

4. Advantages:
   - This hybrid approach combines the average-case efficiency of quicksort with the worst-case efficiency of heapsort.
   - It avoids quicksort's worst-case scenario (O(n^2)) by switching to heapsort, ensuring O(n log n) worst-case performance.
   - Using insertion sort for small subarrays improves performance for smaller datasets and as a final step in larger sorts.

5. Implementation details:
   The exact implementation can vary between different versions of GCC and libstdc++. The source code for the current implementation can be found
    in the GCC source repository, typically in the file `include/bits/stl_algo.h`.

It's worth noting that while this is the typical implementation in GNU g++, the C++ standard doesn't specify the exact algorithm to be used for std::sort.
It only requires that it must have O(n log n) complexity in the average and worst cases.
===========================
The `qsort` function in the GNU C Library (glibc), which is used by GCC, doesn't strictly adhere to a single sorting algorithm. Its implementation is more nuanced:

1. Name origin: The name "qsort" suggests QuickSort, but this is somewhat historical and doesn't necessarily reflect the current implementation.

2. Actual implementation: The glibc `qsort` uses a combination of algorithms:

- For small arrays (typically less than 4 elements), it uses insertion sort.
- For larger arrays, it uses an introsort algorithm.

3. Introsort: This is the primary algorithm used for larger arrays. Introsort is a hybrid sorting algorithm that:
- Begins with quicksort
- Switches to heapsort when the recursion depth exceeds a certain level (to avoid quicksort's worst-case scenario)
- Uses insertion sort for small partitions

4. Optimization: The exact details may vary depending on the version of glibc and can be subject to optimizations and changes over time.

5. Quicksort connection: While introsort does use quicksort as its base, it's designed to avoid quicksort's worst-case O(n^2) time complexity, ensuring a worst-case O(n log n) performance.

So, to directly answer your question: While GNU GCC's `qsort` does use quicksort as part of its algorithm, it's not a pure implementation
of quicksort. It's a more sophisticated approach that combines multiple sorting techniques for efficiency and reliability across different input scenarios.
*/

/*  #include <limits.h>      // https://en.cppreference.com/w/c/algorithm/qsort
#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b) {
 int arg1 = *(const int*)a;
 int arg2 = *(const int*)b;
 if (arg1 < arg2) return -1;
 if (arg1 > arg2) return 1;
 return 0;
        // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
        // return arg1 - arg2; // erroneous shortcut: undefined behavior in case of
        // integer overflow, such as with INT_MIN here
}

int main(void) {
 int ints[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
 int size = sizeof ints / sizeof *ints;
 printf("%ld \n", sizeof *ints);  // TODO??: why pointer???, why not just int?
 printf("%ld \n", sizeof ints);
 printf("%ld \n", sizeof(int));
 qsort(ints, size, sizeof(int), compare_ints);
 for (int i = 0; i < size; i++)
     printf("%d ", ints[i]);
 printf("\n");
}*/
