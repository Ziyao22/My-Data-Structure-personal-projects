#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;
//Ziyao Gao zg8rw 10/05/2020
//BinaryNode.h
class BinaryNode {
    BinaryNode();
    ~BinaryNode();

    string value;
    BinaryNode* left;
    BinaryNode* right;

    friend class BinarySearchTree;
};

#endif
