// FIle bankAccount.cpp

#include "bankAccount.h"
#include <iostream>
using namespace std;
// Ziyao Gao zg8rw  09/06/2020                                 
// File name: bankAccount.cpp 
bankAccount::bankAccount():balance(0.00){
  
}
bankAccount::bankAccount(double newBalance){
  balance=newBalance;
  
}
bankAccount::~bankAccount(){
}
double  bankAccount::withdraw(double  number){
   if(number>balance){
     return balance;
   }
   else
    return balance=balance-number;
}
double  bankAccount::deposit(double number1){
  return balance=balance+number1;
}
double  bankAccount::getBalance(){
  return balance;
}



  
