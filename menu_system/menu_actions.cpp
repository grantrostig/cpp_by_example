#include <iostream>
#include <algorithm>
#include "lib_tty.h"
#include "menu.h"
#include "menu_actions.h"
#include "window_panel.h"
#include "interaction_result.h"
#include "action_dialog.h"

// #include "menu_option.h"

using std::cin, std::cout, std::endl, std::cerr;

// ---- Actions called by menu which are part of the menuing control system, not the general application.

InteractionResult action_save_work( State_menu & state) {
    cerr << "int action_save_work( State & state) {" << endl;
    // Save data even if we don't think it needs it.  Listen to the user!
    cerr << "saving application data: "<<state.getApplication_data()->int_data<<endl;
    cout << "Data saved."<<endl;
    state.getApplication_data()->setIs_data_saved(true);
    return { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_program_exit_with_prompts( State_menu & state) {
    cerr << "int action_program_exit( State & state) {" << endl;
    if (state.getIs_data_unsaved()) {
        // internal data structure, don't bother asking user about this!
        cerr << "saving menu system state: "<<endl;
    }
    if (state.getApplication_data()->getIs_data_saved()) {

//        char c {'Y'};
//        cout << "Save unsaved data? ("<<c<<"/n)";
//        cout.flush();
//        cin >> c;
//        cin.clear();
//        if (c == '\n' || c == 'Y' || c == 'y') {
//            action_save_work( state );
//        }
        if ( action_dialog_modal_approve(state, "Save unsaved data?") )
            action_save_work( state );
        else {
            std::string message {"Work not saved."};
            pagination_reset( state, { 1, message.length() });
            cout << "\n" << message << endl;
        }
    }
    return { {}, {}, InteractionResultNav::exit_pgm_immediately };
}

InteractionResult action_program_exit_immediately( State_menu const & ) {  // we might use it in later versions?
    cerr << "int action_program_exit_immediately( State & state) {" << endl;
    std::exit(0); // return { {}, {}, Action_post_return_navigation::exit_immediately };
}

InteractionResult action_go_back_up_menu( State_menu & state) {
    // go back up one levels of menu, only if we are not already at main menu.
    if ( state.is_menu_current_main() ) {
        cerr << "int action_go_back( State &): retain menu." << endl;
        return { {}, {}, InteractionResultNav::retain_menu };
    }
    cerr << "int action_go_back( State &): prior menu." << endl;
    return { {}, {}, InteractionResultNav::prior_menu };
}

InteractionResult action_print_menu_help( State_menu & state, Menu const & the_menu) {
    the_menu.print( state );
    cerr << "int action_print_menu_help( State &) "<<endl;
    auto result = pagination( state, { .height= 1, .width= the_menu.help.length() });
    // todo: process the hot_key from result
    cout <<the_menu.help<<endl;
    return { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_print_menu( State_menu & state, Menu & menu) {
    menu.print( state );
    return { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_home_menu( State_menu & ) {
    cerr << "int action_home_menu( State & state):" << endl;
    return { {}, {}, InteractionResultNav::main_menu };
}

//InteractionResult action_menu_forward_pagination( State_menu & ) {  // todo: complete this: need a "pagination menu" that can be used anytime that a variable size list is printed.
//    cerr << "int action_list_forward( State & state) { " << endl;
//    return { {}, {}, InteractionResultNav::continue_forward_pagination };
//}

//InteractionResult action_menu_backward_pagination( State_menu & ) {  // todo: need a "pagination menu" that can be used anytime that a variable size list is printed.
//    cerr << "int action_list_backward( State & state) { " << endl;
//    return { {}, {}, InteractionResultNav::continue_backward_pagination };
//}

//Action_post_return_struct action_undo( State &) {  // todo: complete this
//    cerr << "int action_undo( State &) {" << endl;

//    return 0;
//}
//Action_post_return_struct action_space_forward( State &) {  // todo: does this call action_menu_forward_navigation?
//    cerr << "int action_space_forward( State &) {" << endl;

//    return 0;
//}
//Action_post_return_struct action_tab_forward( State &) {  // todo: does this call action_menu_forward_navigation?
//    cerr << "int action_tab_forward( State &) {" << endl;

//    return 0;
//}
//Action_post_return_struct action_null_forward( State &) {  // todo: does this call action_menu_forward_navigation?
//    cerr << "int action_null_forward( State &) {" << endl;
//    return 1;
//}

