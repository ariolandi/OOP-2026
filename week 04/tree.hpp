#ifndef __TREE__
#define __TREE__
#include "string.hpp";
#include <iostream>

class Tree {
    String type;
    unsigned int age;

    public:
    Tree(const char* type, const unsigned int& age);

    void operator++();    // prefix
    void operator++(int); // postfix

    bool operator==(const Tree& other) const;
    bool operator!=(const Tree& other) const;
    bool operator>(const Tree& other) const;
    bool operator<(const Tree& other) const;

    void print() const;
};

Tree::Tree(const char* type, const unsigned int& age): 
    age(age), type(type) {}

void Tree::operator++(){
    ++ this->age;
}

void Tree::operator++(int){
    this->age ++;
}

bool Tree::operator==(const Tree& other) const {
    return this->type == other.type && this->age == other.age;
}

bool Tree::operator!=(const Tree& other) const {
    return this->type != other.type;
}

bool Tree::operator>(const Tree& other) const {
    return this->type == other.type && this.age > other.age;
}

bool Tree::operator<(const Tree& other) const {
    return this->type != other.type && this.age < other.age;
}

void Tree::print() const {
    type.print();
    std::cout << age << std::endl;
    std::cout << "-----------" << std::endl;
}

#endif