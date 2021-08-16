#include "binaryTree.h"
#include<string>
//Ziyao Gao zg8rw 11/10/2020
//binaryTree.cpp
binaryTree::binaryTree(){
  times=0;
  letters=" ";
  left=right=nullptr;
}
binaryTree::binaryTree(int time, string letter){
  times=time;
  letters=letter;
  left=right=nullptr;
}
