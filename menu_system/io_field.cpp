#include <chrono>
#include "io_field.h"
#include "io_table.h"

//IO_data_to_cpp_type_map convert_string_value_to_field_type_value(const IO_table &table, const unsigned short num, const std::string &val) {

//    if (        std::holds_alternative< IO_field_spec_bool >( table.spec.fields.at(num).field_spec ) ) {
//        return val == "Y" ? true : false;

//    } else if ( std::holds_alternative< IO_field_spec_character >( table.spec.fields.at(num).field_spec )) {
//        if ( val.length() == 0 ) return {};  // todo: should return std::monostate?
//        else if (val.length() == 1 ) return val[0];
//        else throw std::logic_error( "value_to_field():FATAL ERROR: expecting zero or one characters and got more than one in a string." );

//    } else if ( std::holds_alternative< IO_field_spec_uint64 >( table.spec.fields.at(num).field_spec )) {
//        throw std::logic_error( "value_to_field():FATAL ERROR: disallowed IO_field_spec_*" );

//    } else if ( std::holds_alternative< IO_field_spec_time_point >( table.spec.fields.at(num).field_spec )) {
//        throw std::logic_error( "value_to_field():FATAL ERROR: disallowed IO_field_spec_*" );

//    } else if ( std::holds_alternative< IO_field_spec_tm >( table.spec.fields.at(num).field_spec )) {
//        std::tm my_tm = {0,0,0,27,10,85
                         
//                         std::any IO_field_spec::getField_value() const
//                         {
//                             return field_value;
//                         }
                         
//                         void IO_field_spec::setField_value(const std::any &value)
//                         {
//                             field_value = value;
//                         }
                         
//                          ,4,365,-1,0,""};  // todo: complete this: perform transformation of date string to tm.
//                         return my_tm;
                         
//                        } else if ( std::holds_alternative< IO_field_spec_alphanumeric >( table.spec.fields.at(num).field_spec )) {
//        return val;

//    } else if ( std::holds_alternative< IO_field_spec_integer >( table.spec.fields.at(num).field_spec )) {
//        return stol( val );

//    } else if ( std::holds_alternative< IO_field_spec_decimal >( table.spec.fields.at(num).field_spec )) {
//        return stod( val );

//    } else
//        throw std::logic_error( "value_to_field():FATAL ERROR: unknown IO_field_spec_*" );
//}
