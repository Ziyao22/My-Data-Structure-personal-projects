#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;
//Ziyao Gao zg8rw 10/07/2020
//AVLNode.h
class AVLNode {
    AVLNode();
    ~AVLNode();

    string value;
    AVLNode* left;
    AVLNode* right;
    int height;

    friend class AVLTree;
};

#endif
