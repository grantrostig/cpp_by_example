#include <iostream>
#include <variant>
#include <string>
#include <vector>
//#include <iosfwd>
#include <sstream>
#include <fstream>
//#include <cereal/archives/binary.hpp>
//#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/string.hpp>

struct S1 {
    int a {};
    template< class Archive >
    void serialize( Archive & archive ) {
        archive( a );
    }
};
struct S2 {
    std::string b {};
    template< class Archive >
    void serialize( Archive & archive ) {
        archive( b );
    }
};
using Svariant = std::variant<S1,S2>;
struct Data {
    int my_int {5};
    template< class Archive>
    void serialize( Archive & archive ) {
        archive( my_int );
    }
};
struct Datas1 {
    S1 my_s1 {5};
    template< class Archive>
    void serialize( Archive & archive ) {
        archive( my_s1 );
    }
};
struct Vec {
    int my_int {5};
    std::vector<Svariant> vec { S1 {3}, S2 {"hello"}, S1 {4} };
    template< class Archive>
    void serialize( Archive & archive ) {
        archive( vec, my_int );
    }
};
struct Vec2 {
    int my_int {5};
    std::vector<S1> vec { S1 {3}, S1 {4} };
    template< class Archive>
    void serialize( Archive & archive ) {
        archive( vec, my_int );
    }
};
struct Vec3 {
    int my_int {5};
    std::vector<int> vec { 3, 4 };
    template< class Archive>
    void serialize( Archive & archive ) {
        archive( vec, my_int );
    }
};
struct Variant1 {
    //Variant1() = default;  // does this add anything?
    std::variant<int,std::string> data {"hello"};
    template< class Archive>
    void serialize( Archive & archive ) {
        archive( data );
    }
};
struct Vec4 {
    int my_int {5};
    std::vector<Variant1> vec { Variant1 {3}, Variant1 {"hello"}, Variant1 {4} };
    template< class Archive>
    void serialize( Archive & archive ) {
        archive( vec, my_int );
    }
};
int main() {
    std::stringstream my_stream;
    //std::ofstream my_stream( "my_ofstream.cereal_binary", std::ios::binary );
    //err: std::ofstream my_stream( "my_ofstream.cereal_binary", std::ios_base::out );
    //err: std::fstream my_stream( "my_ofstream.cereal_binary", std::ios::binary );
    auto old_exceptions { my_stream.exceptions() };
    my_stream.exceptions(my_stream.exceptions()|(std::ios_base::failbit&std::ios_base::badbit));
    {
        //cereal::BinaryOutputArchive oarchive(my_stream);
        //cereal::PortableBinaryOutputArchive oarchive(my_stream);
        cereal::JSONOutputArchive oarchive(my_stream);
        Data data {42};
        Datas1 datas1 {42};
        Vec vec {};
        Vec2 vec2 {};
        Vec3 vec3 {42, {43,44}};
        Vec4 vec4 {42, std::vector {Variant1 {43} , Variant1 {"bye"}, Variant1 {44}}};
        Variant1 variant1 {"bye"};// Variant1 variant2 {42};
        oarchive( data ); // works
        oarchive( datas1 ); // works
        oarchive( vec );  // compile error
        oarchive( vec2 ); // works
        oarchive( vec3 ); // works
        oarchive( vec4 ); // compile error
        oarchive( variant1 );   // compile error
    } 	// archive goes out of scope, ensuring all contents are flushed

    std::cout << my_stream.str() << std::endl;
//    my_stream.flush();
//    //my_stream.seekg(0);
//    my_stream.close();

//    //std::ifstream my_stream2( "my_ofstream.cereal_binary", std::ios_base::in );
//    std::ifstream my_stream2( "my_ofstream.cereal_binary", std::ios::binary );
//    my_stream2.setstate(my_stream.exceptions()|(std::ios_base::failbit&std::ios_base::badbit));
//    {
//        //cereal::PortableBinaryInputArchive iarchive(my_stream);
//        cereal::JSONInputArchive iarchive(my_stream2);
//        Data data {};
//        Datas1 datas1 {};
//        Vec vec {};
//        Vec2 vec2 {};
//        Vec3 vec3 {};
//        Vec4 vec4 {};
//        Variant1 variant1 {};
//        iarchive( data ); // works
//        iarchive( datas1 ); // works
//        iarchive( vec );  // compile error
//        iarchive( vec2 ); // works
//        iarchive( vec3 ); // works
//        iarchive( vec4 );   // compile error
//        iarchive( variant1 );   // compile error
//    }
    std::cout << "###";
}
