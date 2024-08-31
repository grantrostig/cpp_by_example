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
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <random>

using std::cout; using std::endl;
constexpr int item_count{523'221};    // large number, based on system memory size limitations.  TODO??: seg fault in random_fill(), what?, why? but only with this larger number.

struct Timer {
    using Clock =  std::chrono::high_resolution_clock;
    using Second = std::chrono::duration< double, std::ratio<1> >;  // TODO??: magic number!!
    // using Second2= std::chrono::seconds ;  // TODO??: magic number!!
    // using Second3= std::chrono::duration< double,            1  >;  // TODO??: magic number!!
    std::chrono::time_point<Clock> beginning_;
public:
    Timer(): beginning_ {Clock::now()} {}
    void reset() { beginning_ = Clock::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<Second>( Clock::now() - beginning_ ).count();
    }
};

template <class T, unsigned int N> // TODO??: implement contracts: requires std::is_floating_point<T>{};
void random_float_fill(T (&data)[N]) {
    cout << "start fill." << endl;
    std::mt19937 my_generator{ std::random_device{}() };
    cout << "generator." << endl;
    std::uniform_real_distribution<T> my_distribution{
        0, 999999
        // std::numeric_limits<T>::min(),
        // std::numeric_limits<T>::max()
    };
    cout << "dist:" << std::numeric_limits<T>::min() << "," << std::numeric_limits<T>::max() << endl;
    std::generate(std::begin(data), std::end(data), [&my_distribution, &my_generator]() { return my_distribution(my_generator); });
    cout << "generated." << endl;
}

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

int i{};
bool less_double(double const & a, double const & b) {
    i++;
    bool const result{ a < b };
    return result;
}

int compare(void const *a, void const *b) {
    // double difference_new{ *(double*)a <=> *(double*)b };  // TODO??: doesn't work for c array.
    double const difference{ *(double const *)a - *(double const *)b };
    if(difference > 0) return 1;
    if(difference < 0) return -1;
    return 0;
}

int compare_non_branching(void const *a, void const *b) {  // Optimization: No branching so can be pipelined? better?
    return ( *(double*)a > *(double*)b ) - ( *(double*)a < *(double*)b );
}

int compare_old(void const*a, void const*b) {  // TODO??: really?
    return *(double*)a - *(double*)b < 0? -1: 1;  // A small negative value would round to 0 rather than -1.
}

double original_data[item_count];
double sortable_data[item_count];

int main() {
    random_float_fill(original_data);
    //assert( not std::is_sorted( std::begin(original_data),  std::end(original_data) ));
    //cout<<"$$filled:"<<endl;
    //for (double i:original_data) { cout <<i<< ", "; }; cout <<endl;
    //for (int i{0};i<ITEM_COUNT;++i) { cout << original_data[i] << ", "; } cout <<endl;
    //std::copy(original_data, original_data + ITEM_COUNT, sortable_data);
    std::copy(std::begin(original_data), std::end(original_data), std::begin(sortable_data)); // cout<<"copy1"<<endl; // [begin,end) end one beyond value ~ sentinel

    Timer t{};
    std::qsort(sortable_data, item_count, sizeof(double), compare);  // C lang sort using maybe a quick sort
    double elapsed{t.elapsed()};
    //assert( std::is_sorted( sortable_data,  sortable_data + ITEM_COUNT) );
    //assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) , compare) );
    //assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) ));
    std::cout << "C lang qsort() time: " << elapsed << " seconds\n";

    std::copy(original_data, original_data + item_count, sortable_data); // cout<<"copy3"<<endl;
    t.reset();
    qsort(sortable_data, item_count, sizeof(double), compare);  // C lang sort using a quick sort variant
    elapsed = t.elapsed();
    //assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) ));
    std::cout << "C lang qsort() time: " << elapsed << " seconds\n";

    std::copy(original_data, original_data + item_count, sortable_data); // cout<<"copy2"<<endl;
    t.reset();
    std::qsort(sortable_data, item_count, sizeof(double), compare_non_branching);  // C lang sort using a quick sort variant
    elapsed = t.elapsed();
    //assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) ));
    std::cout << "std::qsort() compare_non_branching: " << elapsed << " seconds\n";

    std::copy(original_data, original_data + item_count, sortable_data); // cout<<"copy4"<<endl;
    t.reset();
    std::sort(std::begin(sortable_data), std::end(sortable_data), less_double);  // C++ sort using a quick sort variant TODO??: prove it.
    elapsed = t.elapsed();
    //assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) ));
    std::cout << "std:: sort() less_double time: " << elapsed << " seconds\n";

    std::copy(original_data, original_data + item_count, sortable_data); // cout<<"copy4"<<endl;
    t.reset();
    std::sort(std::begin(sortable_data), std::end(sortable_data));  // C++ sort using a quick sort variant TODO??: prove it.
    //std::sort(std::begin(sortable_data), std::end(sortable_data), std::less<double>{});  // C++ sort using a quick sort variant TODO??: prove it.
    elapsed = t.elapsed();
    //assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) ));
    std::cout << "std:: sort() time: " << elapsed << " seconds\n";
}

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
