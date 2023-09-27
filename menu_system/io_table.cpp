#include "io_table.h"
#include "action_io_row.h"

// void IO_table_spec::assign_field_validation( /*OUT*/ Row_Field_loc_a_val_row_mappings &row_mappings, unsigned short const field_index, IO_field_spec const &spec) {
void IO_table_spec::assign_field_validation( unsigned short const field_index, IO_field_spec const &spec) {
    if (        auto fs = std::get_if< IO_field_spec_bool >		( &spec.field_spec )) {
        field_validation_fn_mapping.at( field_index ).validate_value_fn = &validate_bool_value;
    } else if ( auto fs = std::get_if< IO_field_spec_character >( &spec.field_spec )) {

    } else if ( auto fs = std::get_if< IO_field_spec_uint64 >   ( &spec.field_spec )) {

    } else if ( auto fs = std::get_if< IO_field_spec_time_point >( &spec.field_spec )) {

    } else if ( auto fs = std::get_if< IO_field_spec_tm >        ( &spec.field_spec )) {

    } else if ( auto fs = std::get_if< IO_field_spec_alphanumeric >( &spec.field_spec )) {
        field_validation_fn_mapping.at( field_index ).validate_value_fn = &validate_alphanumeric_value;
    } else if ( auto fs = std::get_if< IO_field_spec_integer >	 ( &spec.field_spec )) {

    } else if ( auto fs = std::get_if< IO_field_spec_decimal >	 ( &spec.field_spec )) {

    } else throw std::logic_error( "unknown IO_field_spec.");

    // = spec.field_spec;
    // criteria.default_handling
}

void IO_table_spec::create_map() {
    // if (person) {
    unsigned short field_index {0};
    for (auto field_var_ptr: fields ) {
        assign_field_validation( field_index, fields.at( field_index ) );
        ++field_index;
    }
}
