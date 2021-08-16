#include<iostream>
using namespace std;
#include <climits>
#include<string>
//ZIyao Gao zg8rw 09/26/2020
// FIle name: prelab4.cpp
void  sizeOfTest(){
  // int x;
   cout<<"Size of int: "<<sizeof(int)<<endl;
   cout<<"Size of unsigned int: "<<sizeof(unsigned int)<<endl;
   cout<<"Size of float: "<<sizeof(float)<<endl;
   cout<<"Size of double: "<<sizeof(double)<<endl;
   cout<<"Size of char: "<<sizeof(char)<<endl;
   cout<<"Size of bool: "<<sizeof(bool)<<endl;
   cout<<"Size of int*: "<<sizeof(int*)<<endl;
   cout<<"Size of char*: "<<sizeof(char*)<<endl;
   cout<<"Size of double*: "<<sizeof(double*)<<endl;
}

void  overflow(){
   cout<<UINT_MAX<<" +"<<" 1 = "<<UINT_MAX+1<<endl;
}
string  outputBinary(unsigned int input,int endBase){
  int remainder;
  int position=0;
  string total;
   while(input>0){
   remainder=input%endBase;
   //   if(position%4==0){
   // total=" "+total;
   //  }
   total=to_string(remainder)+total;
    input=input/endBase;
    position++;
   }
   // total=to_string(1)+total;
  //for(int i=position; i<32;i++){
  // if(i%4==0){
  //   total=" "+total;
  //  }
  // total=to_string(0)+total;
  // }
  return total;
}
int main(){
 unsigned int input1;
 int endBase;
 cin>>input1;
 cin>>endBase;
    // cout<<outputBinary(input1)<<endl;

    sizeOfTest();
    overflow();
    cout<<outputBinary(input1,endBase)<<endl;
 
	 return 0;
};
