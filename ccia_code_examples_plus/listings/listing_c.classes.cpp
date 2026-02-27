#include <condition_variable>
#include <iostream>
#include <queue>
#include <memory>
#include <mutex>
namespace CCIA_Messaging {
struct Message_base {
    virtual ~Message_base() {}  // This is boring "must have" boilerplate.
};

template <typename Msg>
struct Wrapped_message : Message_base {  // TODO??: define in detail "wrapped" in this context and in general? Is it just to use runtime dispatch?
    Msg contents{};
    explicit Wrapped_message(Msg const &contents_) : contents(contents_) {}
};
class Queue {
    std::mutex                                mtx_to_protect_queue_sptr{};
    std::queue<std::shared_ptr<Message_base>> queue_sptr_to_wrapped_msg{};
    std::condition_variable                   cond_var{};
public:
    template <typename T>
    void push(T const &msg) { {
            std::lock_guard<std::mutex> lk{mtx_to_protect_queue_sptr};
            queue_sptr_to_wrapped_msg.push(std::make_shared<Wrapped_message<T>>(msg));
        }
        cond_var.notify_all();
    }
    std::shared_ptr<Message_base> wait_and_pop() {
        std::unique_lock<std::mutex> lk{mtx_to_protect_queue_sptr};
        cond_var.wait(lk, [&] { return not queue_sptr_to_wrapped_msg.empty(); });
        auto result {queue_sptr_to_wrapped_msg.front()};
        queue_sptr_to_wrapped_msg.pop();
        return result;
    }
};

template <typename PreviousDispatcher, typename Msg, typename Func>
class TemplateDispatcher {
    Queue              *ptr_queue{};
    PreviousDispatcher *ptr_prev_dispatcher{};
    Func                f{};
    bool                is_chained{ false };

    TemplateDispatcher(TemplateDispatcher const &)            = delete;
    TemplateDispatcher &operator=(TemplateDispatcher const &) = delete;

    template <typename Dispatcher, typename OtherMsg, typename OtherFunc> friend class TemplateDispatcher;
    void wait_and_dispatch() {
        for(;;) {
            auto msg = ptr_queue->wait_and_pop();
            if( dispatch(msg)) break;
        }
    }
    bool dispatch( std::shared_ptr<Message_base> const &sptr_msg ) {
        if( Wrapped_message<Msg> *wrapper { dynamic_cast< Wrapped_message<Msg> *>( sptr_msg.get() ) }
            ) {
             f(wrapper->contents);
             return true;
        } else {
            return ptr_prev_dispatcher->dispatch(sptr_msg);
        }
    }
public:
    TemplateDispatcher(TemplateDispatcher &&other_)
        : ptr_queue(other_.ptr_queue), ptr_prev_dispatcher(other_.ptr_prev_dispatcher), f(std::move(other_.f)), is_chained(other_.is_chained) {
        other_.is_chained = true;
    }
    TemplateDispatcher(Queue *q_, PreviousDispatcher *prev_, Func &&f_)
        : ptr_queue(q_), ptr_prev_dispatcher(prev_), f(std::forward<Func>(f_)), is_chained(false) {
        prev_->is_chained = true;
    }

    template <typename OtherMsg, typename OtherFunc>
    TemplateDispatcher<TemplateDispatcher, OtherMsg, OtherFunc> handle(OtherFunc &&of) {
        return TemplateDispatcher<TemplateDispatcher, OtherMsg, OtherFunc>(ptr_queue, this, std::forward<OtherFunc>(of));
    }
    ~TemplateDispatcher() noexcept(false) {
        if(!is_chained) { wait_and_dispatch(); }
    }
};

class Close_queue_actor_frmwrk_msg {};
class Dispatcher {
    Queue *q;
    bool   is_chained{ false }; // grostig added false
    Dispatcher(Dispatcher const &)            = delete;
    Dispatcher &operator=(Dispatcher const &) = delete;

    template <typename Dispatcher, typename Msg, typename Func>

    friend class TemplateDispatcher;

    void
    wait_and_dispatch() {
        for(;;) {
            auto msg = q->wait_and_pop();
            dispatch(msg);
        }
    }
    bool
    dispatch(std::shared_ptr<Message_base> const &msg) {
        if(dynamic_cast<Wrapped_message<Close_queue_actor_frmwrk_msg> *>(msg.get())) { throw Close_queue_actor_frmwrk_msg(); }
        return false;
    }
public:
    Dispatcher(Dispatcher &&other) : q(other.q), is_chained(other.is_chained) { other.is_chained = true; }
    explicit Dispatcher(Queue *q_) : q(q_), is_chained(false) {}

