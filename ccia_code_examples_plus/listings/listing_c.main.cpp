#include <condition_variable>
#include <iostream>
#include <queue>
#include <memory>
#include <mutex>
#include "listing_c.classes.cpp"

int main() {
    bool                            quit_pressed     {false};
    Bank_cloud_smachine             bank_cloud_s_machine{};
    Interface_smachine              interface_hardware_s_machine{};
    Atm_s_machine                   atm_s_machine     {bank_cloud_s_machine.get_sender(), interface_hardware_s_machine.get_sender()};
    CCIA_Messaging::Sender_actor    atm_sender       {atm_s_machine.get_sender()};

    std::thread                     bank_thread      {&Bank_cloud_smachine::run, &bank_cloud_s_machine};
    std::thread                     interface_thread {&Interface_smachine::run, &interface_hardware_s_machine };
    std::thread                     atm_thread       {&Atm_s_machine::run,&atm_s_machine};

    while(!quit_pressed) {  // input loop for sending input to atm_s_machine
        char c=getchar();
        switch(c) {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            atm_sender.send(Atm_system_msg::Digit_pressed(c));
            break;
        case 'b':
            atm_sender.send(Atm_system_msg::Balance_pressed());
            break;
        case 'w':
            atm_sender.send(Atm_system_msg::Withdraw_pressed(50));
            break;
        case 'c':
            atm_sender.send(Atm_system_msg::Cancel_pressed());
            break;
        case 'q':
            quit_pressed=true;
            break;
        case 'i':
            atm_sender.send(Atm_system_msg::Card_inserted("acc1234"));
            break;
        }
    }
    bank_cloud_s_machine.done(); atm_s_machine.done(); interface_hardware_s_machine.done();
    atm_thread.join(); bank_thread.join(); interface_thread.join();
    std::cout << "###" << std::endl;
}
