#include <array>
#include <barrier>
#include <functional>
#include <iostream>
#include <latch>
#include <string>
#include <thread>
using std::cout, std::endl, std::cin;
int f(){return 42;};
struct Job {
    const std::string   name{};
    std::string         product{"not worked"};
    std::thread         action{};
};
int main() {
    std::array<Job, 3>  jobs{{{"Annika"}, {"Buru"}, {"Chuck"}}};
    std::latch          multLatch_wait_for_work_done_prior_to_clean{std::ssize(jobs)};
    // std::latch          w2rk_done_not_cleaned_yet_wait_latch_multiple{std::size(jobs)};
	// std::latch          w3rk_done_not_cleaned_yet_wait_latch_multiple{ jobs.ssize() }; // TODO??: ssize() is C++20, not C++17
    std::latch          uniLatch_wait_for_worked_to_start_clean_up{true};

    auto work_and_clean_eventually = [&multLatch_wait_for_work_done_prior_to_clean, &uniLatch_wait_for_worked_to_start_clean_up](Job& my_job) {
        my_job.product=my_job.name + " worked";
        multLatch_wait_for_work_done_prior_to_clean.count_down();
        uniLatch_wait_for_worked_to_start_clean_up.wait();
        my_job.product=my_job.product + " and cleaned.";
    };

    std::cout << "Work is starting... ";
    for (auto& job : jobs)
        job.action = std::thread{work_and_clean_eventually, std::ref(job)};
        // job.action = std::thread{work, job};  // TODO??: invocable?

    multLatch_wait_for_work_done_prior_to_clean.wait(); std::cout << "done:\n";
    for (auto const& job : jobs)
        std::cout << job.product << '\n';

    std::cout << "Workers are cleaning up... ";
    uniLatch_wait_for_worked_to_start_clean_up.count_down();
    for (auto& job : jobs)
        job.action.join();

    std::cout << "done:\n";
    for (auto const& job : jobs)
        std::cout << job.product << '\n';

    cout << "###" << endl;
    return 0;
}
