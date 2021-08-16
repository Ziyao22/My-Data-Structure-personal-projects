#ifndef postfixCalculator_H
#define postfixCalculator_H
#include <iostream>
//#include "stackNode.h"
#include "stack.h"
// ZIyao Gao zg8rw 09/22/2020   
// File Name: postfixCalculator.h
class postfixCalculator{
public:
   postfixCalculator();
   
   void intInput(int x);
   void addition();
   
   void subtraction();
   //void charInput(char a);
   void multiplication();
   void division();
   void unaryNegation();
   int getResult() const;
   
   private:
   stack  value;
   //char symbol;

};

#endif
