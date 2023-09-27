#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <algorithm>

#include <utility>

using namespace std;

constexpr int NUM_STATUSES = 8;

//enum class Stati:int {  // todo: why can't I get an enum class to compile?  Value type for array<> init???
enum Status {
    BLUE = 0,
    GREEN = 1
};

// https://en.cppreference.com/w/cpp/experimental/to_array
//template <std::size_t N>
//auto prepare_songses_border( int * (&in_array) [N])
//{ auto std_array = std::experimental::make_array(in_array);  // todo: what does this do, and what are: the syntax of in_array and N above?
//    array<int,NUM_STATUSES+2> return_val {0, {std_array} ,0}; return return_val;
//}

vector<int> diversity(int rideDuration, vector<int> songDurations)
{

    int targetDuration = rideDuration - 30;
    vector<int> playList {};
    vector<pair<int,int>> candidates;


    for (int i=0; i < songDurations.size(); ++i) {
        for (int j=1; j < songDurations.size(); ++j) {
            if (songDurations[i]+songDurations[j] == targetDuration) {
                candidates.push_back( { i, j });
            }
        }
    }

    pair<int,int> bestCandidate {};
    int longestSong {};
    int index_of_best {};
    for ( auto i=0; i < candidates.size(); ++i) {
        int m = max( songDurations[ candidates[i].first],
                songDurations[ candidates[i].second] );
        if (m > longestSong )
            longestSong = m;
            index_of_best = i;
    }
    playList.push_back(candidates[index_of_best].first);
    playList.push_back(candidates[index_of_best].second);
    return playList;
}

int main()
{
    vector<int> songs {1,10,25,35,60};  // todo: convert these to enum values
    diversity( 90, songs );
    // return: {2,3};

    cout << "###" << endl;
    return 0;
}
