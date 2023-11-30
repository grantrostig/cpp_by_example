/* (c) Cppmsg.com License Boost 1.0
   Usage:
    - CTRL-C to exit, then at the shell prompt
        $stty sane
        # to fix the tty character handling back to "cooked mode".
    - run and enter just ESC.
    - run and enter just the F1 key.
    - above two give different results.
*/
//#include <bits/stdc++.h>
//#include <istream>
#include <array>
#include <cassert>
#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <sstream>
#include <termios.h>
using namespace std;

// Bad file global I know... just for fun and learning/renaming "static"
#define STATIC_GLOBAL_HIDER static     // similar to $ namespace {}
STATIC_GLOBAL_HIDER streamsize position {};  // here static just hides the obj from linker, same as unnamed namespace TODO:??
inline constexpr ssize_t POSIX_ERROR{-1};  /// yes, believe it or not, it is not zero, which we think is good. :)
/// C++ class name capitalization convention of the POSIX C type.
using Termios = termios;    // Tty terminal IO & speed structure, used for getting and setting them. // Enforcing the C++ struct type name capitalization convention for the POSIX C type.  I like it that way.

Termios & termio_get() { // uses POSIX
    static Termios termios;
    if (auto result = tcgetattr( fileno(stdin), &termios); result == POSIX_ERROR) { // TODO: throw() in signature?
        int errno_save = errno;
        errno = errno_save;
        cerr << "We will exit(1) for this error"<<endl;
        exit(1);
    }
    return termios;  // copy of POD?
}

/** We set POSIX terminal with Termios control attributes.
    Applications that need ALL of the requested changes to work properly should follow tcsetattr()
    with a call to tcgetattr() and compare then appropriate field values.
    We do the check after this call within the caller.  TODO consider doing it in here.
    TODO not called yet, refactor for 3 uses. */
void termio_set( Termios const & termios_new ) { // uses POSIX
    if ( auto result = tcsetattr( fileno(stdin), TCSADRAIN, /*IN*/ &termios_new );
        result == POSIX_ERROR ) {
        int errno_save = errno;
        cerr<<"Standard in is not a tty keyboard with errno of:"<< errno_save <<endl;
        errno = errno_save;
        exit(1);
    }
    //Termios const termios_current { termio_get() };
    //assert( check_equality( termios_new, termios_current ) && "Tcsetattr failed at least partially." );
};

