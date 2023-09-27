#include <iostream>
#include <memory>
#include <array>
#include <vector>
using namespace std;

class stupid_class {
    void what_i_want_to_run();
};

class Another_class {};

class My_interface {
public:
    int i_int {0};
    virtual ~My_interface() {}
    virtual void my_interface_member_function()=0;
};

class My_base_class : public My_interface {
public:
    int b_int {0};
    int b {22};
    virtual ~My_base_class() override {
        cout << "My_base_class::~ running\n";
    }
    virtual void my_interface_member_function() override {
        cout << "My_base_class::My_interface_member_function(): running\n";
    }
    virtual void my_base_member_function() {
        cout << "My_base_class::My_base_member_function(): running\n";
    }
};

class My_derived_class : public My_base_class {
    int c_int {0};
public:
    int d {33};
    int d2{33};
    int d3{33};
    int d4{33};
    int d5{33};
    int d6{33};
    virtual ~My_derived_class() final {
        cout << "My_derived_class::~ running\n";
    }
    virtual void my_interface_member_function() final {
        cout << "My_derived_class::My_interface_member_function(): running\n";
    }
    virtual void my_derived_member_function() {
        cout << "My_derived_class::My_derived_member_function(): running\n";
    }
};

class My_derived_class2 : public My_base_class {
    int c_int {0};
public:
    virtual ~My_derived_class2() final {
        cout << "My_derived_class2::~ running\n";
    }
    virtual void my_interface_member_function() final {
        cout << "My_derived_class2::My_interface_member_function(): running\n";
    }
    virtual void my_derived_member_function() {
        cout << "My_derived_class2::My_derived_member_function(): running\n";
    }
};
int main() {
    /* unique_ptr< My_interface > interface_ptr( new My_interface );  // compile error: abstract type cannot be instanciated.

//    unique_ptr< My_interface > interface_class_uptr  ( new My_base_class );
//    unique_ptr< My_interface > interface_class_uptr2 ( new My_derived_class );
//    interface_class_uptr->my_interface_member_function();

//    unique_ptr< My_base_class > base_class_uptr( new My_base_class );
//    base_class_uptr->my_interface_member_function();

//    // My_interface * base_class_ptr( new My_base_class ); // different from {}?
//    My_base_class * base_class_ptr { new My_base_class };
//    base_class_ptr->my_base_member_function();

//    unique_ptr< My_interface > derived_class_uptr( new My_derived_class );
//    derived_class_uptr->my_interface_member_function();
//    // (My_derived_class *) interface_class_uptr2->my_interface_member_function();

    //std::vector< My_interface * > vec { */
    std::vector< My_interface * > vec {
        new My_derived_class (),
        new My_derived_class2 (),
        new My_derived_class (),
        nullptr
        // , new Another_class()
        };

    /*std::vector< std::unique_ptr<My_interface> > vec {
        //std::make_unique< My_derived_class >(),
        //std::make_unique< My_derived_class2 >(),
        //std::make_unique< My_derived_class >(),
                                                   //}; */
    for (auto i = vec.begin(); i != vec.end(); i++) {
        // (*i).get()->my_interface_member_function();
        (*i)->my_interface_member_function();

        /* auto ptr = dynamic_cast<My_derived_class *>((*i));
        if (ptr) ptr->my_derived_member_function(); else cout << "can't be null, but Alan made his point.\n";
        auto ptr2 = dynamic_cast<My_derived_class2 *>((*i));
        if (ptr2) ptr2->my_derived_member_function(); else cout << "can't be null, but Alan made his point\n.";
        cout << "+++++++++++++++++++++++\n";
        */

        //delete (*i);
    }

    cout << "###" << endl;
}
