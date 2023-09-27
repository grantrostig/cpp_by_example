/* file used in development of lib_tty - retain for history */
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <variant>
#include <optional>
#include <any>
#include <functional>
#include <cassert>
#include <locale>
// #include <ios>

using std::cin, std::cout, std::cerr, std::endl;

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
 */

enum class Data_type {
    intr,
    intrl,
    dec,
    decl,
    fp,
    fpl,
    alphanum,
    alphanum_bin,
    charr,
    booln,
    time,
    date,
    d_time
};

enum class Field_type {
    text,
    text_box,
    date,
    check_box,
    radio_button_group,
    drop_down_single,
    drop_down_multiple,
    search_box_interactive,
    hidden_todo,
};

enum class input_validation {
    length,
    length_unlimited,
    hot_key // like the arrow keys or ESC or TAB, or CTRL-S
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
    int 		a {2};
    int 		a2 {4};
    float 		b {3};
    std::string c {"data_row_init_string"};
    char		d {'a'};
    std::byte 	e {'b'};
    bool 		f {true};
};

struct Data_type_spec_integer {
    Data_type data_type {Data_type::dec};
    uint precision;
    double min_value;  // todo: make c++ correct
    double max_value;  // todo: make c++ correct
};

struct Co_ord {
    uint x {1}, y {2}, z {3};  // allows for 2D or 3D, but not yet implemented.
};

struct Ordering {
    // the order in which the component appears on input or ouput.
    std::byte major {};
    std::byte minor {};
    std::byte s_minor {};
    std::byte ss_minor {};
};

enum class Input_result {
    re_enter,
    re_display,
    success,
    eof,
    fail // todo: this probably should be a throw?
};

struct Field_input_spec {
    Field_type field_type {Field_type::text};
    Data_type data_type   {Data_type::alphanum};
    void * variable_p; // type must correspond to the 'type' of "data_type" in this class.
    std::any variable_by_ref; // type must correspond to the 'type' of "data_type" in this class. todo:TODO instead of void *
    std::string prompt {"FIXME: input_prompt."};
    uint length_min {1};
    uint length_max {64};
    Co_ord co_ord_prompt {};  // todo: why not all zeros?
    Co_ord co_ord_input;      // todo: is this initialized properly? seems to be based on default values in the struct.
    std::string input_sample_value {""}; // what is visible when user first sees field, "(000)000-0000" or "enter name here"
    std::string default_value {""};  // what value is used if user skips field or enters "".
    std::string allowable_vals {""};
    std::string regex_pattern {""};  // could incorporate the min/max length, but that would be complicated?
    bool optional {false};  // what is difference between "" and NULL and <default>?
    bool null_able {false};  // what is difference between "" and NULL and <default>?
    bool trim_leading_ws {true};
    bool trim_trailing_ws {true};
    std::function<int(std::string)> input_validation_fn {};
    std::function<int(std::string)> output_validation_fn {};
};

struct Field_output_spec {
    // todo
};

struct Field_block {
    std::string name {"FIXME:default_field_block."};
    std::vector< Field_input_spec > fields_in;  // everything about how to input a field
    std::vector< Field_output_spec > fields_out;  // everything about how to output a field, probably similar to input.
    std::vector< Ordering > field_orderings_in;  // the ordering of the fields when they are input in the context of this block.
    std::vector< Ordering > field_orderings_out;  // the ordering of the fields when they are output in the context of this block, probably similar to input
    Ordering ordering_in;
    Ordering ordering_out;
};

struct Page_block {
};

