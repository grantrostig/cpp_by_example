#include "action_dialog.h"
#include "state_menu.h"
#include "valid_values.h"
#include "interaction_result.h"
#include "window_panel.h"

void output_prompt_dialog( State_menu & state, std::string const & prompt, ValidityCriteriaDialog const & validity ) {
    pagination_reset( state, {1,20} ); // todo: complete this, is this reset true?  20 is an estimate!
    cout << prompt;
    switch (validity.default_handling) {
    case ValidityHandlingDialog::default_is_to_approve:
        cout <<"(Yes/No,";
        cout <<"default="<<validity.value_default_approve_prompt << ")>>";
        break;
    case ValidityHandlingDialog::default_is_to_deny:
        cout <<"(Yes/No,";
        cout <<"default="<<validity.value_default_deny_prompt << ")>>";
        break;
    case ValidityHandlingDialog::default_is_provided:
        cout <<"(one valid value,";
        cout <<"(default="<<validity.value_default_provided << ")>>";
        break;
    case ValidityHandlingDialog::default_is_to_notify:
        cout <<">>";
        break;
    case ValidityHandlingDialog::no_specific_value_checking:
        cout <<"(any one value";
        if ( validity.lengths.min || validity.lengths.min ) cout <<" lenght min:"<<validity.lengths.min<<","<<validity.lengths.max<<")>>"<<endl; else cout<< ")>>"<<endl;
        break;
    case ValidityHandlingDialog::check_valid_values:
        cout <<"(one valid value)>>";
        break;
    }
}

Kb_value_plus input_dialog_response( State_menu & state, std::string const & prompt, ValidityCriteriaDialog const & validity ) {
    while ( true ) {
        output_prompt_dialog( state, prompt, validity );
        // todo: here we should a support selection from the valid values. complete this.
        auto [kb_regular_value, hot_key, file_status] = get_value_raw();  // todo: specify size??

        std::string junk = kb_regular_value; // todo: TODO why do I need this or get compile error?

        switch (validity.default_handling) {
            case ValidityHandlingDialog::default_is_to_notify:
                return { {}, hot_key, {} }; // no problem, the end value will just be "".
            case ValidityHandlingDialog::default_is_to_approve:
                if ( kb_regular_value.length() == 0 )
                    return { validity.value_default_approve_equivalents.at(0), hot_key, {} };
                if ( std::find_if( validity.value_default_approve_equivalents.begin(), validity.value_default_approve_equivalents.end(),  [junk] (std::string a) { return a == junk; }) != validity.value_default_approve_equivalents.end() )
                    return { validity.value_default_approve_equivalents.at(0), hot_key, {} };
                if ( std::find_if( validity.value_default_deny_equivalents.begin(), validity.value_default_deny_equivalents.end(),  [junk] (std::string a) { return a == junk; }) != validity.value_default_deny_equivalents.end() )
                    return { validity.value_default_deny_equivalents.at(0), hot_key, {} };
                break;
            case ValidityHandlingDialog::default_is_to_deny:
                if ( kb_regular_value.length() == 0)
                    return { validity.value_default_deny_equivalents.at(0), hot_key, {} };
                if ( std::find_if( validity.value_default_deny_equivalents.begin(), validity.value_default_deny_equivalents.end(),  [junk] (std::string a) { return a == junk; }) != validity.value_default_deny_equivalents.end() )
                    return { validity.value_default_deny_equivalents.at(0), hot_key, {} };
                if ( std::find_if( validity.value_default_approve_equivalents.begin(), validity.value_default_approve_equivalents.end(),  [junk] (std::string a) { return a == junk; }) != validity.value_default_approve_equivalents.end() )
                    return { validity.value_default_approve_equivalents.at(0), hot_key, {} };
                break;
            case ValidityHandlingDialog::default_is_provided:
                if ( kb_regular_value.length() == 0 ) {
                    kb_regular_value = validity.value_default_provided;
                    return { kb_regular_value, hot_key, {} };
                }
                break;
            case ValidityHandlingDialog::check_valid_values:
            case ValidityHandlingDialog::no_specific_value_checking:
                break;
        }
        std::string user_error_prompt {};
        switch (validity.default_handling) {
            case ValidityHandlingDialog::check_valid_values:
                if ( validity.valid_values.size() <= 0) assert(false);
                else { // auto found2 = std::find_if( valid.values.begin(), valid.values.end(), "junk" /*kb_regular_value*/);  // todo: TODO why on earth do I get a strange iteration compile error on this?
                    if ( std::find_if( validity.valid_values.begin(), validity.valid_values.end(),  [junk] (std::string a) { return a == junk; }) != validity.valid_values.end() )
                        return { kb_regular_value, hot_key, {} };
                }
                user_error_prompt = "Is not one of the valid values(";
                pagination( state, {1, user_error_prompt.length()});
                cout << user_error_prompt ;
                for (auto & i: validity.valid_values ) {
                    pagination( state, {0, i.length() + 1} );
                    cout << i << ",";
                }
                break;
            case ValidityHandlingDialog::no_specific_value_checking:
            case ValidityHandlingDialog::default_is_to_notify:
            case ValidityHandlingDialog::default_is_to_approve:
            case ValidityHandlingDialog::default_is_to_deny:
            case ValidityHandlingDialog::default_is_provided:
                if (( validity.lengths.min || validity.lengths.max )   // if we have them then check them.
                       &&
                    ( kb_regular_value.length() < validity.lengths.min || kb_regular_value.length() > validity.lengths.max ))
                {
                    user_error_prompt = "Value is too ";
                    pagination( state, {1, user_error_prompt.length() + 5 + 1});
                    cout << user_error_prompt << (kb_regular_value.length() < validity.lengths.min ? "long" : "short");
                    cout << ".";
                    break;
                }
                else
                    return { kb_regular_value, hot_key, {} };
        }
        cout <<'\a'<<endl;  // just ring the bell? // todo: complete this: notify user about length requirements failure.
    }
}
/*
InteractionResultNav specialize_dialog_field_completion_nav( Kb_value_plus const & value_plus ) {
    auto [ kb_regular_value, hot_key, file_status ] = value_plus;
    switch ( hot_key.f_completion_nav ) {
        case FieldCompletionNav::page_down: // most likely outcome
        case FieldCompletionNav::down_one_field:
        case FieldCompletionNav::skip_to_end_of_fields:
        case FieldCompletionNav::eof:
            return InteractionResultNav::prior_menu;
        case FieldCompletionNav::esc:
            return InteractionResultNav::prior_menu;
        case FieldCompletionNav::up_one_field:
        case FieldCompletionNav::page_up:
        case FieldCompletionNav::save_form_as_is:
        case FieldCompletionNav::exit_with_prompts:
            return InteractionResultNav::retain_menu;  // todo: is this true?
        case FieldCompletionNav::interrupt:
        case FieldCompletionNav::kill:
        case FieldCompletionNav::quit:
        case FieldCompletionNav::na:
            throw std::logic_error( "specialize_dialog_field_completion_nav():Bad FieldCompletion_Nav." );
    }
}

InteractionResultNav specialize_dialog_function_cat( Kb_value_plus const & value_plus ) {
    auto [ kb_regular_value, hot_key, file_status ] = value_plus;
    switch ( hot_key.function_cat ) {

        case HotKeyFunctionCat::nav_field_completion:
            return specialize_dialog_field_completion_nav( value_plus );

        case HotKeyFunctionCat::navigation_esc:
            return InteractionResultNav::prior_menu_discard_value;

        case HotKeyFunctionCat::nav_intra_field:
        case HotKeyFunctionCat::editing_mode:
        case HotKeyFunctionCat::help_popup:
        case HotKeyFunctionCat::job_control:
        case HotKeyFunctionCat::na:
            throw std::logic_error( "specialize_dialog_function_cat():Bad HotKeyFunctionCat." );
    }
}

InteractionResultNav calculate_dialog_navigation( Kb_value_plus const & value_plus ) {
    // InteractionResultNav v = specialize_dialog_function_cat( value_plus );
    auto [kb_regular_value, hot_key, file_status] = value_plus;

    Hot_key hot_key2 = hot_key;  // todo:  TODO why do I need this indirection?

    auto v = std::find_if( FNIMap.begin(), FNIMap.end(), [&hot_key2](FieldNavInteractionRelation r){ return (r.category == InteractionCategory::dialog && r.field_nav == hot_key2.f_completion_nav );});
    if ( v != FNIMap.end() )
        return v->interaction_nav;
    else
        throw std::logic_error( "calculate_dialog_navigation(): Missing entry in FNIMap.");
}
*/
InteractionResultNav find_interaction_result_nav( Kb_value_plus const & val, InteractionCategory const cat ) {
    auto 	[kb_regular_value, hot_key, file_status] = val;
    Hot_key  hot_key2 								 = hot_key;  // todo:  TODO why do I need this indirection?
    auto v = std::find_if( FNIMap.begin(), FNIMap.end(), [&hot_key2, cat](FieldNavInteractionRelation r){ return (r.category == cat && r.field_nav == hot_key2.f_completion_nav );});
    if ( v != FNIMap.end() )
        return v->interaction_nav;
    else
        throw std::logic_error( "calculate_dialog_navigation(): Missing entry in FNIMap.");
}

