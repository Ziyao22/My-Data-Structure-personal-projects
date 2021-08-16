// This program shows how C++-based file I/O works.
// It will open a file, read in the first two strings, and print them to the screen.
//Ziyao Gao zg8rw 11/14/2020
//topological.cpp
/*
 \author Ziyao Gao
 \date 11/14/2020
 \version 4.1a
 \warning  unused warning to the user
 \copyright Public License
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "middleearth.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
using namespace std;

struct node{
  int indegree;
  vector<string>adj;
  string key;
  node* previous;
  node* next;
};

// we want to use parameters
int main(int argc, char** argv) {
  vector<node*>current;
  vector<string>value1;
  string temp;
  int count=0;
  int count1=0;
  string  graph="included";
  string  degree="needed";
  node* path=new node();
  priority_queue<string,vector<string>,greater<string>>order;
  //priority_queue<string,vector<string>,compare<string>>order;
  // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    string s1, s2;
    //	file >> s1;
    //  file >> s2;
        while(s1>"0"||s1<"0"){
        file >> s1;
        file >> s2;
	node* current1=new node();
	node* next=new node();
       	node* previous=new node();
	int count2=0;
    	//for(int i=0;i<current.size();i++){
	while(count2<current.size()){
	if(current.at(count2)->key==s1){
        graph="notIncluded";
	count=count2;
	}
	if(current.at(count2)->key==s2){
        degree="notNeeded";
	count1=count2;
	}
	count2++;
        }
	if(s1>"0"||s1<"0"){
        if(graph=="included"){
        current1->key=s1;
	next->key=s2;
        (current1->adj).push_back(s2);
        current.push_back(current1);
	if(degree=="needed"){
	next->indegree=1;
        current.push_back(next);
	}
	else if(s1>"0"||s1<"0")
	current.at(count1)->indegree++;
	}
	else{
        previous->key=s2;
	(current.at(count)->adj).push_back(s2);
	if(degree=="needed"&&s1>"0"||s1<"0"){
	  previous->indegree=1;
	  current.push_back(previous);
	}
	else 
	  current.at(count1)->indegree++;
	  //next->key=s2;
	  //(current1->adj).push_back(s2);
	  // current.push_back(current1);
	}
       }
	graph="included";
	degree="needed";
	}
	list<node*>list1;
	int count3=0;
	//int count4=0;
	//int count5=0;
	while(count3<current.size()){
	path=current.at(count3);
        if(path->indegree==0)
	list1.push_back(path);
	count3++;
        }
	while(list1.size()>0){
	path=list1.front();
        value1=path->adj;
	list1.pop_front();
	int count4=0;
	while(count4<value1.size()){
	for(int count5=0;count5<current.size();count5++){
	if(value1.at(count4)==current.at(count5)->key){
        (current.at(count5)->indegree)--;
        if(current.at(count5)->indegree==0)
	  order.push(current.at(count5)->key);
	  }
	}
	count4++;
	}
	//path=q.front();
	//value1=path->adj;
	//q.pop_front();
	string letter=" ";
	while(list1.size()>0){
	  letter=list1.front()->key; 
	  list1.pop_front();
	  order.push(letter);
     	 }
	 while(order.size()>0){
	 temp=order.top();
	 order.pop();
	int count5=0;
	while(count5<current.size()){
	  if(temp==current.at(count5)->key)
	list1.push_back(current.at(count5));
	count5++;
	}
	}
	 cout<<path->key<<" ";
	 } 
	//}
	string a[1000];
    for(int i=0;i<current.size();i++){
      //cout<<value.at(i)->key;
      a[i]=current.at(i)->key;
    }
    string min;
    for(int i=0;i<current.size();i++){
      //   string temp;  
      for(int j=current.size()-1;j>0;j--){
	if(a[j]<a[j-1]){
	min=a[j];
      a[j]=a[j-1];
      a[j-1]=min;
	}
      }
    }
    for(int i=0;i<current.size();i++){
      //cout<<a[i]<<" ";
    }
	cout<<endl;
	file.close();
    return 0;
}
