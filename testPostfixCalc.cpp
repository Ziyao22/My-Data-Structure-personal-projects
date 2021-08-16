#include<iostream>
//#include<stack>
#include<string>
//#include"stackNode.h"
#include"stack.h"
#include "postfixCalculator.h"
#include<cstdlib>
using namespace std;
// ZIyao Gao zg8rw 09/22/2020                           
// File Name:testPostfixCalc.cpp 
int main(){
   postfixCalculator calculator;//=new postfixCalculator();
   string input;
   while(cin>>input){
   if(input=="+"){
   calculator.addition(); 
}
   else if (input=="-"){
   calculator.subtraction();
}
   else if (input=="*"){
     calculator.multiplication(); 
   }
   else if(input=="/"){
     calculator.division();
   }
   else if(input=="~"){
     calculator.unaryNegation();
   }
   else if(input<="0"||input>"0"){
     int x;
     x=stoi(input);
     calculator.intInput(x);
     // convert a string to an signed integer value: stoi();
}
   else cout<<"Please an valid expression!"<<endl;
}
   cout<<calculator.getResult()<<endl;
   return 0;
}
