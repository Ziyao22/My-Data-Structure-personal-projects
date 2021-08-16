#include <iostream>
using namespace std;
int main(){
int n;
int a[n];
 int x=0;
int iterate=0;
int element=0;
 int number;
 cin>>n;
 //for(int i=0;i<n;i++){
 // cin>>number;
 // a[i]=number;
 // }
while(iterate<n){
  cin>>number;
  a[iterate]=number;
  element=a[iterate];
  cout<<element<<endl;
  iterate++;
 }
 iterate=iterate-1;
 while(iterate>=0){
  element=a[iterate];
  cout<<element<<endl;
  iterate--;
  }
 return 0;
}
