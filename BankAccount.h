#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount();  // Default constructor
    BankAccount(std::string accNum, std::string holderName, double initialBalance);  // Parameterized constructor

    // Getters
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    // Setter
    void setAccountHolderName(const std::string& newName);

    // Bank operations
    void deposit(double amount);
    void withdraw(double amount);
};

#endif
