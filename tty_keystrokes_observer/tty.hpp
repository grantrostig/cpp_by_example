#pragma once
#include "broadcaster.hpp"
#include <atomic>
#include <chrono>
#include <mutex>
#include <termios.h>
#include <unistd.h>

enum class Direction { u, d, l, r };

struct Modifiers {
    const bool ctrl  : 1; //todo??: what is : doing there?  bitfields, only in "structs"
    const bool alt   : 1;
    const bool shift : 1;
};

class Keystroke_events_I {
public:
    virtual ~Keystroke_events_I() = default;
    virtual void tk_escape()                          = 0;
    virtual void tk_char(         char,       bool) {}
    virtual void tk_enter(        const Modifiers &&) {}
    virtual void tk_backspace(    const Modifiers &&) {}
    virtual void tk_ins(          const Modifiers &&) {}
    virtual void tk_del(          const Modifiers &&) {}
    virtual void tk_home(         const Modifiers &&) {}
    virtual void tk_end(          const Modifiers &&) {}
    virtual void tk_center(       const Modifiers &&) {}
    virtual void tk_tab(          Direction) {}
    virtual void tk_arrow(        Direction, const Modifiers &&) {}
    virtual void tk_page(         Direction, const Modifiers &&) {}
    virtual void tk_function(     int8_t, const Modifiers &&) {}
    virtual void tk_unhandled(    uint64_t)             = 0;
};

class Tty : public Broadcaster< Keystroke_events_I > {
public:
  ~Tty();
  void read_keystrokes();
  void stop();
private:
  static constexpr auto     _threads_sleep_interval     {std::chrono::microseconds{1}};  // both threads sleep to TODO??: save CPU time?
  static constexpr auto     _single_char_esc_timeout    {std::chrono::microseconds{500}}; // time required to expire to be sure that ESC is not a CSI for a keyboard multibype sequence.
  std::mutex                _read_char_mutex            {};
  std::atomic_bool          _is_stop_request_atomic     {false};
  std::atomic_bool          _is_char_ready_atomic       {false};
  int                       _in_char                    {0};    // TODO??: is this really just an int?  what about return value from cin.get()?
  tcflag_t                  _tty_cflags                 {};     // TODO??: why not 0 zero? or is nothing zero?
  tcflag_t  config_tty();
  void      restore_tty();
  void      read_tty_thread();

  static constexpr uint8_t ascii_eot{0x04};
  static constexpr uint8_t ascii_tab{0x09};
  static constexpr uint8_t ascii_lf{0x0A};
  static constexpr uint8_t ascii_cr{0x0D};
  static constexpr uint8_t ascii_esc{0x1B};
  static constexpr uint8_t ascii_bs{0x7F};
  static constexpr uint8_t bs_ctrl_alt{0x08};

  static constexpr uint64_t key_seq_tab_shift{0x5B5A};  // TODO??: requires a 64 bit processor, or a library that supports this type.

  static constexpr uint64_t key_seq_f1{0x4F50};
  static constexpr uint64_t key_seq_f1_shift{0x5B313B3250};
  static constexpr uint64_t key_seq_f1_alt{0x5B313B3350};
  static constexpr uint64_t key_seq_f1_alt_shift{0x5B313B3450};
  static constexpr uint64_t key_seq_f1_ctrl{0x5B313B3550};
  static constexpr uint64_t key_seq_f1_ctrl_shift{0x5B313B3650};
  static constexpr uint64_t key_seq_f1_ctrl_alt_shift{0x5B313B3850};

  static constexpr uint64_t key_seq_f2{0x4F51};
  static constexpr uint64_t key_seq_f2_shift{0x5B313B3251};
  static constexpr uint64_t key_seq_f2_alt{0x5B313B3351};
  static constexpr uint64_t key_seq_f2_alt_shift{0x5B313B3451};
  static constexpr uint64_t key_seq_f2_ctrl{0x5B313B3551};
  static constexpr uint64_t key_seq_f2_ctrl_shift{0x5B313B3651};
  static constexpr uint64_t key_seq_f2_ctrl_alt_shift{0x5B313B3851};

