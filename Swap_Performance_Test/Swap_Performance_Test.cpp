/* Copyright (c) 2016 Grant Rostig  */

#include <cassert>
#include <utility>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

namespace grostig {

enum class Operation_Type {
    swap_temp, swap_temp_move, swap_xor, swap_swap
};

template<typename Ta, typename Tb, typename Ti>
void time_operation(Operation_Type const operation_type, Ta & a, Tb & b, Ti const iterations) {
    // requires Swappable<Ta, Tb>()
    assert (iterations > 0);

    Ta temp = {};
    chrono::system_clock::time_point    start_time {};
    chrono::system_clock::time_point    end_time {};
    chrono::system_clock::duration      elapsed_time {};
    chrono::system_clock::duration      loop_time {};

    constexpr chrono::system_clock::duration    zero_time = {};
    // todo: how do these work?
    // loop_time = chrono::duration::zero();?
    // loop_time = chrono::duration_values<rep>::zero();?

    cout << "Staring values of a,b,t: " << a << ", " << b << ", " << temp << "." << endl;
    loop_time = zero_time;
    for (Ti var = 0; var < iterations; ++var) {
        // todo: better to eliminate this switch statement via more template magic.
        switch (operation_type) {
        case Operation_Type::swap_swap:
            start_time = chrono::system_clock::now();
            std::swap(a,b);
            end_time = chrono::system_clock::now();
        break;
        case Operation_Type::swap_xor:  // probably would not work for different integral type combinations
            start_time = chrono::system_clock::now();
            b ^= a; a ^= b; b ^= a;
            end_time = chrono::system_clock::now();
        break;
        case Operation_Type::swap_temp:
            start_time = chrono::system_clock::now();
            temp = a; a = b; b = temp;
            end_time = chrono::system_clock::now();
        break;
        case Operation_Type::swap_temp_move:  // makes no sense, or speed difference for built in types since they have no move operators. TCPLv2 P516
            start_time = chrono::system_clock::now();
            temp = std::move(a); a = std::move(b); b = std::move(temp);
            end_time = chrono::system_clock::now();
        break;
        }
        elapsed_time = end_time - start_time;
        loop_time += elapsed_time;
    }
    cout << " Duration: " << chrono::duration_cast<chrono::nanoseconds>(loop_time).count()/static_cast<double>(iterations)
         << ". Ending values of a,b,t: " << a << ", " << b << ", " << temp << "." << std::endl;
}

/* NOT USED: template<typename Ta, typename Tb, typename Ti> // requires Swappable<Ta, Tb>()
void time_operation2(Operation_Type operation_type, Ta a, Tb b, Ti iterations) {
    assert (iterations > 0);
    // assert (!(a==nullptr));

    Ti temp = {};  // default initializer assumed to set to 0
    chrono::system_clock::time_point    start_time = {}, end_time = {}; // Do any classes need to be initialized, or are they guaranteed to be 0 by the compiler??
    chrono::system_clock::duration      elapsed_time = {}, loop_time = {};

    // I don't know how to set a duration to zero??, so I'm using a default initialized object and copy (or move??) assignment
    constexpr chrono::system_clock::duration    zero_time = {};

    cout << "Staring values of a,b,t: " << a << ", " << b << ", " << temp << "." << std::endl;
    //loop_time = chrono::duration::zero();
    //loop_time = chrono::duration_values<rep>::zero();
    loop_time = zero_time;
    for (long var = 0; var < iterations; ++var) {
        switch (operation_type) {
        case Operation_Type::swap_swap:
            start_time = chrono::system_clock::now();
            std::swap(a,b);
            end_time = chrono::system_clock::now();
        break;
        case Operation_Type::swap_xor:
            start_time = chrono::system_clock::now();
            b ^= a; a ^= b; b ^= a;
            end_time = chrono::system_clock::now();
        break;
        case Operation_Type::swap_temp:
            start_time = chrono::system_clock::now();
            temp = a; a = b; b = temp;
            end_time = chrono::system_clock::now();
        break;
        }
        elapsed_time = end_time - start_time;
        loop_time += elapsed_time;
    }
    cout << " Duration: " << chrono::duration_cast<chrono::nanoseconds>(loop_time).count()/iterations
         << ". Ending values of a,b,t: " << a << ", " << b << ", " << temp << "." << std::endl;
}
*/

} // end namespace

int main(int argc, char *argv[])
{
    {
        short int   a {10};
        short int   b {20};
        long int    iterations (1.0e+8);
        grostig::time_operation( grostig::Operation_Type::swap_swap,      a, b, iterations);
        grostig::time_operation( grostig::Operation_Type::swap_temp_move, a, b, iterations);
        grostig::time_operation( grostig::Operation_Type::swap_xor,       a, b, iterations);
        grostig::time_operation( grostig::Operation_Type::swap_temp,      a, b, iterations);

        // Note:  Using gcc (unoptimized), the speed of the above, vary depending on variable type and the processor, ie. AMD vs Intel.
        //        On AMD FX8350 the operations as coded above, are ordered from slowest to fastest.
    }

    {
        long long int a {10};
        long long int b {20};
        long int      iterations (1.0e+8);
        grostig::time_operation( grostig::Operation_Type::swap_swap,      a, b, iterations);
        grostig::time_operation( grostig::Operation_Type::swap_temp_move, a, b, iterations);
        grostig::time_operation( grostig::Operation_Type::swap_xor,       a, b, iterations);
        grostig::time_operation( grostig::Operation_Type::swap_temp,      a, b, iterations);

        // Note:  Using gcc (unoptimized), the speed of the above, vary depending on variable type and the processor, ie. AMD vs Intel.
        //        On AMD FX8350 the operations as coded above, are ordered from slowest to fastest.
    }

    return 0; // Success
}
