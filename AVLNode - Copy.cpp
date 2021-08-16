#include "AVLNode.h"
#include <string>
using namespace std;
//Ziyao Gao zg8rw  10/07/2020
//AVLNode.cpp
AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