Termios & termio_set_raw() { // uses POSIX
    cin.sync_with_stdio( false );  									// TODO:  iostreams bug?  This is required for timer time-out else a bug occurs.
    static Termios termios_orig { termio_get() };
    Termios 	   termios_new 	{ termios_orig };                   // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Mode-Data-Types
        // /usr/include/sys/ttydefaults.h
        // /usr/include/bits/termios-c_lflag.h
        // local modes
    termios_new.c_lflag 		&= static_cast<tcflag_t>(~ISIG);    // TODO?: turn off ???  // want this bit ON for cbreak mode.
    termios_new.c_lflag 		&= static_cast<tcflag_t>(~ICANON);  // turn off "canonical" or "cooked" mode and go to "non-canonical" or "raw" mode, ie. don't wait for <Enter>. // want this bit OFF for cbreak mode.
    termios_new.c_lflag 		&= static_cast<tcflag_t>(~ECHO);    // turn off "echo" mode, ie. don't automatically show the characters being typed. // want this bit OFF for cbreak mode.
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~ECHOE);     // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~ECHOK);     // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~ECHONL);    // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~ECHOCTL);   // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~ECHOPRT);   // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~ECHOKE);    // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~FLUSHO);    // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~NOFLSH);    // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~PENDIN);    // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~TOSTOP);    // TODO?: not touched?
    termios_new.c_lflag 		&= static_cast<tcflag_t>(~IEXTEN);  // TODO?: turn off ??? maybe not!
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~EXTPROC);   // TODO?: not touched?
    //termios_new.c_lflag 		&= static_cast<tcflag_t>(~XCASE);     // TODO?: not touched?
    // /usr/include/bits/termios-c_iflag.h
    // local modes
    termios_new.c_iflag 		&= static_cast<tcflag_t>(~IGNBRK);  // TODO?: turn off ???
    termios_new.c_iflag 		&= static_cast<tcflag_t>(~BRKINT);  // TODO?: turn off ???
    //termios_new.c_iflag 		&= static_cast<tcflag_t>(~IGNPAR);    // TODO?: not touched?
    termios_new.c_iflag 		&= static_cast<tcflag_t>(~PARMRK);  // TODO?: turn off ???
    termios_new.c_iflag 		&= static_cast<tcflag_t>(~INPCK);   // TODO?: turn off ???
    termios_new.c_iflag 		&= static_cast<tcflag_t>(~ISTRIP);  // TODO?: turn off ???
    termios_new.c_iflag 		&= static_cast<tcflag_t>(~INLCR);   // TODO?: turn off ???
    termios_new.c_iflag 		&= static_cast<tcflag_t>(~IGNCR);   // TODO?: turn off ???
    termios_new.c_iflag 		&= static_cast<tcflag_t>(~ICRNL);   // TODO?: turn off ???  // want this bit OFF for cbreak mode.
    //termios_new.c_iflag 		&= static_cast<tcflag_t>(~IUCLC);     // TODO?: not touched?
    termios_new.c_iflag 		&= static_cast<tcflag_t>(~IXON);    // TODO?: turn off ???
    //termios_new.c_iflag 		&= static_cast<tcflag_t>(~IXANY);     // TODO?: not touched?
    //termios_new.c_iflag 		&= static_cast<tcflag_t>(~IXOFF);     // TODO?: not touched?
    //termios_new.c_iflag 		&= static_cast<tcflag_t>(~IMAXBEL);   // TODO?: not touched?
    //termios_new.c_iflag 		&= static_cast<tcflag_t>(~IUTF8);     // TODO?: not touched?
    // /usr/include/bits/termios-c_oflag.h
    // output modes
    termios_new.c_oflag 		&= static_cast<tcflag_t>(~OPOST);   // turn off all post-process output processing. NOTE: there are about 20 more that are not touched, decided not to list them in comments, since I don't thinkn they are needed.
        // /usr/include/bits/termios-c_cc.h
        // http://www.unixwiz.net/techtips/termios-vmin-vtime.html
        // not sure what to call these c? cc? what are they?
    termios_new.c_cc[VTIME] 	= 0; 								// wait forever to get the next char.  //NOTE: there are about 15 more that are not touched, decided not to list them in comments, since I don't thinkn they are needed.
    termios_new.c_cc[VMIN]  	= 1;  								// get minimun one char
    termio_set( termios_new );
    return termios_orig;
}
void print_iosbase() {
    /*    enum _Ios_Iostate {
        _S_goodbit 		= 0,
        _S_badbit 		= 1L << 0,
        _S_eofbit 		= 1L << 1,
        _S_failbit		= 1L << 2,
        _S_ios_iostate_end = 1L << 16,
        _S_ios_iostate_max = __INT_MAX__,
        _S_ios_iostate_min = ~__INT_MAX__ }
    */;
    auto rds = cin.rdstate();
    cout<< "\n\r:rds:" << rds << endl;
    if (cin.rdstate() == std::ios_base::goodbit) cout<< "\n\rgoodbit" << endl;
    if (cin.rdstate() == std::ios_base::badbit) cout<< "\n\rbadbit" << endl;
    if (cin.rdstate() == std::ios_base::eofbit) cout<< "\n\reofbit" << endl;
}
void print_tellg() {  // This code can help you to check existence of data in the stdin without blocking: // https://stackoverflow.com/questions/3317740/checking-data-availability-before-calling-stdgetline
    //streamsize position{std::cin.tellg()};
    position = std::cin.tellg();
    if (position < 0) cout << "\n\r:no chars available" << endl;
    else {
        cout <<"\n\r:length:"<<position<<endl;
        std::cin.seekg( 0, std::cin.beg );      // If stdin has some data - don't forget to set the position back to the beginning.
                                                // TODO??: why called "seekdir"?
                                                // what offset the position? tellg? or just a pre-caution
    }
} // end stackoverflow example EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEe

