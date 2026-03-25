#include <iostream>
#include "tree.hpp"

int main() {
    Tree t("varba", 45);

    // ++t;
    t++;
    t.print();

    return 0;
}