struct Form_block {
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

/* linux keyboard mappings
 * TAB: 	 ws
 * ESC:		 27
 * F1:		 27,79,80
 * Delete:   27,91,51,126
 * Shift-TAB:27,91,90
 */

void get_kb_ch_input() {
    char ch {};
    cin >> ch;		 // does not capture the <RETURN> or any other character that might have been typed after the first one.
    if (ch == 0 );
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

void prompt_field( Field_input_spec & fi) {
    cout<<fi.prompt<<" "<<std::flush;
}

std::string output_field_to_string( Field_input_spec & fi){
    std::string out_str2;
    switch (fi.data_type) {
    case Data_type::alphanum:
        // out_str = *static_cast< std::string * > (fi.variable_p);
        // out_str = std::any_cast< std::string > (fi.variable_object);
        out_str2 = std::any_cast< std::reference_wrapper<std::string>> ( fi.variable_by_ref);
        break;
    case Data_type::alphanum_bin:
        assert(false);
        break;
    case Data_type::booln:
        if ( std::any_cast< std::reference_wrapper<bool>> ( fi.variable_by_ref) == true )
             out_str2 = "true";
        else out_str2 = "false";
        break;
    case Data_type::date:
    case Data_type::time:
    case Data_type::d_time:
        assert(false);
        break;
    default: // all numeric types
        // int
        // out_str = std::to_string( std::any_cast< int >( fi.variable_object));
        // out_str = std::to_string( *(int*)(fi.variable_p));
        // out_str = std::to_string( *static_cast< int * >( fi.variable_p));
        out_str2 = std::to_string( std::any_cast< std::reference_wrapper<int>> ( fi.variable_by_ref));
        break;
    }
    return out_str2;
}

std::string convert_output_format_to_input( Field_input_spec & fi, std::string input_line) {
    if (fi.data_type == Data_type::booln) {  // todo: this is an ugly hack.
        if ( input_line == "true" ) {
            input_line = "T";
            return "T";
        }
        if ( input_line == "false" ) {
            input_line = "F";
            return "F";
        }
    }
    return output_field_to_string( fi );
}

Input_result input_field_once( Field_input_spec & fi) {
    std::string input_line {};
    if (output_field_to_string( fi ).size()!=0 ) {  // existing value in target data structure, so offer it to user.
        cout << output_field_to_string(fi);
        for (size_t i = 0; i < output_field_to_string( fi ).size(); ++i) cout << '\b';  // place the cursor over the value
    } else if (fi.input_sample_value.size()!=0 ) {  // else show a sample value, if available.
        cout << fi.input_sample_value;
        for (size_t i = 0; i < fi.input_sample_value.size(); ++i) cout << '\b';    // place the cursor over the value
    }
    try { // todo: remote possibility this could be so large as to cause memory allocation problem.
        auto & r = getline(cin, input_line);
        if (r.eof()) return Input_result::eof;
    } catch (std::bad_alloc) {
        // could use std::istream::getline() instead of try{}, but then I would have to allocate a fixed size array of chars for the maximum size.
        cerr << "input ERROR: input too large.\n";
        return Input_result::re_enter;
    }
    if ( input_line.size()==0 ) {  // user pressed only <Enter>
        if ( output_field_to_string( fi ).size() !=0 )  // we have an existing value so load that.
            input_line = convert_output_format_to_input( fi, output_field_to_string( fi ) );
        else input_line = fi.default_value; // no existing, so use default, which might also be zero length.
    }

    if ( fi.trim_leading_ws )  input_line.erase( 0, input_line.find_first_not_of( "\t\n\r\f\v") );
    if ( fi.trim_trailing_ws ) input_line.erase( input_line.find_last_not_of( "\t\n\r\f\v") + 1 );
    if ( input_line.length() < fi.length_min) {
        cout << "Error: input has too few characters."<<endl;
        return Input_result::re_enter;
    }
    if ( input_line.length() > fi.length_max) {
        cout << "Error: input has too many characters."<<endl;
        return Input_result::re_enter;
    }

    switch (fi.data_type) {
    case Data_type::alphanum:
        std::any_cast< std::reference_wrapper<std::string> >(fi.variable_by_ref).get() = input_line;
        break;
    case Data_type::alphanum_bin:
        assert(false);
        break;
    case Data_type::booln:
        if (input_line.find_first_not_of("YyNnTtFf") != std::string::npos) {
            return Input_result::re_enter;
        } // else success
        if (input_line.find_first_of("YyTt") != std::string::npos)
            std::any_cast< std::reference_wrapper<bool> >(fi.variable_by_ref).get() = true;
        else
            std::any_cast< std::reference_wrapper<bool> >(fi.variable_by_ref).get() = false;
        break;
    case Data_type::date:
    case Data_type::time:
    case Data_type::d_time:
        assert(false);
        break;
    default: // all numeric types // todo: consider using .type to figure out what type to input or output, but that would be RTTI?
        int int_val {};
        try {
            int_val = stoi(input_line);
        }
        catch (std::out_of_range e) {
            cerr << "Input ERROR: value is outside of valid range\n";  // todo: what happens with unsigned int, if neg value is given?
            return Input_result::re_enter;
        }
        catch (std::invalid_argument e) {
            cerr << "Input ERROR: is not a valid number.\n";
            return Input_result::re_enter;
        }
        std::any_cast< std::reference_wrapper<int> >( fi.variable_by_ref ).get() = int_val;
        break;
    }
    return Input_result::success;
}

Input_result input_field (Field_input_spec & fi) {
    while (true) {
        prompt_field( fi );
        Input_result r = input_field_once( fi );
        switch (r) {
        case Input_result::re_enter:
            break;  // the case, but do go round the loop.
        case Input_result::re_display:
            // todo: re display means what? and do we return too?
            return r;
        case Input_result::success:
        case Input_result::eof:
        case Input_result::fail:
            return r;
        }
    }
}

Input_result input_block(Field_block & fb) {
    for (auto f = fb.fields_in.begin(); f != fb.fields_in.end(); ++f) {
        Input_result r = input_field(  *f );
        switch (r) {
        case Input_result::re_enter:
            assert(false);
            break;
        case Input_result::re_display:
        case Input_result::success:
            break;
        case Input_result::eof:
        case Input_result::fail:
            return r;
        }
        cout << "<"<<output_field_to_string( *f )<<">"<<endl;;
    }
    return Input_result::success;
}

int main() {
    std::string r = std::locale("").name(); // auto r = std::locale("").name().c_str();  // todo: why print out .c_str instead as show on cppref?
    std::cout << "User-preferred locale setting is " << r << endl;
    try { std::locale::global(std::locale("C.UTF-8")); } catch (...) { // todo: doesn't appear to work!
        std::cout << "Falling back to \"C\" locale.\n"<< endl;;
        std::locale::global(std::locale("C"));
    }
    std::locale::global(std::locale("C"));  // doesn't appear to be setting the global, or global is not the same as default?
    std::cout << "todo: Is this the current locale setting? or how to do? " << std::locale("").name() << endl;
    while (true) {
        Data_row data_row;
        Field_block fb;
        { // new scope only to control scope of fis and allow copy past of the creation of each fis
            Field_input_spec fis {};
            fis.data_type = Data_type::intr;
            fis.variable_by_ref = std::reference_wrapper<int>(data_row.a);
            fis.variable_p = &data_row.a2;
            fis.prompt = "enter an int:";
            fis.input_sample_value = "<int goes here>";
            fb.fields_in.emplace_back( fis );  // todo:  does this really move the df object?  Instrumentation.
        }

        fb.fields_in.emplace_back( Field_input_spec
            { Field_type::text, Data_type::alphanum, nullptr, std::reference_wrapper<std::string>(data_row.c), "enter, type any non-special keys:", 1, 64, {0,0,0}, {0,0,0}, "<type any non special keys here>" });

        Field_input_spec fis { Field_type::text, Data_type::booln, nullptr, std::reference_wrapper<bool>(data_row.f), "enter, 'y' if you like this program, otherwise 'n' (default:Y):", 0, 1, {0,0,0}, {0,0,0}, "<enter one of: Y/y/N/n>", "T", "YnNnTtFf" };
        fb.fields_in.emplace_back( fis);

        Input_result r = input_block( fb );
        if (r == Input_result::eof) break;

        cout << "\nContent of data_row:\n" << data_row.a << endl;
        cout << data_row.a2 << endl;
        cout << data_row.b << endl;
        cout << data_row.c << endl;
        cout << data_row.d << endl;
        cout << static_cast<int>(data_row.e) << endl;
        cout << data_row.f << endl;

        cout << "input_block done." << endl;
        cout << "..." << endl;
    }
    cout << "###" << endl;
    return 0;
}