    template <typename Message, typename Func>
    TemplateDispatcher<Dispatcher, Message, Func>
    handle(Func &&f) {
        return TemplateDispatcher<Dispatcher, Message, Func>{ q, this, std::forward<Func>(f) };
    }
    ~Dispatcher() noexcept(false) {
        if(!is_chained) { wait_and_dispatch(); }
    }
};

class Sender_actor {
    Queue *q;
public:
    Sender_actor() : q(nullptr) {}
    explicit Sender_actor(Queue *q_) : q(q_) {}

    template <typename Message>
    void send(Message const &msg) {
        if(q) { q->push(msg); }
    }
};
class Receiver_actor {
    Queue q;
public:
    operator Sender_actor() { return Sender_actor(&q); }
    Dispatcher wait() {
        return Dispatcher(&q);
    }
};
} // END namespace Messaging NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

namespace Atm_system_msg {
struct Withdraw {
    std::string account;
    unsigned amount;
    mutable CCIA_Messaging::Sender_actor atm_queue;
    Withdraw(std::string const& account_, unsigned amount_, CCIA_Messaging::Sender_actor atm_queue_)
        : account(account_),amount(amount_), atm_queue(atm_queue_) {}
};
struct Withdraw_ok {};
struct Withdraw_denied {};
struct Cancel_withdrawal {
    std::string account;
    unsigned amount;
    Cancel_withdrawal(std::string const& account_, unsigned amount_)
        : account(account_),amount(amount_) {}
};
struct Withdrawal_processed {
    std::string account;
    unsigned amount;
    Withdrawal_processed(std::string const& account_, unsigned amount_): account(account_),amount(amount_) {}
};
struct Card_inserted {
    std::string account;
    explicit Card_inserted(std::string const& account_): account(account_) {}
};
struct Digit_pressed {
    char digit;
    explicit Digit_pressed(char digit_): digit(digit_) {}
};
struct Clear_last_pressed {};
struct Eject_card {};
struct Withdraw_pressed {
    unsigned amount;
    explicit Withdraw_pressed(unsigned amount_): amount(amount_) {}
};
struct Cancel_pressed {};
struct Issue_money {
    unsigned amount;
    Issue_money(unsigned amount_): amount(amount_) {}
};
struct Verify_pin {
    std::string account;
    std::string pin;
    mutable CCIA_Messaging::Sender_actor atm_queue;
    Verify_pin(std::string const& account_,std::string const& pin_, CCIA_Messaging::Sender_actor atm_queue_)
        : account(account_),pin(pin_),atm_queue(atm_queue_) {}
};
struct Pin_verified {};
struct Pin_incorrect {};
struct Display_enter_pin {};
struct Display_enter_card {};
struct Display_insufficient_funds {};
struct Display_withdrawal_cancelled {};
struct Display_pin_incorrect_message {};
struct Display_withdrawal_options {};
struct Get_balance {
    std::string account{};
    mutable CCIA_Messaging::Sender_actor atm_queue{};
    Get_balance(std::string const& account_,CCIA_Messaging::Sender_actor atm_queue_)
        : account(account_),atm_queue(atm_queue_) {}
};
struct Balance {
    unsigned amount;
    explicit Balance(unsigned amount_): amount(amount_) {}
};
struct Display_balance {
    unsigned amount;
    explicit Display_balance(unsigned amount_): amount(amount_) {}
};
struct Balance_pressed {};
} // END namespace Msg NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

class Atm_s_machine {  // s_machine = state machine, which in this case runs in its own thread started in main?
    CCIA_Messaging::Receiver_actor incoming{};
    CCIA_Messaging::Sender_actor   bank{};
    CCIA_Messaging::Sender_actor   interface_hardware{};
    std::string         account{};
    std::string         pin{};
    unsigned            withdrawal_amount{};

