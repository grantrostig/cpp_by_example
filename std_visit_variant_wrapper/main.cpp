/* Created as part of 'Password Manager' application by Grant Rostig
 * Study: std::visit std::variant
   Preparation for password_manager and file_maintenance projects.
 * Author: Grant Rostig
 * License: BOOST */
#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <memory>
#include <cassert>
#include <map>
using namespace std;

struct Struct1 {
    int a {};
    void print () const {
        cerr << "a:" << a <<endl;
    }
};

struct Struct2 {
    std::string b {};
    void print () const {
        cerr << "b:" << b <<endl;
    }
};

struct Struct1m {
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
    std::pair< Key, Value > get_map_value_pair() const {
        return {key,value};
    }
    void print (std::string message) const {
        cerr<<message<<">> s1_int1:"<< s1_int1<<", s1_int2:"<<s1_int2<<", s1_str1:"<<s1_str1<<endl;
        cerr<<message<<">> key_p1:"<< key.key_part1<<", key_p2:"<<key.key_part2<<", value:"<<value.value_part1<<endl;
    }
};

struct Struct2m {
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
    std::pair< Key, Value > get_map_value_pair() const {
        return {key,value};
    }
    void print (std::string message) const {
        cerr<<message<<">> s1_int1:"<< s1_int1<<", s1_int2:"<<s1_int2<<", s1_str1:"<<s1_str1<<endl;
        cerr<<message<<">> key_p1:"<< key.key_part1<<", key_p2:"<<key.key_part2<<", value:"<<value.value_part1<<endl;
    }
};

struct Struct1mv {
    using S1_int1_t = short;
    using S1_int2_t = long;
    using S1_str1_t = std::string;
    //S1_int1_t 	& s1_int1 {Struct2::key.key_part1};
    //S1_int2_t	    & s1_int2 {Struct2::key.key_part2};
    //S1_str1_t 	& s1_str1 {Struct2::value.value_part1};
    struct Key {
        S1_int1_t key_part1 {};
        S1_int2_t key_part2 {};
    } key {};
    struct Value {
        S1_str1_t value_part1 {};
    } value {};
    decltype(Key::key_part1) 	 & s1_int1 {key.key_part1};
    decltype(Key::key_part2)	 & s1_int2 {key.key_part2};
    decltype(Value::value_part1) & s1_str1 {value.value_part1};
//    Struct1mv & operator=( Struct1mv && other) {
//        key.key_part1 = other.key.key_part1;
//        key.key_part2 = other.key.key_part2;
//        value.value_part1 = other.value.value_part1;
//        other.key.key_part1 = 0;
//        other.key.key_part2 = 0;
//        other.value.value_part1 = "";
//        return *this;
//    }
    struct Compare {
        bool operator()( Key const & lhs, Key const & rhs) const {
            return std::tie( lhs.key_part1, lhs.key_part2 ) < std::tie( rhs.key_part1, rhs.key_part2 );
        }
    };
    Struct1mv get_map_value_pair() const {
        return {key,value};
    }
//    Struct1mv get_map_value_pair() const {  TODO what does this do and why doesn't it work when used?
//        return {std::move(key),std::move(value)};
//    }
    //Struct1mv & get_map_value_pair() const {  TODO what does this do and why doesn't it work when used?
        //return {std::move(key),std::move(value)};
    //}
    Struct1mv get_struct() const {
        return {key,value};
    }
    void print (std::string message) const {
        // cerr<<message<<">> s1_int1:"<< s1_int1<<", s1_int2:"<<s1_int2<<", s1_str1:"<<s1_str1<<endl;
        cerr<<message<<">> key_p1:"<< key.key_part1<<", key_p2:"<<key.key_part2<<", value:"<<value.value_part1<<endl;
    }
};

using StructVariant =  std::variant<Struct1, Struct2>;

class Test_vector_of_variant {
public:
    StructVariant                new_struct       { Struct1 {99} };
    std::vector< StructVariant > existing_structs { Struct1 {42}, Struct2 {"a Struct2"} };

