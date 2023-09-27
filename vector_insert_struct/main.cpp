#include <iostream>  // c++17 gcc 8.3.0-6 debian
#include <vector>
#include <tuple>
using std::endl, std::cout, std::cerr;
struct Struct1 {
    int 		s1_int1 {};
    int			s1_int2 {};
    std::string s1_str1 {};
//    struct Key {
//        decltype (s1_int1) & key_part1;
//        decltype (s1_int2) & key_part2;
//    } key   { s1_int1, s1_int2 };
//    struct Value {
//        decltype (s1_str1) & value_part1;
//    } value { s1_str1 };
//    struct Compare {
//        bool operator()( Key const & lhs, Key const & rhs) const {
//            return std::tie( lhs.key_part1, lhs.key_part2 ) < std::tie( rhs.key_part1, rhs.key_part2 );
//        }
//    };
    void print (std::string message) const {
        cerr<<message<<">> s1_int1:"<< s1_int1<<", s1_int2:"<<s1_int2<<", s1_str1:"<<s1_str1<<endl;
    }
};
void r_print( Struct1 const & v ) {
    cerr<<"inserted: key.key_part1:"<<v.s1_int1<<", key.key_part2:"<<v.s1_int2<<", value.s1_str1:"<<v.s1_str1<<endl;
};
//void r_print( std::pair<Struct1::Key,Struct1::Value> const & pair, bool is_inserted ) {
//    cerr<<"is_inserted:"<<is_inserted<<", key.key_part1:"<<pair.first.key_part1<<", key.key_part2:"<<pair.first.key_part2<<", value.s1_str1:"<<pair.second.value_part1<<endl;
//};
int main()
{
    std::vector<Struct1> my_map {};
    Struct1 map_value1 {11,12,"s13"};
    Struct1 map_value2 {21,22,"s23"};
    map_value1.print("map_value :12");
    auto const r1 = my_map.insert(my_map.end(), map_value1 );
    r_print( *r1 );
    for (auto & v:my_map )
        cerr<< "key.key_part1:"<<v.s1_int1<<", key.key_part2:"<<v.s1_int2<<", value.s1_str1:"<<v.s1_str1<<endl;

    map_value2.print("map_value2:22");
    auto const r2 = my_map.insert(my_map.end(), map_value2 );
    r_print( *r2);
    for (auto & v:my_map )
        cerr<< "key.key_part1:"<<v.s1_int1<<", key.key_part2:"<<v.s1_int2<<", value.s1_str1:"<<v.s1_str1<<endl;

    map_value1.s1_int1 = 31; map_value1.s1_int2 = 32; map_value1.s1_str1 = "s33";
    map_value1.print("map_value :31");
    auto const r3 = my_map.insert(my_map.end(), map_value1 );
    r_print( *r3);
    for (auto & v:my_map )
        cerr<< "key.key_part1:"<<v.s1_int1<<", key.key_part2:"<<v.s1_int2<<", value.s1_str1:"<<v.s1_str1<<endl;
    cout << "###" << endl;
    return 0;
}
