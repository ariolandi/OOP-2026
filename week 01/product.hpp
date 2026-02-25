#ifndef __PRODUCT__
#define __PRODUCT__
#include <cstring>
#include <iostream>

const size_t STRSIZE = 51;

struct Product {
    char name[STRSIZE];
    double amount;
    char unitOfMeasure;

    Product();
    Product(const char name[], const double amount, const char unitOfMeasure);

    void read();
    void prettyPrint();
};

Product::Product() {
    name[0] = '\0';
    amount = 0;
    unitOfMeasure = 0;
}

Product::Product(const char name[], const double amount, const char unitOfMeasure) {
    strcpy(this->name, name);
    this->amount = amount;
    this->unitOfMeasure = unitOfMeasure;
}

void Product::read() {
    std::cin.getline(name, STRSIZE);
    std::cin >> amount >> unitOfMeasure;
    std::cin.ignore(); 
}

void Product::prettyPrint() {
    std::cout << " - " << name << ", " << amount << unitOfMeasure << std::endl; 
}

#endif