    void insert_struct () {
        std::variant< std::vector< StructVariant > *> existing_structs_kludge { &existing_structs };
        // std::variant< unique_ptr< vector< StructVariant >>> structs_kludge { unique_ptr< vector< StructVariant >>(&structs) };  // todo: TODO why FAILS to mutate the vector?
        // std::variant< unique_ptr< vector< StructVariant >>> structs_kludge { make_unique< vector< StructVariant >>(structs) };  // todo: TODO why FAILS to mutate the vector?

        std::visit( [] (auto existing_structs, auto const & my_struct) {
                existing_structs->emplace_back( my_struct );
                cerr<<"visit()::structs.size(): "<<existing_structs->size()<<endl;
                my_struct.print();
        }, existing_structs_kludge, new_struct );
    }
};

using Vector1 = std::vector<Struct1>;
using Vector2 = std::vector<Struct2>;
using VectorVariant =  std::variant<Vector1, Vector2>;
class Test_variant_of_vector {
public:
    Struct1 new_struct1 {99};
    Struct2 new_struct2 {"a Struct2"};
    VectorVariant existing_vector1 { Vector1 { Struct1 {1}, Struct1 {2}, Struct1 {3}, } };
    VectorVariant existing_vector2 { Vector2 { Struct2 {"a Struct2"}, Struct2 {"a Struct2"}, Struct2 {"a Struct2"}, } };

    void insert_struct () {
        std::variant< Struct1 *, Struct2 *> new_struct_kludge1 { & new_struct1 };
        struct EmplaceParensFnVariant {
            void operator()( Vector1 & existing_vector, Struct1 const * new_struct_ptr ) {
                // existing_vector.emplace_back( * new_struct_ptr );
                existing_vector.insert( existing_vector.end(), * new_struct_ptr );
                cerr<<"visit()::structs.size(): "<<existing_vector.size()<<endl;
                new_struct_ptr->print();
            }
            void operator()( Vector2 & existing_vector, Struct2 const * new_struct_ptr ) {
                existing_vector.emplace_back( * new_struct_ptr );
                cerr<<"visit()::structs.size(): "<<existing_vector.size()<<endl;
                new_struct_ptr->print();
            }
            void operator()( Vector1 & , Struct2 const * ) { assert(false); }
            void operator()( Vector2 & , Struct1 const * ) { assert(false); }
        };
        std::visit( EmplaceParensFnVariant()
                //[] (auto & existing_vector1, auto const my_struct) {
                //existing_vector1.emplace_back( * my_struct );
                // cerr<<"visit()::structs.size(): "<<existing_vector1.size()<<endl;
                // my_struct->print();
                //}
            , existing_vector1, new_struct_kludge1 );
    }
};

