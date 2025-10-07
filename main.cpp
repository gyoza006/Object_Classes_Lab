#include <iostream>
#include <vector>
#include "BankAccount.h"
using namespace std;

void displayMenu() {
    cout << "\n=== Bank Account Management System ===" << endl;
    cout << "1. Create new account" << endl;
    cout << "2. View all accounts" << endl;
    cout << "3. Deposit funds" << endl;
    cout << "4. Withdraw funds" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string accNum, name;
            double balance;
            cout << "Enter account number: ";
            cin >> accNum;
            cin.ignore();
            cout << "Enter account holder name: ";
            getline(cin, name);
            cout << "Enter initial balance: ";
            cin >> balance;

            BankAccount newAccount(accNum, name, balance);
            accounts.push_back(newAccount);
            cout << "Account created successfully!" << endl;
        }
        else if (choice == 2) {
            for (const auto& acc : accounts) {
                cout << "Account Number: " << acc.getAccountNumber() << endl;
                cout << "Holder Name: " << acc.getAccountHolderName() << endl;
                cout << "Balance: $" << acc.getBalance() << endl;
                cout << "--------------------------" << endl;
            }
        }
        else if (choice == 3) {
            string accNum; double amount;
            cout << "Enter account number: ";
            cin >> accNum;

            bool found = false;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    acc.deposit(amount);
                    cout << "Deposit successful." << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found." << endl;
        }
        else if (choice == 4) {
            string accNum; double amount;
            cout << "Enter account number: ";
            cin >> accNum;

            bool found = false;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    acc.withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found." << endl;
        }

    } while (choice != 5);

    cout << "Goodbye!" << endl;
    return 0;
}
