#include <iostream>
#include "triangle.hpp"

int main() {
    size_t n;
    Triangle triangles[128];

    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        triangles[i].input();
        // triangles[i].output();

        std::cout << triangles[i].S() << std::endl;
    }

    int maxEqualS = 0;
    for (size_t i = 0; i < n; ++i) {
        int equalS = 1;
        double S = triangles[i].S();
        for (size_t j = i + 1; j < n; ++j) {
            if (triangles[j].S() == S) {
                equalS ++;
            }
        }

        if (equalS > maxEqualS) {
            maxEqualS = equalS;
        }
    }

    std::cout << maxEqualS << std::endl;

    return 0;
}
