/* file used in development of lib_tty using references with POSIX C language calls - retain for history
 * Generated as part of the password manager effort.
 * Used to test lib_tty.
 *
 * Copyright 2021 Grant Rostig all rights reserved,
 * no rights granted to anyone at this time,
 * no license granted to anyone at this time,
 * except to use during CppMSG meetings during 2021-2021.
 *
 */
#include <string>
#include <iostream>
#include <termios.h>
#include <cassert>
#include <cstring>
// #include <unistd.h>
// #include <signal.h>
using namespace std;
constexpr ssize_t POSIX_ERROR  	= -1;
constexpr ssize_t CTL_D 		= 4;			// EOF
using 	  Termios 			    = termios; 		// Terminal & IO & Speed structure, used for getting/setting them. // C++ class name capitalization convention of the POSIX C type;

bool check_equality(const Termios &terminal_status, const Termios &terminal_status2){
    /* https://embeddedgurus.com/stack-overflow/2009/12/effective-c-tip-8-structure-comparison/
     * https://isocpp.org/blog/2016/02/a-bit-of-background-for-the-default-comparison-proposal-bjarne-stroustrup
     * https://stackoverflow.com/questions/141720/how-do-you-compare-structs-for-equality-in-c
     * https://stackoverflow.com/questions/46995631/why-are-structs-not-allowed-in-equality-expressions-in-c
     * https://stackoverflow.com/questions/7179174/why-doesnt-c-provide-struct-comparison/47056810#47056810
     * if ( terminal_status.c_iflag != terminal_status2.c_iflag
        && terminal_status.c_oflag  != terminal_status2.c_oflag
        && terminal_status.c_cflag  != terminal_status2.c_cflag
        && terminal_status.c_lflag  != terminal_status2.c_lflag
        && terminal_status.c_line   != terminal_status2.c_line
        && terminal_status.c_ispeed != terminal_status2.c_ispeed
        && terminal_status.c_ospeed != terminal_status2.c_ospeed ) return false;
    for (int i=0; i< NCCS; ++i)
        if (terminal_status.c_cc[i] != terminal_status2.c_cc[i]) return false; */
    if ( std::memcmp( &terminal_status, &terminal_status2, sizeof terminal_status) != 0) return false;  // todo:?? Are Termios structures initialized, including the possible padding when defined as below?  How does c++ know the padding that the Linux kernel expects in a system call?
    return true;
}

Termios & termio_get() { // todo:?? what is difference if I don't have &, return by reference or return by pointer becomes a copy, or does copy elision work magic?
    static Termios terminal_status {};
    if (auto result = tcgetattr( fileno(stdin), /*OUT*/ &terminal_status); result == POSIX_ERROR) { // todo: TODO throw() in signature?
        perror("termio_get()");
        exit(1); }
    return terminal_status;
}

/* alternative suggestions by Alan U
 */
#include <memory>
using namespace std;
weak_ptr<Termios> termio_get_ptr() { // todo:?? what is difference if I don't have &, return by reference or return by pointer becomes a copy, or does copy elision work magic?
   // static shared_ptr<Termios> terminal_status = make_shared<Termios>();
    static shared_ptr<Termios> terminal_status = shared_ptr<Termios>(new Termios{});
    //static weak_ptr<Termios> t = terminal_status;
    if (auto result = tcgetattr( fileno(stdin),  terminal_status.get()); result == POSIX_ERROR) { // todo: TODO throw() in signature?
        perror("termio_get()"); exit(1); }
    return terminal_status;
}

shared_ptr<Termios> termio_get_sptr() { // todo:?? what is difference if I don't have &, return by reference or return by pointer becomes a copy, or does copy elision work magic?
    static shared_ptr<Termios> terminal_status = make_shared<Termios>();
    if (auto result = tcgetattr( fileno(stdin), terminal_status.get()); result == POSIX_ERROR) { // todo: TODO throw() in signature?
        perror("termio_get()"); exit(1); }
    return terminal_status;
}
// */

