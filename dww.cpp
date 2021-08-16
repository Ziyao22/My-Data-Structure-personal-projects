int input;
int remainder;
int position=0;
int total=0;
cin>>input;
while(input!=0){
remainder=input%2;
input=input/2;
total+=remainder*(10^position);
 position++; 
 }



555%2=1  z=1 555/2=278  278%2=0  z=10+1 
