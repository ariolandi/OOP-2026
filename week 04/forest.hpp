#ifndef __FOREST__
#define __FOREST__
#include "tree.hpp"

class Forest {
    Tree** trees;
    size_t size;

    void copyForest(const Forest& other);
    void moveForest(Forest&& other);
    void deleteForest();

    public:
    Forest();
    Forest(const Forest& other);
    Forest(Forest&& other);
    Forest& operator=(const Forest& other);
    Forest& operator=(Forest&& other);
    ~Forest();
};

void Forest::copyForest(const Forest& other) {
    this->trees = new Tree*[other.size];
    this->size = other.size;

    for (size_t i = 0; i < this->size; ++i) {
        this->trees[i] = new Tree(other.trees[i]);
    }
}

void Forest::moveForest(Forest&& other) {
    this->trees = other.trees;
    this->size = other.size;

    other.trees = nullptr;
}


void Forest::deleteForest() {
    for (size_t i = 0; i < size; ++i) {
        delete trees[i];
    }
    delete[] trees;
}

Forest::Forest() {
    trees = nullptr;
    size = 0;
}

Forest::Forest(const Forest& other) {
    copyForest(other);
}

Forest::Forest(Forest&& other) {
    moveForest(other);
}

Forest& operator=(const Forest& other) {
    if (this != &other) {
        deleteForest();
        copyForest(other);
    }

    return *this;
}

Forest& Forest::operator=(Forest&& other) {
    if (this != &other) {
        deleteForest();
        moveForest(other);
    }

    return *this;
}

Forest::~Forest() {
    deleteForest();
}

#endif