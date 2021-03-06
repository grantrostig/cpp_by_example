#include "tty_keystroke_observer.hpp"
#include <cassert>
#include <iostream>
#include <thread>

Tty_keystroke_subject::~Tty_keystroke_subject() {
    _is_stop_request_atomic = true;  // TODO??: why bother at this point?  read_thread is already down, correct?
    restore_tty();
}

void Tty_keystroke_subject::stop() { _is_stop_request_atomic = true; }  // TODO: why not clear out _in_char and reset is_char_ready?

tcflag_t Tty_keystroke_subject::config_tty_to_raw() {
  tcflag_t          initial_lflag;
  struct termios    t;
  tcgetattr( 0, &t);          // TODO: need to check errors.
  initial_lflag =   t.c_lflag;
  t.c_lflag &=      static_cast<unsigned int>(~(ICANON | ECHO));
  tcsetattr( 0, TCSANOW, &t);
  return initial_lflag;
}

void Tty_keystroke_subject::restore_tty() {
  struct termios    t;
  tcgetattr(0, &t);          // TODO: need to check errors.
  t.c_lflag =       _orig_tty_cflags;
  tcsetattr(0, TCSANOW, &t);
}

void Tty_keystroke_subject::tty_read_thread() {    // ThreadTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
  // Grab chars until EOT or stop_request.
  assert( _in_char == 0                && "Precondition: we are just starting to read, so should be empty.");
  assert( not _is_char_ready_atomic    && "Precondition: we are just starting to read, so should not be ready.");
  assert( not _is_stop_request_atomic  && "Precondition: we are just starting to read, so should not be stopping.");
  while (_in_char != ascii_eot) {
      while (_is_char_ready_atomic.load()) { std::this_thread::sleep_for(_threads_sleep_interval); }  // If we have a char we sleep until it gets grabbed by other thread.
      if (   _is_stop_request_atomic.load())  {      // TODO: Who sets this?  Other thread?
          return;   // ReturnRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
      }
      _in_char = std::cin.get();        // TODO??: Should this be inside lock_guard scope?  Why not?  Would it hang main thread? No since it is not reading cin?  What if it were reading cin?
      {                               // lock scope
          std::lock_guard           {_read_char_mutex};
          // _in_char =                _in_char < 0 ? ascii_eot : _in_char;  // TODO??: below is better!??
          _in_char =                _in_char == EOF ? ascii_eot : _in_char;
          _is_char_ready_atomic =   true;           // TODO??: can this be outside the lock_guard?
      }
  }
  return;   // ReturnRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
}

