// The tree data structure and some of the initial algorithms inspired by 'Algorithms in C++ -- R. Sedgewick'
// Keywords:  Recursion, Interitance, Access Specifiers

#include <memory>
#include <iostream>
#include <binary_tree_node.h>
#include <binary_tree_node2.h>

using namespace std;
using node_uptr = Binary_tree_node *;

namespace hide_me {
//using node_uptr = unique_ptr<Tree_node_interface>;
//class Tree_node_interface {
//public:
//    // using node_uptr = unique_ptr<Tree_node_interface>;
//    using node_uptr = Tree_node_interface *;

//    //virtual unique_ptr<Tree_node_interface> next() { clog << "Tree_node_interface.virtual_next().\n"; return Tree_node_interface::node_uptr {"test"};}
//    virtual string key() const;

//    virtual node_uptr next_child() const = delete;

//    virtual ~Tree_node_interface() {}
//protected:
//    Tree_node_interface(){}
//    Tree_node_interface(string key_ );
//    virtual void set_key(string);

//    string _key;
//private:
//};
}

class Tree_interface {
private: // only visible to this class and friends
    int TI_private_int {};
    void TI_private_f() {}
protected: // only visible to this class, derived, and friends
    int TI_protected_int {};
    void TI_protected_f() {}

    node_uptr root_;  // can't be private if derived class is to manipulate it.
public:
    int TI_public_int {};
    Tree_interface() = default;
    Tree_interface(Binary_tree_node & n){
        root_ = &n;
    }
    void TI_public_f() {}
    void set_root(Binary_tree_node & n){  // todo: why can parameter be const?  I could change it but I promise not too. :)
        root_ = &n;
    }
    void print() {
        root_->print_sub_tree_prefix();
    }
};

class Binary_tree_private : private Tree_interface {
private:
    int BTP_private_int {};
    void BTP_private_f() {}
protected: // only visible to this class, derived, and friends
    int BTP_protected_int {};
    void BTO_private_f() {}
    // node_uptr root_;
public:
    Binary_tree_private() = default;
    Binary_tree_private(Binary_tree_node & n){
        root_ = &n;
    }
    void set_root(Binary_tree_node & n){  // todo: why can parameter be const?  I could change it but I promise not too. :)
        root_ = &n;
    }
    void print() {
        root_->print_sub_tree_prefix();
    }
    friend class Friend_of_binary_tree;  // todo: does this need to be in any particular access block, ie. public? Any effect from that?
};


class Binary_tree_protected : protected Tree_interface {
private:
    int BTO_private_int {};
    void BTO_private_f() {
        TI_protected_int = 1;
    }
protected: // only visible to this class, derived, and friends
    int BTO_protected_int {};
    void BTO_protected_f() {
        TI_protected_int = 1;
    }
    // node_uptr root_;
public:
    int BTO_public_int {};
    Binary_tree_protected() = default;
    Binary_tree_protected(Binary_tree_node & n){
        root_ = &n;
    }
    void f2() {
        TI_protected_int = 1; // todo: I'm a derived class. Why compile error?
    }
    void set_root(Binary_tree_node & n){  // todo: why can parameter be const?  I could change it but I promise not too. :)
        root_ = &n;
    }
    void print() {
        root_->print_sub_tree_prefix();
    }
    friend class Friend_of_binary_tree;  // Apparently 'friend class' can be in any access block for full effect. todo: verify: does this need to be in any particular access block, ie. public? Any effect from that?
};

class Binary_tree_public : public Tree_interface {
    void BTP_public_f() {
        Tree_interface t {};
        // t.TI_protected_int;  // not accessible, but below is.
        TI_protected_int = 0;
    }
};

class Friend_of_binary_tree {
public:
    Binary_tree_private t_BTP;
    Binary_tree_protected t_BTO;
    void f(){
      t_BTP.BTP_protected_int = 1;
      t_BTP.BTP_private_int = 1;
      t_BTO.BTO_protected_int = 1;
    }
};

int main()
{
    cout << "~~~" << endl;
    Binary_tree_node node_free_floating_test;
//    node_free_floating_test.print();
//    Binary_tree_node * temp_ptr = node_free_floating_test.left_child_ptr();
//    temp_ptr->print();

    Binary_tree_node nodeP {"P"};
    nodeP.print();
    Binary_tree_node nodeM {"M"};
    nodeM.print();
    Binary_tree_node nodeL {"L"};
    nodeL.print();
    Binary_tree_node nodeS {"S"};
    nodeS.print();
    Binary_tree_node nodeA {"A"};
    nodeA.print();
    Binary_tree_node nodeA2 {"A2"};
    nodeA2.print();
    Binary_tree_node nodeE {"E"};
    nodeE.print();
    Binary_tree_node nodeR {"R"};
    nodeR.print();
    Binary_tree_node nodeT {"T"};
    nodeT.print();
    Binary_tree_node nodeE2 {"E2"};
    nodeE2.print();
    Binary_tree_node nodeE3 {"E3"};
    nodeE3.print();

    nodeP.set_left_child(nodeM);
    nodeP.set_right_child(nodeL);

    nodeM.set_left_child(nodeS);

/*    	      	p
               / \
            M		L
           / 		  \
        S				E
       / \   			 \
    A		A				R
                           / \
                        T		E
                               /
                            E
*/

    nodeS.set_left_child(nodeA);
    nodeS.set_right_child(nodeA2);

    nodeL.set_right_child(nodeE);

    nodeE.set_right_child(nodeR);

    nodeR.set_left_child(nodeT);
    nodeR.set_right_child(nodeE2);

    nodeE2.set_left_child(nodeE3);

    cout << "nodeP.print_sub_tree_prefix()\n";
    nodeP.print_sub_tree_prefix();
    cout << "nodeP.print_sub_tree_infix()\n";
    nodeP.print_sub_tree_infix();
    cout << "nodeP.print_sub_tree_postfix()\n";
    nodeP.print_sub_tree_postfix();

    Tree_interface tree;  // does not create another zero_node
    tree.set_root(nodeP);
    tree.print();

    // === delete internal leaf node and recover memory
    // delete &nodeA; // todo: double delete?, destructor is called and then delete?
    // nodeA.~Binary_tree_node(); // todo: not double delete apparently.
    node_uptr tree_root_ptr = &nodeP;
    cout << "nodeA.delete_sub_tree(tree_root_ptr);\n";
    nodeA.delete_sub_tree(tree_root_ptr);

    // === delete internal node which has a subtree
    cout << "nodeS.delete_sub_tree(tree_root_ptr);\n";
    nodeS.delete_sub_tree(tree_root_ptr);
    // === delete root node which has a subtree(s)
    cout << "nodeP.delete_sub_tree(tree_root_ptr);\n";
    nodeP.delete_sub_tree(tree_root_ptr);

    //Binary_tree_private tree_private(node2);  // does not create another zero_node
    //tree_private.print();

    //Binary_tree_protected tree_protected(node2);  // does not create another zero_node
    //tree_protected.print();

    // tree_protected.BTO_protected_int = 1;  // Error expected.
    // tree_protected.TI_protected_int = 1;      // todo: Error expected.?
    // tree_protected.TI_public_int = 1;         // todo: Error expected.?

    // tree_protected.BTO_protected_f(); 	// Error expected. access.
    // tree_protected.TI_protected_f();  // todo: 2 Errors, cast and access.

    //Binary_tree_public tree_public;
    //tree_public.TI_public_f();

    cout << "###" << endl;
    return 0;
}
