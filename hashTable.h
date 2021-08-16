#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<string>
#include<iostream>
#include<vector>
#include<list>
using namespace std;
//Ziyao Gao zg8rw 10/11/2020
//File name: hashTable.h
class hashTable{
 public:
  //hashTable();
  hashTable(int size);
  int hashTable1(string key);
  void insert(string key);
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
  bool find(string key);

 private:
  int size;
  //hashTable* next;
  list<string> *HT;
  
  
};
#endif
