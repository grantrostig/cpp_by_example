#include "process_menu.h"
#include <iostream>
#include <cassert>
#include "state_menu.h"
#include "menu.h"
#include "menu_option.h"
#include "window_panel.h"
#include "lib_tty.h"
#include "interaction_result.h"
using std::endl, std::cin, std::cerr, std::cout;

Menu_option & input_menu_selection( State_menu & state_menu, std::shared_ptr<Menu> menu_sp ) {  // loop until we return either a menu selection or a number representing the entry to be selected
    while (true) {
        auto r = pagination( state_menu, {.height= 1, .width= menu_sp->name.length() + 3 + 1} );  // +1 for cursor position.
        // todo: complete this above.
        cout << menu_sp->name<<">> ";
        cout.flush();
        pagination_reset( state_menu, {0,0});
        auto [kb_regular_value, hot_key, file_status] = get_kb_keys_raw( 1 , false );
        cout << '\n';
        for ( Menu_option & menu_option: menu_sp->options )
            if ( kb_regular_value == menu_option.input_token )
                return menu_option;
        cout << "Invalid menu selection, try again, or press the single <h> key for (h)elp.\n";
    }
    assert(false);  // infinute loop that is exited via a menu selection.  Should never get here, obviously not needed, but placed here for clarity. todo:  fix this up.
}

// The 'Overloaded' pattern _could_ have been standardized in c++20 but wasn't, as per Stroustup in A Tour of C++ 2nd Edition, Page 176.
template<class... Ts>  				// variadic ie. any number of any type are handled. Below we use several in the contructor of our one object. // ... is a parameter pack.
struct Overloaded : Ts... { 		// inherit from all those types
    using Ts::operator()...;  		// all of those operator()s.  // new in c++17.
};

template<class... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;  // deduction guide.  -> = returns.  todo: explain: what returns what to whom?

InteractionResult process_menu_selection(State_menu & state, Menu_option const & menu_selection ) {
    // get some data, even though it is not used for every overload.
    std::shared_ptr<Menu> menu_sp = state.menu_top_sp();  // todo: I don't think I need a value in the lambda, because it is overridden at std::visit?
    Menu menu 					  = *menu_sp;
    // if ( std::get<>(menu_selection.menu_action_fn) != nullptr) {
        // auto r = std::get<std::function<Action_post_return_struct(State&)>>(menu_selection.menu_action_fn_variant)(state);
    auto function_object_overload_set = Overloaded {
            [&state]  		  (std::function<decltype(action_program_exit_with_prompts)> &af){ auto r = af(state); return r; }, // to be invoked via operator() on the function object (AKA lambda) or any callable object.
            [&state,&menu]    (std::function<decltype(action_print_menu)> &af) 	{ auto r = af(state,menu); return r; }, // to be invoked via operator() on the function object (AKA lambda) or any callable object.
            [&state,&menu_sp] (std::function<decltype(process_menu)> &af) 		{ auto r = af(state,menu_sp); return r; }, // to be invoked via operator() on the function object (AKA lambda) or any callable object.
    };
    auto fo_return_type_overloaded_set = [&] (auto /*I want this:&*/ ... args) -> InteractionResult { return function_object_overload_set(  args  ...); };  // todo: TODO: why & compile error? not needed if all return types are the same.  which is the current case!
    auto action_result = std::visit( fo_return_type_overloaded_set, menu_selection.menu_action_fn_variant );
    return action_result;
//    }
    // return menu_selection.option_value;  todo: TODO
}

InteractionResult const process_menu(State_menu & state, std::shared_ptr<Menu> menu_sp ) {
    if (menu_sp == nullptr) { assert(false); }
    // menu_update_push( state, menu_sp );
    state.push_menu_sp( menu_sp );
    while (true) {

        auto menu_option         = input_menu_selection(state, menu_sp);

        InteractionResult result = process_menu_selection( state, menu_option );

        // post processing: load the correct menu to be shown to user, or exit.
        switch ( result.navigation ) {
        case InteractionResultNav::retain_menu:  // just loop.
            break;
        case InteractionResultNav::prior_menu :   // we have been asked to go back one level of menu.
            // menu_update_pop_to( state, state.getMenu_prior(), /*OUT*/ menu_sp );
            menu_sp = state.menu_pop_top_sp();
            // return { {}, {}, Action_post_return_navigation::retain_menu };
            break;
        case InteractionResultNav::main_menu :   // we have been asked to go back one level of menu.
            // menu_update_pop_to( state, state.getMenu_main(), /*OUT*/ menu_sp );
            menu_sp = state.menu_pop_to_sp(state.getMenu_main());
            break;
        case InteractionResultNav::exit_pgm_immediately:
            return { {}, {}, InteractionResultNav::exit_pgm_immediately };
        case InteractionResultNav::continue_forward_pagination:
//        case InteractionResultNav::continue_backward_pagination:
            assert(false);
            break;
//        case InteractionResultNav::exit_with_prompts:
//                // todo: complete this.
//            return { {}, {}, InteractionResultNav::exit_immediately };
        }
    }
}

InteractionResult const process_main_menu(State_menu & state ) {  // cannot overload process_menu, or Overload become ambiguous.  todo: TODO Is there a fix/cast?
    action_print_menu_help( state, *state.getMenu_main());
    return process_menu( state, state.getMenu_main());
}
