#ifndef __BANK_ACCOUNT__
#define __BANK_ACCOUNT__
#include <cstring>

class BankAccount {
    char IBAN[20];
    double balance;
    char password[20];

    void setPassword(const char password[]);
    void setBalance(const double& balance);

    bool transaction(const double& amount, const char password[]);

    public:
    BankAccount(
        const char IBAN[], 
        const double& balance, 
        const char password[]);

    bool withdraw(const double& amount, const char password[]);
    bool deposit(const double& amount, const char password[]);

    const char* getIBAN() const {
        return IBAN;
    }

    const char* getPassword() const {
        return password;
    }

    double getBalance() const {
        return balance;
    }
};

void BankAccount::setPassword(const char password[]) {
    if (strlen(password) < 5) {
        throw std::logic_error("Password is too short");
    }

    strcpy(this->password, password);
}

void BankAccount::setBalance(const double& balance) {
    if (balance < 0) {
        throw std::logic_error("Negative balance");
    }

    this->balance = balance;
}

bool BankAccount::transaction(const double& amount, const char password[]) {
    double newBalance = balance + amount;

    if (newBalance < 0 || strcmp(this->password, password)) {
        return false;
    }

    balance = newBalance;
    return true;
}

BankAccount::BankAccount(const char IBAN[], 
    const double& balance, 
    const char password[]) {
    setPassword(password);
    this->balance = balance;
    strcpy(this->IBAN, IBAN);
}

bool BankAccount::withdraw(const double& amount, const char password[]) {
    if (amount < 0) {
        return false;
    }

    return transaction(amount * -1, password);
}

bool BankAccount::deposit(const double& amount, const char password[]) {
    if (amount < 0) {
        return false;
    }

    return transaction(amount, password);
}

#endif