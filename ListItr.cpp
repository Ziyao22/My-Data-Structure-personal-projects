#include<iostream>
#include"ListNode.h"
#include"List.h"
#include"ListItr.h"
using namespace std;
// Ziyao Gao zg8rw  09/15/2020                                                  
// File name: ListItr.cpp

ListItr::ListItr(){
  current=NULL;
}
ListItr::ListItr(ListNode* theNode){
  current=theNode;
}

    // Returns true if the iterator is currently pointing past the end position
    // in the list (i.e., it's pointing to the dummy tail), else false
bool::ListItr::isPastEnd() const{
  if(current->next==NULL){
    return true;
  }
  else return false;

}

    // Returns true if the iterator is currently pointing past (before) the first position
    // in list (i.e., it's pointing to the dummy head), else false
bool::ListItr::isPastBeginning() const{
  if(current->previous==NULL){
    return true;
  }
  else return false;  
}

    // Advances `current` to the next position in the list (unless already past the end of the list)
void::ListItr::moveForward(){
  if(isPastEnd()){
  }
  else
   current=current->next;
  
}

    // Moves `current` back to the previous position in the list (unless already past the beginning of the list)
void::ListItr:: moveBackward(){
  if(isPastBeginning()){ 
  }
  else current=current->previous;
}
    // Returns the value of the item in the current position of the list
int::ListItr::retrieve() const{
   return current->value;
}
