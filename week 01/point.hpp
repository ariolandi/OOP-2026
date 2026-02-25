#ifndef __POINT__
#define __POINT__
// #pragma once
#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;

    Point() {}
    Point(const double x, const double y);

    void input();
    void output();

    double dist(const Point& other);
};

Point::Point(const double x, const double y) {
    this->x = x;
    this->y = y;
}

void Point::input() {
    std::cin >> this->x >> this->y;
}

void Point::output() {
    std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}

double Point::dist(const Point& other) {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

#endif