  static constexpr uint64_t key_seq_f3{0x4F52};
  static constexpr uint64_t key_seq_f3_shift{0x5B313B3252};
  static constexpr uint64_t key_seq_f3_alt{0x5B313B3352};
  static constexpr uint64_t key_seq_f3_alt_shift{0x5B313B3452};
  static constexpr uint64_t key_seq_f3_ctrl{0x5B313B3552};
  static constexpr uint64_t key_seq_f3_ctrl_shift{0x5B313B3652};
  static constexpr uint64_t key_seq_f3_ctrl_alt_shift{0x5B313B3852};

  static constexpr uint64_t key_seq_f4{0x4F53};
  static constexpr uint64_t key_seq_f4_shift{0x5B313B3253};
  static constexpr uint64_t key_seq_f4_alt{0x5B313B3353};
  static constexpr uint64_t key_seq_f4_alt_shift{0x5B313B3453};
  static constexpr uint64_t key_seq_f4_ctrl{0x5B313B3553};
  static constexpr uint64_t key_seq_f4_ctrl_shift{0x5B313B3653};
  static constexpr uint64_t key_seq_f4_ctrl_alt_shift{0x5B313B3853};

  static constexpr uint64_t key_seq_f5{0x5B31357E};
  static constexpr uint64_t key_seq_f5_shift{0x5B31353B327E};
  static constexpr uint64_t key_seq_f5_alt{0x5B31353B337E};
  static constexpr uint64_t key_seq_f5_alt_shift{0x5B31353B347E};
  static constexpr uint64_t key_seq_f5_ctrl{0x5B31353B357E};
  static constexpr uint64_t key_seq_f5_ctrl_shift{0x5B31353B367E};
  static constexpr uint64_t key_seq_f5_ctrl_alt_shift{0x5B31353B387E};

  static constexpr uint64_t key_seq_f6{0x5B31377E};
  static constexpr uint64_t key_seq_f6_shift{0x5B31373B327E};
  static constexpr uint64_t key_seq_f6_alt{0x5B31373B337E};
  static constexpr uint64_t key_seq_f6_alt_shift{0x5B31373B347E};
  static constexpr uint64_t key_seq_f6_ctrl{0x5B31373B357E};
  static constexpr uint64_t key_seq_f6_ctrl_shift{0x5B31373B367E};
  static constexpr uint64_t key_seq_f6_ctrl_alt_shift{0x5B31373B387E};

  static constexpr uint64_t key_seq_f7{0x5B31387E};
  static constexpr uint64_t key_seq_f7_shift{0x5B31383B327E};
  static constexpr uint64_t key_seq_f7_alt{0x5B31383B337E};
  static constexpr uint64_t key_seq_f7_alt_shift{0x5B31383B347E};
  static constexpr uint64_t key_seq_f7_ctrl{0x5B31383B357E};
  static constexpr uint64_t key_seq_f7_ctrl_shift{0x5B31383B367E};
  static constexpr uint64_t key_seq_f7_ctrl_alt_shift{0x5B31383B387E};

  static constexpr uint64_t key_seq_f8{0x5B31397E};
  static constexpr uint64_t key_seq_f8_shift{0x5B31393B327E};
  static constexpr uint64_t key_seq_f8_alt{0x5B31393B337E};
  static constexpr uint64_t key_seq_f8_alt_shift{0x5B31393B347E};
  static constexpr uint64_t key_seq_f8_ctrl{0x5B31393B357E};
  static constexpr uint64_t key_seq_f8_ctrl_shift{0x5B31393B367E};
  static constexpr uint64_t key_seq_f8_ctrl_alt_shift{0x5B31393B387E};

