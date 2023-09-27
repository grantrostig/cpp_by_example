#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

struct My_types {
    int a;
    string b;
};

// std::array<My_types,2> spec  { 1,"one",  2,"two", 3,"three"};
std::array<My_types,20> spec6 { 1,"one",  2, {}};
std::array<My_types,2> spec5 { 1,"one",  2,"two"};
// std::array<My_types,2> spec4 {{1,"one"},{2,"two"}};
std::array<int,10>     spec3 {1,2};

const My_types spec2[] {{1,"one"},{2,"one"}};
// const My_types spec8[2] {1,"one",2,"one",3,"three"};
// const My_types spec7[] {{1,"one"},{2,1}};

std::vector<My_types> vspec1 {{1,"one"},{2,"two"},{3,"two"}};
// std::array<int, vspec1.end()-vspec1.begin()> vspec2;

int main()
{
    std::array<int, sizeof(spec6)> sized_array6;
    std::array<int, sizeof(spec2)> sized_array2;
    cout << "spec2[] num_elements, element_size, overall_size: "<<sizeof(spec2)/sizeof(My_types)<<", "<<sizeof(My_types)<<", "<<sizeof (spec2)<< endl;
    cout << "spec6[] num_elements, element_size, overall_size: "<<sizeof(spec6)/sizeof(My_types)<<", "<<sizeof(My_types)<<", "<<sizeof (spec6)<< endl;
    cout << "vspec1[] num_elements, element_size, overall_size: "<<sizeof(vspec1)/sizeof(My_types)<<", "<<sizeof(My_types)<<", "<<sizeof (vspec1)<< endl;
    cout << "vspec1[] num_elements, element_size, overall_size: "<<sizeof(vspec1)/sizeof(My_types)<<", "<<sizeof(My_types)<<", "<<vspec1.end()-vspec1.begin()<< endl;
    //cout << spec6.at(0).b << endl;
    //cout << spec6.at(1).b << endl;
    //cout << spec6.at(2).b << endl;
    cout << spec2[0].b << endl;
    cout << spec2[990000].a << endl;
    int i = 999999;
    cout << spec2[i].a << endl;
    cout << spec2[990000].a << endl;
    cout << "Hello World!" << endl;
    return 0;
}
