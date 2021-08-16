#include<iostream>
using namespace std;
#include<string>
//Ziyao Gao zg8rw 09/28/2020
//FIle name: bitCounter.cpp
int numberOfOnes(int input){
  if(input==1){
    return 1;
  }
  else if (input==0){
    return 0;
  }
  else  if(input%2==0)
    return numberOfOnes(input/2);
  
  else 
    return 1+numberOfOnes(input/2);
  
}
void  hexToInt(string input,int startBase,int endBase){
  // const char *convert=input.c_str();
  int length=input.length();
  int power=0;
  int result=0;
  if(input.at(length-1)=='0'){
  }
  else if(input.at(length-1)=='1'){
    result=1;
  }
  else if(input.at(length-1)=='2'){
    result=2;
  }
else if(input.at(length-1)=='3'){
    result=3;
  }
else if(input.at(length-1)=='4'){
    result=4;
  }
else if(input.at(length-1)=='5'){
    result=5;
  }
else if(input.at(length-1)=='6'){
    result=6;
  }
else if(input.at(length-1)=='7'){
    result=7;
  }
else if(input.at(length-1)=='8'){
    result=8;
  }
else if(input.at(length-1)=='9'){
    result=9;
  }
else if(input.at(length-1)=='A'){
    result=10;
  }
else if(input.at(length-1)=='B'){
    result=11;
  }
else if(input.at(length-1)=='C'){
    result=12;
  }
else if(input.at(length-1)=='D'){
    result=13;
  }
else if(input.at(length-1)=='E'){
    result=14;
  }
 else {
    result=15;
  }
  if(input.length()!=1){
  for(int i=length-2;i>=0;i--){
  if(input.at(i)=='0'){
    // result+=0*pow(startBase,power);
    }
     else if(input.at(i)=='1'){
       int power1=1;
       for(int i=0;i<=power;i++){
	 power1 *=startBase;
       }
       result+=1*power1;
       //  result+=1*pow(startBase,power);
    }
    else if(input.at(i)=='2'){
      int power2=1;
     for(int i=0;i<=power;i++){
         power2 *=startBase;
       }
       result+=2*power2;
       // result+=2*pow(startBase,power);
    }
    else if(input.at(i)=='3'){
      int power3=1;
     for(int i=0;i<=power;i++){
         power3 *=startBase;
       }
       result+=3*power3;
      // result+=3*pow(startBase,power);
    }
    else if(input.at(i)=='4'){
      int power4=1;
     for(int i=0;i<=power;i++){
         power4 *=startBase;
       }
       result+=4*power4;
      // result+=4*pow(startBase,power);
    }
    else if(input.at(i)=='5'){
      int power5=1;
      for(int i=0;i<=power;i++){
         power5 *=startBase;
       }
      result+=5*power5;
      // result+=5*pow(startBase,power);
    }
    else if(input.at(i)=='6'){
      int power6=1;
      for(int i=0;i<=power;i++){
         power6 *=startBase;
       }
       result+=6*power6;
      //result+=6*pow(startBase,power);
    }
    else if(input.at(i)=='7'){
      int power7=1;
      for(int i=0;i<=power;i++){
         power7 *=startBase;
       }
       result+=7*power7;
      // result+=7*pow(startBase,power);
    }
    else if(input.at(i)=='8'){
      int power7=1;
      for(int i=0;i<=power;i++){
         power7 *=startBase;
       }
       result+=8*power7;
      // result+=8*pow(startBase,power);
    }
    else if(input.at(i)=='9'){
      int power8=1;
      for(int i=0;i<=power;i++){
         power8 *=startBase;
       }
       result+=9*power8;
      // result+=9*pow(startBase,power);
    }
    else if(input.at(i)=='A'){
     int power9=1;
      for(int i=0;i<=power;i++){
         power9 *=startBase;
       }
       result+=10*power9;
      // result+=10*pow(startBase,power);
    }
    else if(input.at(i)=='B'){
    int power10=1;
      for(int i=0;i<=power;i++){
         power10 *=startBase;
       }
       result+=11*power10;
      // result+=11*pow(startBase,power);
    }
    else if(input.at(i)=='C'){
      int power11=1;
      for(int i=0;i<=power;i++){
         power11 *=startBase;
       }
       result+=12*power11;
      // result+=12*pow(startBase,power);
    }
    else if(input.at(i)=='D'){
      int power12=1;
      for(int i=0;i<=power;i++){
         power12 *=startBase;
       }
       result+=13*power12;
      //result+=13*pow(startBase,power);
    }
    else if(input.at(i)=='E'){
      int power13=1;
      for(int i=0;i<=power;i++){
         power13 *=startBase;
       }
       result+=14*power13;
      // result+=14*pow(startBase,power);
    }
    else{
      int power14=1;
      for(int i=0;i<=power;i++){
         power14 *=startBase;
       }
       result+=15*power14;
     // result+=15*pow(startBase,power);
    }
  power++;
  }
    }
  if(endBase==10){
  cout<<input<<" (base "<<startBase<<")"<<" = "<<result<<" (base "
  <<endBase<<")"<<endl;
  }
  else {
  int remainder;
  //  int position=0;
  string total;
   while(result>0){
    remainder=result%endBase;
   // if(position%4==0){
   //  total=" "+total;
   // }
   // cout<<"Remainder:"<<remainder<<endl;
    total=to_string(remainder)+total;
    result=result/endBase;
    // cout<<"Result:"<<result<<endl;
   };
   // result=stoi(total);
    // position++;
   
   // }
  // int remainder;
  //  string total;
  // if(endBase!=10){
  // while(result/endBase!=0){
  // remainder=result%endBase;
  // total=to_string(remainder)+total;
  // result=result/endBase;
   // result+=stoi(total);
  // }
  // result=stoi(total);
  // }
  cout<<input<<" (base "<<startBase<<")"<<" = "
  <<total <<" (base "<<endBase<<")" <<endl;
  }
}
int main(int argc, char **argv){
   int input1;
   string input2;
   int startBase;
   int endBase;
   input1=atoi(argv[1]);
   input2=argv[2];
   startBase=atoi(argv[3]);
   endBase=atoi(argv[4]);
    // string x=(argv[i]);
    // cout<<argv[1]<<endl;
    // cout<<input1<<" has "<<numberOfOnes(input1)<<" bit(s)"<<endl;
    // hexToInt(input2,startBase,endBase);

  // cout<<input1<<" "<<input2<<" "<<startBase<<" "<<endBase<<endl;
     cout<<input1<<" has "<<numberOfOnes(input1)<<" bit(s)"<<endl;
     hexToInt(input2,startBase,endBase);
  return 0;
}
