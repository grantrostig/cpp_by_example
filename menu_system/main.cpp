/* copyright (c) Grant Rostig 2019, all rights reserved
 * permission granted for use during CppMSG events during 2019.
 *
 * Generated as part of Grant's password manager effort to show
 * how the Overloaded pattern is used by std::visit.
 *
 * This example code shows how overloaded could be applied to a menu system.
 * The menu system allows for various function signatures
 * and various configurations of return values.
 */

#include <iostream>
#include <memory>
#include <functional>

#include "state_menu.h"
#include "state_application.h"
#include "menu.h"
#include "process_menu.h"
#include "interaction_result.h"

using namespace std;

int main()
{
    Menu menu_main; // create main first, then the sub-menus.
    Menu menu_edit;
    Menu menu_file;
    Menu menu_settings;
    State_menu state {};
    State_application application_state {};
    state.setMenu_main( std::make_shared<Menu>(menu_main) ); // record menu pointers in state
    state.setMenu_edit( std::make_shared<Menu>(menu_edit) );
    state.setMenu_file( std::make_shared<Menu>(menu_file) );
    state.setMenu_settings( std::make_shared<Menu>(menu_settings) );
    state.setApplication_data( std::make_shared<State_application>(application_state) );

    // Create the menu options and link menus together

    cerr << "initialize_menu_main_options( state, state.getMenu_main());" << endl;
    initialize_menu_main_options( state, state.getMenu_main());

    cerr << "initialize_menu_edit_options( state, state.getMenu_edit());" << endl;
    initialize_menu_edit_options( state, state.getMenu_edit());

    cerr << "initialize_menu_options_options( state, state.getMenu_options());" << endl;
    initialize_menu_file_options( state, state.getMenu_file());

    cerr << "initialize_menu_settings_options( state, state.getMenu_settings());" << endl;
    initialize_menu_settings_options( state, state.getMenu_settings());

    // state.push_menu_sp( state.getMenu_main() );  // todo:  should not need this line.

    // not used, just playing with syntax:
    // auto f = std::bind(process_menu, std::ref(state), state.getMenu_main());
    // auto f2 = std::bind(process_menu, std::ref(state) );

    auto [data, error, naviation ] = process_main_menu( state );
    cout << "###" << endl;
    return 0;
}
