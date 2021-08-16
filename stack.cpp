#include<iostream>
//#include"stackNode.h"
#include"stack.h"
#include<cstdlib>
//#include"postfixCalculator.h"
//Ziyao Gao zg8rw  09/22/2020
//File name: stack.cpp
using namespace std;

stack::stack(){
  value1=0;
  next=NULL;
  head=NULL;
}

stack::~stack(){
  delete head;
  delete next;
}
void stack::push(int e){
   stack* current=new stack();
   current->value1=e;
   if(head==NULL){
     head=current;
   }
   else{
     current->next=head;
     head=current;
   }
   //   delete current;
  
}
void stack::pop(){
  if(empty()){
    cout<<"The stack is empty"<<endl;
    exit(-1);
  }
  else{
    head=head->next;
  }
}
int::stack::top()const {
  if(head==NULL)
  exit(-1);
  else 
    return head->value1;  
}
bool::stack::empty(){
  if(head==NULL){
    return true;
  }
  else return false;

}
