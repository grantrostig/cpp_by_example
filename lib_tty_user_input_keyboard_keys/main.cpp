/* file used in development of lib_tty - retain for history */
#include <iostream>
#include <vector>
#include <array>
#include <locale>
#include <cstddef>
#include <variant>
#include <optional>
#include <cassert>
#include <algorithm>
#include <functional>

#include <cstdio>
#include <cstdlib>
#include <termio.h>
#include <termios.h>

using std::endl, std::cin, std::cout, std::string;

// #define GETLINE // hack to identify just the ESC key not other ESC sequences.  todo: try a timer to see if just ESC was pressed or other keys are coming.
// #define CIN_GTGT
#define CIN_GET

constexpr unsigned char ESC = 27;
// constexpr unsigned char GS 	= 29;  // Group Separator
constexpr unsigned char ONE	= 49;  // numeric one character '1'
constexpr unsigned char TWO	= 50;  // numeric two character '2'
// constexpr unsigned char THREE = 51;  // numeric two character '2'
// constexpr unsigned char FOUR  = 52;  // numeric two character '2'
// constexpr unsigned char FIVE  = 53;  // numeric two character '2'
constexpr unsigned char OH	  = 79;  // alphabectic O
constexpr unsigned char LSB   = 91;  // Left square bracket '['
constexpr unsigned char TILDE = 126;

using Simple_key_char = unsigned char;
using Hot_key_chars = std::vector<Simple_key_char>;

struct Hot_key {
    std::string name;
    Hot_key_chars k;
};
using Hot_keys = std::vector<Hot_key>;

enum class File_status {
    other,
    eof
};
using Hot_key_o_fstat = std::variant < Hot_key, File_status >;

using Kb_key = std::variant < Simple_key_char, Hot_key, File_status >;
using Kb_key_optional = std::optional < Kb_key >;
using Kb_key_a_fstat = std::pair < Kb_key_optional, File_status >;

using Kb_regular_value = std::string;
using Kb_value_o_hkey = std::variant< Hot_key, Kb_regular_value>;
// using Value_optional = std::optional < Kb_value >;
// using Value_plus = std::tuple < Value_optional, Hot_key, File_status >;
using Value_plus = std::tuple < std::string, Hot_key, File_status >;

std::optional<Hot_key> find_hot_key( const Hot_keys & hot_keys, Hot_key_chars this_key) {
    for (auto & hk : hot_keys)
        if (hk.k == this_key )
            return hk;
    return {};
}

using Termios = termios; // C++ class name from the c language type;
Termios termio_set_raw() {
    int result {};
    Termios terminal_status {};
    Termios terminal_status_save {};
    // if ((result = ioctl (fileno(stdin), TCGETA, &terminal_status)) < 0) {  // old way to do this.
    if ((result = tcgetattr( fileno(stdin), &terminal_status)) != 0) {
        cout << "Error ioctl():"<<errno<<", standard in is not a tty keyboard."<<endl;
        exit(1);
    }
    terminal_status_save = terminal_status;
    terminal_status.c_lflag &= static_cast<unsigned int>(~ICANON);  // turn on "raw" mode, ie. don't wait for <Enter>.
    terminal_status.c_cc[VMIN] = 1;  // get minimun one char
    terminal_status.c_cc[VTIME] = 0; // wait forever to get that char
    // if ((result = ioctl(fileno(stdin), TCSETA, &terminal_status)) < 0) {  // old way to do this.
    if ((result = tcsetattr(fileno(stdin), TCSADRAIN, &terminal_status)) != 0) {
        // https://pubs.opengroup.org/onlinepubs/9699919799/
        // todo: Applications that need all of the requested changes made to work properly should follow tcsetattr() with a call to tcgetattr() and compare the appropriate field values.
        cout << "Error ioctl():"<<errno<<", TCSETA."<<endl;
        exit(1);
    }
    return terminal_status_save;
}

