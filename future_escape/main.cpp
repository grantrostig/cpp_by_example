//
//  main.cpp
//  asyncInput
//
//  Created by Alan Uthoff on 8/12/20.
//  Copyright is open to CPPMSG users
//	Edited by Grant Rostig
//

#include <cstdlib>
#include <future>
// #include <future_escape>
#include <iostream>
#include <chrono>
// #include <thread>
// #include <experimental/
#include <future>
// todo: what is this? #include <future_escape>
using namespace std::chrono_literals;

int main() {
    auto get_line = [] () {
        std::cerr << "\nWaiting for input.\n"<<std::endl;
        std::string line;
        std::cin >> line;
        return line;
    };
    auto worker = [] () {
        static int invocation = 1; // todo: this value does not accumulate.
        int work = 0;  // to block compilter optimization/ellision.
        for( unsigned int index = 0; index < 10; ++index) {
            std::this_thread::sleep_for(1.5s);
            ++work;
            std::cerr << " Work at: "<<work<<", ";
        }
        std::cerr << "\nWorker:"<<invocation<<" completed.\n";
        return work;
    };
    std::future<std::string> line_Future = std::async( std::launch::async, get_line);
    std::future<int> 		 work_Future = std::async( std::launch::async, worker) ;
    // todo: work_Future.THEN()???
    // while(std::cin.peek() != 'q') // todo: There is a race condition here?
    // while(std::cin.peek() != 'q')//There is a race condition here
    int i = {0};
    while( ++i < 1'000'000 ) {
        // if (line_Future.valid()) // std::cerr << "\n***** the line future valid.\n"; // else std::cerr << "\n***** the line future is NOTvalid.\n";
        if (line_Future.wait_for( 0s ) ==  std::future_status::ready) {
            //if (std::cin.peek() == 'q')
             //   break;
            auto stuff = line_Future.get();
            if ( stuff == "q") {
                // std::cerr << "\nBreaking main loop.\n"; break; // while
                std::cerr << "\nExit on final iteration:"<<i<<"\n###\n"; exit(0); std::exit(0); // while
            }
            else
                line_Future = std::async(std::launch::async,get_line);
        }

        // if (work_Future.valid()) // std::cerr << "\n***** work future is valid.\n"; // else std::cerr << "\n***** work future is NOTvalid.\n";
        if( work_Future.wait_for( 0s ) ==  std::future_status::ready) {
            std::cerr << "Work_future is done: "<< work_Future.get()<<".\n";
            work_Future = std::async( std::launch::async, worker);
        }
        // std::this_thread::sleep_for( 66ms );
        if ( i % 10'000 == 0 ) std::cerr << "\nLooping in main on iteration: "<<i<<".";
    }
    work_Future.~future(); // todo: waits for future work to finish, what about killing it right away?
    std::cerr << "\nFinal Iteration:"<< i <<"\n";
    std::cerr << "###\n";
}
