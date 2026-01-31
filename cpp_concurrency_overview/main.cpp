#include <algorithm>
#include <numeric>
#include <thread>
#include <iostream>
#include <future>
#include <vector>
using namespace std;

// NO async a package_task
// future has a promise within



double accum( vector<double>::const_iterator const beg, vector<double>::const_iterator const end, double init) {
//double accum( vector<double>::const_iterator const & beg, vector<double>::const_iterator const & end, double init) {
    //return std::accumulate(beg, end, init); //return std::accumulate(&*beg, &*end, init);
    return std::reduce(beg, end, init); //return std::accumulate(&*beg, &*end, init);
}

double comp_2(vector<double> const & v) {
    packaged_task packaged_task1 {accum};
    packaged_task packaged_task2 {accum};
    future<double> fut1 {packaged_task1.get_future()};
    future<double> fut2 {packaged_task2.get_future()};
    auto first{v.cbegin()};                                 //double * first{&v[0]};
    //jthread thread1 {std::move(packaged_task1), first,              first + v.size()/2, 0};
    //jthread thread2 {std::move(packaged_task2), first + v.size()/2, first + v.size(),   0};
    thread thread1 {std::move(packaged_task1), first,              first + v.size()/2, 0.};
    thread thread2 {std::move(packaged_task2), first + v.size()/2, first + v.size(),   0.};
    double r1=fut1.get();
    double r2=fut2.get();
    thread1.join();
    thread2.detach();
    return r1 + r2;
    //return fut1.get() + fut2.get();
}

double comp_4(vector<double> const & v) {
    auto first{v.cbegin()};
    auto future1{ async( accum, first,                first + v.size()/4,   0 ) };
    auto future2{ async( accum, first + v.size()/4,   first + v.size()/2,   0 ) };
    auto future3{ async( accum, first + v.size()/2,   first + v.size()*3/4, 0 ) };
    auto future4{ async( accum, first + v.size()*3/4, first + v.size(),     0 ) };
    double r1{future1.get()};
    double r2{future2.get()};
    double r3{future3.get()};
    double r4{future4.get()};
    return r1+r2+r3+r4;
};

int main() {
    double retd_val1{comp_2( vector{1.5,2.,3.,4.,5.,6.} )};
    double retd_val2{comp_4( vector{1.0,2.,3.,4.,5.,6.} )};
    cout << retd_val1 << endl;
    cout << retd_val2 << endl;
    cout << "###" << endl;
    return 0;
}
