#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    struct Record {
        int v1 {};
        int v2 {};
    };

    vector<Record> v {{3,99},{3,21},{77,3},{4,-22}};
    sort( v.begin(), end(v), [](const Record& a, const Record& b){ return (a.v1 < b.v1); });  // two ways shown for v's iterator.

    map<int,int>   m {};

    /*
     * Note: Insert in fact is Upsert, or 'insert OR update'
     */

    for (const Record& r: v) {
        m[r.v1] = r.v2;
        // other clever alternative if we know it is sorted :)
        m.insert(m.end(),{r.v1,r.v2});
    }

    // Doesn't work, requires and 'input_iterator' TBD todo_cppmsg
    // m.insert(v.begin(), v.end());

    cout << "###" << endl;
    return 0;
}
