#ifndef VALID_VALUES_H
#define VALID_VALUES_H
#include <string>
#include <vector>
#include <memory>

class LengthRange { // invariants: min <= max., both >= 0;
public:
    size_t 			min 	{0};
    size_t 			max 	{60};
};
class IntegerValueRange { // invariants: min <= max., both >= 0;
public:
    long long int 	min		{-999999999999999};
    long long int 	max   	{ 999999999999999};
    int			  	step 	{};
    bool 			is_not_between	{false}; // excluding the range.
};
class DecimalValueRange { // invariants: min <= max., both >= 0;
public:
    double 			min		{-999999999999999};
    double 			max		{ 999999999999999};
    int 			precision {};
    short			significant_values {9999};
    int			  	step 	{};
    bool 			is_not_between	{false}; // excluding the range.
};
enum class CharacterCaseHandling {
    none,
    force_upper,
    force_lower,
    force_initial_cap,
    force_initial_capitals
};
enum class DefaultHandling {
    default_is_to_approve,
    default_is_to_deny,
    default_is_provided,
    default_is_to_notify, // accept any keypress, just a notification.
    na
};
constexpr std::string_view YES {"Yes"};
constexpr std::string_view NO {"No"};

enum class ValidValuesHandling {
    check_valid_values,
    no_specific_value_checking,  // but we do check lengths.
    na
};
enum class ValidationFieldError {  // https://developer.mozilla.org/en-US/docs/Web/API/ValidityState
    value_missing,
    regex_mismatch,
    range_overflow,
    range_underflow,
    range_not_between,
    step_mismatch,
    too_long,
    too_short,
    type_mismatch,    // as per mozilla
    bad_input         // as per mozilla
    /*  equal to // ??
        not equal to
        greater than
        less than
        greater than or equal to
        less than or equal to */
};
enum class ValidityHandlingDialog {
    default_is_to_approve,
    default_is_to_deny,
    default_is_provided,
    default_is_to_notify, // accept any keypress, just a notification.
    // above used as a logical group for handling defaults, below specify 2 cases, but not defaults.  todo:  could make this better with invariants in ValidityCritera...  todo:  could make this better with invariants in ValidityCritera...
    check_valid_values,
    no_specific_value_checking  // but we do check lengths.
};
class ValidityCriteriaDialog { // invariants: values must have some values if Default_handling is default_is_provided.
public:
    LengthRange                    lengths {0, std::max( YES.length(), NO.length())};  // NOTE: also applies to both values vector and defaults below!
    ValidityHandlingDialog         default_handling { ValidityHandlingDialog::no_specific_value_checking };
    std::vector<std::string>       valid_values {};  // remember to consider the case of the characters ie. upper/lower.
    const std::vector<std::string> value_default_approve_equivalents {std::string {YES},"yes","Y","y"}; // note: use .at(0) for a defaulted value
    const std::vector<std::string> value_default_deny_equivalents {std::string {NO},"no","N","n"}; // note: use .at(0) for a defaulted value
    const std::string 		   	   value_default_approve_prompt {YES};
    const std::string 			   value_default_deny_prompt {NO};
    const std::string 			   value_default_provided {"FILL THIS VALUE if used!"}; // a little debugging help.  only a default if length > 0.
};
class ValidityCriteriaDialog2 {  // todo: implement this new data structure, replacing prior.
public:
    LengthRange                    lengths {0, std::max( YES.length(), NO.length())};  // NOTE: also applies to both values vector and defaults below!
    DefaultHandling				   default_handling { DefaultHandling::na};
    const std::vector<std::string> value_default_approve_equivalents {std::string {YES},"yes","Y","y"}; // note: use .at(0) for a defaulted value
    const std::vector<std::string> value_default_deny_equivalents {std::string {NO},"no","N","n"}; // note: use .at(0) for a defaulted value
    const std::string 		   	   value_default_approve_prompt {YES};
    const std::string 			   value_default_deny_prompt {NO};
    const std::string 			   value_default_provided {"FILL THIS VALUE if used!"}; // a little debugging help.  only a default if length > 0.
    ValidValuesHandling 	       valid_values_handling { ValidityHandlingDialog::no_specific_value_checking };
    std::vector<std::string>       valid_values {};  // remember to consider the case of the characters ie. upper/lower.
    std::vector<std::string>       values_prohibited {};  // todo: implement this. remember to consider the case of the characters ie. upper/lower.
    std::shared_ptr<std::string>   values_prohibited_shared {};
};
#endif // VALID_VALUES_H
