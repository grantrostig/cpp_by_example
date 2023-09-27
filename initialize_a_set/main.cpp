#include <set>
#include <string>
#include <vector>
#include <variant>
#include <iostream>

using namespace std;

struct Record {
    string name {};
    bool   is_what {};
};
struct Record2 {
    string name {};
    bool   is_what {};
};

using Record_var = std::variant<Record, Record2>;

struct RecordCompare {
    bool operator() ( const Record & lhs, const Record & rhs) const { return lhs.name < rhs.name;}
};
struct Record2Compare {
    bool operator() ( const Record2 & lhs, const Record2 & rhs) const { return lhs.name < rhs.name;}
};

using Record_set =  std::set< Record, RecordCompare >;
using Record2_set =  std::set< Record2, Record2Compare >;

using Set_var = std::variant<
    Record_set,
    Record2_set
>;

auto junk = [](auto lhs,auto rhs){ return lhs.name < rhs.name;};

int main()
{
    std::set<int> int_set {1,2};

    Record my_rec {"name", true};
    Record my_rec2 {};

    std::set<Record, RecordCompare> record_set { {"my_name1", true}, {"my_name2",true}, {"my_name3",true} };
//    std::set<Record, junk > record_set { {"my_name", true} };  // todo: compile error.  must be a type? why how?
//    std::vector<record_set::node_type()> set_index { record_set.begin(), record_set.end() };  // todo TODO

    //Set_var record_set_var { Record_set {Record {"my_name", true}} };
    //Set_var record2_set_var { Record2_set {Record2 {"my_name", true}} };

    cerr << "**** name2\n";
    auto itr = record_set.find({"my_name2",true});
    if ( itr == record_set.begin() ) cerr <<" begin().\n";
    if ( itr == record_set.end()   ) cerr <<" end().\n";
    // if ( itr == record_set.end() )   cerr <<(long)record_set.end()._M_node  <<" end().\n";
    // if ( itr == record_set.begin() ) cerr <<(long)record_set.begin()._M_node<< " begin().\n";
    // cerr <<itr._M_node<< "itr->name: "<< itr->name<<endl;
    cerr << "itr->name: "<< itr->name<<endl;

    itr--;  // 1
    cerr << "** name1\n";
    if ( itr == record_set.begin() ) cerr <<" begin().\n";
    if ( itr == record_set.end()   ) cerr <<" end().\n";
    cerr << "itr->name: "<< itr->name<<endl;

    itr--;  // begin?
    cerr << "** name0???\n";
    if ( itr == record_set.begin() ) cerr <<" begin().\n";
    if ( itr == record_set.end()   ) cerr <<" end().\n";
//    cerr << "itr->name: "<< itr->name<<endl;

    itr++;
    cerr << "** name1\n";
    if ( itr == record_set.begin() ) cerr <<" begin().\n";
    if ( itr == record_set.end()   ) cerr <<" end().\n";
    cerr << "itr->name: "<< itr->name<<endl;

    itr--;
    cerr << "** name2\n";
    if ( itr == record_set.begin() ) cerr <<" begin().\n";
    if ( itr == record_set.end()   ) cerr <<" end().\n";
    cerr << "itr->name: "<< itr->name<<endl;

    cerr << "**** name2\n";
    auto itr2 = record_set.find({"my_name2",true});
    if ( itr2 == record_set.begin() ) cerr <<" begin().\n";
    if ( itr2 == record_set.end()   ) cerr <<" end().\n";
    cerr << "itr->name: "<< itr2->name<<endl;

    itr2++;
    cerr << "** name3\n";
    if ( itr2 == record_set.begin() ) cerr <<" begin().\n";
    if ( itr2 == record_set.end()   ) cerr <<" end().\n";
    cerr << "itr->name: "<< itr2->name<<endl;

    itr2++;
    cerr << "** name4\n";
    if ( itr2 == record_set.begin() ) cerr <<" begin().\n";
    if ( itr2 == record_set.end()   ) cerr <<" end().\n";
    // cerr << "itr->name: "<< itr2->name<<endl;

    itr2--;
    cerr << "** name3\n";
    if ( itr2 == record_set.begin() ) cerr <<" begin().\n";
    if ( itr2 == record_set.end()   ) cerr <<" end().\n";
    cerr << "itr->name: "<< itr2->name<<endl;

    itr2--;
    cerr << "** name2\n";
    if ( itr2 == record_set.begin() ) cerr <<" begin().\n";
    if ( itr2 == record_set.end()   ) cerr <<" end().\n";
    cerr << "itr->name: "<< itr2->name<<endl;


    cout << "Hello World!" << endl;
    return 0;
}