void termio_restore(Termios terminal_status_save) {
    int result {};
    if ((result = tcsetattr(fileno(stdin), TCSADRAIN, &terminal_status_save)) < 0) { // restore prior status
        cout << "Error ioctl():"<<errno<<", TCSETA."<<endl;
        exit(1);
    }
}

Hot_key_o_fstat which_ESC_OH( const Hot_keys & hot_keys){
    Simple_key_char kbc3 {};
    cin >> kbc3;
    if (cin.eof()) return File_status::eof;
    if (auto r = find_hot_key( hot_keys,  Hot_key_chars { ESC, OH,  kbc3 }) )
        return *r;
    cin.putback( kbc3 );  // todo: type problem on cin?
    return {};
}

Hot_key_o_fstat which_ESC_LSB_1_2( const Hot_keys & hot_keys, Simple_key_char kbc3 ) {
    Simple_key_char kbc4 {}, kbc5 {};
    cin >> kbc4; if (cin.eof()) return File_status::eof;
    cin >> kbc5; if (cin.eof()) return File_status::eof;
    if (auto r = find_hot_key( hot_keys, Hot_key_chars { ESC, LSB,  kbc3, kbc4, kbc5 }) )
        return *r;
    cin.putback( kbc4 );  // todo: type problem on cin?
    cin.putback( kbc5 );  // todo: type problem on cin?
    return {};
};

Hot_key_o_fstat which_ESC_LSB( const Hot_keys & hot_keys ) {
    Simple_key_char kbc3 {}, kbc4 {};
    cin >> kbc3; if (cin.eof()) return File_status::eof;

    if ( kbc3 == TWO ) { //50
        cin >> kbc4; if (cin.eof()) return File_status::eof;
        if (kbc4 != TILDE) { // strange overlap case of "Insert" and "F8-F12"
            cin.putback( kbc4 );  // must be processed by LSB_12
            if (auto variant = which_ESC_LSB_1_2( hot_keys, kbc3 ); std::holds_alternative<Hot_key>(variant))
                return std::get<Hot_key>(variant);
            else
                return std::get<File_status>(variant);
        }
        cin.putback( kbc4 );  // kbc4, put it back so it can be processed by the switch and look at "TWO" again.
        // cin.putback( kbc3 );
    }

    switch (kbc3) {
    case ONE:
        if (auto variant = which_ESC_LSB_1_2( hot_keys, kbc3 ); std::holds_alternative<Hot_key>(variant))
             return std::get<Hot_key>(variant);
        else return std::get<File_status>(variant);
        // break;  to turn off warning. todo: annotate.
    case TWO:  // 50, second use case for TWO! yes the keyboard coding is strange.
    case 51:
    case 53: // skipped 52 intentionally because of kb esc sequence specification.
    case 54:
        cin >> kbc4; if (cin.eof()) return File_status::eof;
        if ( kbc4 == TILDE ) {  // todo: check to see if 2 chars are in fact valid.
            if (auto r = find_hot_key( hot_keys,  Hot_key_chars { ESC, LSB,  kbc3, TILDE }) )
                return *r;
        }
        else {
            cin.putback( kbc4 );  // todo: type problem on cin?
            cin.putback( kbc3 );
            return {};
        }
        break;
    default:
        if (auto r = find_hot_key( hot_keys, Hot_key_chars { ESC, LSB, kbc3}) )
            return *r;
    }

    // *** we found no hot key
    cin.putback( kbc3 );
    return {};
}

Hot_key_o_fstat which_esc_sequence( const Hot_keys & hot_keys ) {
    // Hot_keys special_key;
    Simple_key_char kbc2 {};
    cin >> kbc2; if (cin.eof()) return File_status::eof;

    if ( kbc2 == OH ) {
        if (auto variant = which_ESC_OH( hot_keys ); std::holds_alternative<Hot_key>(variant))
            return std::get<Hot_key>(variant);
        else return std::get<File_status>(variant);
    }
    else if ( kbc2 == LSB ) {
        if (auto variant = which_ESC_LSB( hot_keys ); std::holds_alternative<Hot_key>(variant))
            return std::get<Hot_key>(variant);
        else return std::get<File_status>(variant);
    }
    cin.putback( kbc2 );  // todo: type problem on cin?
    //return {}; // not more than ESC.
    return {File_status::other}; // not more than ESC.
};

