#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Binary_tree_node {
public:
    using Node_uptr = Binary_tree_node *;
private:
    std::string 		_key {"initial_value"};
    Node_uptr 			_left_uptr {};  // points to another internal node, or to the 'zero_node'.
    Node_uptr 			_right_uptr {};
    // _zero is static and points to a node called zero_value (which points to itself).
    static Node_uptr    _zero; 			// initialization of the value of static must be set in *.cpp file. todo: but in my code it doesn't get done. :(
    static size_t 	    _num_zero_users;

    Binary_tree_node(int,int,int): _key("zero_node_0") { // todo: warning: special use dummy zero constructor, using 3 ints to get another signature.
                // clog << "Binary_tree_node(INT-start): " << _key << ", " << _num_zero_users << ", " << _left << ", " << _right  << ", " << _zero << endl;
        _left_uptr = this; _right_uptr = this; _zero = this; // todo: why is _zero not set with its address after this constructor ends?  It seems I have to set the value here.
                clog << "Binary_tree_node(INT): " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }
public:
    Binary_tree_node():_left_uptr(_zero), _right_uptr(_zero) { // todo: test me, not currently executed with current test data.
                // clog << "Binary_tree_node(DEFAULT-start): " << _key << ", " << _num_zero_users << ", " << _left << ", " << _right  << ", " << _zero << endl;
        ++_num_zero_users;
                clog << "Binary_tree_node(DEFAULT): " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }
    Binary_tree_node(std::string key_): _key(key_), _left_uptr(_zero), _right_uptr(_zero) {
        // Binary_tree_node(); // does this re-run the initializers and or create another object? Apparently it does create another object!  Does it zero _left out?
                //clog << "Binary_tree_node(key-start): " << _key << ", " << _num_zero_users << ", " << _left << ", " << _right  << ", " << _zero << endl;
        ++_num_zero_users;
                clog << "Binary_tree_node(key) result: " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
        if (!key_.length()) throw std::logic_error("Binary_tree_node(key): key must not be zero length.");
    }
    Binary_tree_node(std::string key_, Node_uptr & left_, Node_uptr & right_ ): _key(key_), _left_uptr(left_), _right_uptr(right_) {
        ++_num_zero_users;
                clog << "Binary_tree_node(key,left,right) result: " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }
    ~Binary_tree_node() {
        // Is 'recursive' via the destructor function, and using postfix traversal to delete child internal nodes.
        // Pre-condition: WARNING: Node to be destructed must not be referenced by any other nodes, or those nodes
        // will have dangling pointers.  // todo: make destructor private, but that breaks node creation code in main().
        // Post-condition: this and all child nodes are

        clog << "~Binary_tree_node(): " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
        if (_left_uptr != _zero ) {
            clog << "delete left begin.\n";
            _left_uptr->~Binary_tree_node();
            _left_uptr = _zero;
            clog << "deleted left.\n";
        }
        if (_right_uptr != _zero ) {
            clog << "delete right begin. \n";
            _right_uptr->~Binary_tree_node();
            _right_uptr = _zero;
            clog << "deleted right. \n";
        }
        --_num_zero_users;
        if (_num_zero_users == 0) {
            clog << "delete _zero begin. \n";
            _zero->~Binary_tree_node(); // todo: where is zero in memory, static pointer points to it.  Does destructor get rid of the last bit of static memory?
            clog << "deleted _zero. \n";
        }
    }

   void query_parent_node(Node_uptr tree_node_ptr, Node_uptr target_node_ptr, Node_uptr & parent_ptr) {
        if (target_node_ptr == tree_node_ptr->_left_uptr ||
            target_node_ptr == tree_node_ptr->_right_uptr) {
                parent_ptr = tree_node_ptr;
        }
        // else do nothing, since we didn't find what we are looking for.
        return;
    }

    void traverse_find_parent(Node_uptr tree_node_ptr, Node_uptr target_node_ptr, Node_uptr & parent_ptr) {
        if (tree_node_ptr == _zero) return;
        query_parent_node(tree_node_ptr, target_node_ptr, parent_ptr);
        traverse_find_parent(tree_node_ptr->_left_uptr, target_node_ptr, parent_ptr);
        traverse_find_parent(tree_node_ptr->_right_uptr, target_node_ptr, parent_ptr);
        return;
    }

    void delete_sub_tree(Node_uptr head_node_ptr, Node_uptr target_node_ptr = nullptr) {
        if (target_node_ptr == nullptr) target_node_ptr = this;
        // We need to zero out any parent nodes that point to the subtree which is to be deleted.
        if (head_node_ptr != target_node_ptr) {
            Node_uptr parent_ptr = _zero;
            traverse_find_parent(head_node_ptr, target_node_ptr, parent_ptr);

            if (parent_ptr == _zero) throw std::logic_error ("delete_sub_tree(): parent node of target_node was not found.");
            if (parent_ptr->_left_uptr == target_node_ptr)  parent_ptr->_left_uptr  = _zero;
            if (parent_ptr->_right_uptr == target_node_ptr) parent_ptr->_right_uptr = _zero;
        }

        target_node_ptr->~Binary_tree_node();
    }

    void set_left_child(Binary_tree_node & n) {
        _left_uptr = &n;
        clog << "Binary_tree_node(key): " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }

    void set_right_child(Binary_tree_node & n) {
        _right_uptr = &n;
        clog << "Binary_tree_node(key): " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }

    Node_uptr left_child_ptr()  {return _left_uptr;}
    Node_uptr right_child_ptr() {return _right_uptr;}

    void print() {
        cout << "Binary_tree_node.print():" << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }
    void print_sub_tree_prefix() {
        if ( this == _zero ) return;
        print();
                        //clog << "print left below:" << endl;
        _left_uptr->print_sub_tree_prefix();  // recursive
                        //clog << "print right below:" << endl;
        _right_uptr->print_sub_tree_prefix();
    }
    void print_sub_tree_infix() {
        if ( this == _zero ) return;
                        //clog << "print left below:" << endl;
        _left_uptr->print_sub_tree_infix();  // recursive
        print();
                        //clog << "print right below:" << endl;
        _right_uptr->print_sub_tree_infix();
    }
    void print_sub_tree_postfix() {
        if ( this == _zero ) return;
                        //clog << "print left below:" << endl;
        _left_uptr->print_sub_tree_postfix();  // recursive
                        //clog << "print right below:" << endl;
        _right_uptr->print_sub_tree_postfix();
        print();
    }
};
#endif // BINARY_TREE_NODE_H
