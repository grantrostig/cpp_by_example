#include <iostream>
#include <vector>
#include <numeric>

//import std;

using namespace std;

struct S {
  int           x;
  std::string   s;
};

struct Sv {
  std::vector<int>      x {1,2,3};
  std::string           s {"NULL"};
};

int main() {
  std::vector< int > my_vec    { 42, 99, 1};
  std::vector< int > my_vec2 = { 42, 99, 1};
  std::vector< int > my_vec4   { 42, 99 };
  std::vector< int > my_vec3   ( 42, 99 );
  int my_int (99);

  std::vector< S > my_svec3   { {42,"hello"}, {99, "world"} };
  std::vector< Sv > my_sv_vec3   {
                                    { {42,42,42,42,42,42,42},"hello"},
                                    { {41,42,42,42,42,42,42},"world"},
  };

// Case A
  std::vector<int> seq  {};
  //seq.reserve(999);
  seq.resize(999);
  //int i;
  //for ( auto & k:seq ) { k=3; i++; };
  //for ( int i = 0; i<999 ; ++i ) { seq[i] =3; };
  // std::iota( seq.begin(), seq.end(), -4 );
  //for ( auto i = seq.begin(); i != seq.end(); i++ ) { *i = 3; };
  //for ( auto i = seq.begin(); i != seq.end(); i++ )   { *i = 3; };
  //for ( std::vector<int>::iterator i = seq.begin(); i != seq.end(); i++ ) { *i = 3; };
  for ( std::vector<int>::iterator i = seq.begin(); i++ != seq.end(); ) { * std::prev(i) = 3; };

// Case B
  std::vector<int> seq2  (999,3);




  cout << "Hello World!" << endl;
  return 0;
}
