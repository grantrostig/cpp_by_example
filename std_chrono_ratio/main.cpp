/* std_chrono_ratio
 * different approaches to clocks and intervals
 * Grant Rostig
 */
#include <iostream>
#include <thread>
#include <ratio>
#include <chrono>
#include <limits>

using namespace std;

int main() {
    for (short i = 0; i< std::numeric_limits<short>::max(); ++i ) {
        std::chrono::time_point< std::chrono::high_resolution_clock,
                                 std::chrono::duration< long ,
                                                        //std::ratio< 1, 1000'000'000 >>
                                                        std::nano > > const
                    start 	{ std::chrono::high_resolution_clock::now() };
        cout << " ," << i << flush;
        auto const 	end   	{ std::chrono::high_resolution_clock::now() };

        std::chrono::duration<double, std::nano> const elapsed_time {end - start};
        cout << elapsed_time.count()<< flush;
        cout << elapsed_time.duration()<< flush;
        elapsed_time.()
        std::this_thread::sleep_for( std::chrono::seconds(1) );
        using namespace std::chrono_literals;
        std::this_thread::sleep_for( 1ms );
    }
    cout << "###" << endl;
    return 0;
}
