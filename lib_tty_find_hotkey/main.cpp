/* file used in development of lib_tty using goto - retain for history
 * Generated as part of the password manager effort.
 * Used to test lib_tty.
 *
 * Copyright 2019 Grant Rostig all rights reserved,
 * no rights granted to anyone at this time,
 * no license granted to anyone at this time,
 * except to use during CppMSG meetings during 2021.
 *
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <variant>
#include "../../lib_tty/lib_tty.h"
using namespace std;
using namespace Lib_tty;

template<typename T>            // utility f() to print vectors
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '<';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, "&"));
        // out << "\b\b]";
        out << ">";
    }
    return out;
}

void print_vec( const std::vector<char> & v) {
    cout << "::";
    for (auto /* const */ & i: v) {
        cout << std::setw(3) << (int)i << "&";
    }
    cout << "\b::";
}

using Find_hot_key_rv = std::variant< std::monostate, int, Lib_tty::Hot_key >;

/*struct Record {
int a {};
int b {};
bool operator< (const Record& in) const {
    return ( b < in.b );
}
};

struct Record2 {
int a {99};
vector<char> b {};
bool operator< (const Record2& in) const {
    return ( b < in.b );
}*/

bool is_hk_chars_equal( Lib_tty::Hot_key const & left, Lib_tty::Hot_key const & right ) {
    return ( left.characters == right.characters );
}

