#include<string>
#include "puzzle.h"
#include<vector>
using namespace std;
//Ziyao Gao zg8rw 11/18/2020
//puzzle.cpp
puzzle::puzzle(int newPuzzle[]){
  for(int i=0;i<9;i++){
    input[i]=newPuzzle[i];
  }
  }
puzzle::puzzle(puzzle* current, vector<int>current1){
  this->current=current;
  track1=current1;
}
void puzzle::up(){
  // if(count-3<=0){
    int current=track();
  vector<int> current1=track1;
  if(current-3>=0){
    int temp=0;
    temp=current1[current-3];
    current1.at(current-3)=current1.at(current);
    current1.at(current)=temp;
    //cout<<current1.at(current)<<current1.at(current-3)<<endl;
    puzzle* node=new puzzle(this,current1); 
    children.push_back(node);  
  }
}
void puzzle::down(){
int current=track();
  vector<int> current1=track1;
  if(current/3<2){
    int temp=0;
    temp=current1[current+3];
    current1.at(current+3)=current1.at(current);
    current1.at(current)=temp;
    //cout<<current1.at(current)<<current1.at(current+3)<<endl;
    puzzle* node=new puzzle(this,current1);
    children.push_back(node);
  }
}
void puzzle::left(){
  int current=track();
  vector<int> current1=track1;
  if(current%3!=0){
    int temp=0;
    temp=current1[current-1];
    current1.at(current-1)=current1.at(current);
    current1.at(current)=temp;
    //cout<<current1.at(current)<<current1.at(current-1)<<endl;
    puzzle* node=new puzzle(this,current1);
    children.push_back(node);
  }
}
void puzzle::right(){
  int current=track();
  vector<int> current1=track1;
  if(current%3!=2){
    int temp=0;
    temp=current1[current+1];
    current1.at(current+1)=current1.at(current);
    current1.at(current)=temp;
    //cout<<current1.at(current)<<current1.at(current+1)<<endl;
    puzzle* node=new puzzle(this,current1);
    children.push_back(node);
  }
}
int puzzle::track(){
  vector<int>::iterator itr;
  itr=find(track1.begin(),track1.end(),0);
  int track=distance(track1.begin(),itr);
  return track;
}
bool puzzle::check(unordered_set<string>&current,puzzle* current1){
  /*puzzle* node=current.front();
  while(node!=NULL){
    int count=0;
    for(int i=0;i<node->track1.size();i++){
      if(node->track1.at(i)!=current1->track1.at(i))
	count++;
      // }
      if(count==9)
      return true;
       }
    }
    return false;*/
  if(current.find(current1->convert())==current.end()){
    return false;
  }
  return true;
}
string puzzle::convert(){
  string temp;
  for(int i=0;i<track1.size();i++){
    temp+=to_string(track1.at(i));
  }
  return temp;
}
void puzzle::options(){
  left();
  up();
  right();
  down();
}
/*void puzzle::parent(int current[],int previous[]){
  int count=0;
  while(count<previous.length)
    current[count]=previous[count];
    }*/
int puzzle::parent(vector<puzzle*>current1, puzzle* parent) {
  int count=0;
  puzzle* node=parent;
  current1.push_back(parent);
  while(node->current!=NULL) {
    node=node->current;
    current1.push_back(node);
    count++;
  }
  return count;
}
