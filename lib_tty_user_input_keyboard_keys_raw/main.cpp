/*
 * Generated as part of the password manager effort.
 * Used to test lib_tty.
 */
#define _POSIX_C_SOURCE 200809L // https://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html  http://man7.org/linux/man-pages/man7/feature_test_macros.7.html
#include <string>
#include <iostream>
#include <chrono>

// POSIX
#include <signal.h>
#include <termios.h>
#include <unistd.h>

#include "lib_tty.h"
using std::endl, std::cin, std::cout, std::cerr, std::string;
using namespace std::chrono_literals;  // for wait().

void test_posix() {
    cerr << "POSIX read single character from stdin via read(,,)."<<endl;
    char 	buffer_char[51] {'z'};  // +1 for the NULL.
    ssize_t read_result 	{};
    while (true) { // all keys captured.
        Termios terminal_status_orig  { termio_set_raw() };
        cerr <<"RAW  :";
        read_result = read( STDIN_FILENO, &buffer_char[0], 1l);  // POSIX read
        cerr <<"\nRAW  :has been read.\n";
        if (read_result == POSIX_EOF)   { cerr << "ERROR:read() EOF.\n"; }
        if (read_result == POSIX_ERROR) { cerr << "ERROR:I/O error\n"; }
        cerr << "read() result:raw       <<<"<<read_result<<">>>"<<endl;
        cerr << "read()       :raw       <<<"<<buffer_char[0]<<">>>, "<< static_cast<int>(buffer_char[0]) <<endl;
        buffer_char[0] = 'z';

        Termios terminal_status_raw { termio_set_timer( 20 ) }; /* new name on next line */
        cerr<<"RAW with timer:";
        read_result = read( STDIN_FILENO, &buffer_char[0], 1l );
        if (read_result == POSIX_EOF) { cerr << "ERROR:read() EOF.\n"; }
        if (read_result == POSIX_ERROR) { cerr << "ERROR:I/O error\n"; }
        cerr<<"\nRAW T: has been read.\n";
        cerr << "read() result:rawT     <<<" << read_result << ">>>" << endl;
        cerr << "read()       :rawT     <<<" << buffer_char[0] << ">>>, " << static_cast<int>(buffer_char[0])<<endl;
        buffer_char[0] = 'z';
        // STDIN_FILENO doesn't appear to need a "clear" or "reset".
        termio_restore( terminal_status_raw );

        termio_restore( terminal_status_orig );
        cerr<<"Back to original, ie. canonical:";
        read_result = read( STDIN_FILENO, &buffer_char[0], 1l );
        cerr<<"\nCanon: has been read.\n";
        if (read_result == POSIX_EOF) { cerr << "ERROR:read() EOF.\n"; }
        if (read_result == POSIX_ERROR) { cerr << "ERROR:I/O error\n"; }
        cerr << "read() result:canonical <<<"<<read_result<<">>>"<<endl;
        cerr << "read()       :canonical <<<"<<buffer_char[0]<<">>>, "<< static_cast<int>(buffer_char[0])<<endl;
        buffer_char[0] = 'z';
    }
}

