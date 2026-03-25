#include <iostream>
#include "string.hpp"

void f(String&& s) {

}

int main() {
    // String str;
    // String str1 = str; // String str1(str);

    f(String("fhfh"));

    // f(str);

    return 0;
}
