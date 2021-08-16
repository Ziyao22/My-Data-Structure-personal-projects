#include "BinaryNode.h"
#include <string>
using namespace std;
//Ziyao Gao zg8rw 10/05/2020
//BinaryNode.cpp
BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
