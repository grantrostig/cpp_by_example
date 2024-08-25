// boost 1.0 license
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <random>

using std::cout; using std::endl;
constexpr int ITEM_COUNT{523'221};  // large number, based on system memory size limitations.  TODO??: seg fault in random_fill(), what?, why? but only with this larger number.
//constexpr int ITEM_COUNT{200'000};  // large number, based on system memory size limitations.  TODO??: seg fault in random_fill(), what?, why? but only with this larger number.
//constexpr int ITEM_COUNT{100};  // large number, based on system memory size limitations.  TODO??: seg fault in random_fill(), what?, why? but only with this larger number.

struct Timer {
    using Clock =  std::chrono::high_resolution_clock;
    using Second = std::chrono::duration< double, std::ratio<1> >;
    std::chrono::time_point<Clock> beginning_;
public:
    Timer(): beginning_ {Clock::now()} {}
    void reset() { beginning_ = Clock::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<Second>( Clock::now() - beginning_ ).count();
    }
};

template <class T, unsigned int N>                               // requires std::is_floating_point<T>{};
void random_float_fill( T(&data)[N] ) {
    cout<<"start fill."<<endl;
    std::mt19937 my_generator{std::random_device{}()};
    cout<<"generator."<<endl;
    std::uniform_real_distribution<T> my_distribution{
        0,
        999999
        //std::numeric_limits<T>::min(),
        //std::numeric_limits<T>::max()
    };
    cout<<"dist:"<<std::numeric_limits<T>::min()<<","<< std::numeric_limits<T>::max()<<endl;
    std::generate(std::begin(data), std::end(data), [&]{return my_distribution(my_generator);});
    cout<<"generated."<<endl;
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


int compare(void const *a, void const *b) {
    // double difference_new{ *(double*)a <=> *(double*)b };  // TODO??: doesn't work for c array.
    double const difference{ *(double const *)a - *(double const *)b };
    if( difference > 0) return  1;
    if( difference < 0) return -1;
    return 0;
}

int double_comp_old(void const*a, void const*b) {  // does not comply with standard C++ or C since it must return a zero for equality
    return *(double*)a - *(double*)b < 0? -1: 1;
}

double original_data[ITEM_COUNT];
double sortable_data[ITEM_COUNT];

int main() {
    random_float_fill(original_data);
    assert( not std::is_sorted( std::begin(original_data),  std::end(original_data) ));
    cout<<"filled:"<<endl;
    //for (double i:original_data) { cout <<i<< ", "; }; cout <<endl;
    //for (int i{0};i<ITEM_COUNT;++i) { cout << original_data[i] << ", "; } cout <<endl;
    //std::copy(original_data, original_data + ITEM_COUNT, sortable_data);
    std::copy(std::begin(original_data), std::end(original_data), std::begin(sortable_data)); cout<<"copy1"<<endl;

    Timer t{};
    std::qsort(sortable_data, ITEM_COUNT, sizeof(double), compare);  // C lang sort using maybe a quick sort
    double elapsed{t.elapsed()};
    //assert( std::is_sorted( sortable_data,  sortable_data + ITEM_COUNT) );
    //assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) , compare) );
    assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) ));
    std::cout << "qsort() time = " << elapsed << " seconds\n";

    std::copy(original_data, original_data + ITEM_COUNT, sortable_data); cout<<"copy2"<<endl;
    t.reset();
    qsort(sortable_data, ITEM_COUNT, sizeof(double), compare);  // C lang sort using maybe a quick sort
    elapsed = t.elapsed();
    assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) ));
    std::cout << "std::qsort() time = " << elapsed << " seconds\n";

    std::copy(original_data, original_data + ITEM_COUNT, sortable_data); cout<<"copy3"<<endl;
    t.reset();
    std::sort(std::begin(sortable_data), std::end(sortable_data));  // C++ sort using maybe a quick sort TODO??: prove it. // OLDER version: std::sort(sortable_data, sortable_data + ITEM_COUNT);
    elapsed = t.elapsed();
    assert( std::is_sorted( std::begin(sortable_data),  std::end(sortable_data) ));
    std::cout << "std::sort() time = " << elapsed << " seconds\n";
}
