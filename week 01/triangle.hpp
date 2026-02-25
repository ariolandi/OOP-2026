#ifndef __TRIANGLE__
#define __TRIANGLE__
#include "point.hpp"

struct Triangle {
    Point a, b, c;

    Triangle() {}
    Triangle(const Point& a, const Point& b, const Point& c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void input() {
        a.input();
        b.input();
        c.input();
    }

    void output() {
        std::cout << "{" << std::endl;
        a.output();
        b.output();
        c.output();
        std::cout << "}" << std::endl;
    }

    double S() {
        double distA = b.dist(c);
        double distB = a.dist(c);
        double distC = a.dist(b);

        double p = (distA + distB + distC) / 2;

        return sqrt(p * (p - distA) * (p - distB) * (p - distC));
    }
};

# endif 