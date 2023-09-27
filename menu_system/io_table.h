#ifndef IO_TABLE_H
#define IO_TABLE_H
#include "global_entities.h"
#include "io_field.h"
#include "io_row.h"
// #include "action_io_row.h"

class IO_table_spec{
public:
    std::string 			   name				{"MANDATORY: FILL ME IN!"};
    std::string				   full_description {"FILL full description in!"};
    std::string				   help 			{"FILL help in!"};
    std::array<IO_field_spec,
               IO_ROW_FIELDS_NUM_MAX >
                               fields 	    {};  // todo: use X_MACROs to replace counts  https://stackoverflow.com/questions/12194793/how-do-i-get-the-number-of-members-in-a-structure https://www.embedded.com/reduce-c-language-coding-errors-with-x-macros-part-1/
//  std::shared_ptr<IO_table_spec> 			    parent_table {};  // todo: complete this: work out the pointers
//  std::vector<std::shared_ptr<IO_table_spec>> child_tables {};
    Row_Field_loc_a_val_row_mappings field_validation_fn_mapping {}; // must be initialize later!!
    IO_row					   temp_row			{};
// private:
    void assign_field_validation(unsigned short const field_index, IO_field_spec const &);
public:
    void create_map();
};
// example for the std::vector<> case, instead of the std::array<,7> currently in use : static const IO_table_spec person_table_spec { "person", "The desc.", "The help.", {
//        { "name",			   "Name" },
//        { "age",		 	   "Age", 					 IO_field_spec_integer  { {}, 0, 144 } },
//        { "is_cpp_programmer", "Modern C++_programmer?", IO_field_spec_bool         {             }, "desc", "help", true, "enter data here", "default data not typed in.", "regex", false, guest_user},

class IO_table{
public:
    // std::unique_ptr< IO_table_spec > 			 spec    ;  // todo: should I init it with {}?
    IO_table_spec  			 					 spec    ;  // todo: should I init it with {}?
    std::variant< std::vector< IO_row_person > > rows {};
};

static const IO_table io_table_persons {
    // ***spec*** IO_table_spec {},
    { 		// name
        "person",
            // full_descrition
        "The desc.",
            // help text
        "The help.",
            // fields - init into the array
        {
/* 00 */ "name", 	 			"Name",	                IO_field_spec_alphanumeric { {}, {0, 60}   }, "desc", "help", true, "enter data here", "default data not typed in.", "regex", false, IO_echo_mode::normal, IO_alignment::none, super_user, false, false,
/* 01 */ "balance", 	 		"Balance in account",	IO_field_spec_decimal      { {},  2, {}, {}}, "desc", "help", true, "enter data here", "default data not typed in.", "regex", false, IO_echo_mode::normal, IO_alignment::none, super_user, false, false,
/* 02 */ "age", 	 			"Person's age",	        IO_field_spec_integer      { {}, {0, 144}  }, "desc", "help", true, "enter data here", "default data not typed in.", "regex", true, IO_echo_mode::normal, IO_alignment::none, super_user, false, false,
/* 03 */ "is_cpp_programmer",	"Modern C++_programmer?", IO_field_spec_bool       {               }, "desc", "help", true, "enter data here", "default data not typed in.", "regex", false, IO_echo_mode::normal, IO_alignment::none, guest_user, false, false,
/* 04 */ "date_of_birth",		"Date of Birth",        IO_field_spec_tm           {               }, "desc", "help", true, "enter data here", "default data not typed in.", "regex", true, IO_echo_mode::normal, IO_alignment::none, guest_user, false, false,
/* 05 */ "optional_data",		"Optional text data",	IO_field_spec_alphanumeric { {}, {0, 4048} }, "desc", "help", true, "enter data here", "default data not typed in.", "regex", false, IO_echo_mode::normal, IO_alignment::none, super_user, false, false,
/* 06 */ "yesno", 	    		"Opted in? (Y/N)",		IO_field_spec_bool         {               }, "desc", "help", true, "enter data here", "default data not typed in.", "regex", true, IO_echo_mode::normal, IO_alignment::none, super_user, false, false,
/* 07 */ "system_time_stamp",	"Sytem originated time stamp", IO_field_spec_time_point {    	   }, "desc", "help", true, "enter data here", "default data not typed in.", "regex", false, IO_echo_mode::normal, IO_alignment::none, super_user, true,  false,
/* 08 */ "guid",				"Globally unique",	 	IO_field_spec_uint64   	   {               }, "desc", "help", true, "enter data here", "default data not typed in.", "regex", false, IO_echo_mode::normal, IO_alignment::none, super_user, true,  true,
// ^^ number above should match IO_ROW_FIELDS_NUM_PERSON
        },
            // validations - init
        Row_Field_loc_a_val_row_mappings {
/* 00 */ &io_row_person.name,  							IO_field_spec_alphanumeric {}, 	std::function< void() > {}, false, false ,
/* 01 */ &io_row_person.balance,  						IO_field_spec_decimal {}, 		std::function< void() > {}, false, false ,
/* 02 */ &io_row_person.age,  							IO_field_spec_integer {}, 		std::function< void() > {}, false, false ,
/* 03 */ &io_row_person.is_cpp_programmer,  			IO_field_spec_bool {}, 			std::function< void() > {}, false, false ,
/* 04 */ &io_row_person.date_of_birth,  				IO_field_spec_tm {}, 			std::function< void() > {}, false, false ,
/* 05 */ &io_row_person.optional_data,  				IO_field_spec_alphanumeric {}, 	std::function< void() > {}, false, false ,
/* 06 */ &io_row_person.yesno,  						IO_field_spec_bool {},  	    std::function< void() > {}, false, false ,
/* 07 */ &io_row_person.system_time_stamp,  			IO_field_spec_time_point {},   	std::function< void() > {}, false, false ,
/* 08 */ &io_row_person.guid,  							IO_field_spec_uint64 {}, 	   	std::function< void() > {}, false, false ,
// ^^ number above should match IO_ROW_FIELDS_NUM_PERSON
        },
            // IO_row - init
        IO_row_person {}
    },

    // ***rows*** std::variant< std::vector< IO_row_person >> {}
    std::vector<IO_row_person> {
          //    0							1  2	3	 4     5														  6     7 	8
          // { "Grant Rostig", 	  	    12.34,60,  true, {}, "Is very interested in hearing criticism of this program.", true , {}, 0} // for testing.
    // }
        // we can preload sample data
        //    0							1  2	3	 4     5														  6     7 	8
        { "Grant Rostig", 	  	    12.34,60,  true, {}, "Is very interested in hearing criticism of this program.", true , {}, 0},
        { "Bjarne Stroustup", 		42.42, 0,  true, {}, "Creator of C++, and has guided its development for many years.",  false,  {}, 0},
        { "Mr. Unknown Age",  		00.01, {}, true, {}, "Age is NULL!!", 													false,  {}, 0},
        { "Mr. GUID",  		  		00.0, 99999, true, {},"Default Age is too large!!", 									false,  {}, 0},
        { "Mr. Not C++ Programmer", -5.0,	4, false, {}, "Default Age is too large!!", 									false,  {}, 0},
    }

};

#endif // IO_TABLE_H
