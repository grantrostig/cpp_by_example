#ifndef MENU_H
#define MENU_H
#include <vector>
#include <functional>
#include "state_menu.h"
#include "menu_option.h"  // must have this.
#include "interaction_result.h"

/* A 'menu' allows users to control an application.
 * It has a collection of sub-menus (also menus) and menu 'options'
 * which run 'actions', following which program control returns to the menu which invoked it.
 * Generally an application has only one root menu called 'main menu'.
 * The menu is implemented by a menu system.
 * The class 'Menu' implements the storage and use (invocation/running) of the
 * sub-menus and the options.
 */
struct Menu {
    std::string name 		{"Configuration error:Need to Initialize!"};
    std::string description {"Configuration error:Need to Initialize!"};
    std::string help 		{"Detailed Help: When you see words followed by >> and the blinking box (the prompt followed by the cursor), the system is waiting for you to select what you want to do next. Type the one keyboard character which corresponds to the action you want. For example: (h)elp highlights the <h> key. The system will respond right away unless you are editing data, you don't need to enter <RETURN> for the system to respond in most cases."};
    std::vector<Menu_option> options {};
    // Menu();  // builds the linked/self-referring datastructures to hold all the menus.
    void print( State_menu & ) const;
    friend void initialize_universal_options();
    friend void initialize_menu_main_options();
    friend void initialize_menu_file_options();
    friend void initialize_menu_edit_options();
    friend void initialize_menu_settings_options();
};
void initialize_universal_options(State_menu &, std::shared_ptr<Menu>);
void initialize_menu_main_options(State_menu &, std::shared_ptr<Menu>);
void initialize_menu_file_options(State_menu &, std::shared_ptr<Menu>);
void initialize_menu_edit_options(State_menu &, std::shared_ptr<Menu>);
void initialize_menu_settings_options(State_menu &, std::shared_ptr<Menu>);

#endif // MENU_H
