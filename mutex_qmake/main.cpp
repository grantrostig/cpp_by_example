// mutex.cpp :
#include <iostream>
#include <mutex>
#include <vector>
#include <string>
#include <optional>
#include <thread>

std::mutex  my_mutex;
int         sequence_id    { 1 };

struct My_job {
    std::string         name{};
    std::vector<int>    my_sequence_ids{};
    std::optional<int> get_id() {
        std::lock_guard<std::mutex> my_lock {my_mutex};
        my_sequence_ids.push_back(sequence_id++);
        return sequence_id;
    };
};


int main() {
    // std::vector<My_job> jobs {};
    std::thread 				job1 { My_job::get_id() };
    // std::vector<std::thread> 	jobs 	{ std::move( new(std::thread(My_job))) };





    std::cout << "###";
}