Find_hot_key_rv find_kb_key ( Hot_key_chars const & candidate_hk_chars ) {
    static const Lib_tty::Ascii_Posix_map ascii_posix_map {  // todo: locked every invocation.  TODO why no constexpr  is it the vector?
        //ascii_id, ascii_name,        posix_id, ascii_ctrl+,  \+, ascii_char, posix_char
        {"NUL", "Null",					"EOL", 		'@',	{},		0,	0},   // [ctl-spacebar does this!] (typically, ASCII NUL) is an additional line delimiter, like the NL character. EOL is not normally used. // If ICANON is set, the EOL character is recognized and acts as a special character on input (see ``Local modes and line disciplines'' in termio(M)).  probably of not used or even available as a char from a PC or any type of keyboard?!
        {"SOH",	"start_of_heading",		"???", 	    'a',	{},		1,	1},   //
        {"STX",	"start_of_text",		"???",	 	'b',	{},		2,	2},   //
        {"ETX",	"end_of_text",			"INTR", 	'c',	{},		3,	3},   // interrupt/stop the program / paste (from copy-paste)?/-SIGINT
        {"EOT",	"end_of_transmission",	"EOF",		'd',  	{}, 	4,	4},   // I perfer to call this "end of file", apparently this is a ascii character char when in POSIX raw mode tty.
        {"ENQ",	"Enquiry",				"???",		'e',  	{}, 	5,	5},   //
        {"ACK",	"Acknowledgement",		"???",		'f',  	{}, 	6,	6},   //
        {"BEL",	"bell",					"BELL?",	'g', 	'a',	7,	7},   // todo: NOT IMPLEMENTED in hot_keys // Ctrl-g = \a  alert?
        {"BS",	"backspace",		 	"BS",		'h',	'b',	8,	8},   // todo: NOT IMPLEMENTED in hot_keys // character erase character works on linux and DOS? Backspace on MacOS use DEL for ERASE?
        {"HT",	"horizontal_tab",		"TAB",		'i',	't',	9,	9},
        {"LF",	"line_feed",			"NL-LF",	'j',	'n',	10,	10},  // end the line. newline. NL posix normal line delimiter. On linux with ANSI keyboard this is "Enter" key, was "Return" on typewriters and old PCs? What about "CR"
        // EOF is \r\n or 13, 10, or CR,LF  https://www.ni.com/en-us/support/documentation/supplemental/21/labview-termination-characters.html
        {"VT",	"vertical_tab",			"VT?",		'k',	'v',	11,	11},  // todo: NOT IMPLEMENTED in hot_keys  // cursor down one line, like what one would call LF Line feed.
        {"FF",	"form_feed",			"FF?",		'l',	'f',	12,	12},  // todo: NOT IMPLEMENTED in hot_keys // redisplay page.
        {"CR",	"carriage_return",		"CR",		'm',	'r',	13,	13},  // CR note the 'r', end the line. DOS style LF/NL, but is two characters: \n\r?
        {"SO",	"shift_out",			"???",		'n',	{},		14,	14},  //
        {"SI",	"shift_in",				"DISCARD",	'o',	{},		15,	15},  //
        {"CR",	"carriage_return",		"???",		'p',	{},		16,	16},  //
        {"DC1",	"device_control_1/XON",	"START",	'q',	{},		17,	17},  // todo: NOT IMPLEMENTED in hot_keys // resume tty output  IXON is a tty setting not a character!
        {"DC2",	"device_control_2",		"REPRINT",	'r',	{},		18,	18},  // todo: NOT IMPLEMENTED in hot_keys // redraw the current line.
        {"DC3", "device_control_3/XOFF","STOP",	's',	{},		19,	19},  // todo: NOT IMPLEMENTED in hot_keys // suspend tty output IXOFF is a tty setting not a character!
        {"DC4", "device_control_4",		"STATUS",	't',	{},		20,	20},  // todo: NOT IMPLEMENTED in hot_keys // on macOS and BSD.
        {"NAK",	"neg. acknowledge",		"KILL",		'u',	{},		21,	21},  // todo: NOT IMPLEMENTED in hot_keys // deletes entire line being typed. todo: "line erase character" kills the current input line when using the POSIX shell?
        {"SYNC","synchronous_idle",		"LNEXT",	'v',	{},		22,	22},  // todo: NOT IMPLEMENTED in hot_keys // paste (from copy-paste)?/
        {"ETB",	"end_of_tranmission_block","WERASE",'w',	{},		23,	23},  // todo: NOT IMPLEMENTED in hot_keys // erase the last word typed.
        {"CAN",	"cancel",				"CANCEL?",	'x',	{},		24,	24},  // todo: NOT IMPLEMENTED in hot_keys // cancel the input line? / cut (from copy-paste)? /
        {"EM",	"end_of_medium",		"???",		'y',	{},		25,	25},  //
        {"SUB",	"substitute",			"SUSP",		'z',	{},		26,	26},  // todo: NOT IMPLEMENTED in hot_keys //send a terminal stop signal. posix job-control: suspend process.  note: use "fg" to bring to foreground, "bg" to make it run in background.  AKA SIGSTOP?-SIGTSTP
        {"ESC",	"escape",				"ESC",		'[',	'e',	27,	27},  // ESC key, the first char of POSIX CSI Control Sequence Introducer
        {"FS",	"file_separator",		"QUIT",		'\\',	{},		28,	28},  // posix - nothing!?!, unix job-control: quit process and create a "core file". todo: TODO WARNING: may include current contents of memory??-SIGQUIT
        {"GS",	"group_separator",		"???",		']',	{},		29,	29},  //
        {"RS",	"record_separator",		"???",		'^',	{},		30,	30},  //
        {"US",	"unit_separator",		"???",		'_',	{},		31,	31},  //
        {"DEL",	"delete",				"ERASE",	'?',	{},	   127,127},  // erase the last character typed. similar to "BS" // todo: NOT IMPLEMENTED in hot_keys //  BS/ERASE on MacOS?
    };
    static Lib_tty::Hot_keys hot_keys {
        // my_name	     char sequence
        // first the single key char action keys that are the good old Unix shell standard.
        {"escape",		{find_posix_char_from_posix_name(ascii_posix_map, "ESC")},			HotKeyFunctionCat::navigation_esc,			FieldCompletionNav::esc,			 	FieldIntraNav::na},
        {"eof",			{find_posix_char_from_posix_name(ascii_posix_map, "EOF")}, 			HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::eof,			 	FieldIntraNav::na},
        {"quit",		{find_posix_char_from_posix_name(ascii_posix_map, "QUIT")}, 		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::quit_signal,		FieldIntraNav::na},
        {"interrupt",	{find_posix_char_from_posix_name(ascii_posix_map, "INTR")},			HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::quit_signal,		FieldIntraNav::na},

        {"tab",			{find_posix_char_from_posix_name(ascii_posix_map, "TAB")},   		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::skip_one_field, 	FieldIntraNav::na},

        {"CR-CTL-M",    {find_posix_char_from_posix_name(ascii_posix_map, "CR")}, 			HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::down_one_field, 	FieldIntraNav::na},
        {"LF-CTL-J",	{find_posix_char_from_posix_name(ascii_posix_map, "NL-LF")},		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::down_one_field, 	FieldIntraNav::na},

        {"kill",		{find_posix_char_from_posix_name(ascii_posix_map, "KILL")},			HotKeyFunctionCat::nav_intra_field,			FieldCompletionNav::na,		 			FieldIntraNav::kill},
        {"backspace_left_erase",
            {find_posix_char_from_posix_name(ascii_posix_map, "BS")},			HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na,					FieldIntraNav::backspace_left_erase},
        {"erase_left",  {find_posix_char_from_posix_name(ascii_posix_map, "ERASE")},		HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na,					FieldIntraNav::erase_left},  // todo: is this correct for macOS or Linux or PC??

        // Secondly the multicharacter ESC sequences for the XTERM initially and then VT100 or ANSI.SYS? keyboard, which might be different as in "termcap" on some other hardware.
        // XTERM https://en.wikipedia.org/wiki/ANSI_escape_code#Terminal_input_sequences
        {"f1",			{CSI_ESC,'O','P'}, 				HotKeyFunctionCat::help_popup, 				FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f2",			{CSI_ESC,'O','Q'}, 				HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f3",			{CSI_ESC,'O','R'}, 				HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f4",			{CSI_ESC,'O','S'}, 				HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"up_arrow",	{CSI_ESC,'[','A'}, 				HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::browse_up, 		FieldIntraNav::na},
        {"down_arrow",	{CSI_ESC,'[','B'}, 				HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::browse_down, 	FieldIntraNav::na},
        {"right_arrow",	{CSI_ESC,'[','C'}, 				HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::move_right},
        {"left_arrow",	{CSI_ESC,'[','D'}, 				HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::move_left},
        {"end",			{CSI_ESC,'[','F'}, 				HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::goto_end},
        {"key_pad_5",	{CSI_ESC,'[','G'}, 				HotKeyFunctionCat::na,			 		FieldCompletionNav::na, 			FieldIntraNav::na},
        {"home",		{CSI_ESC,'[','H'}, 				HotKeyFunctionCat::nav_intra_field,			FieldCompletionNav::na,			 	FieldIntraNav::goto_begin},
        {"shift-tab",	{CSI_ESC,'[','Z'}, 				HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::up_one_field, 	FieldIntraNav::na},
        // VT100/220
        {"insert",		{CSI_ESC,'[','2','~'}, 			HotKeyFunctionCat::editing_mode,			FieldCompletionNav::na,			 	FieldIntraNav::na},
        {"delete",		{CSI_ESC,'[','3','~'}, 			HotKeyFunctionCat::nav_intra_field,			FieldCompletionNav::na, 			FieldIntraNav::delete_char},
        {"pageup",	  	{CSI_ESC,'[','5','~'}, 			HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::page_up,		FieldIntraNav::na},
        {"pagedown",	{CSI_ESC,'[','6','~'}, 			HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::page_down,		FieldIntraNav::na},
        {"f5",			{CSI_ESC,'[','1','5','~'}, 		HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f6",			{CSI_ESC,'[','1','7','~'}, 		HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // note skipped 54 '6'
        {"f7",			{CSI_ESC,'[','1','8','~'}, 		HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f8",			{CSI_ESC,'[','1','9','~'}, 		HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f9",			{CSI_ESC,'[','2','0','~'}, 		HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f10",			{CSI_ESC,'[','2','1','~'}, 		HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // todo: is this like ESC or EOF_CHAR?
        {"f11",			{CSI_ESC,'[','2','3','~'}, 		HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // note skipped 50
        {"f12",			{CSI_ESC,'[','2','4','~'},  	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        // VT100/220, but not on USA PC AT keyboard
        {"f13",			{CSI_ESC,'[','2','5','~'},  	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f14",			{CSI_ESC,'[','2','6','~'},  	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f15",			{CSI_ESC,'[','2','7','~'},  	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f16",			{CSI_ESC,'[','2','8','~'},  	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f17",			{CSI_ESC,'[','3','1','~'},  	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f18",			{CSI_ESC,'[','3','2','~'},  	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f19",			{CSI_ESC,'[','3','3','~'},  	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"f20",			{CSI_ESC,'[','3','4','~'},  	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        // ;2 is shift
        //{"shf-insert",	{CSI_ESC,'[','2',	 ';','2','~'}, 	HotKeyFunctionCat::editing_mode,			FieldCompletionNav::na,			 	FieldIntraNav::na},
        {"shf-delete",		{CSI_ESC,'[','3', 	 ';','2','~'},	HotKeyFunctionCat::nav_intra_field,			FieldCompletionNav::na, 			FieldIntraNav::delete_char},
        //{"shf-pageup",	{CSI_ESC,'[','5',    ';','2','~'}, 	HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::page_up,		FieldIntraNav::na},
        //{"shf-pagedown",	{CSI_ESC,'[','6',    ';','2','~'}, 	HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::page_down,		FieldIntraNav::na},
        {"shf-up_arrow",	{CSI_ESC,'[','1',    ';','2','A'},	HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::browse_up, 		FieldIntraNav::na},
        {"shf-down_arrow",	{CSI_ESC,'[','1',    ';','2','B'},	HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::browse_down, 	FieldIntraNav::na},
        {"shf-right_arrow",	{CSI_ESC,'[','1',    ';','2','C'},	HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::move_right},
        {"shf-left_arrow",	{CSI_ESC,'[','1',    ';','2','D'},	HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::move_left},
        //???{"shf-home",	{CSI_ESC,'[','1',    ';','2','H'}}, HotKeyFunctionCat::nav_intra_field,			FieldCompletionNav::na,			 	FieldIntraNav::goto_begin},
        //???{"shf-end",	{CSI_ESC,'[','1',    ';','2','F'}}, HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::goto_end},
        {"sht-f1",			{CSI_ESC,'[','1',    ';','2','P'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"sht-f2",			{CSI_ESC,'[','1',    ';','2','Q'}, 	HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // note skipped 54 '6'
        {"sht-f3",			{CSI_ESC,'[','1',    ';','2','R'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"sht-f4",			{CSI_ESC,'[','1',    ';','2','S'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"sht-f5",			{CSI_ESC,'[','1','5',';','2','~'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"sht-f6",			{CSI_ESC,'[','1','7',';','2','~'}, 	HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // note skipped 54 '6'
        {"sht-f7",			{CSI_ESC,'[','1','8',';','2','~'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"sht-f8",			{CSI_ESC,'[','1','9',';','2','~'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"sht-f9",			{CSI_ESC,'[','2','0',';','2','~'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        //???{"sht-f10",	{CSI_ESC,'[','2','1',';','2','~'}, 	HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // todo: is this like ESC or EOF_CHAR?
        {"sht-f11",			{CSI_ESC,'[','2','3',';','2','~'}, 	HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // note skipped 50
        {"sht-f12",			{CSI_ESC,'[','2','4',';','2','~'},  HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        // shift-keypad_key's is just like "NumLock", you get the numbers, not the arrows etc., ie. like shift for the keypad. This may be false!
        {"shf-key_pad_5",	{'5'},				 				HotKeyFunctionCat::na,			 		FieldCompletionNav::na, 			FieldIntraNav::na},
        // ;5 is ctl
        //{"ctl-insert",	{CSI_ESC,'[','2',';','5','~'}, 		HotKeyFunctionCat::editing_mode,			FieldCompletionNav::na,			 	FieldIntraNav::na},
        {"ctl-delete",		{CSI_ESC,'[','3',';','5','~'}, 		HotKeyFunctionCat::nav_intra_field,			FieldCompletionNav::na, 			FieldIntraNav::delete_char},
        {"ctl-pageup",		{CSI_ESC,'[','5',';','5','~'}, 		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::page_up,		FieldIntraNav::na},
        {"ctl-pagedown",	{CSI_ESC,'[','6',';','5','~'}, 		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::page_down,		FieldIntraNav::na},
        {"ctl-up_arrow",	{CSI_ESC,'[','1',';','5','A'},		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::browse_up, 		FieldIntraNav::na},
        {"ctl-down_arrow",	{CSI_ESC,'[','1',';','5','B'},		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::browse_down, 	FieldIntraNav::na},
        {"ctl-right_arrow",	{CSI_ESC,'[','1',';','5','C'},		HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::move_right},
        {"ctl-left_arrow",	{CSI_ESC,'[','1',';','5','D'},		HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::move_left},
        //???{"ctl-home",	{CSI_ESC,'[','1',    ';','5','H'}}, 					HotKeyFunctionCat::nav_intra_field,			FieldCompletionNav::na,			 	FieldIntraNav::goto_begin},
        //???{"ctl-end",	{CSI_ESC,'[','1',    ';','5','F'}}, 					HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::goto_end},
        {"ctl-f1",			{CSI_ESC,'[','1',    ';','5','P'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"ctl-f2",			{CSI_ESC,'[','1',    ';','5','Q'}, 	HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // note skipped 54 '6'
        {"ctl-f3",			{CSI_ESC,'[','1',    ';','5','R'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"ctl-f4",			{CSI_ESC,'[','1',    ';','5','S'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"ctl-f5",			{CSI_ESC,'[','1','5',';','5','~'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"ctl-f6",			{CSI_ESC,'[','1','7',';','5','~'}, 	HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // note skipped 54 '6'
        {"ctl-f7",			{CSI_ESC,'[','1','8',';','5','~'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"ctl-f8",			{CSI_ESC,'[','1','9',';','5','~'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        {"ctl-f9",			{CSI_ESC,'[','2','0',';','5','~'}, 	HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},
        //{"ctl-f10",		{CSI_ESC,'[','2','1',';','5','~'}, 	HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // todo: is this like ESC or EOF_CHAR?
        {"ctl-f11",			{CSI_ESC,'[','2','3',';','5','~'}, 	HotKeyFunctionCat::na, 					FieldCompletionNav::na, 			FieldIntraNav::na}, // note skipped 50
        {"ctl-f12",			{CSI_ESC,'[','2','4',';','5','~'},  HotKeyFunctionCat::na,					FieldCompletionNav::na, 			FieldIntraNav::na},

        // ;3 is alt
        {"alt-insert",		{CSI_ESC,'[','2',';','3','~'}, 		HotKeyFunctionCat::editing_mode,			FieldCompletionNav::na,			 	FieldIntraNav::na},
        {"alt-delete",		{CSI_ESC,'[','3',';','3','~'}, 		HotKeyFunctionCat::nav_intra_field,			FieldCompletionNav::na, 			FieldIntraNav::delete_char},
        {"alt-pageup",		{CSI_ESC,'[','5',';','3','~'}, 		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::page_up,		FieldIntraNav::na},
        {"alt-pagedown",	{CSI_ESC,'[','6',';','3','~'}, 		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::page_down,		FieldIntraNav::na},
        {"alt-up_arrow",	{CSI_ESC,'[','1',';','3','A'},		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::browse_up, 		FieldIntraNav::na},
        {"alt-down_arrow",	{CSI_ESC,'[','1',';','3','B'},		HotKeyFunctionCat::nav_field_completion,	FieldCompletionNav::browse_down, 	FieldIntraNav::na},
        {"alt-right_arrow",	{CSI_ESC,'[','1',';','3','C'},		HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::move_right},
        {"alt-left_arrow",	{CSI_ESC,'[','1',';','3','D'},		HotKeyFunctionCat::nav_intra_field, 		FieldCompletionNav::na, 			FieldIntraNav::move_left},
    };
                                                // std::sort( hot_keys.begin(), hot_keys.end(), [] ( Hot_key &left, Hot_key &right) { return (left.characters < right.characters); } );
    if (static bool once {false}; !once) {
        once = true;
        if ( hot_keys.empty() )
            assert( ("lib_tty logic error: we don't allow empty hotkeys",false) );
        std::sort( hot_keys.begin(), hot_keys.end() );
        if ( auto dup = std::adjacent_find( hot_keys.begin(), hot_keys.end(), is_hk_chars_equal ); dup != hot_keys.end() ) {
            cerr << "duplicate hot_key:" << dup->my_name << endl;
            assert( ("lib_tty logic error: we don't allow duplicate hotkey character sequences",false) );
        }
        for (auto & i : hot_keys) {
            cout << std::setw(18) << i.my_name;
            print_vec(i.characters);
            cout << endl;
        }
        cout << "\b\b. " << endl;
    }
    cout << "candidate_hk_chars: "; print_vec(candidate_hk_chars); cout << "." << endl;
    Hot_key const candidate_hk { {}, candidate_hk_chars };
                                                        //auto const [ lower_bound_itr, upper_bound_itr ] = std::equal_range( hot_keys.begin(), hot_keys.end(), candidate_hk );
    auto const lower_bound_itr = std::lower_bound( hot_keys.begin(), hot_keys.end(), candidate_hk );
    cout << "find_hot_key2():" << lower_bound_itr->my_name; print_vec(lower_bound_itr->characters); cout << "." << endl;
                                                        // enum class Search_result { no_match, partial_match, full_match } search_result { Search_result::no_match }; // Not needed.
                                                        // bool const prior_possible_partial_match  	{ lower_bound_itr == hot_keys.end() }; 		    // no full match OR empty container // Not needed.
                                                        // bool const no_prior_entry          		 	{ lower_bound_itr == hot_keys.begin() }; 		// no prior entry // Not needed.
    bool const no_match_end  		{ lower_bound_itr == hot_keys.end() }; // due to the fact we skipped all values, we have one, of several reasons for, no match.
                                                        //if ( std::equal( std::prev(lower_bound_itr)->characters, candidate_hk_chars.begin(), candidate_hk_chars.back(), std::prev(lower_bound_itr)->characters.size() ) { 	    // PROBABLY WRONG.
    bool const partial_match 		{ !no_match_end &&
                                      std::equal( candidate_hk_chars.begin(),	// not the same as == since length of candidate is not length of hot_key
                                                  candidate_hk_chars.end(),
                                                  lower_bound_itr->characters.begin(),
                                                  std::next( lower_bound_itr->characters.begin(), candidate_hk_chars.size() ) )  // check at most the min of both lengths.
                                    };
    bool const full_match 			{ partial_match &&
                                      lower_bound_itr->characters.size() == candidate_hk_chars.size()
                                    };
    // *** NOTE: we still might not have a match.  The if below determines final determination of no_match.
    if      ( full_match )    return *lower_bound_itr;
    else if ( partial_match ) return {};
    return    E_NO_MATCH;
}

void print_answer( Find_hot_key_rv const & rv1 ) {
    if ( std::holds_alternative<Hot_key>(rv1) ) {
        cout << "found key:" << std::get<Hot_key>(rv1).my_name << endl;
    } else if ( std::holds_alternative<int>(rv1) )
        cout << "error #:" << std::get<int>(rv1) << endl;
    else
        cout << "partial_match:" << endl;
}

int main() {
        /*  ***** demonstrate how sort handles less_than() or operator()
        Record a {3,3}, b {2,2}, c {99,99};
        bool compare = a < c;
        cout << "record:" << compare << endl;
        vector<Record> vec {a,b,c};
        sort(vec.begin(), vec.end());
        cout << "sort:";
        for ( auto i : vec ) cout << i.a <<",";
        cout << endl;
        Record2 a2 {3,{'a','b','c'}};
        Record2 b2 {2,{'a','a','a'}};
        Record2 c2 {99,{'a','z','z'}};
        compare = a2 < c2;
        cout << "record2:" << compare << endl;
        vector<Record2> vec2 {a2,b2,c2};
        sort(vec2.begin(), vec2.end());
        cout << "sort2:";
        for ( auto i : vec2 ) cout << i.a <<",";
        cout << endl;
        */
    print_answer( find_kb_key( {CSI_ESC,'[','C'} ));
    print_answer( find_kb_key( {CSI_ESC,'?','?'} ));
    print_answer( find_kb_key( {CSI_ESC,'['} ));
    print_answer( find_kb_key( {CSI_ESC,91,91} ));
    cout << "###" << endl;
    exit( 0 );
}
