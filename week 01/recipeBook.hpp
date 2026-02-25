#ifndef __RECIPE_BOOK__
#define __RECIPE_BOOK__
#include "recipe.hpp"

struct RecipeBook {
    size_t recepiesSize;
    Recipe recipies[100];

    RecipeBook();

    void addRecipe(const Recipe& recipe);
    int findRecipe(const char title[]);

    void prettyPrint();
};

RecipeBook::RecipeBook() {
    recepiesSize = 0;
}

void RecipeBook::addRecipe(const Recipe& recipe) {
    recipies[recepiesSize] = recipe;
    ++recepiesSize;
}

int RecipeBook::findRecipe(const char title[]) {
    for (size_t i = 0; i < recepiesSize; ++i) {
        if (recipies[i].hasTitle(title)) {
            return i;
        }
    }

    return -1;
}

void RecipeBook::prettyPrint() {
    for (size_t i = 0; i < recepiesSize; ++i) {
        recipies[i].prettyPrint();
        std::cout << "--------------------------------------" << std::endl;
    }
}

#endif /* __RECIPE_BOOK__ */