InteractionResult action_dialog_modal_vals(State_menu & state, std::string const & prompt, ValidityCriteriaDialog const & validity) {  // different from process_menu() because we don't expect a major change in the flow of the program, ie. yes/no for a data save to file. BUT yes we do want to support _some_ hot_keys!
    Kb_value_plus 		 	 value_plus 		= input_dialog_response( 	   state, prompt, validity );
    Kb_regular_value 	 kb_regular_value 	= std::get<Kb_regular_value>(  value_plus );
    InteractionResultNav irn 				= find_interaction_result_nav( value_plus, InteractionCategory::dialog );
    return { kb_regular_value, {}, irn }; // return { kb_regular_value, InteractionResultError {}, InteractionResultNav::retain_menu };
}

bool action_dialog_modal_approve( State_menu & state, std::string const & prompt ) {
    ValidityCriteriaDialog validity { {}, ValidityHandlingDialog::default_is_to_approve };
    auto [ data, na1, na2] = action_dialog_modal_vals( state, prompt, validity ) ;
    if ( *std::get_if<std::string>(&data) == (ValidityCriteriaDialog {}).value_default_approve_equivalents.at(0))  // todo: does the object get optimized away?  static global?
        return true;
        else return false; // todo: check other values.
}

bool action_dialog_modal_deny( State_menu & state, std::string const & prompt ) {
    ValidityCriteriaDialog validity { {}, ValidityHandlingDialog::default_is_to_deny };
    auto [ data, na1, na2] = action_dialog_modal_vals( state, prompt, validity ) ;
    if ( *std::get_if<std::string>(&data) == (ValidityCriteriaDialog {}).value_default_deny_equivalents.at(0)) return true; else return false; // todo: check other values.
}

void action_dialog_modal_notify( State_menu & state, std::string const & prompt ) {
    ValidityCriteriaDialog validity { {}, ValidityHandlingDialog::default_is_to_notify };
    action_dialog_modal_vals( state, prompt, validity ); // todo: check other values.
    // throw away all values?
}
