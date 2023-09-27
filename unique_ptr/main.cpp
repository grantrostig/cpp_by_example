#include <memory>

#include <iostream>
#include <array>
#include <experimental/array>
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <system_error>
#include <ios>
#include <filesystem>
#include <type_traits>
#include <cassert>
#include <thread>
using std::cout, std::endl;

using namespace std;

static int instance {0};
struct my_class {
    std::array<int,10>  my_array {42,43,44};

    explicit my_class(){
        ++instance;
        my_array[0]=instance;
        cout << "constructor: "<<my_array[0]<<endl;
    }
    // explicit my_class(my_class& x) {
        // my_array = x.my_array;
        // cout << "constructor: "<<my_array[0]<<endl;
    // }

    my_class& operator=(const my_class& x) {
        my_array = x.my_array;
        cout << "copy: "<<my_array[0]<<endl;
        return *this;
    }

    ~my_class(){
        cout << "destructor: "<<my_array[0]<<endl;
    }
};

int main()
{
    std::vector<std::unique_ptr<my_class>> vec_classes;
    std::vector<std::unique_ptr<my_class>> vec_classes2;
    {
        std::unique_ptr<my_class> up1 {std::unique_ptr<my_class>( new my_class )};
        auto up2 {std::make_unique<my_class>()};
        static_assert( std::is_same<decltype(up1), decltype(up2)>::value, "Not the same type." );
        vec_classes.push_back(std::move(up1));
        vec_classes.push_back(std::move(up2));
        vec_classes2.emplace_back(std::make_unique<my_class>());
        vec_classes2.emplace_back(std::make_unique<my_class>());
    }
    my_class val1 = *vec_classes.back();  vec_classes.pop_back();
    my_class val2 = *vec_classes.back();  vec_classes.pop_back();
    my_class val3 = *vec_classes2.at(0);
    my_class val4 = *vec_classes2[1];
    std::this_thread::sleep_for(1s);
    cout<< "my vals: "<<val1.my_array[0]<<", "<<val2.my_array[0]<< ", "<<val3.my_array[0]<< ", "<<val4.my_array[0]<<endl;

    // std::unique_ptr<my_class> upmc1 = std::move(vec_classes.back());
    // std::unique_ptr<my_class> upmc2 = std::move(vec_classes.back());
    std::unique_ptr<my_class> upmc3 = std::move(vec_classes2.at(0));
    std::unique_ptr<my_class> upmc4 = std::move(vec_classes2[1]);

    cout<< "my upmc val: "<<(*upmc3).my_array[0]<<", "<<
          // upmc2.get().my_array[0]<< ", "<<(upmc3.get()).my_array[0]<< ", "<<(upmc4.get()).my_array[0]<<
           endl;
    cout << "###" << endl;
    return 0;
}
