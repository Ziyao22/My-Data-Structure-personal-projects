#include<iostream>
#include"timer.h"
using namespace std;
//Ziyao Gao zg8rw 11/01/2020
//threexinput.cpp
extern "C" int threexplusone(int);

int main(){
  int number;
  int iterations;
  cout<<"Enter a number: ";
  cin>>number;
  cout<<"Enter iterations of subroutine: ";
  cin>>iterations;
  //timer sum;
  //sum.start();
  for(int i=0;i<iterations;i++){
    threexplusone(number);
  }
  /*int i=0;
  while(i<iterations){
    threexplusone(number);
    i++;
  }*/
  //sum.stop();
  cout<<"Iterations: "<<threexplusone(number)<<endl;
  // cout<<sum.getTime()*1000/iterations<<endl;
  return 0;
}
