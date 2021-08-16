#include<iostream>
#include<string>
#include<vector>
#include<list>
#include "hashTable.h"
using namespace std;
//Ziyao Gao zg8rw 10/11/2020
//File name: hashTable.cpp

/*hashTable::hashTable(){
  list<string>element;
  for(int i=0;i<size;i++){
    HT.push_back(element);
  }
  }*/
hashTable::hashTable(int size1){
  if(checkprime(size1)==false){
    // size=2*size1;
     size=getNextPrime(size1);
  }
  else size=size1;
  // table=new list<string>[size];
  for(int i=0;i<size;i++){
  // list<string>element;
  //HT.push_back(element);
     HT=new list<string>[size];
      }
}
int hashTable::hashTable1(string key){
  int location=0;
  int length=0;
  for(int i=0;i<key.length();i++){
    location+=(int)key[i];
  }
  //length=(3*location+7)%size;
  length=location%size;
  return length;
}
void hashTable::insert(string key){
  int element=hashTable1(key);
    HT[element].push_back(key);
    //cout<<"1";
    //}
  // else{
  //  hashTable* currentNode;
  //  currentNode=hashTable[element];
    //hashTable* currentNode1=new hashTable();
  // while(currentNode->next!=NULL){
  // currentNode=currentNode->next;
  // element++;
    //hashTable[element]=key;
  // }
  // HT[element].push_back(key);
  // }
}
bool hashTable::find(string key){
  int number=hashTable1(key);
  bool found=false;
  list<string>::iterator itr;
  for(itr=HT[number].begin();itr!=HT[number].end();itr++){
  if(*itr==key){
    found=true;
    // return found;
    break;
  }
  }
  return found;
}
bool hashTable::checkprime(unsigned int p){
  if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases     
        return false;
    if ( p == 2 ) // 2 is prime                                             
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime            
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p      
        if ( p % i == 0 )
            return false;
    return true;
}
int hashTable::getNextPrime(unsigned int n){
  while ( !checkprime(++n) );
  return n; // all your primes are belong to us
}
