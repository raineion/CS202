/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 5
 * Description: Implementation of Account, CheckingAccount, 
 *              and SavingsAccount classes
 * Input: N/A
 * Output: N/A
 */

#include "accounts.h" // for Account information
#include <cmath> // for pow
#include <iomanip> // for fixed, setprecision

using namespace std;

/*
 * Account::Account
 * Description: Default constructor for Account
 * Input: None
 * Output: None
 */
Account::Account() : customerName(""), accountBalance(0.0), 
                     interestRate(0.0) {}

/*
 * Account::Account
 * Description: Parametrized constructor for Account
 * Input: string name, double amount, double rate
 * Output: None
 */
Account::Account(string name, double amount, double rate)
    : customerName(name), accountBalance(amount), 
                             interestRate(rate) {}

/*
 * Account::getCustomerName
 * Description: Getter for customerName
 * Input: None
 * Output: string
 */
string Account::getCustomerName() const {
    return customerName;
}

/*
 * Account::getAccountBalance
 * Description: Getter for accountBalance
 * Input: None
 * Output: double
 */
double Account::getAccountBalance() const {
    return accountBalance;
}

/*
 * Account::getInterestRate
 * Description: Getter for interestRate
 * Input: None
 * Output: double
 */
double Account::getInterestRate() const {
    return interestRate;
}

/*
 * Account::setCustomerName
 * Description: Setter for customerName
 * Input: string name
 * Output: None
 */
void Account::setCustomerName(string name) {
    customerName = name;
}

/*
 * Account::setAccountBalance
 * Description: Setter for accountBalance
 * Input: double amount
 * Output: None
 */
void Account::setAccountBalance(double amount) {
    accountBalance = amount;
}

/*
 * Account::setInterestRate
 * Description: Setter for interestRate
 * Input: double rate
 * Output: None
 */
void Account::setInterestRate(double rate) {
    interestRate = rate;
}

/*
 * Account::compoundInterest
 * Description: Computes and compounds daily interest
 * Input: None
 * Output: None
 */
void Account::compoundInterest() {
    double rate = interestRate / 100.0;
    double n = 365.0; // Compounding daily
    double t = 1.0 / 365.0;
    
    accountBalance = accountBalance * pow
                     ((1 + rate / n), n * t);
    accountBalance = round(accountBalance * 100) / 100; 
}

/*
 * CheckingAccount::CheckingAccount
 * Description: Default constructor for CheckingAccount
 * Input: None
 * Output: None
 */
CheckingAccount::CheckingAccount() : Account() {}

/*
 * CheckingAccount::CheckingAccount
 * Description: Parametrized constructor for CheckingAccount
 * Input: string name, double amount, double rate
 * Output: None
 */
CheckingAccount::CheckingAccount(string name, 
      double amount, double rate)
    : Account(name, amount, rate) {}

/*
 * CheckingAccount::printAccountInfo
 * Description: Prints account information
 * Input: None
 * Output: None
 */
void CheckingAccount::printAccountInfo() const {
    cout << fixed << setprecision(2);
    cout << "Checking account for customer " 
         << getCustomerName() << endl;
    cout << "Current balance: " 
         << getAccountBalance() << endl;
    cout << "APR: " << getInterestRate() 
         << "%" << endl;
}

/*
 * CheckingAccount::checkAccount
 * Description: Checks if a specified amount can be withdrawn
 * Input: double amount
 * Output: bool
 */
bool CheckingAccount::checkAccount(double amount) {
    return getAccountBalance() >= amount;
}

/*
 * CheckingAccount::withdrawAccount
 * Description: Processes a withdrawal transaction
 * Input: double amount
 * Output: None
 */
void CheckingAccount::withdrawAccount(double amount) {
    if (checkAccount(amount)) {
        setAccountBalance(getAccountBalance() - amount);
    }
}

/*
 * SavingsAccount::SavingsAccount
 * Description: Default constructor for SavingsAccount
 * Input: None
 * Output: None
 */
SavingsAccount::SavingsAccount() : Account(), withdrawalEvents(0) {}

/*
 * SavingsAccount::SavingsAccount
 * Description: Parametrized constructor for SavingsAccount
 * Input: string name, double amount, double rate
 * Output: None
 */
SavingsAccount::SavingsAccount(string name, double amount, double rate)
    : Account(name, amount, rate), withdrawalEvents(0) {}

/*
 * SavingsAccount::getWithdrawalEvents
 * Description: Getter for withdrawalEvents
 * Input: None
 * Output: int
 */
int SavingsAccount::getWithdrawalEvents() {
    return withdrawalEvents;
}

/*
 * SavingsAccount::resetWithdrawalEvents
 * Description: Resets withdrawal events count to 0
 * Input: None
 * Output: None
 */
void SavingsAccount::resetWithdrawalEvents() {
    withdrawalEvents = 0;
}

/*
 * SavingsAccount::printAccountInfo
 * Description: Prints account information
 * Input: None
 * Output: None
 */
void SavingsAccount::printAccountInfo() const {
    cout << fixed << setprecision(2);
    cout << "Savings account for customer " 
         << getCustomerName() << endl;
    cout << "Current balance: " 
         << getAccountBalance() << endl;
    cout << "APR: " << getInterestRate() 
         << "%" << endl;
}

/*
 * SavingsAccount::checkAccount
 * Description: Checks if a specified amount can be withdrawn
 * Input: double amount
 * Output: bool
 */
bool SavingsAccount::checkAccount(double amount) {
    return getAccountBalance() >= amount && withdrawalEvents 
                               < MAX_WITHDRAWALS;
}

/*
 * SavingsAccount::withdrawAccount
 * Description: Processes a withdrawal transaction
 * Input: double amount
 * Output: None
 */
void SavingsAccount::withdrawAccount(double amount) {
    if (checkAccount(amount)) {
        setAccountBalance(getAccountBalance() - amount);
        withdrawalEvents++;
    }
}
