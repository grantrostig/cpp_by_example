#include <iostream>
#include "actions.h"
#include "menu_option.h" // need this one!
#include "window_panel.h"
#include "interaction_result.h"

using std::cin, std::cout, std::endl, std::cerr;

InteractionResult action_print_categories( State_menu &) {
    cerr << "int action_print_categories( State &) {" << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_print_list( State_menu & state) {
    cerr << "int action_print_list( State &) {" << endl;
    pagination_reset( state, {0,0});
    auto & r = state.getApplication_data()->vec_data;
    int i {};
    for ( auto & d : r) {
        pagination( state, { .height= 1, .width= d.length() + 4 + 1} );
        if (!i==0) cout << endl;
        cout << ++i << ":"<< d;
    }
    cout << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_print_search_entries( State_menu &) {
    cerr << "int action_print_search_entries( State &) {" << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_entry_selection( State_menu &) {
    cerr << "int action_entry_selection( State &) {" << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_entry_viewing( State_menu &) {
    cerr << "int action_entry_viewing( State &) {" << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_entry_edit( State_menu &) {
    cerr << "int action_entry_viewing( State &) {" << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_add_entry( State_menu &) {
    cerr << "int action_add_entry( State &) {" << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_delete_entry( State_menu &) {
    cerr << "int action_delete_entry( State &) {" << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_delete_all( State_menu &) {
    cerr << "int action_delete_all( State &) {" << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_save_changes_to_disk( State_menu &) {
    cerr << "int action_save_changes_to_disk( State &) " << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_save_as_changes_to_disk( State_menu &) {
    cerr << "int action_save_changes_to_disk( State &) " << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_load_data_from_disk( State_menu &) {
    cerr << "int action_load_data_from_disk( State &) " << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_backup_data( State_menu &) {
    cerr << "int action_backup_data( State &) " << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_screen_size( State_menu &) {
    cerr << "int action_screen_size( State &) " << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_advanced_settings_selection( State_menu &) {
    cerr << "int action_advanced_settings_selection:" << endl;
    return InteractionResult { {}, {}, InteractionResultNav::retain_menu };
}