Termios & termio_set_raw() {
    static Termios terminal_status_orig { termio_get() };
    Termios 	   terminal_status_new 	{ terminal_status_orig };
    terminal_status_new.c_lflag 		&= static_cast<tcflag_t>(~ICANON);  // turn off "canonical" or "cooked" mode and go to "non-canonical" or "raw" mode, ie. don't wait for <Enter>. // want this bit OFF for cbreak mode.
    terminal_status_new.c_lflag 		&= static_cast<tcflag_t>(~ECHO);    // turn off "echo" mode, ie. don't automatically show the characters being typed. // want this bit OFF for cbreak mode.
    terminal_status_new.c_lflag 		&= static_cast<tcflag_t>(~IEXTEN);  // turn off ???
    terminal_status_new.c_lflag 		&= static_cast<tcflag_t>(~ISIG);    // turn off ???  // want this bit ON for cbreak mode.
    terminal_status_new.c_iflag 		&= static_cast<tcflag_t>(~BRKINT);  // turn off ???
    terminal_status_new.c_iflag 		&= static_cast<tcflag_t>(~ICRNL);   // turn off ???  // want this bit OFF for cbreak mode.
    terminal_status_new.c_iflag 		&= static_cast<tcflag_t>(~IGNBRK);  // turn off ???
    terminal_status_new.c_iflag 		&= static_cast<tcflag_t>(~IGNCR);   // turn off ???
    terminal_status_new.c_iflag 		&= static_cast<tcflag_t>(~INLCR);   // turn off ???
    terminal_status_new.c_iflag 		&= static_cast<tcflag_t>(~INPCK);   // turn off ???
    terminal_status_new.c_iflag 		&= static_cast<tcflag_t>(~ISTRIP);  // turn off ???
    terminal_status_new.c_iflag 		&= static_cast<tcflag_t>(~IXON);    // turn off ???
    terminal_status_new.c_iflag 		&= static_cast<tcflag_t>(~PARMRK);  // turn off ???
    terminal_status_new.c_oflag 		&= static_cast<tcflag_t>(~OPOST);   // turn off all output processing.
    terminal_status_new.c_cc[VTIME]		= 0; 				// wait forever to get that char // http://www.unixwiz.net/techtips/termios-vmin-vtime.html
    terminal_status_new.c_cc[VMIN] 		= 1;  				// get minimun one char
    if (auto result = tcsetattr( fileno(stdin), TCSADRAIN, &terminal_status_new); result == POSIX_ERROR) { // https://pubs.opengroup.org/onlinepubs/9699919799/ // todo: Applications that need all of the requested changes made to work properly should follow tcsetattr() with a call to tcgetattr() and compare the appropriate field values.
        perror("termio_set_raw()");
        exit(1); }
    Termios terminal_status_actual { termio_get() };
    if ( !check_equality( terminal_status_actual, terminal_status_new )) {
        cerr << "lib_tty: termio_restore() termio not fully raw." << endl;
        assert( false ); }
    return terminal_status_orig;
}

void termio_restore(Termios const &terminal_status_orig) { 			// uses POSIX  // todo: TODO do you like my const 2x, what is effect calling POSIX?
    if (auto result = tcsetattr( fileno(stdin), TCSADRAIN, /*IN*/ &terminal_status_orig); result == POSIX_ERROR ) { 	// restore prior status
        perror("termio_restore()");
        exit(1);  }
    Termios	terminal_status_actual { termio_get() };
    if ( !check_equality( terminal_status_actual, terminal_status_orig )) {
        cerr << "lib_tty: termio_restore() termio not restored." << endl;
        assert( false ); }
    return;
}

int main() {
    cout << "Enter a series of key presses (including function keys) one by one at this prompt $, \nnote that an <ENTER> required for the value to be read.\nControl-D to end this loop.\n$";
    Termios	terminal_status_save { termio_set_raw() };
    char ch {};
    while (ch != CTL_D) { 		//for (int i=24; i-->0 && ch != CTL_D;) {
        cin.get( ch );
        cout << "\n" << "Got>" << (int)(unsigned char)ch <<"<>";
        if (ch == 27) cout << "ESC";
        else 		  cout << ch;
        cout << "< $" ;
    }
    cout << endl;
    termio_restore( terminal_status_save );
    std::string value {};
    cout << "Now, once enter a series of characters and end it by <ENTER> $";
    cin >> value;
    cout <<"Got value:>"<< value << "<\n";
    cout << "###" << endl;
}
