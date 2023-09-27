#include <iostream>
#include <array>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cassert>

using namespace std;

//int total_remainders(int num, int * arr, int candidate) {
//    int sum {};
//    for (int i = 0; i < num; ++i) {
//        int remainder = arr[i] % candidate;
//        sum += remainder;
//    }
//    return sum;
//}

int recursive_gcd() {
    return int {};
};

/* AKA
 * greatest common divisor: GCD,
 * highest  common divisor: HCD,
 * greatest common factor:  GCF,
 * highest  common factor:  HCF,
 * greatest common measure: GCM,
 * or {greatest|highest} common {divisor|factor|measure}
 */

int greatest_common_divisor_of_list(int num, int arr[])
{
    if (num < 1) return 0;  // todo or should this be 1?;

//    int num_max {0};
//    for (int i = 0; i < num; ++i) {
//        if (arr[i] > num_max) num_max = arr[i];
//    }
//    for (int gcd_test = 1; gcd_test < num_max+1; ++gcd_test) {
//        int want_zero_val =  accumulate(arr, arr+num /* one beyond the end!*/, 0, [&gcd_test](int a, int b){ return ((b % gcd_test)+a);} );
//        int want_zero_val2 =  total_remainders(num, arr, gcd_test);
//        assert (want_zero_val == want_zero_val2);
//        if (want_zero_val) {
//            return highest_gcd;
//        }
//        if (gcd_test > highest_gcd) {
//            highest_gcd = gcd_test;
//        }
//    }
//    return highest_gcd;

    int greater {};
    greater = arr[0];
    for (int i = 1; i < num; ++i) {
        greater = gcd( arr[i], greater );
    }

    vector<int> v( static_cast<size_t>(num),0)  ;
    //greater = recursive_gcd(arr[0])

    return greater;
}

int main()
{
    // is a number odd or even?
    cout << (5)%2 << "\n"; // works
    cout << (6)%2 << "\n"; // works
    cout << (5+1)%2 << "\n"; // bad idea
    cout << (6+1)%2 << "\n"; // bad idea

    int status[5] {2,3,4,5,6};  // todo: convert these to enum values
    int result_1 = greatest_common_divisor_of_list( 5, status );
    // return: 1

    int status2[5] {2,4,6,8,10};  // todo: convert these to enum values
    int result_2 = greatest_common_divisor_of_list( 5, status2 );
    // return: 2

    int status3[5] {2,4,6,8,32007};  // todo: convert these to enum values
    int result_3 = greatest_common_divisor_of_list( 5, status3 );
    // return: 1

    int status4[1] {32007};  // todo: convert these to enum values
    int result_4 = greatest_common_divisor_of_list( 1, status4 );
    // return: 1

    int status5[3] {8, 40, 100};  // todo: convert these to enum values
    int result_5 = greatest_common_divisor_of_list( 3, status5 );
    // return: 1

    cout << "###" << endl;
    return 0;
}
