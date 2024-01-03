/** This code illustrates:
   + unique_ptr
   + parametric polymophism
   + run-time polymorhpism
   modified by Grant Rostig from Stroustup TCPLv4 */

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//int * raw_ptr_argument( int * i ) {
void raw_ptr_argument( int * i /* IN, OUT */ ) {  // call by "explicit pointer for logical In-Out-Parameter calling mode" http://www.cs.ecu.edu/karl/2530/spr18/Notes/lec21A.html
    //++i;
    int r{*i}; /* copy value of IN */
    ++r;
    *i = r;  /* OUT */
    //return &r;
}

class Shape {
    int i {};
public:
    void draw() {
        cout << "Shape:draw()\n";
    }
};

class Circle : public Shape {
};

template <typename Container, typename Operation>
void for_all2( Container & container, Operation operation) {
    for(auto & iterator_ptr_to_element:container)
        operation( *iterator_ptr_to_element );
}

int main()  {
    int arg{42};
    // int * arg_ptr_result{raw_ptr_argument(&arg)};
    raw_ptr_argument(&arg);
    cout << arg << endl;
    // cout << *arg_ptr_result << endl;

    /* vector< unique_ptr< Shape >>   vector_uptr_to_Shape;
    vector< Shape * >              vector_ptr_to_Shape;
    vector_uptr_to_Shape.emplace_back( make_unique< Shape >() );
    vector_uptr_to_Shape.emplace_back( new Shape {} );

    for_all2( vector_uptr_to_Shape,
              [](Shape & s){ s.draw();}
            );

    // Stroustrup notes that this code works also, in TCPL-3.4.3-paragraph.last
    // todo:  What is a unique_pointer really?  A real pointer, with other
    //        features added via it being a class?  Is * overloaded?

    for_all2( vector_ptr_to_Shape,
              [](Shape & s){ s.draw();}
            ); */

    cout << "###" << endl;
    return 0;
}
