/* file used in development of lib_tty
 * Generated as part of the password manager effort.
 * Used to test lib_tty.
 */
#include <iostream>
#include <termios.h>
#include <chrono>
#include <thread>
#include <cassert>
#define POSIX_ERROR -1
using Termios = termios;
using std::cin, std::cout, std::cerr, std::endl ;
using namespace std::chrono_literals;  // for: 5s

void print_iostate(std::istream const & stream) {  // todo: TODO how do I pass in cin or cout to this? gmail
    if (stream.rdstate() == std::ios_base::goodbit) cerr << "goodbit only, ";
    if (stream.rdstate() & std::ios_base::goodbit) cerr << "goodbit, ";
    if (stream.rdstate() & std::ios_base::eofbit) cerr << "eofbit, ";
    if (stream.rdstate() & std::ios_base::failbit) cerr << "failbit, ";
    if (stream.rdstate() & std::ios_base::badbit) cerr << "badbit.";
    cerr << endl;
}

int main()
{
    cin.sync_with_stdio(false);  // todo:  iostreams bug?  This is required or timer time-out bug occurs.
    int result {};
    Termios terminal_status;  // POSIX tty calls
    Termios terminal_status_save;  // POSIX tty calls
    if ((result = tcgetattr( fileno(stdin), &terminal_status)) == POSIX_ERROR) {
        cerr << "Error termio_set_raw():"<<errno<<", standard in is not a tty keyboard."<<endl;
        std::perror("termio");
        exit(1);
    }
    terminal_status_save = terminal_status;
    terminal_status.c_lflag &= static_cast<tcflag_t>(~ICANON);  // turn on "raw" mode, ie. don't wait for <Enter>.
    terminal_status.c_cc[VTIME] = 40;  // wait some time to get that char  in 1/10 th of second
    terminal_status.c_cc[VMIN]  = 0;  // no minimum char to get
    if ((result = tcsetattr(fileno(stdin), TCSADRAIN, &terminal_status)) == POSIX_ERROR) {
        cerr << "Error termio_set_timer():"<<errno<<", standard in is not a tty keyboard."<<endl;
        std::perror("termio_set_timer()");
        exit(1);
    }
    cerr << "C++ read single character at a time from stdin via cin.get(ch)."<<endl;
    char ch {'z'};
    for (int i = 8; i-->0;) {
        int result2 {};
        Termios terminal_status2;  // POSIX tty calls
        if ((result2 = tcgetattr( fileno(stdin), &terminal_status2)) == POSIX_ERROR) {
            cerr << "Error termio_set_raw():"<<errno<<", standard in is not a tty keyboard."<<endl;
            std::perror("termio");
            exit(1);
        }
        print_iostate(cin);
        cerr<<"RAW T:";
        cin.get(ch);  // type a char within timeout and all works, let it time out and the next time around, it doesn't wait for a char to be typed in.
        cerr<<"\nRAWT :has been read.\n";
        print_iostate(cin);
        if ( cin.eof() ) {
            cerr << "ERROR: EOF\n";
            std::perror( "perror():get():cin.eof()");
        }
        if ( cin.fail() ) {
            cerr << "ERROR: I/O error with type in ERRNO.\n";
            std::perror( "perror():get():cin.fail()");
        }
        cin.clear();  	// this does NOT clear the failbit created by the timeout of the timer.
        // cin.sync();  	// doesn't help timeout problem.
        // cin.seekg(0); 	// doesn't help timeout problem.
        print_iostate(cin);
        cerr << "cin.get(ch):raw       <<<"<<ch<<">>>, "<<static_cast<int>(ch)<<endl;
        ch = 'z';
    }
    if ((result = tcsetattr(fileno(stdin), TCSADRAIN, &terminal_status_save)) == POSIX_ERROR) { // restore prior status
        int errno_save = errno;
        cerr << "Error termio_restore():"<<errno_save<<", standard in is not a tty keyboard."<<endl;
        perror("termio_restore()");
        exit(1);
    }
    std::this_thread::sleep_for(9999s);
    cout << "###" << endl;
    return 0;
}