Kb_key_a_fstat get_kb_key()  {
    Simple_key_char kbc1 {};
    static const Hot_keys hot_keys {
        // Enter			??  // todo: triggers getline to return, but does not set eof unless it is a empty line?
        // CTRL-d			??  // todo: triggers getline to return, but does not set eof unless it is a empty line?
        // {"backspace_left_erase",	{1} },  // todo:
        // {"Tab",			{1}},  // todo:
        {"Esc",			{ESC}},
        {"F1",			{ESC,OH,80}},
        {"F2",			{ESC,OH,81}},
        {"F3",			{ESC,OH,82}},
        {"F4",			{ESC,OH,83}},

        {"up-arrow",	{ESC,LSB,65}},
        {"down-arrow",	{ESC,LSB,66}},
        {"right-arrow",	{ESC,LSB,67}},
        {"left-arrow",	{ESC,LSB,68}},
        {"End",			{ESC,LSB,70}},
        {"Home",		{ESC,LSB,72}},
        {"Shift-tab",	{ESC,LSB,90}},

        {"Insert",		{ESC,LSB,TWO,TILDE}},
        {"Delete",		{ESC,LSB, 51,TILDE}},
        {"PageDown",	{ESC,LSB, 54,TILDE}},
        {"PageUp",	  	{ESC,LSB, 53,TILDE}},
        {"F5",			{ESC,LSB,ONE,   53,TILDE}},
        {"F6",			{ESC,LSB,ONE,   55,TILDE}}, // note skipped 54
        {"F7",			{ESC,LSB,ONE,   56,TILDE}},
        {"F8",			{ESC,LSB,ONE,   57,TILDE}},
        {"F9",			{ESC,LSB,TWO,   48,TILDE}},
        {"F10",			{ESC,LSB,TWO,   49,TILDE}},
        {"F11",			{ESC,LSB,TWO,   51,TILDE}}, // note skipped 50
        {"F12",			{ESC,LSB,TWO,   52,TILDE}}
        /* Shift-F1		{ESC,LSB,TWO,   59,80}
         * Shift-F2		{ESC,LSB,TWO,   59,81}
         * CTRL-F1		{ESC,LSB,FIVE,  59,80}
         * CTRL-F2		{ESC,LSB,FIVE,  59,81}
         */
    };

#ifdef GETLINE
    std::cin >> std::ws;
    std::string line;
    getline(cin, line);  // we get a line just to see if there is only one ESC on the line. yup!
    for (size_t n = line.length()-1 ; n >- 0; n--) {
       cin.putback(line[n]);
    }
    if (line.length()==1 && line[0] == ESC) {
            return Named_special_key {"Escape", {ESC}};
    }
    else {
        kbc1 = static_cast<unsigned char>(line[0]);
        // todo: need to allow getline to pull the next characters without having to type <ENTER> again, until we are out of chars, and more are entered.
    }
#endif
#ifdef CIN_GTGT
    cin >> kbc1;
#endif
#ifdef	CIN_GET
    char ch;
    cin.get(ch);
    cin.get(*(char*)&kbc1); // todo: TODO why can't I cast this?
    cin.get(*reinterpret_cast<char*>(&kbc1)); // todo: TODO why can't I cast this?
    kbc1 = ch;
#endif
    if (cin.eof()) return { {}, File_status::eof };

    if ( kbc1 == ESC ) { // ESC, or longer sequence.
//        std::array<char,2> test {0,0}; //todo: hack to see if another key is waiting related to other hack above.
//        auto num_read = cin.readsome(&test[0],1);
//        if (num_read == 1) {
//            cin.putback(test[0]);
//        }
//        else {
//            return Named_special_key {"Escape", {ESC}};
//        }
        if (auto variant = which_esc_sequence( hot_keys ); std::holds_alternative<Hot_key>(variant)) {
            return { std::get<Hot_key>(variant), File_status::other } ;
        }
        else { 		// got no additional result
            return { Hot_key {"Escape", {ESC} }, std::get<File_status>(variant)} ;
        }
    }
    else
        return { kbc1, File_status::other };
};