    void (Atm_s_machine::*state)();  // pointer to member function? TODO??: what is this?
    void process_withdrawal_s() {  // a state in which this statemachine can be.
        incoming.wait()
            .handle<Atm_system_msg::Withdraw_ok>(
                [&](Atm_system_msg::Withdraw_ok const& msg) {
                    interface_hardware.send(
                        Atm_system_msg::Issue_money(withdrawal_amount));
                    bank.send(
                        Atm_system_msg::Withdrawal_processed(account,withdrawal_amount));
                    state=&Atm_s_machine::done_processing_s;
                } )
            .handle<Atm_system_msg::Withdraw_denied>(
                [&](Atm_system_msg::Withdraw_denied const& msg) {
                    interface_hardware.send(Atm_system_msg::Display_insufficient_funds());
                    state=&Atm_s_machine::done_processing_s;
                } )
            .handle<Atm_system_msg::Cancel_pressed>(
                [&](Atm_system_msg::Cancel_pressed const& msg) {
                    bank.send(
                        Atm_system_msg::Cancel_withdrawal(account,withdrawal_amount));
                    interface_hardware.send(
                        Atm_system_msg::Display_withdrawal_cancelled());
                    state=&Atm_s_machine::done_processing_s;
                } );
    }
    void process_balance_s() {
        incoming.wait()
            .handle<Atm_system_msg::Balance>(
                [&](Atm_system_msg::Balance const& msg) {
                    interface_hardware.send(Atm_system_msg::Display_balance(msg.amount));
                    state=&Atm_s_machine::wait_for_action_s;
                } )
            .handle<Atm_system_msg::Cancel_pressed>(
                [&](Atm_system_msg::Cancel_pressed const& msg) {
                    state=&Atm_s_machine::done_processing_s;
                } );
    }
    void wait_for_action_s() {
        interface_hardware.send(Atm_system_msg::Display_withdrawal_options());
        incoming.wait() .handle<Atm_system_msg::Withdraw_pressed>(
                [&](Atm_system_msg::Withdraw_pressed const& msg) {
                    withdrawal_amount=msg.amount;
                    bank.send( Atm_system_msg::Withdraw( account, msg.amount, incoming) );
                    state=&Atm_s_machine::process_withdrawal_s;
                } )
            .handle<Atm_system_msg::Balance_pressed>(
                [&](Atm_system_msg::Balance_pressed const& msg) {
                    bank.send(Atm_system_msg::Get_balance(account,incoming));
                    state=&Atm_s_machine::process_balance_s;
                } )
            .handle<Atm_system_msg::Cancel_pressed>(
                [&](Atm_system_msg::Cancel_pressed const& msg) {
                    state=&Atm_s_machine::done_processing_s;
                } );
    }
    void verifying_pin_s() {
        incoming.wait()
            .handle<Atm_system_msg::Pin_verified>(
                [&](Atm_system_msg::Pin_verified const& msg) {
                    state=&Atm_s_machine::wait_for_action_s;
                } )
            .handle<Atm_system_msg::Pin_incorrect>(
                [&](Atm_system_msg::Pin_incorrect const& msg)
                {   interface_hardware.send( Atm_system_msg::Display_pin_incorrect_message());
                    state=&Atm_s_machine::done_processing_s;
                } )
            .handle<Atm_system_msg::Cancel_pressed>(
                [&](Atm_system_msg::Cancel_pressed const& msg) {
                    state=&Atm_s_machine::done_processing_s;
                } );
    }
    void getting_pin_s() {
        incoming.wait()
            .handle<Atm_system_msg::Digit_pressed>(
                [&](Atm_system_msg::Digit_pressed const& msg) {
                    unsigned const pin_length=4;
                    pin+=msg.digit;
                    if(pin.length()==pin_length) {
                        bank.send(Atm_system_msg::Verify_pin(account,pin,incoming));
                        state=&Atm_s_machine::verifying_pin_s;
                    }
                } )
            .handle<Atm_system_msg::Clear_last_pressed>(
                [&](Atm_system_msg::Clear_last_pressed const& msg) {
                    if(!pin.empty()) { pin.pop_back(); }
                } )
            .handle<Atm_system_msg::Cancel_pressed>(
                [&](Atm_system_msg::Cancel_pressed const& msg) {
                    state=&Atm_s_machine::done_processing_s;
                } );
    }
    void waiting_for_card_s() {
        interface_hardware.send(Atm_system_msg::Display_enter_card());
        incoming.wait() .handle<Atm_system_msg::Card_inserted>(
                [&](Atm_system_msg::Card_inserted const& msg) {
                    account=msg.account;
                    pin="";
                    interface_hardware.send(Atm_system_msg::Display_enter_pin());
                    state=&Atm_s_machine::getting_pin_s;
                } );
    }
    void done_processing_s() {
        interface_hardware.send(Atm_system_msg::Eject_card());
        state=&Atm_s_machine::waiting_for_card_s;
    }
    Atm_s_machine(Atm_s_machine const&)=delete;
    Atm_s_machine& operator=(Atm_s_machine const&)=delete;
public:
    Atm_s_machine(CCIA_Messaging::Sender_actor bank_, CCIA_Messaging::Sender_actor interface_hardware_) : bank(bank_),interface_hardware(interface_hardware_) {}
    void done() { get_sender().send(CCIA_Messaging::Close_queue_actor_frmwrk_msg()); }
    void run() {
        state=&Atm_s_machine::waiting_for_card_s;  // Initial state of this s_machine
        try {
            for(;;)
            {
                (this->*state)();
            }
        }
        catch(CCIA_Messaging::Close_queue_actor_frmwrk_msg const&) { }
    }
    CCIA_Messaging::Sender_actor get_sender() {
        return incoming;
    }
};

