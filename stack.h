#ifndef STACK_H
#define STACK_H
//#include"stackNode.h"
#include<iostream>
//Ziyao Gao zg8rw  09/22/2020
//FIle name: stack.h
using namespace std;

class stack{
 public:
  stack();
  ~stack();
  void push(int e);
  void pop();
  int top()const;
  bool empty();
 private:
  stack* head;
  int value1;
  stack* next;
  friend class postfixCalculator;
  friend class testPostfixcalCalc;
  //friend class stackNode;




};
#endif
