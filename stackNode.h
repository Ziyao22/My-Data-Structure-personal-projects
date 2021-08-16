#ifndef STACKNODE_H
#define STACKNODE_H
#include<iostream>
using namespace std;

class stackNode{
 public:
  stackNode();
 private:
  int value;
  stackNode* next;

  friend class stack;
  friend class postfixCalculator;

};
#endif
