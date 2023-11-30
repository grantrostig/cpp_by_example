/* (c) Cppmsg.com License Boost 1.0 */
//#include <bits/stdc++.h>
//#include <istream>
#include <array>
#include <vector>
#include <iostream>
#include <sstream>
#include <termios.h>
using namespace std;

// Bad file global I know... just for fun and learning/renaming "static"
#define STATIC_GLOBAL_HIDER static     // similar to $ namespace {}
STATIC_GLOBAL_HIDER streamsize position {};  // here static just hides the obj from linker, same as unnamed namespace TODO:??
inline constexpr   ssize_t     POSIX_ERROR =       -1;  /// yes, believe it or not, it is not zero, which I think is good. :)
/// C++ class name capitalization convention of the POSIX C type.
using Termios = termios;    // Tty terminal IO & speed structure, used for getting and setting them. // Enforcing the C++ struct type name capitalization convention for the POSIX C type.  I like it that way.

Termios & termio_get() { // uses POSIX  // TODO TODO: what are advantages of other version of this function?
    static Termios termios;
    if (auto result = tcgetattr( fileno(stdin), &termios); result == POSIX_ERROR) { // TODO: throw() in signature?
        int errno_save = errno;
        errno = errno_save;
        cerr << "We will exit(1) for this error"<<endl;
        exit(1);
    }
    return termios;  // copy of POD?
}

/// We set POSIX terminal with Termios control attributes.
/// Applications that need ALL of the requested changes to work properly should follow tcsetattr()
/// with a call to tcgetattr() and compare then appropriate field values.
/// We do the check after this call within the caller.  TODO consider doing it in here.
/// TODO not called yet, refactor for 3 uses.
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
    cout<< "\n:rds:" << rds << endl;
    if (cin.rdstate() == std::ios_base::goodbit) cout<< "\ngoodbit" << endl;
    if (cin.rdstate() == std::ios_base::badbit) cout<< "\nbadbit" << endl;
    if (cin.rdstate() == std::ios_base::eofbit) cout<< "\neofbit" << endl;
}
void print_tellg() {  // This code can help you to check existence of data in the stdin without blocking: // https://stackoverflow.com/questions/3317740/checking-data-availability-before-calling-stdgetline
    //streamsize position{std::cin.tellg()};
    position = std::cin.tellg();
    if (position < 0) cout << "\n:no chars available" << endl;
    else {
        cout <<"\n:length:"<<position<<endl;
        std::cin.seekg( 0, std::cin.beg );      // If stdin has some data - don't forget to set the position back to the beginning.
                                                // TODO??: why called "seekdir"?
                                                // what offset the position? tellg? or just a pre-caution
    }
} // end stackoverflow example EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEe

int main() { char my_char{}, my_c_string[100]{""}; streamsize in_avail_count{}; std::vector<char> char_vec(1024); string  my_string{}; basic_streambuf<char> * cin_streambuf{};
    termio_set_raw();
    print_tellg(); if (not(position < 0)) cin.read( char_vec.data(), 1 ); cout << "\n:*char_vec.begin():" << *char_vec.begin() << endl; // You can then read all data including \0 (can be more than one) at the end of the buffer:

    cin.sync_with_stdio(false);  // Required for in_avail() to work TODO??:
    cout << "\nEnter keyboard input:";

    print_tellg(); if (not(position < 0)) cin.read( char_vec.data(), 1 ); cout << "\n:*char_vec.begin():" << *char_vec.begin() << endl; // You can then read all data including \0 (can be more than one) at the end of the buffer:

    cin  >> my_char; cout << "\n:Got my_char input."<<endl;
    cout << "\n:my_char as int, then char:" << (int)my_char <<","<< my_char << endl;

    cin.readsome(my_c_string, 1); // reads 'This ' and stores in c[0] .. c[4]
    cout << "\n:my_c_string:" << my_c_string << endl;
    cin_streambuf = cin.rdbuf();
    in_avail_count = cin_streambuf->in_avail(); cout << "\n:in_avail_count:" << in_avail_count << endl;

    cin  >> my_string;
    cout << "\n:text:" << my_string << endl;
    cin_streambuf = cin.rdbuf();
    in_avail_count = cin_streambuf->in_avail(); cout << "\n:in_avail_count:" << in_avail_count << endl;

    cout << "\n###" << endl;
    return 0;
}
