#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
//Ziyao Gao zg8rw  10/24/2020
//File name: mathfun.cpp
extern "C" int product(int,int);
extern "C" int power(int,int);

int main(){
  int input1;
  int input2;
  cout<<"Enter integer 1:"<<endl;
  cin>>input1;
  cout<<"Enter integer 2:"<<endl;
  cin>>input2;
  int result;
  result=product(input1,input2);
  int result2=power(input1,input2);
  cout<<"Product: "<<result<<endl;
  cout<<"Power: "<<result2<<endl;
  return 0;
}
