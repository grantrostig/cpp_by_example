//  created as part of 'Password_Manager' AKA 'file_maintenance' application by Grant Rostig
//  IGNORE this Broken code, we have mostly fixed this, but the solution is in this project: map_insert_struct.pro
#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <map>
#include <memory>
#include <tuple>
using std::endl, std::cout, std::cerr;

template<typename Key, typename Value>
void print_result( std::pair<Key,Value> const & pair, bool is_inserted ) {
    cerr<<"is_inserted:"<<is_inserted<<", key.key_part1:"<<pair.first.key_part1<<", key.key_part2:"<<pair.first.key_part2<<", value.s1_str1:"<<pair.second.value_part1<<endl;
}

template< typename Map>
void print_map( Map const & my_map ) {
    for (auto & [key,value]:my_map )
        cerr<< "key.key_part1:"<<key.key_part1<<", key.key_part2:"<<key.key_part2<<", value.s1_str1:"<<value.value_part1<<endl;
}

/*struct Struct1 { // old version only works for vector of variant
    int 		s1_int1 {};
    int 		s1_int2 {};
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
    void print () const {
        cerr << "s1_int1:" << s1_int1<<", s1_int2:" << s1_int2 << ", s1_str1:" << s1_str1 <<endl;
    }
};*/

struct Struct1 {
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

struct Struct2 {
    int 		s2_int1 {};
    std::string s2_str1 {};
    void print (std::string message) const {
        cerr <<message<< "s2_str1:" << s2_str1 <<endl;
    }
};

struct Struct3 {
    struct Key {
        int s3_int1 {};
        int s3_int2 {};
    } key;
    struct Value {
        std::string S3_str1 {};
    } value;
};
Struct3 junk3 { {1,2},{"junk"}};

struct Struct4 {
    struct Key {
        int s4_int1 {};
        int s4_int2 {};
    } key;
    struct Value {
        std::string S4_str1 {};
    } value;
    //std::tuple<Key &, Value & > record;
    std::pair<Key, Value > record;
    // Struct4( Key k_, Value v_): key(k_), value(v_) {
        // decltype (pair) pair2 =  std::tie<key,value>;
        // record = {&key, &value};
        // record = {std::forward_as_tuple(key), std::forward_as_tuple(value)};
        // std::get<0>(record) = key;
        // std::get<1>(record) = value;
        //std::get<0>(record) = key;
        //std::get<1>(record) = value;
    // }
};

struct Struct5 {
    struct Key {
        int s5_int1 {};
        int s5_int2 {};
    };
    struct Value {
        std::string S5_str1 {};
    };
    // std::pair<Struct5::Key, Struct5::Value > record;
    std::pair<Key, Value > record;
    struct Compare {
    bool operator()( Struct5::Key const & lhs, Struct5::Key const & rhs) const {
        return std::tie( lhs.s5_int1, lhs.s5_int2 ) < std::tie( rhs.s5_int1, rhs.s5_int2 );
    }
};
};
//Struct5 junk5 { std::make_pair( {1,2}, "str") };

struct Key {
    int s5_int1;
    int s5_int2;
};
struct Value {
     std::string S5_str1 {};
};
struct Struct6 {
    std::pair<Key,Value> record;
};

struct Struct7 {
    std::pair<Value, Value> record;
};
std::string str="hi";

using StructVariant =  std::variant<Struct1, Struct2>;

/*struct IndexStruct1 {
//    decltype (Struct1::s1_int1) key_part1;
//    decltype (Struct1::s1_int2) key_part2;
//};
*/

struct IndexStruct2 {
    decltype (Struct2::s2_int1) key_part1;
};

using IndexVariant = std::variant< Struct1::Key, IndexStruct2>;

struct IndexStruct1_compare {
    bool operator()( Struct1::Key const & lhs, Struct1::Key const & rhs) const {
        return std::tie( lhs.key_part1, lhs.key_part1 ) < std::tie( rhs.key_part2, rhs.key_part2) ;
    }
};

struct IndexStruct2_compare {
    bool operator()( IndexStruct2 const & lhs, IndexStruct2 const & rhs) const {
        return lhs.key_part1 < rhs.key_part1;
    }
};

struct IndexStruct3_compare {
    bool operator()( Struct3::Key const & lhs, Struct3::Key const & rhs) const {
        return std::tie( lhs.s3_int1, lhs.s3_int1 ) < std::tie( rhs.s3_int1, rhs.s3_int2 );
    }
};

struct IndexStruct4_compare {
    bool operator()( Struct4::Key const & lhs, Struct4::Key const & rhs) const {
        return std::tie( lhs.s4_int1, lhs.s4_int1 ) < std::tie( rhs.s4_int1, rhs.s4_int2 );
    }
};

struct IndexStruct5_compare {
    bool operator()( Struct5::Key const & lhs, Struct5::Key const & rhs) const {
        return std::tie( lhs.s5_int1, lhs.s5_int2 ) < std::tie( rhs.s5_int1, rhs.s5_int2 );
    }
};

using CompareVariant = std::variant< Struct1::Compare, IndexStruct2_compare >;

class Visit_vector_test {
public:
    std::vector< StructVariant > structs_container { Struct1 {11,12,"struct1"}, Struct2 {21,"struct2"} };
    StructVariant  new_struct { Struct1 {98,99,"struct1_added"} };
    void insert_struct () {
        std::variant< std::vector< StructVariant > *> structs_container_kludge { &structs_container };

        std::visit( [] (auto & structs_container, auto const & my_struct) {
            structs_container->emplace_back(my_struct);
            cerr<<"visit()::structs.size(): "<<structs_container->size()<<", ";
            my_struct.print("visit_vector_test:");
        }, structs_container_kludge, new_struct );
    }
};

class Visit_map_test {
public:
    // std::map< IndexVariant, StructVariant, CompareVariant       > structs_container1 {};  // { Struct1 {11,12,"struct1"}, Struct2 {21,"struct2"} };
    std::map< Struct1::Key, Struct1, Struct1::Compare > structs_container2 {};  // { Struct1 {11,12,"struct1"}, Struct2 {21,"struct2"} };
    std::map< IndexVariant, StructVariant             > structs_container {};  // { Struct1 {11,12,"struct1"}, Struct2 {21,"struct2"} };
    StructVariant  new_struct { Struct1 {98,99,"struct1_added"} };
    void insert_struct () {
        std::variant< std::map< IndexVariant, StructVariant > *> structs_container_kludge { &structs_container };

        std::visit( [] (auto & structs_container, auto const & my_struct) {
            struct {int a; int b;} key {1,2};
      //      structs_container->insert( key, my_struct );
            cerr<<"visit()::structs.size(): "<<structs_container->size()<<", ";
            my_struct.print("visit_map_test");
        }, structs_container_kludge, new_struct );
    }
};

void insert_test1() {
    std::map<Struct1::Key, Struct1::Value, Struct1::Compare > my_map {};
    //Struct1::Key     key   {11,12};
    //Struct1::Value 	 value {11,12,"s1"};
    Struct1 	 map_value {11,12,"s13"};
    map_value.print("insert_test():");
    // my_map[map_value.key] = map_value.value;  // TODO
    auto const [ignore, is_insert1] = my_map.insert( {map_value.key,map_value.value} );
    cerr << is_insert1<<endl;
    map_value.print("insert_test():");
    Struct1 	map_value2 = {21,22,"s23"};
    map_value2.print("insert_test():");
    auto const [ignore2, is_insert2] = my_map.insert( {map_value2.key,map_value2.value} );
    cerr << is_insert2<<endl;
    map_value2.print("insert_test():");
    map_value.print("insert_test():");
    map_value.s1_int1 = 31;  // DOES std::vector do this also!?!?!
    map_value.s1_int2 = 32;
    map_value.s1_str1 = "s33";
    map_value.print("insert_test():");
    auto const [ignore3, is_insert3] = my_map.insert( {map_value.key,map_value.value} );
    cerr << is_insert3<<endl;
    //my_map.emplace( key,value );
    for (auto & [key,value]:my_map )
        //cerr<< "key.key_part1:"<<key.key_part1<<", key.key_part2:"<<key.key_part2<<", value.s1_int1:"<<value.s1_int1<<", value.s1_int2:"<<value.s1_int2<<", value.s1_str1:"<<value.s1_str1<<endl;
        cerr<< "key.key_part1:"<<key.key_part1<<", key.key_part2:"<<key.key_part2<<", value.s1_str1:"<<value.value_part1<<endl;
}

void insert_test3() {
    using Record_pair = std::pair< Struct3::Key, Struct3::Value >;
    std::map<Struct3::Key, Struct3::Value, IndexStruct3_compare > my_map {};
    Struct3 record { {11,12}, {"s1"} };
    my_map[record.key] = record.value;
    record = 	   { 98, 99, "map.insert()" };
    record.key =   { 98, 99 };
    record.value = { "map.insert()" };
    Record_pair value3 = {record.key, record.value};
    // my_map.emplace(record.key, record.value);
    // my_map.insert( {record.key, record.value} );
    my_map.insert( value3 );
}

void insert_test4() {
    std::map<Struct4::Key, Struct4::Value, IndexStruct4_compare > my_map {};
    // Struct4 record { {11,12}, {"s1"}, { { {11,12}, {"str"} } } };
    Struct4 record {};
    // auto junk = std::make_pair(1,2);
    // my_map[record.key] = record.value;
    // record = 	   { 98, 99, "map.insert()" };
    record.key =   { 98, 99 };
    record.value = { "map.insert()" };
    my_map.emplace( record.key, record.value);
    my_map.insert( {record.key, record.value} );

    using Map_value = std::pair<Struct4::Key, Struct4::Value>;
    Map_value value4 = {record.key, record.value};
    my_map.insert( value4 );
    my_map.emplace( value4 );
}

void insert_test5() {
    std::map<Struct5::Key, Struct5::Value, Struct5::Compare > my_map {};
    Struct5 map_value  { {{11,12}, {"str"}} } ;
    my_map.insert( {std::get<0>(map_value.record), std::get<1>(map_value.record)} ) ;
    map_value = { {{21,22}, {"str"}} } ;
    my_map.insert( {map_value.record.first, map_value.record.second } ) ;
    map_value = { {{41,42}, {"str"}} } ;
    my_map.insert(  map_value.record ) ;
    map_value = { {{51,52}, {"str"}} } ;
    my_map.emplace( map_value.record.first, map_value.record.second );
    map_value = { {{61,62}, {"str"}} } ;
    my_map.emplace( map_value.record );

    //my_map.insert( std::pair<Struct5::Key, Struct5::Value>( {1,2}, "str" ) );
    //Struct5 record2 { {11,12}, "str5"};
    //Struct5 record { std::make_tuple( Struct5::Key {11,12}, "str5")};

}

int main()
{
    insert_test1();
    //insert_test3();
    insert_test5();

    Visit_vector_test test {};
    test.insert_struct();
    cout << "test.structs_container.size(): "<< test.structs_container.size()<<endl<<"Print final results:\n";
    for (auto & s: test.structs_container )
        std::visit( [] (auto & s) { s.print("visit_vector_test result:"); }, s);
    cout << "------------------------" << endl;

    Visit_map_test test2 {};
    test2.insert_struct();
    cout << "test2.structs_container.size(): "<< test2.structs_container.size()<<endl<<"Print final results:\n";
    //for (auto & [ key,value ]: test2.structs_container )
        // std::visit( [] (auto & s) { *value.print(); }, value);

    cout << "###" << endl;
    return 0;
}
