#ifndef BINARY_TREE_NODE2_H
#define BINARY_TREE_NODE2_H

#include <iostream>
#include <string>
using namespace std;

class Binary_tree_node2 {
public:
    using Node_uptr = Binary_tree_node2 *;
private:
    std::string 		_key {"initial_value"};
    Node_uptr 			_left_uptr {};  // points to another internal node, or to the 'zero_node'.
    Node_uptr 			_right_uptr {};
    // _zero is static and points to a node called zero_value (which points to itself).
    static Node_uptr    _zero;
    static size_t 	    _num_zero_users;

    static Node_uptr make_a_zero() {
                // clog << "Binary_tree_node2(INT-start): " << _key << ", " << _num_zero_users << ", " << _left << ", " << _right  << ", " << _zero << endl;
        static Binary_tree_node2  	_a_zero {}; 			// initialization of the value of static must be set in *.cpp file.
        _a_zero._left_uptr = 		&_a_zero;
        _a_zero._right_uptr = 		&_a_zero;
        _a_zero._zero = 			&_a_zero;  // sets it for all Binary_tree_nodes;
                clog << "make_a_zero(): " << _a_zero._key << ", " << _a_zero._num_zero_users << ", " << _a_zero._left_uptr << ", " << _a_zero._right_uptr  << ", " << _a_zero._zero << endl;
        return &_a_zero;
    }
public:
    Binary_tree_node2() : _key("default_constr_val"), _left_uptr(make_a_zero()), _right_uptr(make_a_zero()) { // todo: test me, not currently executed with current test data.
                // clog << "Binary_tree_node2(DEFAULT-start): " << _key << ", " << _num_zero_users << ", " << _left << ", " << _right  << ", " << _zero << endl;
        ++_num_zero_users;
                clog << "Binary_tree_node2(DEFAULT): " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }
    Binary_tree_node2(std::string key_): _key(key_), _left_uptr(make_a_zero()), _right_uptr(make_a_zero()) {
                //clog << "Binary_tree_node2(key-start): " << _key << ", " << _num_zero_users << ", " << _left << ", " << _right  << ", " << _zero << endl;
        ++_num_zero_users;
                clog << "Binary_tree_node2(key) result: " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
        if (!key_.length()) throw std::logic_error("Binary_tree_node2(key): key must not be zero length.");
    }
    Binary_tree_node2(std::string key_, Node_uptr & left_, Node_uptr & right_ ): _key(key_), _left_uptr(left_), _right_uptr(right_){
        ++_num_zero_users;
                clog << "Binary_tree_node2(key,left,right) result: " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }
    ~Binary_tree_node2() {
        // Is 'recursive' via the destructor function, and using postfix traversal to delete child internal nodes.
        // Pre-condition: WARNING: Node to be destructed must not be referenced by any other nodes, or those nodes
        // will have dangling pointers.
        // Post-condition: this and all child nodes are

        clog << "~Binary_tree_node2(): " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
        if (_left_uptr != _zero ) {
            clog << "delete left begin.\n";
            _left_uptr->~Binary_tree_node2();
            _left_uptr = _zero;
            clog << "deleted left.\n";
        }
        if (_right_uptr != _zero ) {
            clog << "delete right begin. \n";
            _right_uptr->~Binary_tree_node2();
            _right_uptr = _zero;
            clog << "deleted right. \n";
        }
        --_num_zero_users;
        if (_num_zero_users == 0) {
            clog << "delete _zero begin. \n";
            _zero->~Binary_tree_node2();
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

        target_node_ptr->~Binary_tree_node2();
    }

    void set_left_child(Binary_tree_node2 & n) {
        _left_uptr = &n;
        clog << "Binary_tree_node(key): " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }

    void set_right_child(Binary_tree_node2 & n) {
        _right_uptr = &n;
        clog << "Binary_tree_node2(key): " << _key << ", " << _num_zero_users << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
    }

    Node_uptr left_child_ptr()  {return _left_uptr;}
    Node_uptr right_child_ptr() {return _right_uptr;}

    void print() {
        cout << "Binary_tree_node2.print():" << _key << ", " << _left_uptr << ", " << _right_uptr  << ", " << _zero << endl;
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
#endif // BINARY_TREE_NODE3_H
