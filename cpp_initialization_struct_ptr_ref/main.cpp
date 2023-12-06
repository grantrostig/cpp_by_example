/* Generated as part of Grant's password manager effort to show
 * how to load a data record, or struct or data row
 */

#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <variant>
#include <memory>
#include <typeinfo>

using std::endl, std::cout, std::string, std::vector;

enum class Data_type {
    boolean,
    integer,
    long_integer,
    floating_point,
    alphanumeric
};

class Target_data_row {
public:
    bool 	b1  {true};
    int 	i1	{-9};
    int 	i2	{-99};
    long 	l1	{-999};
    float 	f1	{-999.9};
    string 	s1 	{"Empty"};
};

enum Data_member_index :int {
    B1,
    I1,
    I2,
    L1,
    F1,
    S1
};

/* template <typename T> // NOT USED
class Location_type_map_templated {
public:
    T* 		location;
    T 		member_type;
    Location_type_map_templated( T * ptr) {
        location = ptr;
    }
    void set_location( T * ptr ) {
        location = ptr;
    }
    T * get_location() {
        return location;
    }
};
*/

int main()
{
    {
        class Type_map {
        public:
            void *  	location;
            Data_type  		member_type;
        };

        Target_data_row data_fields1 {};
        vector<Type_map> location_type_map1 {
            { &data_fields1.b1, Data_type::boolean },
            { &data_fields1.i1, Data_type::integer },
            { &data_fields1.i2, Data_type::integer },
            { &data_fields1.l1, Data_type::long_integer },
            { &data_fields1.f1, Data_type::floating_point },
            { &data_fields1.s1, Data_type::alphanumeric }
        };
/*        class Type_map2 {
        public:
            void 		   * location;
            Data_type  			 member_type;
            // https://stackoverflow.com/questions/13906570/how-to-use-typeid-to-store-a-type-info-object
            // also see: https://stackoverflow.com/questions/30159933/how-do-i-store-and-access-a-type-dynamically-in-c
            std::type_info * type_info_name;  // redundant, but we don't have to code each one specifically. likely UNDEFINED BEHAVIOR // TODO what is going on here and how stable is the value and what about the ABI presuming gcc and all compiled at the same time.
        };
        Target_data_row data_fields21 {};
        vector<Type_map2> location_type_map21 {
            { &data_fields1.b1, Data_type::boolean, 		  const_cast<std::type_info *>( &typeid ( decltype (data_fields21.b1))) },
            { &data_fields1.i1, Data_type::integer, 		  const_cast<std::type_info *>( &typeid ( decltype (data_fields21.i1))) },
            { &data_fields1.i2, Data_type::integer, 		  const_cast<std::type_info *>( &typeid ( decltype (data_fields21.i2))) },
            { &data_fields1.l1, Data_type::long_integer,   const_cast<std::type_info *>( &typeid ( decltype (data_fields21.l1))) },
            { &data_fields1.f1, Data_type::floating_point, const_cast<std::type_info *>( &typeid ( decltype (data_fields21.f1))) },
            { &data_fields1.s1, Data_type::alphanumeric,   const_cast<std::type_info *>( &typeid ( decltype (data_fields21.s1))) },
        };
*/
        bool	bool_val1 	{false};
        int		int_val1	{4};
        int		int_val2	{42};
        long	long_val1	{442};
        float	float_val1	{442.4};
        string	string_val2	{"NOT empty."};

        // *(bool *)(location_type_map1.at(0).location) = bool_val1 ;
        *( decltype(bool_val1) * )(location_type_map1.at(0).location) = bool_val1 ;
        cout << "df1.b1: " << data_fields1.b1 << ", "<< bool_val1 << endl;

        *( decltype(float_val1) *)(location_type_map1.at(4).location) = float_val1 ;
        cout << "df1.f1: " << data_fields1.f1 << ", "<< float_val1 << endl;
        //    *((bool *)(location_type_map1.at(0).location)) =+ bool_val1 ;
        //    cout << "df1.b1: " << data_fields1.b1 << ", "<< bool_val1 << endl;
        //    *((float *)(location_type_map1.at(4).location)) =+ float_val1 ;  // todo: minor, this does nothing?
        //    cout << "df1.f1: " << data_fields1.f1 << ", "<< float_val1 << endl;
    }

    {
        class Type_map {
        public:
            std::any 	location;
            Data_type  		member_type;
        };
        Target_data_row data_fields1 {};
        // Type_map a;
        // a.location = &data_fields1.b1;
        vector<Type_map> location_type_map1 {
            { &data_fields1.b1, Data_type::boolean },
            { &data_fields1.i1, Data_type::integer },
            { &data_fields1.i2, Data_type::integer },
            { &data_fields1.l1, Data_type::long_integer },
            { &data_fields1.f1, Data_type::floating_point },
            { &data_fields1.s1, Data_type::alphanumeric }
        };
        bool	bool_val1 	{false};
        int		int_val1	{4};
        int		int_val2	{42};
        long	long_val1	{442};
        float	float_val1	{442.4};
        string	string_val2	{"NOT empty."};

        // *(bool *)(location_type_map1.at(0).location) = bool_val1 ;
        *( std::any_cast< decltype(bool_val1) *>(location_type_map1.at(0).location)) = bool_val1 ;
        cout << "df1.b1: " << data_fields1.b1 << ", "<< bool_val1 << endl;
        *( std::any_cast< decltype(float_val1) *>(location_type_map1.at(4).location)) = float_val1 ;
        cout << "df1.f1: " << data_fields1.f1 << ", "<< float_val1 << endl;
    }
    {
        class Type_map {
        public:
            std::variant< bool *, int *, long *, float *, string * > location;
            Data_type  			member_type;
        };
        Target_data_row data_fields1 {};
        // Type_map a;
        // a.location = &data_fields1.b1;
        vector<Type_map> location_type_map1 {
            { &data_fields1.b1, Data_type::boolean },
            { &data_fields1.i1, Data_type::integer },
            { &data_fields1.i2, Data_type::integer },
            { &data_fields1.l1, Data_type::long_integer },
            { &data_fields1.f1, Data_type::floating_point },
            { &data_fields1.s1, Data_type::alphanumeric }
        };
        bool	bool_val1 	{false};
        int		int_val1	{4};
        int		int_val2	{42};
        long	long_val1	{442};
        float	float_val1	{442.4};
        string	string_val2	{"NOT empty."};

        if ( auto location = std::holds_alternative<bool *> (location_type_map1.at(B1).location))
            cout << "holds_bool_location\n";
        if ( auto location = std::holds_alternative<string *> (location_type_map1.at(B1).location))
            cout << "holds_string_location\n";

        // *(bool *)(location_type_map1.at(0).location) = bool_val1 ;
        auto location = std::get_if< decltype(bool_val1) *>( &location_type_map1.at( B1 ).location );
        **location = bool_val1;
        cout << "df1.b1: " << data_fields1.b1 << ", "<< bool_val1 << endl;

        // *(std::any_cast<float *>(location_type_map1.at(4).location)) = float_val1 ;
        **std::get_if< decltype(float_val1) *>( &location_type_map1.at( F1 ).location ) = float_val1;
        cout << "df1.f1: " << data_fields1.f1 << ", "<< float_val1 << endl;
    }
    cout << "###" << endl;
    return 0;
}
