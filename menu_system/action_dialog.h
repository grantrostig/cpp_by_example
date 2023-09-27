#ifndef ACTION_DIALOG_H
#define ACTION_DIALOG_H
#include "state_menu.h"
#include "valid_values.h"
#include "interaction_result.h"

// InteractionResultNav find_interaction_result_nav( Kb_value_plus const &, InteractionCategory const );

InteractionResult action_dialog_modal_vals(    State_menu &, std::string   const & prompt, ValidityCriteriaDialog const & valid);
bool 			  action_dialog_modal_approve( State_menu &, std::string   const & prompt );
bool 			  action_dialog_modal_deny(    State_menu &, std::string   const & prompt );
void 			  action_dialog_modal_notify(  State_menu &, std::string   const & prompt );

#endif // ACTION_DIALOG_H
