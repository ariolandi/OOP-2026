#ifndef __RECIPE__
#define __RECIPE__
#include "product.hpp"

const size_t INSTRUCTIONS_SIZE = 1025;

struct Recipe {
    char title[STRSIZE];
    size_t productsSize;
    Product products[100];
    char instructions[INSTRUCTIONS_SIZE];

    Recipe();
    Recipe(
        const char title[], 
        const size_t productsSize,
        const Product products[100],
        const char instructions[]
    );

    bool hasTitle(const char title[]);
    void prettyPrint();
};

Recipe::Recipe() {
    title[0] = '\0';
    instructions[0] = '\0';
    productsSize = 0;
}

Recipe::Recipe(
    const char title[], 
    const size_t productsSize,
    const Product products[100],
    const char instructions[]
) {
    strcpy(this->title, title);
    strcpy(this->instructions, instructions);
    this->productsSize = productsSize;

    for (size_t i = 0; i < productsSize; ++i) {
        this->products[i] = products[i];
    }
}

bool Recipe::hasTitle(const char title[]) {
    return !strcmp(this->title, title);
}

void Recipe::prettyPrint() {
    std::cout << title << std::endl;
    std::cout << "=======================" << std::endl;

    for (size_t i = 0; i < productsSize; ++i) {
        products[i].prettyPrint();
    }

    std::cout << std::endl;
    std::cout << instructions << std::endl;
}


#endif /* __RECIPE__ */
