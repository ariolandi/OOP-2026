#include <iostream>
#include "recipeBook.hpp"

int main() {
    Product products[100];
    size_t productsSize = 2;

    for (size_t i = 0; i < productsSize; ++i) {
        products[i].read();
        products[i].prettyPrint();
    }

    Recipe recipe("Cookies", productsSize, products, "Bake in the oven");

    RecipeBook book;
    book.addRecipe(recipe);

    book.prettyPrint();

    return 0;
}