void Tty_keystroke_subject::read_keystrokes_from_keyboard() {
  using std::chrono::time_point, std::chrono::microseconds, std::chrono::steady_clock, std::chrono::duration_cast;
  //using namespace std::chrono;  // TODO??: what is advantage of using above specifically for this class? or is it a namespace, or something else?
  assert( _in_char == 0                && "Precondition: we are just starting to read, so should be empty.");
  assert( not _is_char_ready_atomic    && "Precondition: we are just starting to read, so should not be ready.");
  assert( not _is_stop_request_atomic  && "Precondition: we are just starting to read, so should not be stopping.");
  time_point<steady_clock>  esc_t0;
  microseconds              esc_elapsed;
  bool                      escaped         {false};
  uint64_t                  sequence        {0};

  _orig_tty_cflags = config_tty_to_raw();
  std::thread               child_read_thread{ [&] () { tty_read_thread(); }};     // CHILD ThreadTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
  //  ******* Main thread continues below.
  while ( not _is_stop_request_atomic.load()) {
    while ( not _is_char_ready_atomic.load()) {  // Check for ALL ready chars read on child_read_thread, .  Give up when more than allowed time has expired for characters arriving.
      if ( escaped ) {                           // TODO??: What is this, considering we might have simple single regular tk_char below?
          esc_elapsed = duration_cast<microseconds>( steady_clock::now() - esc_t0 );
          if ( esc_elapsed > _single_char_esc_timeout) {    // Not a MULTI-BYTE sequence  OR we are the END of a multi-byte sequence.
              escaped = false;
              if (sequence == 0) {
                  notify_fn_args( &Keystroke_events_I::tk_escape                                             );
              } else if ( sequence < 0xFF &&               isprint( static_cast<int>( sequence ))) {
                  notify_fn_args( &Keystroke_events_I::tk_char,           static_cast<char>( _in_char ), true);
              } else {
                  notify_fn_args( &Keystroke_events_I::tk_unhandled, std::forward<uint64_t>( sequence )      );
              }
          }
      }
      std::this_thread::sleep_for(_threads_sleep_interval);
    }
    // ****** START lock_guard scope
    {
      std::lock_guard   {_read_char_mutex};
      if (        _in_char == ascii_eot) {
          _is_char_ready_atomic = false;    // TODO??: redunant would get set a bottom anyway.
          // TODO??: should we set _is_stop_request?  or was it set in read_thread?
          // TODO??: why don't we broadcast this one too?
          break;                            // TODO??: we could end the while loop naturally!
      } else if ( _in_char == ascii_esc) {
          escaped = true;
          sequence = 0;
          esc_t0 = steady_clock::now();
      } else if ( escaped ) {
          escaped = false;
          sequence <<= 8;
          sequence |= static_cast<uint8_t>(_in_char);

          switch ( sequence ) {
          case ascii_lf:
              notify_fn_args(&Keystroke_events_I::tk_enter, {false, true, false});
              break;
          case ascii_bs:
              notify_fn_args(&Keystroke_events_I::tk_backspace, {false, true, false});
              break;
          case bs_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_backspace, {true, true, false});
              break;
          case key_seq_f1:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 1, {false, false, false});
              break;
          case key_seq_f1_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 1, {true, false, false});
              break;
          case key_seq_f1_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 1, {false, true, false});
              break;
          case key_seq_f1_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 1, {false, false, true});
              break;
          case key_seq_f1_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 1, {true, false, true});
              break;
          case key_seq_f1_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 1, {false, true, true});
              break;
          case key_seq_f1_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 1, {true, true, true});
              break;
          case key_seq_f2:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 2, {false, false, false});
              break;
          case key_seq_f2_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 2, {true, false, false});
              break;
          case key_seq_f2_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 2, {false, true, false});
              break;
          case key_seq_f2_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 2, {false, false, true});
              break;
          case key_seq_f2_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 2, {true, false, true});
              break;
          case key_seq_f2_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 2, {false, true, true});
              break;
          case key_seq_f2_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 2, {true, true, true});
              break;
          case key_seq_f3:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 3, {false, false, false});
              break;
          case key_seq_f3_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 3, {true, false, false});
              break;
          case key_seq_f3_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 3, {false, true, false});
              break;
          case key_seq_f3_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 3, {false, false, true});
              break;
          case key_seq_f3_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 3, {true, false, true});
              break;
          case key_seq_f3_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 3, {false, true, true});
              break;
          case key_seq_f3_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 3, {true, true, true});
              break;
          case key_seq_f4:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 4, {false, false, false});
              break;
          case key_seq_f4_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 4, {true, false, false});
              break;
          case key_seq_f4_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 4, {false, true, false});
              break;
          case key_seq_f4_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 4, {false, false, true});
              break;
          case key_seq_f4_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 4, {true, false, true});
              break;
          case key_seq_f4_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 4, {false, true, true});
              break;
          case key_seq_f4_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 4, {true, true, true});
              break;
          case key_seq_f5:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 5, {false, false, false});
              break;
          case key_seq_f5_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 5, {true, false, false});
              break;
          case key_seq_f5_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 5, {false, true, false});
              break;
          case key_seq_f5_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 5, {false, false, true});
              break;
          case key_seq_f5_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 5, {true, false, true});
              break;
          case key_seq_f5_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 5, {false, true, true});
              break;
          case key_seq_f5_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 5, {true, true, true});
              break;
          case key_seq_f6:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 6, {false, false, false});
              break;
          case key_seq_f6_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 6, {true, false, false});
              break;
          case key_seq_f6_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 6, {false, true, false});
              break;
          case key_seq_f6_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 6, {false, false, true});
              break;
          case key_seq_f6_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 6, {true, false, true});
              break;
          case key_seq_f6_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 6, {false, true, true});
              break;
          case key_seq_f6_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 6, {true, true, true});
              break;
          case key_seq_f7:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 7, {false, false, false});
              break;
          case key_seq_f7_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 7, {true, false, false});
              break;
          case key_seq_f7_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 7, {false, true, false});
              break;
          case key_seq_f7_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 7, {false, false, true});
              break;
          case key_seq_f7_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 7, {true, false, true});
              break;
          case key_seq_f7_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 7, {false, true, true});
              break;
          case key_seq_f7_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 7, {true, true, true});
              break;
          case key_seq_f8:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 8, {false, false, false});
              break;
          case key_seq_f8_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 8, {true, false, false});
              break;
          case key_seq_f8_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 8, {false, true, false});
              break;
          case key_seq_f8_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 8, {false, false, true});
              break;
          case key_seq_f8_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 8, {true, false, true});
              break;
          case key_seq_f8_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 8, {false, true, true});
              break;
          case key_seq_f8_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 8, {true, true, true});
              break;
          case key_seq_f9:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 9, {false, false, false});
              break;
          case key_seq_f9_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 9, {true, false, false});
              break;
          case key_seq_f9_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 9, {false, true, false});
              break;
          case key_seq_f9_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 9, {false, false, true});
              break;
          case key_seq_f9_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 9, {true, false, true});
              break;
          case key_seq_f9_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 9, {false, true, true});
              break;
          case key_seq_f9_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 9, {true, true, true});
              break;
          case key_seq_f10:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 10, {false, false, false});
              break;
          case key_seq_f10_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 10, {true, false, false});
              break;
          case key_seq_f10_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 10, {false, true, false});
              break;
          case key_seq_f10_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 10, {false, false, true});
              break;
          case key_seq_f10_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 10, {true, false, true});
              break;
          case key_seq_f10_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 10, {false, true, true});
              break;
          case key_seq_f10_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 10, {true, true, true});
              break;
          case key_seq_f11:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 11, {false, false, false});
              break;
          case key_seq_f11_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 11, {true, false, false});
              break;
          case key_seq_f11_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 11, {false, true, false});
              break;
          case key_seq_f11_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 11, {false, false, true});
              break;
          case key_seq_f11_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 11, {true, false, true});
              break;
          case key_seq_f11_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 11, {false, true, true});
              break;
          case key_seq_f11_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 11, {true, true, true});
              break;
          case key_seq_f12:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 12, {false, false, false});
              break;
          case key_seq_f12_ctrl:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 12, {true, false, false});
              break;
          case key_seq_f12_alt:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 12, {false, true, false});
              break;
          case key_seq_f12_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 12, {false, false, true});
              break;
          case key_seq_f12_ctrl_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 12, {true, false, true});
              break;
          case key_seq_f12_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 12, {false, true, true});
              break;
          case key_seq_f12_ctrl_alt_shift:
              notify_fn_args<int8_t>(&Keystroke_events_I::tk_function, 12, {true, true, true});
              break;
          case key_seq_arrow_u:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::u, {false, false, false});
              break;
          case key_seq_arrow_u_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::u, {true, false, false});
              break;
          case key_seq_arrow_u_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::u, {false, false, true});
              break;
          case key_seq_arrow_u_alt:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::u, {false, true, false});
              break;
          case key_seq_arrow_u_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::u, {false, true, true});
              break;
          case key_seq_arrow_u_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::u, {true, true, false});
              break;
          case key_seq_arrow_d:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::d, {false, false, false});
              break;
          case key_seq_arrow_d_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::d, {true, false, false});
              break;
          case key_seq_arrow_d_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::d, {false, false, true});
              break;
          case key_seq_arrow_d_alt:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::d, {false, true, false});
              break;
          case key_seq_arrow_d_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::d, {false, true, true});
              break;
          case key_seq_arrow_d_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::d, {true, true, false});
              break;
          case key_seq_arrow_r:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::r, {false, false, false});
              break;
          case key_seq_arrow_r_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::r, {true, false, false});
              break;
          case key_seq_arrow_r_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::r, {false, false, true});
              break;
          case key_seq_arrow_r_alt:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::r, {false, true, false});
              break;
          case key_seq_arrow_r_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::r, {false, true, true});
              break;
          case key_seq_arrow_r_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::r, {true, true, false});
              break;
          case key_seq_arrow_r_ctrl_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::r, {true, false, true});
              break;
          case key_seq_arrow_r_ctrl_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::r, {true, true, true});
              break;
          case key_seq_arrow_l:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::l, {false, false, false});
              break;
          case key_seq_arrow_l_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::l, {true, false, false});
              break;
          case key_seq_arrow_l_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::l, {false, false, true});
              break;
          case key_seq_arrow_l_alt:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::l, {false, true, false});
              break;
          case key_seq_arrow_l_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::l, {false, true, true});
              break;
          case key_seq_arrow_l_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::l, {true, true, false});
              break;
          case key_seq_arrow_l_ctrl_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::l, {true, false, true});
              break;
          case key_seq_arrow_l_ctrl_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_arrow, Direction::l, {true, true, true});
              break;
          case key_seq_center:
              notify_fn_args(&Keystroke_events_I::tk_center, {false, false, false});
              break;
          case key_seq_center_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_center, {true, false, false});
              break;
          case key_seq_center_shift:
              notify_fn_args(&Keystroke_events_I::tk_center, {false, false, true});
              break;
          case key_seq_center_alt:
              notify_fn_args(&Keystroke_events_I::tk_center, {false, true, false});
              break;
          case key_seq_center_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_center, {false, true, true});
              break;
          case key_seq_center_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_center, {true, true, false});
              break;
          case key_seq_center_ctrl_shift:
              notify_fn_args(&Keystroke_events_I::tk_center, {true, false, true});
              break;
          case key_seq_center_ctrl_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_center, {true, true, true});
              break;
          case key_seq_end:
              notify_fn_args(&Keystroke_events_I::tk_end, {false, false, false});
              break;
          case key_seq_end_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_end, {true, false, false});
              break;
          case key_seq_end_alt:
              notify_fn_args(&Keystroke_events_I::tk_end, {false, true, false});
              break;
          case key_seq_end_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_end, {true, true, false});
              break;
          case key_seq_home:
              notify_fn_args(&Keystroke_events_I::tk_home, {false, false, false});
              break;
          case key_seq_home_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_home, {true, false, false});
              break;
          case key_seq_home_alt:
              notify_fn_args(&Keystroke_events_I::tk_home, {false, true, false});
              break;
          case key_seq_home_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_home, {true, true, false});
              break;
          case key_seq_ins:
              notify_fn_args(&Keystroke_events_I::tk_ins, {false, false, false});
              break;
          case key_seq_ins_alt:
              notify_fn_args(&Keystroke_events_I::tk_ins, {false, true, false});
              break;
          case key_seq_del:
              notify_fn_args(&Keystroke_events_I::tk_del, {false, false, false});
              break;
          case key_seq_del_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_del, {true, false, false});
              break;
          case key_seq_del_alt:
              notify_fn_args(&Keystroke_events_I::tk_del, {false, true, false});
              break;
          case key_seq_del_shift:
              notify_fn_args(&Keystroke_events_I::tk_del, {false, false, true});
              break;
          case key_seq_del_ctrl_shift:
              notify_fn_args(&Keystroke_events_I::tk_del, {true, false, true});
              break;
          case key_seq_del_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_del, {false, true, true});
              break;
          case key_seq_del_ctrl_alt_shift:
              notify_fn_args(&Keystroke_events_I::tk_del, {true, true, true});
              break;
          case key_seq_page_u:
              notify_fn_args(&Keystroke_events_I::tk_page, Direction::u, {false, false, false});
              break;
          case key_seq_page_u_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_page, Direction::u, {true, false, false});
              break;
          case key_seq_page_u_alt:
              notify_fn_args(&Keystroke_events_I::tk_page, Direction::u, {false, true, false});
              break;
          case key_seq_page_u_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_page, Direction::u, {true, true, false});
              break;
          case key_seq_page_d:
              notify_fn_args(&Keystroke_events_I::tk_page, Direction::d, {false, false, false});
              break;
          case key_seq_page_d_ctrl:
              notify_fn_args(&Keystroke_events_I::tk_page, Direction::d, {true, false, false});
              break;
          case key_seq_page_d_alt:
              notify_fn_args(&Keystroke_events_I::tk_page, Direction::d, {false, true, false});
              break;
          case key_seq_page_d_ctrl_alt:
              notify_fn_args(&Keystroke_events_I::tk_page, Direction::d, {true, true, false});
              break;
          case key_seq_tab_shift:
              notify_fn_args(&Keystroke_events_I::tk_tab, Direction::l);
              break;
          default:
              escaped = true;
          }
      } else if ( isprint(_in_char)) {
          notify_fn_args(&Keystroke_events_I::tk_char, static_cast<char>(_in_char), false);
      } else {
          switch ( _in_char) {
          case ascii_tab:
              notify_fn_args(&Keystroke_events_I::tk_tab, Direction::r);
              break;
          case ascii_lf:
              notify_fn_args(&Keystroke_events_I::tk_enter, {false, false, false});
              break;
          case ascii_bs:
              notify_fn_args(&Keystroke_events_I::tk_backspace, {false, false, false});
              break;
          }
      }
      _is_char_ready_atomic = false;  // TODO??: ERROR we never get here!??
    }
    // ****** END   lock scope
  }
  assert(     _in_char == 0            && "Postcondition: we are ending read, so should be empty.");
  assert( not _is_char_ready_atomic    && "Postcondition: we are ending read, so should not be ready.");
  assert(     _is_stop_request_atomic  && "Postcondition: we are ending read, so should not be stopping.");

  child_read_thread.join();

  assert(     _in_char == 0            && "Postcondition: we are ending read, so should be empty.");
  assert( not _is_char_ready_atomic    && "Postcondition: we are ending read, so should not be ready.");
  assert(     _is_stop_request_atomic  && "Postcondition: we are ending read, so should not be stopping.");
  return;
}
