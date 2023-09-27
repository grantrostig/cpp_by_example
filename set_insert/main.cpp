#include <iostream>
#include <chrono>
#include <set>

using namespace std;

int main()
{
    chrono::system_clock::time_point    time_start1 {};
    chrono::system_clock::time_point    time_start2 {};
    chrono::system_clock::time_point    time_end1 {};
    chrono::system_clock::time_point    time_end2 {};
    chrono::system_clock::duration      time_elapsed1 {};
    chrono::system_clock::duration      time_elapsed2 {};

    std::set<int> my_set {};

    for (int i=0; i<1000; ++i) {
        my_set.insert(my_set.end(),i);
    }
    my_set.clear();
    for (int i=0; i<1000; ++i) {
        my_set.insert(my_set.end(),i);
    }
    my_set.clear();
    for (int i=0; i<1000; ++i) {
        my_set.insert(my_set.end(),i);
    }

    // OK above was to warm up the system.

    my_set.clear();
    time_start1 = chrono::system_clock::now();
    for (int i=0; i<1000; ++i) {
        my_set.insert(my_set.end(),i);  // Winner is!!
    }
    time_end1 = chrono::system_clock::now();

    my_set.clear();
    time_start2 = chrono::system_clock::now();
    for (int i=0; i<1000; ++i) {
        my_set.insert(i);
    }
    time_end2 = chrono::system_clock::now();

    time_elapsed1 = time_end1  - time_start1;
    time_elapsed2 = time_end2 - time_start2;
    cout << " Duration ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed1).count() << endl;
    cout << " Duration us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed1).count() << endl;
    cout << " Duration ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed1).count() << endl;
    cout << " Duration ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed2).count() << endl;
    cout << " Duration us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed2).count() << endl;
    cout << " Duration ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed2).count() << endl;

    cout << "Hello World!" << endl;
    return 0;
}
