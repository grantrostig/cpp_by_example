#ifndef IO_FIELD_H
#define IO_FIELD_H
#include <string>
#include <vector>
#include <variant>
#include <chrono>
#include <any>
#include "lib_tty.h"
#include "valid_values.h"
#include "interaction_result.h"
#include "action_dialog.h"
// #include "io_table.h"
class IO_table;

enum class Security_role {
    read_person,
    read_write_person,
    write_person,
    backup_person,
    restore_person,
    admin_person,
    unknown
};
enum class Security_region {
    a,
    b,
    c,
    d,
    e,
    all,
    unknown
};
enum class Security_level {
    public_info,
    private_info,
    confidential,
    secret,
    top_secret,
    unknown
};
enum class Security_action {
    read,
    write,
    execute,
    all,
    unknown
};
class Security_spec {
public:
    std::vector< Security_role >   roles   { Security_role::admin_person };
    std::vector< Security_region > regions { Security_region::all };
    std::vector< Security_level >  levels  { Security_level::top_secret };
    std::vector< Security_action > actions { Security_action::all };
};
static const Security_spec super_user {}; // yup, that is our default.
static const Security_spec guest_user {
    { Security_role	  ::read_person },
    { Security_region ::all 		},
    { Security_level  ::public_info },
    { Security_action ::read 		}
};
/*  universal_commands <CTRL-ENTER>
    https://www.w3schools.com/html/html_form_attributes.asp
    autocomplete
    autofocus
    form
    formaction
    formenctype
    formmethod
    formnovalidate
    formtarget
    height and width
    list
    min and max
    multiple
    pattern (regexp)
    placeholder
    required
    step
    ----
    between
    not between
    equal to
    not equal to
    greater than
    less than
    greater than or equal to
    less than or equal to
    like
    ** and **
    ** OR **
*/
enum class IO_alignment {  // todo: complete this.
    left,
    right,
    center,
    none
};
enum class IO_echo_mode {  // todo: complete this.
    normal,
    no_echo,
    password,  // show * for each kb_normal_char entered, shows length of password.
    password_echo_one_char,
    password_echo_while_editing
};
enum class IO_data_type {
    boolean,
    character,  // char
    alphanumeric,
    integer,
    integer_long,
    integer_long_long,
    decimal,
    decimal_long,
    scientific,
    time_point
};
using IO_data_to_cpp_type_map = std::variant<
        INTERACTION_RESULT_DATA_TYPES,
        std::chrono::system_clock::time_point,
        uint64_t >; // used for GUID

class IO_field_spec {
public:
    std::string	  id_name   			 	{"FILL id name in!"};
    std::string	  user_prompt 		{"FILL user_prompt text in!"};

    // IO_field_specs_variant field_spec { IO_field_spec_alphanumeric {}};
    std::string	  full_description 	{"FILL full description in!"};
    std::string	  help 			 	{"FILL help in!"};

    bool 		  is_optional 		{false}; // means that the user need not respond to this field. That would imply that the field would have to be nullable (especially in the case of bool and numbers, but not so much for std::string, since we might consider "" to be considered to NULL or "not answered".

    std::string   pre_fill_value 	{};
    std::string   default_value 	{};  	  // is placed instead of the NULL, which is available if optional (which implies nullable).
    std::string   regex_pattern 	{};      // could incorporate the min/max length, but that would be complicated?

    bool          is_null_able 		{false}; // means that this field will be std::optional<> for anything except std::sting?? todo: what is difference between "" and NULL and <default>?

    IO_echo_mode  echo_mode_default {IO_echo_mode::normal};
    IO_alignment  alignment			{IO_alignment::none};

    Security_spec security_spec  		{ super_user };
    bool		  is_system_calculated_read_only {false};
    bool 	      is_programmer_only 	{false};  // used by the computer program only, not visible to any user!!
    bool 		  is_initial_focus 	 	{false};
    bool		  is_greyed_out 	 	{false};

    // virtual ~IO_field_spec();  // todo: I'm guessing... TODO  do I need delete or =0? rule of whatever?
};

