#include<iostream>
using namespace std;

int a;
int b;
int c;



cin>>a;
cin>>b;
cin>>c;
int sum=0;
sum+=a;
sum+=b;
sum+=c;
cout<<sum<<endl;
while(sum!=0){
  cout<<sum<<endl;
  cin>>a;
  cin>>b;
  cin>>c;
  sum=a+b+c;
 }
cout<<a,b,c<<endl;
