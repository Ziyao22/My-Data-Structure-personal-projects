#include"puzzle.h"
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<unordered_set>
using namespace std;
//Ziyao Gao zg8rw 11/19/2020
//solvePuzzle.cpp
/*
  \author Ziyao Gao                                                         
  \data 11/17/2020                                                          
  \version 4.1a                                                             
  \warning unused warning to the user                                       
  \copyright Public License                                                 
 */
int main(){
  int input;
  vector<int>a;
  vector<puzzle*>b;
  //for(int i=0;i<9;i++){
  while(cin>>input){
    a.push_back(input);
    }
  cout<<endl;
  vector<int> goal={1,2,3,4,5,6,7,8,0};
  list<puzzle*>open;
  unordered_set<string>close;
  puzzle current=puzzle(nullptr,a);
  puzzle* current1;
  // int steps=0;
  //current1=open.front();
  /*string aa;
  for(int i=0;i<a.size();i++){
    aa+=a.at(i);
    }*/
  // unordered_map<string,int>check1;
  open.push_back(&current);
  int c[9];
  int inversions=0;
  int temp=0;
  for(int i=0;i<a.size();i++){
    c[i]=a.at(i);
  }
  for(int i=0;i<a.size();i++){
    for(int j=a.size()-1;j>0;j--){
      if(c[j]<c[j-1]){
	temp=c[j];
	c[j]=c[j-1];
	c[j-1]=temp;
	if(c[j]!=0&&c[j-1]!=0)
	  inversions++;
      }
    }
    }
  //cout<<inversions;
  if(a.size()!=9){
    cout<<"Please enter 9 numbers"<<endl;
  }
  // else //if(a==goal){
    //cout<<"Solving puzzle"<<endl;
    //cout<<0<<endl;
    // }
  else if(inversions==1||inversions%2==1){
    cout<<"IMPOSSIBLE"<<endl;
  }
  else{
    cout<<"Solving puzzle"<<endl;
  while(a!=goal){
    current1=open.front();
    open.pop_front();
    current1->options();
    int count=0;
    //cout<<1<<endl;
    // cout<<current1->children.size()<<endl;
    while(count<current1->children.size()){
      puzzle* currentNode=current1->children.at(count);
      count++;
      // cout<<count<<endl;
      if(currentNode->track1==goal){
	a=goal;
	cout<<current1->parent(b,currentNode)<<endl;
      }
      // string abc=to_string(currentNode);
      if(current1->check(close,currentNode)==false){
      open.push_back(currentNode);
      close.insert(currentNode->convert());
      }
  }
  }
  }
  return 0;
}
