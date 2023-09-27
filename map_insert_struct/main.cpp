//  created as part of 'Password Manager' application by Grant Rostig
//  fixes problems in this project: set_variant_insert_visit.pro
#include <iostream>  // c++17 gcc 8.3.0-6 debian
#include <map>
#include <tuple>
#include <utility>
using std::endl, std::cout, std::cerr;
struct Struct1 {
    int 		s1_int1 {},	s1_int2 {};
    std::string s1_str1 {};
    struct Key {
        decltype (s1_int1) & key_part1;
        decltype (s1_int2) & key_part2;
    } key   { s1_int1, s1_int2 };
    struct Value {
        decltype (s1_str1) & value_part1;
    } value { s1_str1 };
    struct Compare {
        bool operator()( Key const & lhs, Key const & rhs) const {
            return std::tie( lhs.key_part1, lhs.key_part2 ) < std::tie( rhs.key_part1, rhs.key_part2 );
        }
    };
    void print (std::string message) const {
        cerr<<message<<">> s1_int1:"<< s1_int1<<", s1_int2:"<<s1_int2<<", s1_str1:"<<s1_str1<<endl;
        cerr<<message<<">> key_p1:"<< key.key_part1<<", key_p2:"<<key.key_part2<<", value:"<<value.value_part1<<endl;
    }
};
struct Struct2 {
    using S1_int1_t = short;
    using S1_int2_t = long;
    using S1_str1_t = std::string;
    //S1_int1_t 	& s1_int1 {Struct2::key.key_part1};
    //S1_int2_t	    & s1_int2 {Struct2::key.key_part2};
    //S1_str1_t 	& s1_str1 {Struct2::value.value_part1};
    struct Key {
        S1_int1_t key_part1;
        S1_int2_t key_part2;
    } key;
    struct Value {
        S1_str1_t value_part1;
    } value;
    decltype(Key::key_part1) 	 & s1_int1 {key.key_part1};
    decltype(Key::key_part2)	 & s1_int2 {key.key_part2};
    decltype(Value::value_part1) & s1_str1 {value.value_part1};
    struct Compare {
        bool operator()( Key const & lhs, Key const & rhs) const {
            return std::tie( lhs.key_part1, lhs.key_part2 ) < std::tie( rhs.key_part1, rhs.key_part2 );
        }
    };
    std::pair< Key, Value > get_map_value_pair() {
        return {key,value};
    }
    void print (std::string message) const {
        cerr<<message<<">> s1_int1:"<< s1_int1<<", s1_int2:"<<s1_int2<<", s1_str1:"<<s1_str1<<endl;
        cerr<<message<<">> key_p1:"<< key.key_part1<<", key_p2:"<<key.key_part2<<", value:"<<value.value_part1<<endl;
    }
};
template<typename Key, typename Value>
void print_result( std::pair<Key,Value> const & pair, bool is_inserted ) {
    cerr<<"is_inserted:"<<is_inserted<<", key.key_part1:"<<pair.first.key_part1<<", key.key_part2:"<<pair.first.key_part2<<", value.s1_str1:"<<pair.second.value_part1<<endl;
}
template< typename Map>
void print_map( Map const & my_map ) {
    for (auto & [key,value]:my_map )
        cerr<< "key.key_part1:"<<key.key_part1<<", key.key_part2:"<<key.key_part2<<", value.s1_str1:"<<value.value_part1<<endl;
}
int main()
{
    std::map<Struct1::Key, Struct1::Value, Struct1::Compare > my_map {};
    Struct1 map_value1 {11,12,"s13"}, map_value2 = {21,22,"s23"};
//    map_value1.print("map_value :11");
//    auto const r1 = my_map.insert( {map_value1.key,map_value1.value} );
//    r_print( *r1.first, r1.second );
//    for (auto & [key,value]:my_map )
//        cerr<< "key.key_part1:"<<key.key_part1<<", key.key_part2:"<<key.key_part2<<", value.s1_str1:"<<value.value_part1<<endl;

    map_value1.print("map_value :12a");
    // auto const r1a = my_map.insert( std::make_pair( Struct1::Key {map_value1.s1_int1, map_value1.s1_int2}, map_value1.value) );
    Struct1::Key key = {map_value1.s1_int1, map_value1.s1_int2};
    auto const r1a = my_map.insert( std::make_pair( key, map_value1.value) );
    print_result( *r1a.first, r1a.second ); print_map( my_map );

    map_value2.print("map_value2:21");
    auto const r2 = my_map.insert( std::make_pair( Struct1::Key {map_value2.s1_int1, map_value2.s1_int2}, map_value2.value) );
    // auto const r2 = my_map.insert( {map_value2.key,map_value2.value} );
    print_result( *r2.first, r2.second ); print_map( my_map );

    map_value1.s1_int1 = 31; map_value1.s1_int2 = 32; map_value1.s1_str1 = "s33";
    map_value1.print("map_value :31");
    //auto const r3 = my_map.insert( {map_value1.key,map_value1.value} );
    //auto const r3 = my_map.insert( std::make_pair( Struct1::Key {map_value1.s1_int1, map_value1.s1_int2}, map_value1.value) );
    key.key_part1 = map_value1.s1_int1;
    key.key_part2 = map_value1.s1_int2;
    auto const r3 = my_map.insert( std::make_pair( key, map_value1.value) );
    print_result( *r3.first, r3.second ); print_map( my_map );
    // +++++++++++ use Struct2 in another/new context {} +++++++
  {
    std::map< Struct2::Key, Struct2::Value, Struct2::Compare > my_map {};
    Struct2 map_value1; //  {11,12,"s13"},
    map_value1.s1_int1 = 11; map_value1.s1_int2 = 12; map_value1.s1_str1 = "s13";
    Struct2 map_value2; //  {21,22,"s23"};
    map_value2.s1_int1 = 21; map_value2.s1_int2 = 22; map_value2.s1_str1 = "s23";
    //    map_value1.print("map_value :12");
    //    auto const r1 = my_map.insert( {map_value1.key,map_value1.value} );
    //    r_print( *r1.first, r1.second );
    //    for (auto & [key,value]:my_map )
    //        cerr<< "key.key_part1:"<<key.key_part1<<", key.key_part2:"<<key.key_part2<<", value.s1_str1:"<<value.value_part1<<endl;

    map_value1.print("map_value :11");
    auto const r1a = my_map.insert( {{map_value1.s1_int1, map_value1.s1_int2},{map_value1.s1_str1}} );
    print_result( *r1a.first, r1a.second ); print_map( my_map );

    map_value2.print("map_value2:22");
    auto const r2 = my_map.insert( {{map_value2.s1_int1, map_value2.s1_int2},{map_value2.s1_str1}} );
    print_result( *r2.first, r2.second ); print_map( my_map );

    map_value2.print("map_value2:22");
    auto const r2a = my_map.insert( {map_value2.key,map_value2.value} );
    print_result( *r2a.first, r2a.second ); print_map( my_map );

    map_value1.s1_int1 = 31; map_value1.s1_int2 = 32; map_value1.s1_str1 = "s33";
    map_value1.print("map_value :31");
    //auto const r3 = my_map.insert( {map_value1.key,map_value1.value} );
    //auto const r3 = my_map.insert( {{map_value1.s1_int1, map_value1.s1_int2},{map_value1.s1_str1}} );
    auto const r3 = my_map.insert( map_value1.get_map_value_pair() );
    print_result( *r3.first, r3.second ); print_map( my_map );
  }

    cout << "###" << endl;
    return 0;
}
