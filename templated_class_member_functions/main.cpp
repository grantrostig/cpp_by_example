struct S1 {
    bool print(int i);
};

struct S2 {
    bool print(int i);
};

bool S1::print(int i) { i=1; return true; }
// template< class T > bool S1::print(int i) { i=1; return true; }  // TODO
template< typename T >
bool  T::print(int i) { i=1; return true; }  // TODO

int main() {
S1 s1 {};
s1.print( 5 );
}
