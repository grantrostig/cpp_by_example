#ifndef ACTIONS_H
#define ACTIONS_H
#include "state_menu.h"
#include "interaction_result.h"
InteractionResult action_print_categories( State_menu &);
InteractionResult action_print_list( State_menu &);
InteractionResult action_print_search_entries( State_menu &);
InteractionResult action_entry_selection( State_menu &);
InteractionResult action_entry_viewing( State_menu &);
InteractionResult action_add_entry( State_menu &);
InteractionResult action_entry_edit( State_menu &);
InteractionResult action_delete_entry( State_menu &);
InteractionResult action_delete_all( State_menu &);
InteractionResult action_save_changes_to_disk( State_menu &);
InteractionResult action_save_as_changes_to_disk( State_menu &);
InteractionResult action_load_data_from_disk( State_menu &);
InteractionResult action_backup_data( State_menu &);
InteractionResult action_screen_size( State_menu &);
InteractionResult action_advanced_settings_selection( State_menu &);

#endif // ACTIONS_H
