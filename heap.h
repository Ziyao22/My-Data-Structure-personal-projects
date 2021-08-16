#ifndef HEAP_H
#define HEAP_H
#include<vector>
#include<string>
#include"binaryTree.h"
using namespace std;
//Ziyao Gao zg8rw 11/10/2020
//heap.h
class heap{
 public:
  heap();
  heap(vector<binaryTree*>vec);
  ~heap();
  void insert(binaryTree* Node);
  binaryTree* findMin();
  binaryTree* deleteMin();
  unsigned int size();	
  void makeEmpty();
  bool isEmpty();
  void print();
  void huffmanTree();
  void prefix(binaryTree* node,vector<string>&pre,vector<string>&curr, string letter);
  void huffmanTree1(binaryTree*& node,int count,string readInPrefix,string letter);
  void printTree(binaryTree* node, int& count,string read);
  vector<binaryTree*>heap1;
  private:
  vector<int>newheap;
  unsigned int heap_size;
  void percolateUp(int hole);
  void percolateDown(int hole);
  friend class binaryTree;
};
#endif
