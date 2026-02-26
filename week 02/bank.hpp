#ifndef __BANK__
#define __BANK__
#include "bankAccount.hpp"
#include <iostream>

class Bank {
    BankAccount** accounts;
    size_t accountSize;

    int findAccount(const char[] IBAN);

    public:
    Bank();
    ~Bank();

    void addAccount(const BankAccount& newAccount);

    bool deposit(const double& balance, const char[] IBAN, const char[] password);
    bool withdraw(const double& balance, const char[] IBAN, const char[] password);
};

// Bank() {}
// ~Bank(){}
Bank::Bank(): accounts(nullptr), accountSize(0) {}

Bank::~Bank() {
    // std::cout << "~Bank()" << std::endl;
    for (size_t i = 0; i < accountSize; ++i) {
        delete accounts[i];
    }
    delete[] accounts;
}

int Bank::findAccount(const char[] IBAN) {
    for (size_t i = 0; i < accountSize; ++i) {
        if (!strcmp(account[i].getIBAN(), IBAN)) {
            return i;
        }
    }

    return -1;
}

void Bank::addAccount(const BankAccount& newAccount) {
    BankAccount** tmp = new BankAccount*[accountSize + 1];

    for (size_t i = 0; i < accountSize; ++i) {
        tmp[i] = accounts[i];
    }

    tmp[accountSize] = new BankAccount(
        newAccount.getIBAN(), 
        newAccount.getBalance(), 
        newAccount.getPassword()
    );

    delete[] accounts;
    accounts = tmp;
    ++accountSize;
}

bool Bank::deposit(const double& balance, const char[] IBAN, const char[] password){
    int index = findAccount(IBAN);

    if (index < 0) {
        throw std::logic_error("Bank account not existing!");
    }

    return accounts[index].deposit(balance, password);
}

bool Bank::withdraw(const double& balance, const char[] IBAN, const char[] password){
     int index = findAccount(IBAN);

    if (index < 0) {
        throw std::logic_error("Bank account not existing!");
    }

    return accounts[index].withdraw(balance, password);
}


#endif