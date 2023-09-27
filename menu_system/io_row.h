#ifndef IO_ROW_H
#define IO_ROW_H
#include <string>
#include <vector>
#include <variant>
#include <optional>
#include <chrono>
#include <ctime>
#include <any>
#include <functional>

#include "global_entities.h"
#include "io_field.h"

// #include <io_table.h>
class IO_table;

enum class IO_row_spec {  // https://www.w3schools.com/html/html_form_attributes.asp
    auto_complete,
    no_validate
};

class Field_location_a_validation {
public:
    std::any 				field_location 		{};
    IO_field_specs_variant	io_field_specs_variant 	{};
    std::function< void() >	validate_value_fn 	{};
//    bool					is_greyed_out 	 	{false};
//    bool					is_initial_focus 	{false};
};

// using Field_loc_a_val_persons = std::array< Field_location_a_validation, 9 >;
using Row_Field_loc_a_val_row_mappings = std::array< Field_location_a_validation, IO_ROW_FIELDS_NUM_MAX >; // todo: magic number for max_fields

//class IO_row {
//    std::vector<IO_field> fields;
//};

class IO_row_company { // just a stub to demonstrate the type
};

class IO_row_person {
public:
 //vector<std::unique_ptr<IO_data_type>  todo: should this be part of the design?
 // NOTE: any std::optional<> data member should NOT have an initializer providing a value! This is depeneded upon in set_field_num();
 /* 00 */ std::string						  name				{};
 /* 01 */ double							  balance			{0.02};
 /* 02 */ std::optional<int> 	 			  age				{};    // NOTE: std::optional here allows for a "NULLable field" in the sense of SQL.
 /* 03 */ bool								  is_cpp_programmer {};    // todo: how to represent NOTHING or std::monostate?
 /* 04 */ std::optional<std::tm>			  date_of_birth 	{};  // this is a human readable C type, C++20 has a replacement.
 /* 05 */ std::string 						  optional_data 	{};  // NOTE: an optional string field is not NULLable, but can be blank
 /* 06 */ std::optional<bool>   			  yesno 			{};
 /* 07 */ std::chrono::system_clock::time_point system_time_stamp {};  // todo:  TODO is this even human readable in a decent format?  c++20?
 /* 08 */ uint64_t							  guid				{};
 // ^^ number above should match IO_ROW_FIELDS_NUM_PERSON

    bool set_row_field_at_num( IO_table table, unsigned short const num, std::string const & val );
};

static IO_row_person io_row_person {};

/* Holds IO_fields for a row during data entry as it is validated and collected.
 * And acts as source to place data into the struct/record/row of the table.
 */
using IO_row = std::variant<
    IO_row_company,
    IO_row_person
>;



#endif // IO_ROW_H
