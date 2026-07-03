#include <barrier>
#include <functional>
#include <iostream>
#include <latch>
#include <string>
#include <thread>
using std::cout, std::endl, std::cin;
int f(){return 42;};
struct Job {
    const std::string name{};
    std::string product{"not worked"};
    std::thread action{};
};
int main() {
    Job jobs[]{{"Annika"}, {"Buru"}, {"Chuck"}};
    std::latch work_done_not_cleaned_yet_wait_latch_multiple{std::size(jobs)};
    std::latch start_clean_up_post_work_wait_latch_single{1};

    auto work_and_clean_eventually = [&](Job& my_job) {
        my_job.product = my_job.name + " worked";
        work_done_not_cleaned_yet_wait_latch_multiple.count_down();
        start_clean_up_post_work_wait_latch_single.wait();
        my_job.product = my_job.name + " cleaned";
    };

    std::cout << "Work is starting... ";
    for (auto& job : jobs)
        job.action = std::thread{work_and_clean_eventually, std::ref(job)};
        // job.action = std::thread{work, job};  // TODO??: invocable?

    work_done_not_cleaned_yet_wait_latch_multiple.wait(); std::cout << "done:\n";
    for (auto const& job : jobs)
        std::cout << job.product << '\n';

    std::cout << "Workers are cleaning up... ";
    start_clean_up_post_work_wait_latch_single.count_down();
    for (auto& job : jobs)
        job.action.join();

    std::cout << "done:\n";
    for (auto const& job : jobs)
        std::cout << job.product << '\n';

    cout << "###" << endl;
    return 0;
}
