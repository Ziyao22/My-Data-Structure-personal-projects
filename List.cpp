#include<iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
using namespace std;
// Ziyao Gao zg8rw  09/15/2020                                                  
// File name: List.cpp
List::List(){
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;
  head->previous=NULL;
  tail->next=NULL;
}
List::List(const List& source){
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;
  // Make a deep copy of the list:
  ListItr iter(source.head->next);
  while(!iter.isPastEnd()){
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
  
}
List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}
List& List::operator=(const List& source){
  if(this==&source){
    //The two are the same list; no need to do anything
    return *this;
  }
  else {
    //Clear out anything this list contained before copying over the items from the other list
    makeEmpty();
    //Make a deep copy of the list
    ListItr iter(source.head->next);
    while(!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}
// Returns true if empty, else false
bool::List::isEmpty() const{
if(head==NULL&&tail==NULL){
  return true;
 }
 else return false;
}
    // Removes (deletes) all items except the dummy head/tail.
    // The list should be a working empty list after this.
void List::makeEmpty(){
  ListNode* itr=head->next;
   while(itr->next!=NULL){
         itr=itr->next;
       remove(itr->previous->value);
     }
   head->next=tail;
   tail->previous=head;
   // remove(itr->value);
   // delete itr;
   count=0;
   // ListNode* itr2=tail;
   // while(itr2->previous!=NULL){
   //  itr2=itr2->previous;
   // delete tail;
   // tail=itr2;
     //count--;
   // }
   // delete itr2;
}
  // count=0;
  // ListNode* current=first().current;
// ListItr  itr;
//  ListItr* temp=head->next->next;
//if(head!=NULL&&tail!=NULL){
  // while(!itr.isPastEnd()){
	// delete itr->current;
       // itr=temp;
       // temp.moveForward();
       //}
      // head->next=tail;
   // tail->previous=head;
   //  count=0 ;
 // else {
  //  while(count!=0){
    // delete head;                                                            
  // tail=tail->previous;
  // delete tail->next;
  // count--;
  // }
  //  delete tail;
  // count=0;

  // }
// }

    // Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty list!)
ListItr List::first(){
  ListItr itr(this->head->next);
  return itr;

}

    // Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
ListItr List :: last(){
  ListItr itr(this->tail->previous);
   return itr;

}

    // Inserts x after current iterator position
void List::insertAfter(int x, ListItr position){
   ListNode* currentNode=new ListNode();
   currentNode->value=x;
   // while(head->next!=currentNode){
   // head=head->next;
   // }
   //currentNode->previous->next=currentNode;
  currentNode->next=position.current->next;
  currentNode->previous=position.current;
  currentNode->next->previous=currentNode;
  position.current->next=currentNode; 
  count++;
}

    // Inserts x before current iterator position
void List:: insertBefore(int x, ListItr position){
  ListNode* currentNode=new ListNode();
  currentNode->value=x;
  currentNode->previous=position.current->previous;
  currentNode->next=position.current;
  currentNode->previous->next=currentNode;
  position.current->previous=currentNode;
  count++;
}

    // Inserts x at tail of list
void List:: insertAtTail(int x){
  ListNode* currentNode=new ListNode();
   currentNode->value=x;
   currentNode->previous=tail->previous;
   tail->previous->next=currentNode;
   tail->previous=currentNode;
   currentNode->next=tail;
   count++;
   // currentNode=NULL;
  }

    // Returns an iterator that points to the first occurrence of x.
    // When the parameter is not in the list, return a ListItr object that points to the dummy tail node.
    // This makes sense because you can test the return from find() to see if isPastEnd() is true.
ListItr List::find(int x){
      ListItr itr=ListItr(head);
      while(itr.current->value!=x&&!itr.isPastEnd()){
	itr.moveForward();
     }
   return itr;
   // ListItr itr(this->head->previous);
   // return itr;

}
    // Removes the first occurrence of x
void List:: remove(int x){
  ListNode* currentNode=head;
  //  ListItr  itr=find(x);
  //  if(itr){
  while(currentNode!=NULL&&currentNode->value!=x){
  currentNode=currentNode->next;
   }
  if(currentNode!=NULL&&currentNode->value==x){
   currentNode->previous->next=currentNode->next;
   currentNode->next->previous=currentNode->previous;
   //currentNode=NULL;
   delete currentNode;
   count--;
    }
  }
   //   delete currentNode;
    // Returns the number of elements in the list
int List::size() const{
  return count;


}   
// printList: non-member function prototype
// prints list forwards (head -> tail) when forward is true
// or backwards (tail -> head) when forward is false
// You **must** use your ListItr class to implement this function!
void printList(List& source, bool forward){
  
  //  if(source.isEmpty()){
  //cout<<"THe list is empty."<<endl;
  //  }
   if(forward){
	ListItr itr1=source.first();
        while(!itr1.isPastEnd()){
	  cout<< itr1.retrieve() <<" ";
   itr1.moveForward();
   }
  }
   // cout<<""<<endl;
       else {
       ListItr itr2=source.last();
      	while(!itr2.isPastBeginning()){
        cout<< itr2.retrieve() <<" ";
       itr2.moveBackward();
       }
       }
       cout<<""<<endl;

   }