void test_getc() {
    //Termios terminal_status_orig {};
    //Termios terminal_status_raw {};
    cerr << "C language read single character from stdin via getc(stdin)."<<endl;
    int char_int {0};
    while (char_int != C_EOF) { // all keys captured.
        char_int = 0;
        // termio_set_raw( /*OUT*/ &terminal_status_orig );
        Termios terminal_status_orig { termio_set_raw() };
        cerr<<"RAW  :";
        char_int = getc(stdin);
        cerr<<"\nRAW  :has been read.\n";
        if ( char_int ==  C_EOF || char_int == C_FERR ) { cerr << "ERROR:getc(stdin) EOF or ERROR !?!\n"; }
        if ( std::feof( stdin) ) {
            cerr << "ERROR: EOF\n";
            std::perror( "perror():getc() eof");
            clearerr( stdin );  // This DOES clear an EOF.
        }
        if ( std::ferror( stdin) ) {
            cerr << "ERROR: I/O error with type in ERRNO.\n";
            std::perror( "perror():getc() ferror");
            clearerr( stdin );  // This DOES clear an EOF.
        }
        cerr << "getc():raw       <<<"<<char_int<<">>>, "<<static_cast<int>(char_int)<<endl;
        char_int = 0;
        Termios terminal_status_raw { termio_set_timer( 20 ) }; /* new name on next line */

        cerr<<"RAW T:";
        char_int = getc(stdin);
        cerr<<"\nRAW T:has been read.\n";
        if ( char_int == C_EOF || char_int == C_FERR ) { cerr << "ERROR:getc(stdin) EOF or ERROR !?!\n"; }
        if ( std::feof( stdin) ) {
            cerr << "ERROR: EOF\n";
            std::perror( "perror():getc() eof");
            clearerr( stdin );  // This DOES clear an EOF created by the failure of the timer.
        }
        if ( std::ferror( stdin) ) {
            cerr << "ERROR: I/O error with type in ERRNO.\n";
            std::perror( "perror():getc() ferror");
            clearerr( stdin );  // This DOES clear an EOF created by the failure of the timer.
        }
        cerr << "getc():rawT      <<<"<<char_int<<">>>, "<<static_cast<int>(char_int)<<endl;
        char_int = 0;
        termio_restore( terminal_status_raw );

        termio_restore( terminal_status_orig );
        cerr<<"CANON:";
        char_int = getc( stdin );
        cerr<<"\nCANON:has been read.\n";
        if ( char_int ==  C_EOF || char_int == C_FERR ) { cerr << "ERROR:getc(stdin) EOF or ERROR !?!\n"; }
        if ( std::feof( stdin) ) {
            cerr << "ERROR: EOF\n";
            std::perror( "perror():getc() eof");
            clearerr( stdin );  // This DOES clear an EOF.
        }
        if ( std::ferror( stdin) ) {
            cerr << "ERROR: I/O error with type in ERRNO.\n";
            std::perror( "perror():getc() ferror");
            clearerr( stdin );  // This DOES clear an EOF.
        }
        cerr << "getc():canonical <<<"<<char_int<<">>>, "<<static_cast<int>(char_int)<<endl;
        //char_int = 0;
    }
}

