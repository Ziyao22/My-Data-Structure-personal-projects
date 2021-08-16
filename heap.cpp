#include<iostream>
#include"heap.h"
using namespace std;
//Ziyao Gao zg8rw 11/10/2020
//heap.cpp
heap::heap():heap_size(0){
  heap1.push_back(0);
}
heap::heap(vector<binaryTree*>vec):heap_size(vec.size()){
  heap1=vec;
  heap1.push_back(heap1[0]);
  heap1[0]=0;
  for(int i=heap_size/2;i>0;i--){
    percolateDown(i);
  }
}
heap::~heap(){
}
void heap::insert(binaryTree* node){
  heap1.push_back(node);
  percolateUp(++heap_size);
}
binaryTree* heap::findMin(){
  if(heap_size==0){
    throw "findMin() called on empty heap";
  }
  return heap1[1];
}
binaryTree* heap::deleteMin(){
  if(heap_size==0){
    throw "deleteMin() called on empty heap";
  }
  binaryTree* ret=new binaryTree();
  ret=heap1[1];
    heap1[1]=heap1[heap_size--];
    heap1.pop_back();
  if(!isEmpty()){
    percolateDown(1);
  }
  return ret;
}
unsigned int heap::size(){
  return heap_size;
}
void heap::makeEmpty(){
  heap_size=0;
  heap1.resize(1);
}
bool heap::isEmpty(){
  return heap_size==0;
}
void heap::print(){
  cout<<"("<<heap1[0]<<")";
  for(int i=1;i<=heap_size;i++){
    cout<<heap1[i]<<" ";
    bool isPow2=(((i+1)&~(i))==(i+1))?i+1:0;
    if(isPow2){
      cout<<endl<<"\t";
    }
  }
  cout<<endl;
}
void heap::percolateUp(int hole){
  binaryTree* node=new binaryTree();
  node=heap1[hole];
  int x=heap1[hole]->times;
  for( ;(hole>1)&&(x<heap1[hole/2]->times); hole/=2){
    heap1[hole]=heap1[hole/2];
  }
  heap1[hole]=node;
}
void heap::percolateDown(int hole){
  binaryTree* node=new binaryTree();
  node=heap1[hole];
  int x=heap1[hole]->times;
  while(hole*2<=heap_size){
    int child=hole*2;
    if((child+1<=heap_size)&&(heap1[child+1]->times<heap1[child]->times)){
      child++;
    }
    if(x>heap1[child]->times){
      heap1[hole]=heap1[child];
      hole=child;
    }
    else{
      break;
    }
  }
  heap1[hole]=node;
}
void heap::huffmanTree(){
  if(heap_size==0){
    throw "huffmanTree() called on empty heap";
  }
  else{
    while(heap_size>1){
      binaryTree* node=new binaryTree();
      binaryTree* left1=new binaryTree();
      left1=findMin();
      deleteMin();
      binaryTree* right1=new binaryTree();
      right1=findMin();
      deleteMin();
      node->left=left1;
      node->right=right1;
      node->times=left1->times+right1->times;
      insert(node);
    }
  }
}
void heap::prefix(binaryTree* node,vector<string>& pre,vector<string>& curr,
		  string letter){
  if(node==NULL){
    cout<<"It is empty!"<<endl;
  }
  else if(node->left==NULL&&node->right==NULL){
    pre.push_back(node->letters);
    curr.push_back(letter);
  }
   else{
     prefix(node->left,pre,curr,letter+"0");
     prefix(node->right,pre,curr,letter+"1");
   }
}
void heap::huffmanTree1(binaryTree*& node,int count,string readInPrefix,
			string letter){
  /* if(node==NULL){
    node=new binaryTree();
  }
  else if(count==(readInPrefix.length())){
    binaryTree* current=new binaryTree(0,readInPrefix);
    node=current;
  }
  else if(readInPrefix.at(count)=='0'&&node!=NULL){
    huffmanTree1(node->left,count+1,readInPrefix,letter);
  }
  else if(readInPrefix.at(count)=='1'&&node!=NULL){
    huffmanTree1(node->right,count+1,readInPrefix,letter);
  }
  else{
  }*/
  if(node==NULL){
    binaryTree* current=new binaryTree();
    node=current;
  }
  if(node!=NULL){
    if(count==(letter.length())){
      binaryTree* current=new binaryTree(count,readInPrefix);
      node=current;
    }
    else if(letter.at(count)=='0'){
      huffmanTree1(node->left,count+1,readInPrefix,letter);
    }
    else if(letter.at(count)=='1'){
      huffmanTree1(node->right,count+1,readInPrefix,letter);
    }
      else{
  }
  }
}
void heap::printTree(binaryTree* node,int& count,string read){
  if(node==NULL){
  }
  else if(node->left==NULL&&node->right==NULL){
      cout<<node->letters;
  }
  else if(read.at(count)=='0'&&node!=NULL){
      printTree(node->left,count+=1,read);
    }
  else if(read.at(count)=='1'&&node!=NULL){
    printTree(node->right,count+=1,read);
   }
    else{
}
}
