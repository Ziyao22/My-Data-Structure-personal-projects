#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<string>
using namespace std;
//Ziyao Gao zg8rw 11/10/2020
//binaryTree.h
class binaryTree{
 public:
  binaryTree();
  binaryTree(int time, string letter);
  int times;
  string letters;
  binaryTree* left;
  binaryTree* right;

 private:
  friend class Heap;
};
#endif
