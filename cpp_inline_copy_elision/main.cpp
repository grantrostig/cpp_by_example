// boost 1.0 license
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <random>

using std::cout; using std::endl;

struct Timer {
    using Clock =  std::chrono::high_resolution_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;
    std::chrono::time_point<Clock> beginning_;
public:
    Timer(): beginning_ {Clock::now()} {}
    void reset() { beginning_ = Clock::now(); }
    double elapsed() const
    {
        return std::chrono::duration_cast<Second>
            (Clock::now() - beginning_).count();
    }
};

template <class T, long unsigned int N>                               // requires std::is_floating_point<T>{};
void random_float_fill( T(&data)[N] ) {
    std::mt19937 my_generator{std::random_device{}()};
    std::uniform_real_distribution<T> my_distribution{
                std::numeric_limits<T>::min(),
                std::numeric_limits<T>::max() };
    std::generate(std::begin(data), std::end(data), [&]{return my_distribution(my_generator);});
}

int double_comp(void const*a, void const*b) {
    return *(double*)a - *(double*)b < 0? -1: 1;
}

int main() {
    //constexpr long unsigned int item_count{523'221};  // large number, based on system memory size limitations.
    constexpr long unsigned int item_count{50'000};  // large number, based on system memory size limitations.
    //constexpr long unsigned int item_count{23'221};  // large number, based on system memory size limitations.
    double original_data[item_count];
    cout<<"array1"<<endl;
    double sortable_data[item_count];
    cout<<"array2"<<endl;
    random_float_fill(original_data);
    cout<<"fill"<<endl;
    std::copy(original_data, original_data + item_count, sortable_data);
    cout<<"copy1"<<endl;

    Timer t;
    qsort(sortable_data, item_count, sizeof(double), double_comp);  // C lang sort using quick sort
    double elapsed{t.elapsed()};
    cout<<"qsort"<<endl;
    std::cout << "qsort() time = " << elapsed << " seconds\n";

    std::copy(original_data, original_data + item_count, sortable_data);
    cout<<"copy2"<<endl;
    t.reset();
    std::sort(sortable_data, sortable_data + item_count);  // C++ sort using quick sort TODO??: prove it.
    elapsed = t.elapsed();
    cout<<"std::sort"<<endl;
    std::cout << "std::sort() time = " << elapsed << " seconds\n";
}