Value_plus get_value_raw() {
    std::string 	value {};
    Simple_key_char skc {};
    Hot_key 		hk {};
    bool 			is_char {false};
    bool 			is_hk   {false};
    bool 			is_eof 	{false};

    Kb_key_a_fstat r = get_kb_key();
    if ( std::holds_alternative< Simple_key_char >( *(r.first))) {
        skc = std::get < Simple_key_char >(*r.first);
        is_char = true;
        value += skc;
        cout << "Got a regular KB_char: "<< static_cast<int>(skc) <<endl;
    }
    if ( std::holds_alternative< Hot_key > ( *(r.first))) {
        Hot_key hk = std::get < Hot_key >(*r.first);
        is_hk = true;
        cout << "Got a Named_special_key: "<<hk.name<<endl;
        // take action based on which named special key it is.
        return {{}, hk, r.second};
    }
    if ( is_hk || r.second == File_status::eof ) {
        cout << "Got a EOF."<<endl;
        return {{}, hk, r.second};
    }

    while ( true ){
        // gather chars to make a value
        r = get_kb_key();
        if ( std::holds_alternative< Simple_key_char >( *(r.first))) {
            skc = std::get < Simple_key_char >(*r.first);
            is_char = true;
            cout << "Got a regular KB_char: "<< static_cast<int>(skc) <<endl;
        }
        if ( std::holds_alternative< Hot_key > ( *(r.first))) {
            Hot_key hk = std::get < Hot_key >(*r.first);
            is_hk = true;
            cout << "Got a Named_special_key: "<<hk.name<<endl;
            // take action based on which named special key it is.
        }

        if ( r.second == File_status::eof ) {
            cout << "Got a EOF."<<endl;
        }


        if ( is_hk || r.second == File_status::eof ) {
            return { value, hk, r.second};
        }

        if (is_char) value += skc;

        is_char = false;
        is_hk = false;
        is_eof = false;
    }


};

int main()
{
    std::cout << "User-preferred locale setting is " << std::locale("").name().c_str() << endl;
    Termios terminal_status_save = termio_set_raw();

    // Part 1 = test keyboard
    // C++ style - shows \r as <10> and \t as <9>
    // char ch {}; while (!cin.eof()) { cin.get(ch); cout << "<<<"<<ch<<">>>, "<<static_cast<int>(ch)<<endl; }

    // C style   - shows \r as <10> and \t as <9> and EOF as -1.
    // FILE* file_ptr = fopen( stdin ,"r" );
    // int ch {}; while (ch!=-1) { ch = getc(stdin); cout << "<<<"<<ch<<">>>, "<<ch<<endl; }

    // POSIX? style - using C headers.
    char ch {};
    int char_int {};
    int result {};

    while (char_int != -1) { char_int = getc(stdin); cout << "<"<<char_int<<">, "<<(int)char_int<<endl; } // all keys captured.
    // while (!cin.eof()) { cin.get(ch); cout << "<<<"<<ch<<">>>, "<<static_cast<int>(ch)<<endl; } // all keys captured.
    // while (!cin.eof()) { cin>>ch; cout << "<<<"<<ch<<">>>, "<<static_cast<int>(ch)<<endl; } // tab and Enter suppressed.

    // Part 2 test key identification logic
    while ( true ) {
        auto [value, hot_key, file_status] = get_value_raw();
        cout << "value,hot_key,file_status: "<<value<< ","<<hot_key.name<<","<<(int)file_status<<endl;
        if (file_status == File_status::eof) exit(0);
    }

    termio_restore( terminal_status_save );
    cout << "###" << endl;
    return 0;
}
