/*
  DO NOT ALTER
*/

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include "accounts.h"

int main() {
  // default constructor for CheckingAccount
  CheckingAccount acct1;

  // make sure we initialized the account properly
  assert(acct1.getCustomerName() == "");
  assert(acct1.getAccountBalance() == 0);
  assert(acct1.getInterestRate() == 0);

  // update member values
  acct1.setCustomerName("Rafael Diaz");
  acct1.setAccountBalance(12345.67);
  acct1.setInterestRate(2.0);

  // make sure we initialized the account properly
  assert(acct1.getCustomerName() == "Rafael Diaz");
  assert(fabs(acct1.getAccountBalance() - 12345.67) < 1e-2);
  assert(fabs(acct1.getInterestRate() - 2.0) < 1e-4);

  // check for correct implementation of compounding
  acct1.compoundInterest();
  assert(fabs(acct1.getAccountBalance() - 12346.35) < 1e-3);

  // check that withdrawing works
  acct1.withdrawAccount(10000);
  assert(fabs(acct1.getAccountBalance() - 2346.35) < 1e-2);

  // try to overdraw account
  acct1.withdrawAccount(10000);
  assert(fabs(acct1.getAccountBalance() - 2346.35) < 1e-2);

  // make sure we would get a bogus value from checking
  assert(!acct1.checkAccount(10000));

  // make sure we would pass for a smaller value
  assert(acct1.checkAccount(2346.35));

  // parametrized constructor for CheckingAccount
  CheckingAccount acct2("Joe Smith", 1000.0, 1.0);

  // make sure we initialized the account properly
  assert(acct2.getCustomerName() == "Joe Smith");
  assert(fabs(acct2.getAccountBalance() - 1000) < 1e-2);
  assert(fabs(acct2.getInterestRate() - 1.0) < 1e-4);

  // call print function
  acct2.printAccountInfo();

  // try savings account now
  SavingsAccount acct3;

  // make sure values are initialized properly
  assert(acct3.getCustomerName() == "");
  assert(acct3.getAccountBalance() == 0);
  assert(acct3.getInterestRate() == 0);
  assert(acct3.getWithdrawalEvents() == 0);

  // update values
  acct3.setCustomerName("Elizabeth Bennet");
  acct3.setAccountBalance(98765432);
  acct3.setInterestRate(5.99);

  // check that values were set correctly
  assert(acct3.getCustomerName() == "Elizabeth Bennet");
  assert(fabs(acct3.getAccountBalance() - 98765432) < 1e-2);
  assert(fabs(acct3.getInterestRate() - 5.99) < 1e-4);

  // check that compounding works correctly
  acct3.compoundInterest();
  assert(fabs(acct3.getAccountBalance() - 98781640.35) < 1e-3);

  // check print function
  acct3.printAccountInfo();

  // now create a savings account with parametrized constructor
  SavingsAccount acct4("Marian Zhou", 250000, 2.99);

  // check that values were set correctly
  assert(acct4.getCustomerName() == "Marian Zhou");
  assert(fabs(acct4.getAccountBalance() - 250000) < 1e-2);
  assert(fabs(acct4.getInterestRate() - 2.99) < 1e-4);

  // check that performing a withdrawal works 2 times
  acct4.withdrawAccount(100000);
  assert(fabs(acct4.getAccountBalance() - 150000) < 1e-2);
  assert(acct4.getWithdrawalEvents() == 1);
  acct4.withdrawAccount(100000);
  assert(fabs(acct4.getAccountBalance() - 50000) < 1e-2);
  assert(acct4.getWithdrawalEvents() == 2);
  // comfirm a check now would fail
  assert(!acct4.checkAccount(1));
  // failed withdrawal because of number of withdrawal events
  acct4.withdrawAccount(1);
  assert(fabs(acct4.getAccountBalance() - 50000) < 1e-2);
  assert(acct4.getWithdrawalEvents() == 2);
  // reset
  acct4.resetWithdrawalEvents();
  assert(acct4.getWithdrawalEvents() == 0);
  // now fail withdrawal because of insufficient funds
  assert(!acct4.checkAccount(50001));
  acct4.withdrawAccount(50001);
  assert(fabs(acct4.getAccountBalance() - 50000) < 1e-2);
  assert(acct4.getWithdrawalEvents() == 0);
  assert(acct4.checkAccount(50000));

  cout << "All tests successfully passed!" << endl;

  return 0;
}