  static constexpr uint64_t key_seq_f9{0x5B32307E};
  static constexpr uint64_t key_seq_f9_shift{0x5B32303B327E};
  static constexpr uint64_t key_seq_f9_alt{0x5B32303B337E};
  static constexpr uint64_t key_seq_f9_alt_shift{0x5B32303B347E};
  static constexpr uint64_t key_seq_f9_ctrl{0x5B32303B357E};
  static constexpr uint64_t key_seq_f9_ctrl_shift{0x5B32303B367E};
  static constexpr uint64_t key_seq_f9_ctrl_alt_shift{0x5B32303B387E};

  static constexpr uint64_t key_seq_f10{0x5B32317E};
  static constexpr uint64_t key_seq_f10_shift{0x5B32313B327E};
  static constexpr uint64_t key_seq_f10_alt{0x5B32313B337E};
  static constexpr uint64_t key_seq_f10_alt_shift{0x5B32313B347E};
  static constexpr uint64_t key_seq_f10_ctrl{0x5B32313B357E};
  static constexpr uint64_t key_seq_f10_ctrl_shift{0x5B32313B367E};
  static constexpr uint64_t key_seq_f10_ctrl_alt_shift{0x5B32313B387E};

  static constexpr uint64_t key_seq_f11{0x5B32337E};
  static constexpr uint64_t key_seq_f11_shift{0x5B32333B327E};
  static constexpr uint64_t key_seq_f11_alt{0x5B32333B337E};
  static constexpr uint64_t key_seq_f11_alt_shift{0x5B32333B347E};
  static constexpr uint64_t key_seq_f11_ctrl{0x5B32333B357E};
  static constexpr uint64_t key_seq_f11_ctrl_shift{0x5B32333B367E};
  static constexpr uint64_t key_seq_f11_ctrl_alt_shift{0x5B32333B387E};

  static constexpr uint64_t key_seq_f12{0x5B32347E};
  static constexpr uint64_t key_seq_f12_shift{0x5B32343B327E};
  static constexpr uint64_t key_seq_f12_alt{0x5B32343B337E};
  static constexpr uint64_t key_seq_f12_alt_shift{0x5B32343B347E};
  static constexpr uint64_t key_seq_f12_ctrl{0x5B32343B357E};
  static constexpr uint64_t key_seq_f12_ctrl_shift{0x5B32343B367E};
  static constexpr uint64_t key_seq_f12_ctrl_alt_shift{0x5B32343B387E};

  static constexpr uint64_t key_seq_arrow_u{0x5B41};
  static constexpr uint64_t key_seq_arrow_u_ctrl{0x5B313B3541};
  static constexpr uint64_t key_seq_arrow_u_shift{0x5B313B3241};
  static constexpr uint64_t key_seq_arrow_u_alt{0x5B313B3341};
  static constexpr uint64_t key_seq_arrow_u_alt_shift{0x5B313B3441};
  static constexpr uint64_t key_seq_arrow_u_ctrl_alt{0x5B313B3741};

  static constexpr uint64_t key_seq_arrow_d{0x5B42};
  static constexpr uint64_t key_seq_arrow_d_ctrl{0x5B313B3542};
  static constexpr uint64_t key_seq_arrow_d_shift{0x5B313B3242};
  static constexpr uint64_t key_seq_arrow_d_alt{0x5B313B3342};
  static constexpr uint64_t key_seq_arrow_d_alt_shift{0x5B313B3442};
  static constexpr uint64_t key_seq_arrow_d_ctrl_alt{0x5B313B3742};

