#ifndef PUZZLE_H
#define PUZZLE_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//Ziyao Gao zg8rw 11/19/2020
//puzzle.h
class puzzle{
 public:
  puzzle(int newPuzzle[]);
  puzzle(puzzle* current, vector<int>current1);
  vector<puzzle*>children;
  puzzle* current;
  int input[9];
  void up();
  void down();
  void left();
  void right();
  void options();
  int parent(vector<puzzle*>current1,puzzle* parent);
  bool check(unordered_set<string>&current,puzzle* current1);
  string convert();
  //void parent(int current[],int previous[]);
  int track();
  vector<int>track1;
};
#endif
