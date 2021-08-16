#include<iostream>
//#include "stackNode.h"
#include "stack.h"
#include<string>
#include "postfixCalculator.h"
#include<cstdlib>
using namespace std;
// ZIyao Gao zg8rw 09/22/2020
// File Name: postfixCalculator.cpp
postfixCalculator::postfixCalculator(){
}
void postfixCalculator::intInput(int x){
       value.push(x);
}
void postfixCalculator::addition(){
  // int x,y,z;
  // value.push(x);
  //value.push(y);
  // z=value.top();
  // value.pop();
  // z+=value.top();
  //value.push(z);
  int input1;
  int input2;
  int input3=input1+input2;
  input1=value.top();
  value.pop();
  input2=value.top();
  value.pop();
  value.push(input1+input2);
}
   // add the two nums and push back to the top of the stack;  
void postfixCalculator::subtraction(){
  int input1;
  int input2;
  //  int input3=input1-input2;
  input1=value.top();
  value.pop();
  input2=value.top();
  value.pop();
  value.push(input2-input1);
}
void postfixCalculator::multiplication(){
  int input1;
  int input2;                                       
  input1=value.top();
  value.pop();
  input2=value.top();
  value.pop();
  value.push(input1*input2);
}
void postfixCalculator::division(){
  int input1;
  int input2;
  input1=value.top();
  value.pop();
  input2=value.top();
  value.pop();
  value.push(input2/input1);
}
void postfixCalculator::unaryNegation(){
  int input1;
  input1=value.top();
  value.pop();
  input1=input1*-1;
  value.push(input1);
}
   int postfixCalculator::getResult() const{
     return value.top();
}
