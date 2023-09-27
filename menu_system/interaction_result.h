#ifndef INTERACTION_RESULT_H
#define INTERACTION_RESULT_H
#include <string>
#include <variant>
#include <chrono>
#include "lib_tty.h"


// todo: just some sample types to start with, more to be added.
#define INTERACTION_RESULT_DATA_TYPES \
    std::monostate, \
    bool, \
    KbFundamentalUnit, \
    int, \
    size_t,\
    long,\
    float,\
    double,\
    std::string,\
    std::tm

using InteractionResultData_Variant = std::variant< INTERACTION_RESULT_DATA_TYPES >;// after the action returns

enum class InteractionResultErrorCat {
    success,
    failed,
    re_try,  	// maybe?
    unavailable,  	// maybe?
    greyed_out,  // maybe?
    na
};

struct InteractionResultError {
    InteractionResultErrorCat category 	{InteractionResultErrorCat::na};
    std::string               message 	{};
};

enum class InteractionResultNav {  // todo: TODO would this be more compact if "char" or "byte"? What are downsides other than performance?
    // universal navigation commands
    exit_pgm_immediately,
    exit_pgm_with_prompts,
    exit_fn_immediately,
    exit_fn_with_prompts,
    na,

    // menu specific navigation commands  	- supplemented by universals'
    retain_menu,
    prior_menu,
    prior_menu_discard_value,
    main_menu,

    // dialog specific navigation commands  - supplemented by menus'
    continue_forward_pagination,
    continue_backward_pagination,

    // detail_row nav 						- supplemented by menus'
    up_one_field,
    down_one_field,
    up_one_block,   // top of block, or if there then top of prior block.
    down_one_block, // bottom of block, or if there then bottom of next block.
    save_form_as_is,
    skip_to_end_of_fields,
    // should we have a separate enum for dialogs, menus, data_fields?
};

enum class InteractionCategory {
    universal,
    menu,
    dialog,
    master_row,
    detail_row,
    na
};

struct FieldNavInteractionRelation {
    InteractionCategory	 category 			{InteractionCategory::na};
    FieldCompletionNav 	 field_nav 			{FieldCompletionNav::na};
    InteractionResultNav interaction_nav 	{InteractionResultNav::na};
};

// What does a hot_key mean in different situations?  See below:
using FieldNavInteractionMap = std::vector<FieldNavInteractionRelation>;
static const FieldNavInteractionMap FNIMap = {
    { InteractionCategory::menu, 	    FieldCompletionNav::esc, 				InteractionResultNav::prior_menu_discard_value }, // for example, esc on menu, should take you back one.
    { InteractionCategory::menu, 	    FieldCompletionNav::exit_immediately, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::menu, 	    FieldCompletionNav::interrupt, 			InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::menu, 	    FieldCompletionNav::exit_with_prompts, 	InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::menu, 	    FieldCompletionNav::eof, 				InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::menu, 	    FieldCompletionNav::help, 				InteractionResultNav::retain_menu },

    { InteractionCategory::menu, 		FieldCompletionNav::up_one_field, 		InteractionResultNav::na },
    { InteractionCategory::menu, 	    FieldCompletionNav::down_one_field, 	InteractionResultNav::retain_menu },
    { InteractionCategory::menu, 	    FieldCompletionNav::page_up, 			InteractionResultNav::na },
    { InteractionCategory::menu, 	    FieldCompletionNav::page_down,		 	InteractionResultNav::na },
    { InteractionCategory::menu, 	    FieldCompletionNav::quit,		 		InteractionResultNav::na },
    { InteractionCategory::menu, 	    FieldCompletionNav::kill,		 		InteractionResultNav::na },
    { InteractionCategory::menu, 	    FieldCompletionNav::save_form_as_is,	InteractionResultNav::na },
    { InteractionCategory::menu, 	    FieldCompletionNav::skip_to_end_of_fields, InteractionResultNav::na },
    { InteractionCategory::menu, 	    FieldCompletionNav::na, 				InteractionResultNav::na },

    { InteractionCategory::dialog, 	    FieldCompletionNav::esc, 				InteractionResultNav::prior_menu },  // for example, if when <Return> to continue, then stop listing the items.
    { InteractionCategory::dialog, 	    FieldCompletionNav::exit_immediately, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialog, 	    FieldCompletionNav::interrupt, 			InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialog, 	    FieldCompletionNav::exit_with_prompts, 	InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::dialog, 	    FieldCompletionNav::eof, 				InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::dialog, 	    FieldCompletionNav::help, 				InteractionResultNav::retain_menu },

    { InteractionCategory::dialog, 		FieldCompletionNav::up_one_field, 		InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    FieldCompletionNav::down_one_field, 	InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    FieldCompletionNav::page_up, 			InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    FieldCompletionNav::page_down,		 	InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    FieldCompletionNav::quit,		 		InteractionResultNav::na },
    { InteractionCategory::dialog, 	    FieldCompletionNav::kill,		 		InteractionResultNav::na },
    { InteractionCategory::dialog, 	    FieldCompletionNav::save_form_as_is,	InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    FieldCompletionNav::skip_to_end_of_fields, InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    FieldCompletionNav::na, 				InteractionResultNav::na },

    { InteractionCategory::detail_row, 	FieldCompletionNav::esc, 				InteractionResultNav::prior_menu },  // for example, if when <Return> to continue, then stop listing the items.
    { InteractionCategory::detail_row, 	FieldCompletionNav::exit_immediately, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::detail_row, 	FieldCompletionNav::interrupt, 			InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::detail_row, 	FieldCompletionNav::exit_with_prompts, 	InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::detail_row, 	FieldCompletionNav::eof, 				InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::detail_row, 	FieldCompletionNav::help, 				InteractionResultNav::retain_menu },

    { InteractionCategory::detail_row, 	FieldCompletionNav::up_one_field, 		InteractionResultNav::up_one_field },
    { InteractionCategory::detail_row, 	FieldCompletionNav::down_one_field, 	InteractionResultNav::down_one_field },
    { InteractionCategory::detail_row, 	FieldCompletionNav::page_up, 			InteractionResultNav::up_one_block },
    { InteractionCategory::detail_row, 	FieldCompletionNav::page_down,		 	InteractionResultNav::down_one_block },
    { InteractionCategory::detail_row, 	FieldCompletionNav::quit,		 		InteractionResultNav::na },
    { InteractionCategory::detail_row, 	FieldCompletionNav::kill,		 		InteractionResultNav::na },
    { InteractionCategory::detail_row, 	FieldCompletionNav::save_form_as_is,	InteractionResultNav::save_form_as_is },
    { InteractionCategory::detail_row, 	FieldCompletionNav::skip_to_end_of_fields, InteractionResultNav::skip_to_end_of_fields },
    { InteractionCategory::detail_row, 	FieldCompletionNav::na, 				InteractionResultNav::na },

    { InteractionCategory::master_row, 	FieldCompletionNav::na, 				InteractionResultNav::na }
};

struct InteractionResult {
        InteractionResultData_Variant  data 		{};
        InteractionResultError		   error 		{};
        InteractionResultNav 	       navigation 	{InteractionResultNav::na};
      };
;

#endif // INTERACTION_RESULT_H
