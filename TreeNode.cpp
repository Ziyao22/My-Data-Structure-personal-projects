// Insert your header information here
// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5
//Ziyao Gao zg8rw 10/04/2020
//TreeNode.cpp
#include "TreeNode.h"

// Default Constructor - left and right are NULL, value '?'
TreeNode::TreeNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

// Constructor - sets value to val
TreeNode::TreeNode(const string& val) {
    value = val;
    left = NULL;
    right = NULL;
}
