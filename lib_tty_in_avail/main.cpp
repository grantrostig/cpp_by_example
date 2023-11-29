/* (c) Cppmsg.com License Boost 1.0 */
//#include <bits/stdc++.h>
//#include <istream>
#include <array>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

// Bad file global I know...
static streamsize position {};  // here static just hides the obj from linker, same as unnamed namespace TODO:??

void print_iosbase() {
    /*    enum _Ios_Iostate {
        _S_goodbit 		= 0,
        _S_badbit 		= 1L << 0,
        _S_eofbit 		= 1L << 1,
        _S_failbit		= 1L << 2,
        _S_ios_iostate_end = 1L << 16,
        _S_ios_iostate_max = __INT_MAX__,
        _S_ios_iostate_min = ~__INT_MAX__ }
    */;
    auto rds = cin.rdstate();
    cout<< "rds:" << rds << endl;
    if (cin.rdstate() == std::ios_base::goodbit) cout<< "goodbit" << endl;
    if (cin.rdstate() == std::ios_base::badbit) cout<< "badbit" << endl;
    if (cin.rdstate() == std::ios_base::eofbit) cout<< "eofbit" << endl;
}
void print_tellg() {  // This code can help you to check existence of data in the stdin without blocking: // https://stackoverflow.com/questions/3317740/checking-data-availability-before-calling-stdgetline
    //streamsize position{std::cin.tellg()};
    position = std::cin.tellg();
    if (position < 0) cout << ":no chars available" << endl;
    else {
        cout <<":length:"<<position<<endl;
        std::cin.seekg( 0, std::cin.beg );      // If stdin has some data - don't forget to set the position back to the beginning.
                                                // TODO??: why called "seekdir"?
                                                // what offset the position? tellg? or just a pre-caution
    }
} // end stackoverflow example EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEe

int main() { char my_char{}, my_c_string[100]{""}; streamsize in_avail_count{}; std::vector<char> char_vec(1024); string  my_string{};
    print_tellg();
    if (not(position < 0)) {
        std::cin.read( char_vec.data(), 1 );    // You can then read all data including \0 (can be more than one) at the end of the buffer:
        cout << *char_vec.begin() << endl;
    }

    cin.sync_with_stdio(false);  // Required for in_avail() to work TODO??:
    cout << "Enter keyboard input:";

    cin  >> my_char;
    cout << ":my_char as int, then char:" << (int)my_char <<","<< my_char << endl;
    cin.readsome(my_c_string, 1); // reads 'This ' and stores in c[0] .. c[4]
    cout << ":my_c_string:" << my_c_string << endl;

    basic_streambuf<char> * cin_streambuf{cin.rdbuf()};
    in_avail_count = cin_streambuf->in_avail();  // Is not blocking!!
    cout << ":in_avail_count:" << in_avail_count << endl;

    in_avail_count = cin.rdbuf()->in_avail();
    cout << ":in_avail_count:" << in_avail_count << endl;

    cout << ":c:" << my_char << endl;
    cout << ":in_avail_count:" << in_avail_count << endl;
    cin  >> my_string;

    in_avail_count = cin.rdbuf()->in_avail();
    cout << ":text:" << my_string << endl;
    cout << ":in_avail_count:" << in_avail_count << endl;

    cout << "###" << endl;
    return 0;
}
