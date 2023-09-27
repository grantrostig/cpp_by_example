#include <chrono>
#include "io_row.h"
#include "io_table.h"


// Invariant: All values should be set, unless it is a std::optional<>,
//            otherwise the value will contain the initializer value,
//            which the end_user probably did not know about or expect.

bool IO_row_person::set_row_field_at_num(IO_table table, const unsigned short field_num, const std::string &val){
    bool is_set {false};
    switch (field_num) {
    case 0:
        name  				= std::get< double >(convert_string_value_to_field_type_value( table, field_num, val ));
        is_set = true;
        break;
    case 1:
        balance   			= std::get< double >(convert_string_value_to_field_type_value( table, field_num, val ));
        is_set = true;
        break;
    case 2:
        age   				= std::get< int >(convert_string_value_to_field_type_value( table, field_num, val ));
        is_set = true;
        break;
    case 3:
        is_cpp_programmer 	= std::get< bool >(convert_string_value_to_field_type_value( table, field_num, val ));
        is_set = true;
        break;
    case 4:
        date_of_birth 		= std::get< std::tm >(convert_string_value_to_field_type_value( table, field_num, val));  // example of user supplied date
        is_set = true;
        break;
    case 5:
        optional_data 		= std::get< std::string >(convert_string_value_to_field_type_value( table, field_num, val));
        is_set = true;
        break;
    case 6:
        yesno 	 			= std::get< bool >(convert_string_value_to_field_type_value( table, field_num, val ));
        is_set = true;
        break;
    case 7:
        system_time_stamp  	= std::get< std::chrono::system_clock::time_point >(convert_string_value_to_field_type_value( table, field_num, val ));
        is_set = true;
        break;
    case 8:
        // guid
        is_set = false;
        throw std::logic_error( "set_field_num():FATAL ERROR:non-user input data type not supported");  // example of GUID.
    }
     // ^^ number above should match IO_ROW_FIELDS_NUM_PERSON
    return is_set;
}
