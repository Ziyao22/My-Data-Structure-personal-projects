// FIle bankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

// Ziyao Gao zg8rw  09/06/2020                                 
// File name: bankAccount.h     
class bankAccount{

 public:
  bankAccount( );
  
  bankAccount(double amount);

  ~bankAccount();

   double withdraw(double amount);

   double deposit(double amount);

   double getBalance();

 private:
  double balance;
};
#endif