void test_cin_get() {
    //Termios terminal_status_orig {};
    //Termios terminal_status_raw {};
    cerr << "C++ read single character from stdin via cin.get(ch)."<<endl;
    char ch {'z'};
    while (true) { // all keys captured. but once timer times-out we get infinite loop with all get.s getting the last char. may be at EOF?!
        // termio_set_raw( /*OUT*/ &terminal_status_orig );
        Termios terminal_status_orig { termio_set_raw() };
        ch = 'z';
        cerr<<"RAW  :";
        cin.get(ch);
        cerr<<"\nRAW  :has been read.\n";
        print_iostate( cin );
        if ( cin.eof() ) {
            assert(false);
            cin.clear(std::ios_base::goodbit);  // todo: this may clear an EOF created by the failure of the timer.
            print_iostate( cin );
        }
        if ( cin.fail() ) {
            cerr << "ERROR: I/O error with type in ERRNO.\n";
            std::perror( "perror():get() ferror");
            cin.clear();  // todo: this may clear an EOF created by the failure of the timer.
            print_iostate( cin );
        }
        cerr << "cin.get(ch):raw       <<<"<<ch<<">>>, "<<static_cast<int>(ch)<<endl;
        ch = 'z';

        Termios terminal_status_raw { termio_set_timer( 20 ) }; /* new name on next line */
        cerr<<"RAW T:";
        cin.get(ch);
        cerr<<"\nRAWT :has been read.\n";
        print_iostate( cin );
        if ( cin.eof() ) {
            cerr << "ERROR: EOF\n";
            std::perror( "perror():get() eof");
            cin.clear(std::ios_base::goodbit);  // todo: this may clear an EOF created by the failure of the timer.
            print_iostate( cin );
        }
        if ( cin.fail() ) {
            cerr << "ERROR: I/O error with type in ERRNO.\n";
            std::perror( "perror():get() ferror");
            cin.clear();  // this does NOT clear an EOF created by the failure of the timer.
            print_iostate( cin );
        }
        cerr << "cin.get(ch):raw       <<<"<<ch<<">>>, "<<static_cast<int>(ch)<<endl;
        ch = 'z';
        cin.clear();
        termio_restore( terminal_status_raw );

        print_iostate( cin );
        termio_restore( terminal_status_orig );
        cerr<<"CANON:";
        print_iostate( cin );
        cin.get(ch);
        cerr<<"\nCanon:has been read.\n";
        print_iostate( cin );
        if ( cin.eof() ) {
            cerr << "ERROR: EOF\n";
            std::perror( "perror():get() eof");
            cin.clear(std::ios_base::goodbit);  // todo: this may clear an EOF created by the failure of the timer.
        }
        if ( cin.fail() ) {  // not cin.fail()
            cerr << "ERROR: I/O error with type in ERRNO.\n";
            std::perror( "perror():get() ferror");
            cin.clear();   // this does NOT clear an EOF created by the failure of the timer.
        }
        cerr << "cin.get(ch):canonical <<<"<<ch<<">>>, "<<static_cast<int>(ch)<<endl;
        ch = 'z';
    }
}

int main() {
    std::cerr << "User-preferred locale setting is " << std::locale("").name().c_str() << endl;
    if ( char * my_tty_name = ttyname(fileno(stdin)); my_tty_name == nullptr ) // could have used isatty().
    { perror("user_input_raw: not a tty."); exit(1); }
    else cerr<< "ttyname: "<< my_tty_name << endl;

    /* ****** Comment out all but one of the "parts" to test each one separately ****** */

    /* Part 1 test reading the keyboard - pick one test of these three part 1 approaches:
     cout << "Part1. Reading keyboard now." << endl;
     test_posix();
     std::this_thread::sleep_for(90s);
     assert(false);
     test_getc();
     std::this_thread::sleep_for(90s);
     assert(false);
     test_cin_get();
     std::this_thread::sleep_for(90s);
     assert(false);
     */

    /* Part 2 test get_kb_keys_raw() */
    cout << "Part2." << endl;
    bool is_require_field_completion {true};
    //size_t 	max_length 				{1};  // NOTE: also test others ****
    //size_t 	max_length 				{2};
    size_t 	max_length 				{5};
    bool 	echo_skc_to_tty  			{true};
    bool 	is_strip_control_chars 	{true};
    bool 	is_password 			{false};
    bool 	is_my_eofs 				{false};
    while ( !is_my_eofs ) {
        cout << "\nPress "<<max_length<<" key(s) or eof to end now: ";

        auto [value, hot_key, file_status] = get_kb_keys_raw( max_length, is_require_field_completion, echo_skc_to_tty, is_strip_control_chars, is_password );  // NOTE: test both these lines ****

                //auto [value, hot_key, file_status] = get_value_raw( max_length, is_require_field_completion, echo_skc_to_tty, is_strip_control_chars, is_password );
                cout << "\nPart2 got: value, hot_key_name, file_status:"<<value<< ", "<<hot_key.my_name<<", "<<static_cast<int>(file_status)<<endl;
                if ( hot_key.my_name == "eof" || file_status == File_status::eof_simple_key_char) {  // todo: both should be true at same time, probably should not be using file_status, since that value may be removed in the 'raw' case.
            is_my_eofs = true;
        }
    }
    cout << "###" << endl;
    return EXIT_SUCCESS; // todo: or POSIX: exit(EXIT_SUCCESS)
}



