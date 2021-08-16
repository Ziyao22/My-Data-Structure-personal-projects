// Ziyao Gao
//zg8rw@virginia.edu
//09/06/2020
//xToN.cpp


#include <iostream>
using namespace std;

  int xton (int x, int y ) {
     int base=x;
     int power=y;
     if(x==0){
       return 0;
     }
     else if (y==0){
       return 1;

     }
     else
       return  x* xton(x,y-1);
    
}
  int main(){
    int a,b,c;
    cin>>a;
    cin>>b;
    c=xton(a,b);
    cout<<c <<endl;
    return 0;
 

}
