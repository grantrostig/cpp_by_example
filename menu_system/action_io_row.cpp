#include "action_io_row.h"
#include "global_entities.h"
#include "action_dialog.h"
#include "io_table.h"

InteractionResult action_io_row_list(State_menu &state, IO_table &table) {
    return {};  // InteractionResultData_Variant, InteractionResultError, InteractionResultNav
}

InteractionResult action_io_row_select(State_menu &state, IO_table &table) {
    return {};  // InteractionResultData_Variant, InteractionResultError, InteractionResultNav
}

void store_field_data( IO_table & table, InteractionResult & ir, unsigned short field_index ) {
    // table.spec.temp_row; // where it actually goes.
    // int  v  = std::any_cast< int > (table.spec.field_validation_fn_mapping.at( field_index ).field_location);
    // int  v2 = std::get_if< int > ( &ir.data);
    // std::get_if< int > ( &ir.data ) = std::any_cast<int > (table.spec.field_validation_fn_mapping.at( field_index ).field_location);
    *( std::any_cast< decltype(ir.data) *>(table.spec.field_validation_fn_mapping.at( field_index ).field_location)) = ir.XXXXdata ;  // todo: complete this: must convert_string_value_to_field_type_value FIRST!!
}

InteractionResult action_io_row_create(State_menu &state, IO_table &table) {
    // determine row schema
    // access target struct
    unsigned short field_index {0};
    bool 		   is_done 	   {false};
    do {
        // loop through fields/columns of the row
        // get a value OR move to other field
        InteractionResult ir = action_dialog_modal_io_field( state, table.spec.fields.at( field_index ) );
        switch ( ir.navigation ) {
        case InteractionResultNav::down_one_field :
        case InteractionResultNav::up_one_block :  // essentially ignore it, assume equivalent to <Enter>
        case InteractionResultNav::continue_forward_pagination :  // essentially ignore it, assume equivalent to <Enter>
            // save field in row.

            ++field_index;
            break;
        case InteractionResultNav::up_one_field :
        case InteractionResultNav::continue_backward_pagination :
            // save field in row.
            if ( field_index > 0 ) --field_index;  else cout << '\a';  // alarm
            break;
        case InteractionResultNav::skip_to_end_of_fields :
        case InteractionResultNav::down_one_block :
        case InteractionResultNav::save_form_as_is :  // is this true??
            // save field in row.
            is_done = true;
            break;
        case InteractionResultNav::exit_fn_with_prompts :
        case InteractionResultNav::exit_fn_immediately :
        case InteractionResultNav::exit_pgm_immediately :
        case InteractionResultNav::exit_pgm_with_prompts :
            // don't save field nor row??
            is_done = true;  // not needed, but...
            return InteractionResult {.data= {} ,.error= {} ,.navigation= ir.navigation } ;
        case InteractionResultNav::retain_menu :
        case InteractionResultNav::prior_menu :
        case InteractionResultNav::prior_menu_discard_value :
        case InteractionResultNav::main_menu :
        case InteractionResultNav::na :
            throw std::logic_error( "invalid navigation.");
        }
        if ( field_index > IO_ROW_FIELDS_NUM_PERSON ) is_done = true;
    } while ( !is_done );

    // write the new row using the target struct
    return {};  // InteractionResultData_Variant, InteractionResultError, InteractionResultNav
}

InteractionResult action_io_row_delete(State_menu &state, IO_table &table) {
    return {};  // InteractionResultData_Variant, InteractionResultError, InteractionResultNav
}

InteractionResult action_io_row_update(State_menu &state, IO_table &table) {
    return {};  // InteractionResultData_Variant, InteractionResultError, InteractionResultNav
}

InteractionResult action_io_row_read(State_menu &state, IO_table &table) {
    return {};  // InteractionResultData_Variant, InteractionResultError, InteractionResultNav
}