using Map1      = std::map<Struct1m::Key, Struct1m::Value, Struct1m::Compare>;
using Map2 		= std::map<Struct2m::Key, Struct2m::Value, Struct2m::Compare>;
using MVector1  = std::vector<Struct1mv>;
using MapVariant =  std::variant<Map1, Map2, MVector1>;
class Test_variant_of_map {
public:
    Struct1m 	new_struct1m 	{ {97, 98}, {"1m_99struct1"}};
    Struct2m 	new_struct2m 	{ {97, 98}, {"2m_99Struct2"}};
    Struct1mv 	new_struct1mv 	{ {97, 98}, {"1mv_99Struct1"}};
    MapVariant 	existing_Map1 	{ Map1 {
            make_pair( Struct1m::Key {11,12}, Struct1m::Value {"1m_str12"} ),
            make_pair( Struct1m::Key {21,22}, Struct1m::Value {"1m_tr23"} ),
            make_pair( Struct1m::Key {31,32}, Struct1m::Value {"1m_str33"} )
    }};
    MapVariant 	existing_Map2 	{ Map2 {
            make_pair( Struct2m::Key {11,12},Struct2m::Value {"2m_str12"} ),
            make_pair( Struct2m::Key {21,22},Struct2m::Value {"2m_str22"} ),
            make_pair( Struct2m::Key {31,32},Struct2m::Value {"2m_str33"} )
    }};
    MapVariant 	existing_mvector1 	{ MVector1 {
            { Struct1mv::Key {11,12}, Struct1mv::Value {"1mv_str12"} },
            { Struct1mv::Key {21,22}, Struct1mv::Value {"1mv_str22"} },
            { Struct1mv::Key {31,32}, Struct1mv::Value {"1mv_str32"} }
    }};
    void insert_struct () {
        /* std::variant< Struct1m *, Struct2m *> new_struct_kludge1 { & new_struct1 };
        struct EmplaceParensFnVariant {
            void operator()( Map1 & existing_map, Struct1m const * new_struct_ptr ) {
                existing_map.insert( new_struct_ptr->get_map_value_pair() );
                cerr<<"visit()::structs.size(): "<<existing_map.size()<<endl;
                new_struct_ptr->print("Map1, post insert:");
            }
            void operator()( Map2 & existing_map, Struct2m const * new_struct_ptr ) {
                existing_map.insert( new_struct_ptr->get_map_value_pair() );
                cerr<<"visit()::structs.size(): "<<existing_map.size()<<endl;
                new_struct_ptr->print("Map1, post insert:");
            }
            void operator()( Map1 & , Struct2m const * ) { assert(false); }
            void operator()( Map2 & , Struct1m const * ) { assert(false); }
        };
        std::visit( EmplaceParensFnVariant()
                   //[] (auto & existing_vector1, auto const my_struct) {
                   //existing_vector1.emplace_back( * my_struct );
                   // cerr<<"visit()::structs.size(): "<<existing_vector1.size()<<endl;
                   // my_struct->print();
                   //}
                   , existing_Map1, new_struct_kludge1 );
*/
        using Data_variant = std::variant<
            std::pair< Map1 &,     Struct1m>,
            std::pair< Map2 &,     Struct2m>,
            std::pair< MVector1 &, Struct1mv>
            >;
        struct EmplaceParensFnVariant {
            void operator()( std::pair< Map1 &, Struct1m> & data_pair) {
                data_pair.first.insert( data_pair.second.get_map_value_pair() );
                cerr<<"visit()::structs.size(): "<<data_pair.first.size()<<endl;
                data_pair.second.print("Map1, post insert:");
            }
            void operator()( std::pair< Map2 &, Struct2m> & data_pair) {
                data_pair.first.insert( data_pair.second.get_map_value_pair() );
                cerr<<"visit()::structs.size(): "<<data_pair.first.size()<<endl;
                data_pair.second.print("Map2, post insert:");
            }
            void operator()( std::pair< MVector1 &, Struct1mv> & data_pair) {
                data_pair.first.push_back( data_pair.second );  // OK
                data_pair.first.emplace_back( std::move(data_pair.second) );  // OK
                data_pair.first.emplace_back( data_pair.second );  // OK
                //data_pair.first.emplace_back( data_pair.second ); // OK
                // data_pair.first.insert( data_pair.first.end(), std::move( data_pair.second.get_map_value_pair() ) );  // error2
                data_pair.first.insert( data_pair.first.end(), data_pair.second.get_map_value_pair() );  // error2
                // data_pair.first.insert( data_pair.first.end(), data_pair.second.get_map_value_pair() );  // error2
                //data_pair.first.insert( data_pair.first.end(), {data_pair.second.s1_int1, data_pair.second.s1_int2, data_pair.second.s1_str1} );
                //data_pair.first.insert( data_pair.first.end(), Struct1m {Struct1m::Key {data_pair.second.key.key_part1, data_pair.second.key.key_part2}, Struct1m::Value {data_pair.second.value}} );
                // Struct1mv kludge = data_pair.second;  // error1
                // Struct1Struct1mvmv kludge = data_pair.second.get_map_value_pair(); // error1
                // Struct1mv kludge = { data_pair.second.key.key_part1, data_pair.second.key.key_part2, data_pair.second.value.value_part1 }; error1
                // data_pair.first.insert( data_pair.first.end(), std::move(kludge) );  // todo: TODO: why does his fail if struct has reference members? error
                // data_pair.first.insert( data_pair.first.end(), data_pair.second );  // todo: TODO: why does his fail if struct has reference members?
                // data_pair.first.insert( data_pair.first.end(), std::move(data_pair.second) );  // todo: TODO: why does his fail if struct has reference members?
                // data_pair.first.insert( data_pair.first.end(), data_pair.second.get_struct() );  // todo: TODO: why does his fail if struct has reference members?
                //data_pair.first.emplace( data_pair.first.end(), std::move(data_pair.second) );  // todo: TODO: why does his fail if struct has reference members?
                cerr<<"visit()::structs.size(): "<<data_pair.first.size()<<endl;
                data_pair.second.print("Map2mv, post insert:");
            }
        };
        //Data_variant data_pair2 { make_pair(std::get<1>(existing_Map2), new_struct2m) };  // not enough type info
        Data_variant data_pair1{ std::pair<Map1 &,Struct1m> { std::get<0>(existing_Map1), new_struct1m} };
        std::visit( EmplaceParensFnVariant(), data_pair1 );
        Data_variant data_pair2 {    std::pair<Map2 &,     Struct2m> { std::get<1>(existing_Map2), new_struct2m} };
        std::visit( EmplaceParensFnVariant(), data_pair2 );
        Data_variant data_pair_mv1 { std::pair<MVector1 &, Struct1mv> { std::get<2>(existing_mvector1), new_struct1mv } };
        // MVector1 & foo();  () instead of {} can be more reliable.
        //Data_variant data_pair_mv1 { std::pair<MVector1 &, Struct1mv> ( foo, new_struct1mv ) };
        //MVector1 & foo2 {position(1),};
        //Data_variant data_pair_mv1 { std::pair<MVector1 &, Struct1mv> { MVector1 {}, Struct1mv {} } };
        std::visit( EmplaceParensFnVariant(), data_pair_mv1 );
    }
};

