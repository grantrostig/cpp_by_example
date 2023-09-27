/* file used in development of lib_tty using goto - retain for history */
#include <iostream>
#include <string>
#include <array>
#include <variant>
#include <optional>
// #include <locale>
// #include <ios>

using std::cin, std::cout, std::endl;

/* Demonstration Program
  * Purposes:
  *
  * To test the capture of the intent of a user in response to a prompt by the system.
 *
 * Possible prompts:
 * 	  Primary intent to be satisfied by the user:
 * +) alpha numeric
 * +) numeric
 * +) various special formatted inputs such as date or phone number
 *    Secondary intents:
 * +)
 *
 * Possible user reply intents:
 * +) satisfy prompt by providing the value
 * +) reprompt, and throw away anything typed for this prompt
 * +) provide help for this prompt
 * +) go back one prompt
 * +) exit menu selection
 * +) goto main menu
 * +) exit program
 * +) Save to disk:
 * 	+.1) all tentative entries are made permanent. Wizards state is saved to allow resumption on re-start of program.
 * 	+.2) state of program, including capturing and maintaining tentative entries, ie. in-progress wizards and unsaved added items.
 * +) print current page to the terminal (or a new window/terminal) or to disk, to printer, to std::err, to std::clog.
 *
 *
 *
 */

enum class Data_type {
    integer,
    integer_long,
    decimal,
    decimal_long,
    alphanumeric,
    character
};

struct valid_inputs {
    /*
    single character
        optional
        include candidates
        exclude candidates
        default?
    string
        optional
        default?
    number/precision/signed.
        optional
        default?
    universal_1_char_commands
    universal_commands
        skip to end/done
        back
        exit
        default?
            <TAB> key?
            <ESC> key?
            <CTRL-ENTER>?
     */
};

struct Data_row {
    int a;
    float b;
    std::string c;
    char d;
};

struct Data_type_spec_integer {
    Data_type data_type {Data_type::decimal};
    int precision;
    double min_value;  // todo: make c++ correct
    double max_value;  // todo: make c++ correct
};

struct Data_row_field_specification {
    Data_type data_type {Data_type::alphanumeric};
    bool optional {false};  // what is difference between "" and NULL and <default>?
    std::string pre_fill_value {};
    std::string default_value {};
    int length_min {1};
    int length_max {64};
    std::string regex_pattern {};  // could incorporate the min/max length, but that would be complicated?
    bool null_able {false};  // what is difference between "" and NULL and <default>?
};

std::optional<std::string> get_kb_line_input() {
    std::string input_line {};
    // cin >> std::ws;  // discard leading blanks.
    auto & ret = getline(cin >> std::ws, input_line);  // grabs the <RETURN> or the <CTRL-D> (ie. EOF)
    if (! ret.eof()) {  // todo: need to check more conditions and perhaps reset state or retry?  when do exceptions get thrown on the cin object?
        return input_line;
    }
    else {
        cout << "EOF." << endl;
        return {};
    }
    /* this form only works with an array of characters/char* (AKA char string)?  todo: why does this only exist for char*? wouldn't a max length be useful for string too?
    char 				ch_star[80];
    std::array<char,80> ch_array;
    // references widen(): https://en.cppreference.com/w/cpp/io/basic_istream/getline
    cin.getline(  ch_star,     80);  // grabs the <RETURN> or the <CTRL-D> (ie. EOF)
    cin.getline( &ch_array[0], 80);  // grabs the <RETURN> or the <CTRL-D> (ie. EOF)  // todo:  why [] needed?
    cin.getline(  ch_star,     80, '#');  // grabs the <RETURN> or the <CTRL-D> (ie. EOF)

    // todo: How to use the two types of widen()?
    // https://en.cppreference.com/w/cpp/io/basic_ios/widen
    // https://en.cppreference.com/w/cpp/locale/ctype/widen
    // Mountains p 1144

    // references widen(): https://en.cppreference.com/w/cpp/io/basic_istream/getline
    cin.getline( ch_star, 80, cin.widen('\n'));
    */
}

void get_kb_ch_input() {
    char ch {};
    cin >> ch;		 // does not capture the <RETURN> or any other character that might have been typed

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');  // flush all extra characters until EOL.
    cin >> std::ws;  // discards any whitespace and the <RETURN> if present
}

void input_menu_selection() {
    bool valid {false};
    do {
        get_kb_ch_input();
    } while (!valid);
    ;
}

/* try to get a value, or some other valid command.
 * repeat, unless valid command to stop trying.
 * get a series of values, but allow going back on the list use goto? */

