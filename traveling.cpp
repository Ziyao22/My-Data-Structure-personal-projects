#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
//Ziyao Gao zg8rw 11/17/2020
//traveling.cpp
/*
  \author Ziyao Gao
  \data 11/17/2020
  \version 4.1a
  \warning unused warning to the user
  \copyright Public License
 */
#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    sort(dests.begin()+1,dests.end());
    //string temp[1000];
    vector<string>temp;
    //float count=computeDistance(me,beginning,dests);
    temp=dests;
    float shorterPath=computeDistance(me,dests.at(0),dests);
    float Path=0.0;
    while(next_permutation(dests.begin()+1,dests.end())){
       Path=computeDistance(me,dests.at(0),dests);
      // float count1=
      if(shorterPath>Path){
	shorterPath=Path;
	temp=dests;
      }
    }
    cout<<"Minimum path has distance "<<shorterPath<<": ";
      //<<printRoute(temp.at(0),temp);
    printRoute(temp.at(0),temp);
    //cout<<endl;
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float distance=0.0;
  //string a=dests.at(0);
  int count=0;
  for(int i=0;i<dests.size()-1;i++){
    distance+=me.getDistance(dests.at(i),dests.at(i+1));
    //a=dests.at(i);
    count++;
  }
  distance+=me.getDistance(dests.at(count),dests.front());
    return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  int count=0;
  while(count<dests.size()){
    cout<<dests.at(count)<<" -> ";
    count++;
  }
  cout<<start<<endl;
}