int main() { unsigned char my_char{255}, my_c_string[100]{""}; streamsize in_avail_count{}; std::vector<char> char_vec(1024); string  my_string{};
    basic_streambuf<char> *                             cin_streambuf{};
    std::chrono::time_point<std::chrono::steady_clock>  clock_start{}, clock_end{};
    std::chrono::duration<long, std::micro>             duration_passed{};
    // Some other ways to read cin
    // - cin.read( char_vec.data(), 1 )
    // - cin.readsome(my_c_string, 2);
    Termios & termios_orig{termio_set_raw()};
    cin.sync_with_stdio(false);  // Required for in_avail() to work TODO??:

    cout << "\n\rEnter keyboard input:";
    my_char = 255; cin  >> my_char; cout << "\n\r:Got my_char input."<<endl;
    clock_start = std::chrono::steady_clock::now();
    if (my_char == 27) {
        cout << "\n\rgot ESC\n\r" <<endl;
        print_tellg(); if (not(position < 0)) cin >> my_char; cout << "\n\r:my_char as int, then char:" << (int)my_char <<","<< my_char << endl;
        // Determine if other chars of a multi-byte sequence are coming, criteria is that they must arrive withing 100 milli-seconds. 1/10 th of a second.
        do {
            std::this_thread::sleep_for(10ms);
            cin_streambuf = cin.rdbuf();
            in_avail_count = cin_streambuf->in_avail(); cout << "\n\r:in_avail_count:" << in_avail_count << endl;
            clock_end = std::chrono::steady_clock::now();
            duration_passed = std::chrono::duration_cast<std::chrono::microseconds>(clock_end - clock_start);
            assert( in_avail_count>=0 && "ERROR: We don't have logic for -1 or lower.");
        } while ( duration_passed < 100ms && in_avail_count == 0 );
        if (duration_passed < 100ms)
            cout << "\n\r:We have a multi-byte sequence!.\n\r" << endl;
        else
            cout << "\n\r:We have a single ESC, NOT a multi-byte sequence!.\n\r" << endl;

    } else {
        print_tellg(); if (not(position < 0)) cin >> my_char; cout << "\n\r:my_char as int, then char:" << (int)my_char <<","<< my_char << endl;
        cin_streambuf = cin.rdbuf();
        in_avail_count = cin_streambuf->in_avail(); cout << "\n\r:in_avail_count:" << in_avail_count << endl;

    }

    my_char = 255; cin  >> my_char; cout << "\n\r:Got my_char input."<<endl;
    cout << "\n\r:my_char as int, then char:" << (int)my_char <<","<< my_char << endl;
    print_tellg(); if (not(position < 0)) cin >> my_char; cout << "\n\r:my_char as int, then char:" << (int)my_char <<","<< my_char << endl;
    cin_streambuf = cin.rdbuf();
    in_avail_count = cin_streambuf->in_avail(); cout << "\n\r:in_avail_count:" << in_avail_count << endl;

    my_char = 255; cin  >> my_char; cout << "\n\r:Got my_char input."<<endl;
    cout << "\n\r:my_char as int, then char:" << (int)my_char <<","<< my_char << endl;
    print_tellg(); if (not(position < 0)) cin >> my_char; cout << "\n\r:my_char as int, then char:" << (int)my_char <<","<< my_char << endl;
    cin_streambuf = cin.rdbuf();
    in_avail_count = cin_streambuf->in_avail(); cout << "\n\r:in_avail_count:" << in_avail_count << endl;

    my_char = 255; cin  >> my_char; cout << "\n\r:Got my_char input."<<endl;
    cout << "\n\r:my_char as int, then char:" << (int)my_char <<","<< my_char << endl;
    print_tellg(); if (not(position < 0)) cin >> my_char; cout << "\n\r:my_char as int, then char:" << (int)my_char <<","<< my_char << endl;
    cin_streambuf = cin.rdbuf();
    in_avail_count = cin_streambuf->in_avail(); cout << "\n\r:in_avail_count:" << in_avail_count << endl;
    termio_set(termios_orig);
    cout << "\n\r###" << endl;
    return 0;
}
