#include <iostream>
#include <vector>
#include <array>
#include <experimental/array>
#include <functional>
#include <algorithm>
#include <experimental/algorithm>

using namespace std;

constexpr int NUM_STATUSES = 8;

//enum class Stati:int {  // todo: why can't I get an enum class to compile?  Value type for array<> init???
enum Status {
    BLUE = 0,
    GREEN = 1
};

// https://en.cppreference.com/w/cpp/experimental/to_array
template <std::size_t N>
auto prepare_statuses_border( int * (&in_array) [N])
{ auto std_array = std::experimental::make_array(in_array);  // todo: what does this do, and what are: the syntax of in_array and N above?
    array<int,NUM_STATUSES+2> return_val {0, {std_array} ,0}; return return_val;
}

vector<int> diversity(int * status, int generations)
{
    array< int, NUM_STATUSES+2 > neighbours {};  // num+2 // create an array element (like a border value) on either side to simplify logic. // todo: is array initialized to zero for sure?
    neighbours.fill( Status::BLUE );
    for (size_t i = 1; i < NUM_STATUSES; ++i) {  //
        neighbours[i] = status[i-1];
    }

//    array< int, NUM_STATUSES+2 > neighbours2 {Status::BLUE};  // num+2 // create an array element (like a border value) on either side to simplify logic. // todo: is array initialized to zero for sure?
//    neighbours2[NUM_STATUSES+1] = Status::BLUE;
//    copy (status, status+(NUM_STATUSES-1), neighbours2.begin()+1);

    for (int i = 0; i < generations; ++i) {
        array<int, NUM_STATUSES+2> neighbours_updated {};
        neighbours_updated.fill( Status::BLUE );

        for (size_t h = 1; h < NUM_STATUSES+1; ++h) {  // todo:  how about for_each or transform?  too ugly a lambda?  see commented line below.
            if (neighbours[h-1]==neighbours[h+1]) {
                neighbours_updated[h]=Status::BLUE;
            }
            else {
                neighbours_updated[h]=Status::GREEN;
            }
        }

        // transform( neighbours.begin(), neighbours.end(), back_inserter(neighbours_updated), [](const int ){} );  // todo:  can the above be done with the STL? probably not since I have to reference other elements than the current one.
        neighbours = neighbours_updated;
    }


//    vector<int> v {};
//    for (size_t i = 0; i < NUM_STATUSES; ++i) {
//        v.push_back(neighbours[i+1]);
//    }

    vector<int> v(NUM_STATUSES);
    copy( neighbours.begin()+1, neighbours.end()-1, v.begin() );  // todo: can I do this with an initializer??

    return v;
}

int main()
{
    int status[8] {1,0,0,0,0,1,0,0};  // todo: convert these to enum values
    diversity( status, 1 );
    // return: {0,1,0,0,1,0,1,0};

    int status2[8] {1,1,1,0,1,1,1,1};
    diversity( status2, 2 );
    // return: {0,0,0,0,0,1,1,0};

    cout << "###" << endl;
    return 0;
}

    // another other task: calculate GCD of n numbers.
    // the lowest integer that divides all the integers without a remainder is output.
    // input: {2,4,6,8,10},5  output: 2
    // input: {2,3,4,5,6},5  output: 1