// validate() fixup() functions - preprocess the field to for example remove ()- on a phone number or credit card.
class IO_field_spec_bool 			: IO_field_spec {}; 		// c++ type
class IO_field_spec_character 		: IO_field_spec {};  // c++ type
class IO_field_spec_uint64  		: IO_field_spec {};  // c++ type: to be used for GUI and similar
class IO_field_spec_time_point 		: IO_field_spec {};  // c++ type // is_future_date_allowed, is_weekdays_only, is_friday..., within_xxxx_year/month
class IO_field_spec_tm 				: IO_field_spec {};         // c time type
class IO_field_spec_alphanumeric 	: IO_field_spec { 	// std::string
public:
    IO_data_type 		data_type  			{IO_data_type::alphanumeric};
    LengthRange			lengths 		 	{0,60};
};
class IO_field_spec_integer 		: IO_field_spec {
public:
    IO_data_type        data_type  		    {IO_data_type::integer};
    IntegerValueRange 	range 				{-999999999999999, 999999999999999};  // todo: make c++ correct
    int	  			  	step				{};  // is it evenly divisible by step?
};
class IO_field_spec_decimal 		: IO_field_spec {
public:
    IO_data_type 		data_type   	   {IO_data_type::decimal};
    int 				precision		   {};
    DecimalValueRange   range  	    	   {-999999999999999, 999999999999999};
    short  				significant_values {9999};
    int	  				step			   {};  // is it evenly divisible by step?
};
class IO_field_spec_scientific 	: IO_field_spec {
public:
    IO_data_type 		data_type			{IO_data_type::scientific};
};
using  IO_field_specs_variant = std::variant<
    IO_field_spec_bool,
    IO_field_spec_character,
    IO_field_spec_uint64,
    IO_field_spec_tm,
    IO_field_spec_time_point,
    IO_field_spec_alphanumeric,
    IO_field_spec_integer,
    IO_field_spec_decimal,
    IO_field_spec_scientific
>;

// IO_data_to_cpp_type_map convert_string_value_to_field_type_value(IO_table const & table, unsigned short const num, std::string const & val );

class IO_field {
public:
    std::any 	  field_value	{};
    std::any 	  field_storage_location	{}; // todo: do I need this?

    virtual void 		setField_value(const std::any &value);
    virtual std::any 	getField_value() const;
    virtual bool 	 	validate_input_value( Value_plus const & value_plus ) {
        return true;
    }
    virtual bool 		set_value( Value_plus const & value_plus ) {
        validate_input_value( value_plus );
        return true;
    }
    //virtual ~IO_field();
};

class IO_field_bool : IO_field {
public:
    std::shared_ptr< IO_field_spec > io_field_spec_bool;
    bool validate_input_value( Value_plus const & value_plus ) override final {
        auto [ kb_regular_value, hot_key, file_status ] = value_plus;
        if ( kb_regular_value == "Y" ){
            field_value = true;
        }
            field_value = false;
    }
    //~IO_field_bool();
};

class IO_field_character : IO_field {
public:
    std::shared_ptr< IO_field_spec_character > io_field_spec_alphanumeric;
    bool validate_input_value( Value_plus const & value_plus ) override final {
        auto [ kb_regular_value, hot_key, file_status ] = value_plus;
        field_value = kb_regular_value;
    }
    //~IO_field_bool();
};
class IO_field_uint64 : IO_field {
public:
    std::shared_ptr< IO_field_spec_uint64 > io_field_spec_alphanumeric;
    bool validate_input_value( Value_plus const & value_plus ) override final {
        auto [ kb_regular_value, hot_key, file_status ] = value_plus;
        field_value = kb_regular_value;
    }
    //~IO_field_bool();
};
class IO_field_time_point : IO_field {
public:
    std::shared_ptr< IO_field_spec_time_point > io_field_spec_alphanumeric;
    bool validate_input_value( Value_plus const & value_plus ) override final {
        auto [ kb_regular_value, hot_key, file_status ] = value_plus;
        field_value = kb_regular_value;
    }
    //~IO_field_bool();
};
class IO_field_tm : IO_field {
public:
    std::shared_ptr< IO_field_spec_tm > io_field_spec_alphanumeric;
    bool validate_input_value( Value_plus const & value_plus ) override final {
        auto [ kb_regular_value, hot_key, file_status ] = value_plus;
        field_value = kb_regular_value;
    }
    //~IO_field_bool();
};

class IO_field_alphanumeric : IO_field {
public:
    std::shared_ptr< IO_field_spec_tm > io_field_spec_alphanumeric;
    bool validate_input_value( Value_plus const & value_plus ) override final {
        auto [ kb_regular_value, hot_key, file_status ] = value_plus;
        field_value = kb_regular_value;
    }
    //~IO_field_bool();
};

class IO_field_integer : IO_field {
public:
    std::shared_ptr< IO_field_spec_integer > io_field_spec_alphanumeric;
    bool validate_input_value( Value_plus const & value_plus ) override final {
        auto [ kb_regular_value, hot_key, file_status ] = value_plus;
        field_value = kb_regular_value;
    }
    //~IO_field_bool();
};

class IO_field_decimal : IO_field {
public:
    std::shared_ptr< IO_field_spec_decimal > io_field_spec_alphanumeric;
    bool validate_input_value( Value_plus const & value_plus ) override final {
        auto [ kb_regular_value, hot_key, file_status ] = value_plus;
        field_value = kb_regular_value;
    }
    //~IO_field_bool();
};

#endif // IO_FIELD_H
