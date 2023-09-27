#ifndef PROCESS_MENU_H
#define PROCESS_MENU_H
#include <memory>
#include "state_menu.h"
#include "interaction_result.h"

/* Called by the main program to allow the user to control the application.
 * It takes input from the user and runs an action.
 * It can call itself recursively for submenus.
 */
InteractionResult process_menu(      State_menu &, std::shared_ptr<Menu> );  // todo: can I hide this from the API user programmer? via an *_impl.h that is not distributed?
InteractionResult process_main_menu( State_menu & );

#endif // PROCESS_MENU_H
