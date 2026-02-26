#include <iostream>
#include "bank.hpp"



void addAccount(Bank& bank) {
    char IBAN[20];
    double balance;
    char password[20];
    
    std::cout << "IBAN: "; 
    std::cin.ignore();
    std::cin.getline(IBAN, 20);
    std::cout << "Balance: ";
    std::cin >> balance;
    std::cout << "Password: ";
    std::cin.ignore();
    std::cin.getline(password, 20);

    BankAccount account(IBAN, balance, password);
    bank.addAccount(account);

    std::cout << "Account added successfully!" << std::endl;
}

void deposit(Bank& bank) {
    char IBAN[20];
    double amount;
    char password[20];
    
    std::cout << "IBAN: "; 
    std::cin.ignore();
    std::cin.getline(IBAN, 20);
    std::cout << "Amount: ";
    std::cin >> amount;
    std::cout << "Password: ";
    std::cin.ignore();
    std::cin.getline(password, 20);

    std::cout << "Deposit " << (bank.deposit(amount, IBAN, password) ? "suceeded" : "failed") << std::endl;
}

void withdraw(Bank& bank) {
    char IBAN[20];
    double amount;
    char password[20];
    
    std::cout << "IBAN: "; 
    std::cin.ignore();
    std::cin.getline(IBAN, 20);
    std::cout << "Amount: ";
    std::cin >> amount;
    std::cout << "Password: ";
    std::cin.ignore();
    std::cin.getline(password, 20);

    std::cout << "Withdraw " << (bank.withdraw(amount, IBAN, password) ? "suceeded" : "failed") << std::endl;
}

void userInterface(Bank& bank) {
    unsigned command;
    bool exitInterface = false;

    do {
        std::cout << "Please enter a command number: " << std::endl;
        std::cout << "1. Add new account" << std::endl;
        std::cout << "2. Withdraw from account" << std::endl;
        std::cout << "3. Deposit to account" << std::endl; 
        std::cout << "4. Exit" << std::endl;
        std::cout << ">> ";

        std::cin >> command;

        switch(command) {
            case 1: addAccount(bank); break;
            case 2: withdraw(bank); break;
            case 3: deposit(bank); break;
            case 4: exitInterface = true; break;
            default: std::cout << "Invalid command!" << std::endl;
        }
    } while (!exitInterface);
}

int main() {
    Bank bank;

    userInterface(bank);

    return 0;
} //~Bank()
