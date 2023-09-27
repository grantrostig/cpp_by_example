#include "menu_option.h"
#include <iostream>
#include "state_menu.h"
#include "interaction_result.h"
#include "window_panel.h"

void Menu_option::print( State_menu & state_menu) const {
    pagination(state_menu,{ 0, 1+input_token.length()+1+name.length()}); // plan to print one line or less, so 0.
    std::cout <<"("<<input_token<<")"<<name;
}