int main()
{
    Test_vector_of_variant test_vec_v {};
    test_vec_v.insert_struct();
    cout << "stucts_obj.structs.size(): "<< test_vec_v.existing_structs.size()<<endl;
    cout << "print final result:\n";
    for (auto & s: test_vec_v.existing_structs )
        std::visit( [](auto & s) {s.print();}, s);

    cout << "---------" << endl;
    Test_variant_of_vector test_vv {};
    test_vv.insert_struct();
    cout << "stucts_obj.structs.size(): "<< std::get<0>(test_vv.existing_vector1).size()<<endl;
    cout << "print final result:\n";
    for (auto & s: std::get<0>(test_vv.existing_vector1) )
        //std::visit( [](auto & s) {s.print();}, s);
        s.print();

    cout << "---------" << endl;
    Test_variant_of_map test_vm {};
    test_vm.insert_struct();
    cout << "stucts_obj.structs.size(): "<< std::get<0>(test_vv.existing_vector1).size()<<endl;
    cout << "print final result:\n";
    for (auto & s: std::get<0>(test_vm.existing_Map1) ) {
        Struct1m map_value1 = {s.first.key_part1,s.first.key_part2,s.second.value_part1};
        map_value1.print("Map1,final_print:");
    }
    for (auto & s: std::get<1>(test_vm.existing_Map2) ) {
        Struct1m map_value1 = {s.first.key_part1,s.first.key_part2,s.second.value_part1};
        map_value1.print("Map2,final_print:");
    }
    for (auto & s: std::get<2>(test_vm.existing_mvector1) ) {
        //Struct1m map_value1 = {s.s1_int1,s.s1_int2,s.s1_str1};
        //map_value1.print("Map1,final_print:");
        s.print( "Map2mv,final_print:" );
    }

    cout << "###" << endl;
    return 0;
}