class Bank_cloud_s_machine {
    unsigned balance{};
    CCIA_Messaging::Receiver_actor incoming{};
public:
    Bank_cloud_s_machine(): balance{199} {}
    void done() { get_sender().send(CCIA_Messaging::Close_queue_actor_frmwrk_msg()); }
    void run() { try { for(;;) {
                incoming.wait()
                    .handle<Atm_system_msg::Verify_pin>(
                        [&](Atm_system_msg::Verify_pin const& msg) {
                            if(msg.pin=="mypin") { msg.atm_queue.send(Atm_system_msg::Pin_verified()); }
                            else { msg.atm_queue.send(Atm_system_msg::Pin_incorrect()); }
                        } )
                    .handle<Atm_system_msg::Withdraw>(
                        [&](Atm_system_msg::Withdraw const& msg) {
                            if(balance>=msg.amount) {
                                msg.atm_queue.send(Atm_system_msg::Withdraw_ok());
                                balance-=msg.amount;
                            }
                            else { msg.atm_queue.send(Atm_system_msg::Withdraw_denied()); }
                        } )
                    .handle<Atm_system_msg::Get_balance>(
                        [&](Atm_system_msg::Get_balance const& msg) {
                            msg.atm_queue.send(Atm_system_msg::Balance(balance));
                        } )
                    .handle<Atm_system_msg::Withdrawal_processed>(
                        [&](Atm_system_msg::Withdrawal_processed const& msg) {
                        } )
                    .handle<Atm_system_msg::Cancel_withdrawal>(
                        [&](Atm_system_msg::Cancel_withdrawal const& msg) {
                        } );
            } } catch(CCIA_Messaging::Close_queue_actor_frmwrk_msg const&) {}
    }
    CCIA_Messaging::Sender_actor get_sender() { return incoming; }
};

class Interface_s_machine {
    std::mutex          iom;
    CCIA_Messaging::Receiver_actor incoming;
public:
    void done() { get_sender().send(CCIA_Messaging::Close_queue_actor_frmwrk_msg()); }
    void run() { try { for(;;) {
                incoming.wait()
                    .handle<Atm_system_msg::Issue_money>(
                        [&](Atm_system_msg::Issue_money const& msg) { {
                                std::lock_guard<std::mutex> lk{iom};
                                std::cout<<"Issuing "<<msg.amount<<std::endl;
                            }
                        } )
                    .handle<Atm_system_msg::Display_insufficient_funds>(
                        [&](Atm_system_msg::Display_insufficient_funds const& msg) { {
                                std::lock_guard<std::mutex> lk{iom};
                                std::cout<<"Insufficient funds"<<std::endl;
                            }
                        } )
                    .handle<Atm_system_msg::Display_enter_pin>(
                        [&](Atm_system_msg::Display_enter_pin const& msg) { {
                                std::lock_guard<std::mutex> lk{iom};
                                std::cout <<"Please enter your PIN (0-9 hint: mypin)" <<std::endl;
                            }
                        } )
                    .handle<Atm_system_msg::Display_enter_card>(
                        [&](Atm_system_msg::Display_enter_card const& msg) { {
                                std::lock_guard<std::mutex> lk{iom};
                                std::cout<<"Please enter your card (I)" <<std::endl;
                            }
                        } )
                    .handle<Atm_system_msg::Display_balance>(
                        [&](Atm_system_msg::Display_balance const& msg) { {
                                std::lock_guard<std::mutex> lk{iom};
                                std::cout <<"The balance of your account is " <<msg.amount<<std::endl;
                            }
                        } )
                    .handle<Atm_system_msg::Display_withdrawal_options>(
                        [&](Atm_system_msg::Display_withdrawal_options const& msg) { {
                                std::lock_guard<std::mutex> lk{iom};
                                std::cout<<"Withdraw 50? (w)"<<std::endl;
                                std::cout<<"Display Balance? (b)" <<std::endl;
                                std::cout<<"Cancel? (c)"<<std::endl;
                            }
                        }
                        )
                    .handle<Atm_system_msg::Display_withdrawal_cancelled>(
                        [&](Atm_system_msg::Display_withdrawal_cancelled const& msg) { {
                                std::lock_guard<std::mutex> lk{iom};
                                std::cout<<"Withdrawal cancelled" <<std::endl;
                            }
                        } )
                    .handle<Atm_system_msg::Display_pin_incorrect_message>(
                        [&](Atm_system_msg::Display_pin_incorrect_message const& msg) { {
                                std::lock_guard<std::mutex> lk{iom};
                                std::cout<<"PIN incorrect"<<std::endl;
                            }
                        } )
                    .handle<Atm_system_msg::Eject_card>(
                        [&](Atm_system_msg::Eject_card const& msg) { {
                                std::lock_guard<std::mutex> lk{iom};
                                std::cout<<"Ejecting card"<<std::endl;
                            }
                        } );
            }
        }
        catch(CCIA_Messaging::Close_queue_actor_frmwrk_msg&) {};
    }
    CCIA_Messaging::Sender_actor get_sender() { return incoming; }
};