  static constexpr uint64_t key_seq_arrow_r{0x5B43};
  static constexpr uint64_t key_seq_arrow_r_ctrl{0x5B313B3543};
  static constexpr uint64_t key_seq_arrow_r_shift{0x5B313B3243};
  static constexpr uint64_t key_seq_arrow_r_alt{0x5B313B3343};
  static constexpr uint64_t key_seq_arrow_r_alt_shift{0x5B313B3443};
  static constexpr uint64_t key_seq_arrow_r_ctrl_alt{0x5B313B3743};
  static constexpr uint64_t key_seq_arrow_r_ctrl_shift{0x5B313B3643};
  static constexpr uint64_t key_seq_arrow_r_ctrl_alt_shift{0x5B313B3843};

  static constexpr uint64_t key_seq_arrow_l{0x5B44};
  static constexpr uint64_t key_seq_arrow_l_ctrl{0x5B313B3544};
  static constexpr uint64_t key_seq_arrow_l_shift{0x5B313B3244};
  static constexpr uint64_t key_seq_arrow_l_alt{0x5B313B3344};
  static constexpr uint64_t key_seq_arrow_l_alt_shift{0x5B313B3444};
  static constexpr uint64_t key_seq_arrow_l_ctrl_alt{0x5B313B3744};
  static constexpr uint64_t key_seq_arrow_l_ctrl_shift{0x5B313B3644};
  static constexpr uint64_t key_seq_arrow_l_ctrl_alt_shift{0x5B313B3844};

  static constexpr uint64_t key_seq_center{0x5B45};
  static constexpr uint64_t key_seq_center_ctrl{0x5B313B3545};
  static constexpr uint64_t key_seq_center_shift{0x5B313B3245};
  static constexpr uint64_t key_seq_center_alt{0x5B313B3345};
  static constexpr uint64_t key_seq_center_alt_shift{0x5B313B3445};
  static constexpr uint64_t key_seq_center_ctrl_alt{0x5B313B3745};
  static constexpr uint64_t key_seq_center_ctrl_shift{0x5B313B3645};
  static constexpr uint64_t key_seq_center_ctrl_alt_shift{0x5B313B3845};

  static constexpr uint64_t key_seq_end{0x5B46};
  static constexpr uint64_t key_seq_end_ctrl{0x5B313B3546};
  static constexpr uint64_t key_seq_end_alt{0x5B313B3346};
  static constexpr uint64_t key_seq_end_ctrl_alt{0x5B313B3746};

  static constexpr uint64_t key_seq_home{0x5B48};
  static constexpr uint64_t key_seq_home_ctrl{0x5B313B3548};
  static constexpr uint64_t key_seq_home_alt{0x5B313B3348};
  static constexpr uint64_t key_seq_home_ctrl_alt{0x5B313B3748};

  static constexpr uint64_t key_seq_ins{0x5B327E};
  static constexpr uint64_t key_seq_ins_alt{0x5B323B337E};

  static constexpr uint64_t key_seq_del{0x5B337E};
  static constexpr uint64_t key_seq_del_ctrl{0x5B333B357E};
  static constexpr uint64_t key_seq_del_alt{0x5B333B337E};
  static constexpr uint64_t key_seq_del_shift{0x5B333B327E};
  static constexpr uint64_t key_seq_del_ctrl_shift{0x5B333B367E};
  static constexpr uint64_t key_seq_del_alt_shift{0x5B333B347E};
  static constexpr uint64_t key_seq_del_ctrl_alt_shift{0x5B333B387E};

  static constexpr uint64_t key_seq_page_u{0x5B357E};
  static constexpr uint64_t key_seq_page_u_ctrl{0x5B353B357E};
  static constexpr uint64_t key_seq_page_u_alt{0x5B353B337E};
  static constexpr uint64_t key_seq_page_u_ctrl_alt{0x5B353B377E};

  static constexpr uint64_t key_seq_page_d{0x5B367E};
  static constexpr uint64_t key_seq_page_d_ctrl{0x5B363B357E};
  static constexpr uint64_t key_seq_page_d_alt{0x5B363B337E};
  static constexpr uint64_t key_seq_page_d_ctrl_alt{0x5B363B377E};
};