std::variant<std::string, Data_row> get_series_of_inputs() {
    Data_row data_row {};
    std::optional<std::string> result {};  // must be declared at this scope to allow use of goto statement. :)
    bool invalid_values {true};
    while (invalid_values) {
        // set_form_default_values_except_passed_in_values();
data_member_a:
        while (true) {
            // if (no default value) set_field_default_value();  // todo: repeat for other input fields.
            cout << "Enter an interger for a:";
            if ((result = get_kb_line_input())) {
                std::string input_line = result.value();
                std::cerr << "{" << input_line << "}" << endl;
                try {
                    size_t position;
                    data_row.a = stoi(input_line, &position);
                    cout <<"val = "<<data_row.a<<", pos = "<<position<<endl;
                    break;
                }
                catch (std::invalid_argument e) {
                    // see if this is a universal_action, ie. quit, back, skip forward...
                    if (input_line.substr(0,1) == "\\") {
                        input_line = input_line.substr(1); // Test for a single '\' and then throw away the '\'.  note: \\ is a single \.
                        if (input_line.substr(0,1) == "H") cout << "Help: enter a number, or <\\B>, <\\E>. ";
                        if (input_line.substr(0,1) == "S") goto end_of_input;  // we don't require the \ when accepting an int
                        if (input_line.substr(0,1) == "R") {  /* reset input values to beginning state */
                            // clear_all_input_values(); // set_form_default_values_except_passed_in_values();
                            goto end_of_input;
                        };
                        if (input_line.substr(0,1) == "E") return "Exit";
                        if (input_line.substr(0,1) == "B") return "Back";
                    }
                }
                catch (std::out_of_range e) {
                    // just loop again
                }
                // catch (...) {}
            } else return "EOF";
        }
// todo: rework inputs below based on the rework done on above code.
data_member_b:
        while (true) {
            cout << "Enter an decimal for b:";
            if ((result = get_kb_line_input())) {
                std::string input_line = result.value();
                std::cerr << "{" << input_line << "}" << endl;
                try {
                    data_row.b = stof(input_line);
                    break;
                }
                catch (std::invalid_argument e) {
                    // see if this is a universal_action, ie. quit, back, skip forward...
                    if (input_line.substr(0,1) == "\\") input_line = input_line.substr(1); // throw away the '\'.
                    if (input_line.substr(0,1) == "S") goto end_of_input;  // we don't require the \ when accepting an int
                    if (input_line.substr(0,1) == "B") goto data_member_a;
                    if (input_line.substr(0,1) == "E") return "Exit";
                    if (input_line.substr(0,1) == "H") cout << "Help: enter a number, or <\\B>, <\\E>. ";
                }
                catch (std::out_of_range e) {
                    // just loop again
                }
                // catch (...) {}
            } else return "EOF";
        }

data_member_c:
        cout << "Enter string c:";
        if ((result = get_kb_line_input())) {
            std::string input_line = result.value();
            std::cerr << "{" << input_line << "}" << endl;
            // see if this is a universal_action, ie. quit, back, skip forward...
            if (input_line.substr(0,1) == "\\") {
                if (input_line.substr(1,1) == "S") goto end_of_input;
                if (input_line.substr(1,1) == "B") goto data_member_b;
                if (input_line.substr(1,1) == "E") return "Exit";
                if (input_line.substr(1,1) == "H") cout << "Help: enter some text, or <\\B>, <\\E>. ";
            }
            data_row.c = input_line ;
        } else return "EOF";  // todo: what is !result, other than EOF?

        // data_member_d
        cout << "Enter char d:";
        if ((result = get_kb_line_input())) {
            std::string input_line = result.value();
            std::cerr << "{" << input_line << "}" << endl;
            // see if this is a universal_action, ie. quit, back, skip forward...
            if (input_line.substr(0,1) == "\\") {
                if (input_line.substr(1,1) == "S") goto end_of_input;  // todo: logically should the program allow this?
                if (input_line.substr(1,1) == "B") goto data_member_c;
                if (input_line.substr(1,1) == "E") return "Exit";
                if (input_line.substr(1,1) == "H") cout << "Help: enter some text, or <\\B>, <\\E>. ";
            }
            data_row.c = input_line ;
        } else return "EOF";  // todo: what is !result, other than EOF?
        cout << "Enter char d:";
end_of_input:
        ;
    }

    cout << "Finshed getting the data row." << endl;
    return data_row;
}

int main()
{
    while (true) {
        auto result = get_series_of_inputs();
        if ( std::holds_alternative<std::string>( result ) ) {
            cout << std::get<std::string>( result ) << endl;
            if (std::get<std::string>( result ) == "Exit")
                break;
        }
        cout << "..." << endl;
    }
    cout << "###" << endl;
    return 0;
}
