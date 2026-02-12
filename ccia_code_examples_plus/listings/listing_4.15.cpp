#include <string>
struct Card_inserted { std::string account;  };
class Atm {
    Messaging::receiver incoming;
    Messaging::sender   bank;
    Messaging::sender   interface_hardware;
    std::string account{};
    std::string pin{};
    void (Atm::*state)();  // TODO??: what is this?
    void waiting_for_card() {
        interface_hardware.send(display_enter_card());
        incoming.wait()
            .handle<Card_inserted>(
                [&](Card_inserted const& msg)
                {
                    account=msg.account;
                    pin="";
                    interface_hardware.send(display_enter_pin());
                    state=&Atm::getting_pin;
                }
                );
    }
    void getting_pin();
public:
    void run() {
        state=&Atm::waiting_for_card;
        try { for(;;) { (this->*state)(); } }
        catch(Messaging::close_queue const&) { }
    }
};
