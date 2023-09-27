#include <iostream>
#include <array>
#include <experimental/array>
#include <vector>
#include <algorithm>
using std::cout, std::endl;

// ===== declaration ===== - says what it _is_ only, ie. _type_ of variable OR _signature_ of function.

extern int external_compilation_unit_variable;  // no initialization, todo: generally in a *.cpp file?
// extern int external_cu_stack_variable; // if extern, link fails, but with this _cheating_ definition, link works.
extern const int x1;

extern const std::vector<int> const_vector;  // todo:  it is default initialized here, probably not?

int my_function(int argument_variable);			// no initialization, generally in a *.h file

// ===== definition ===== - declaration & _allocating_memory_ for variables and their initialization OR saying what the function _does_.

int	data_variable {0};
const int x2 {0};  // below is more modern.  todo: what exactly would be the difference? both RValues? is either moveable?
constexpr int x3 {0};

const std::vector<int> const_vector;
// const std::vector<int> const_value_initialized_vector2(vector_reserve_capacity) {1,2,3,4,5};  // illegal

int my_function(int argument_variable) {
    int return_val = argument_variable * 2;
    return return_val;
};

// extern int my_VLA_function(size_t size, int my_VLA_array[*]);
int my_VLA_function(size_t array_size, int my_VLA_c_array[]) {
    auto temp = sizeof my_VLA_c_array;
}

int main()
{
    int stack_variable {5};
    cout << my_function(stack_variable) << endl;

    cout << my_function(data_variable) << endl;

//  cout << my_function(external_compilation_unit_variable) << endl;  // compiles but doesn't link because no object supplies memory for external variable.

    extern int external_cu_stack_variable;
//  cout << my_function(external_cu_stack_variable) << endl;  // compiles but doesn't link because no object supplies memory for external variable.

    size_t 	size 			 {100};
    int 	initialized_value {42};
    const std::vector<int> const_reserved_vector(size);  // filled with 0.
    const std::vector<int> const_reserved_vector2(size, initialized_value); // filled with value.
    const std::vector<int> const_value_initialized_vector {1,2,3,4,5};  // filled with list of values.


    const std::array<int,10> const_reserved_array {0};  // filled with 0.
          std::array<int,10>       reserved_array {0,1,2};  // filled with 0,1,2,0,0....

    auto init_sized_array1 = std::experimental::make_array(1,2,3,4);
    decltype(auto) init_sized_array4 = std::experimental::make_array<double>(1,2,3,4);
    decltype(auto) init_sized_array5 = std::experimental::make_array(100,4.0);
    decltype(auto) init_sized_array6 = std::experimental::make_array(100);
    // decltype(auto) variable_array2 = std::experimental::make_array {1,2,3,4};
    // auto variable_array3 = std::experimental::make_array = {1,2,3,4};

    // Variable-length arrays (VLA)
    int my_VLA_c_array[ size ];  // size is a variable!
    std::fill( my_VLA_c_array, my_VLA_c_array+size, 42 );  // initialize c_array

    int return_value = my_VLA_function( size, my_VLA_c_array );

    cout << "###" << endl;
    return 0;
}
