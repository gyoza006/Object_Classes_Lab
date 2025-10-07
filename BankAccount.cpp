#include "BankAccount.h"
#include <iostream>
using namespace std;

// Default constructor
BankAccount::BankAccount() {
    accountNumber = "0000";
    accountHolderName = "Default";
    balance = 0.0;
}

// Parameterized constructor
BankAccount::BankAccount(string accNum, string holderName, double initialBalance) {
    accountNumber = accNum;
    accountHolderName = holderName;
    if (initialBalance >= 0)
        balance = initialBalance;
    else {
        cout << "Initial balance cannot be negative. Setting to 0." << endl;
        balance = 0.0;
    }
}

// Getters
string BankAccount::getAccountNumber() const { return accountNumber; }
string BankAccount::getAccountHolderName() const { return accountHolderName; }
double BankAccount::getBalance() const { return balance; }

// Setter
void BankAccount::setAccountHolderName(const string& newName) { accountHolderName = newName; }

// Deposit
void BankAccount::deposit(double amount) {
    if (amount > 0)
        balance += amount;
    else
        cout << "Deposit amount must be positive." << endl;
}

// Withdraw
void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance)
        balance -= amount;
    else if (amount > balance)
        cout << "Insufficient funds." << endl;
    else
        cout << "Withdrawal amount must be positive." << endl;
}
