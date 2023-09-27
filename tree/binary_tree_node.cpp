#include "binary_tree_node.h"

// todo: Tree_node_interface(string key_ ): key(key_) { if (!key.length()) throw "key must not be zero length"; }
// todo: Tree_node_interface::node_uptr Tree_node_interface::next2() { clog << "Tree_node_interface.virtual_next2().\n"; return Tree_node_interface::node_uptr {"test"};}

Binary_tree_node::Node_uptr Binary_tree_node::_zero =
        new Binary_tree_node {0,0,0};  // call 'special' constructor for zero_node.  todo: _zero does not appear to get set with address, I have to do it in the contructor.
        // nullptr;
        // reinterpret_cast<node_uptr>(-99);
        // &_zero; // todo: Compile error: cannot init with rvalue of ptr type.

size_t	Binary_tree_node::_num_zero_users = 0;
