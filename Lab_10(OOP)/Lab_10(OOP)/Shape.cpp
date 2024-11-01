#include <iostream>
#include <cmath>
#include "shape.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Реалізація класу Rectangle
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::area() const {
    return width * height;
}

const char* Rectangle::getType() const {
    return "Rectangle";
}

// Реалізація класу Circle
Circle::Circle(double r) : radius(r) {}

double Circle::area() const {
    return M_PI * radius * radius;  // Використання M_PI
}

const char* Circle::getType() const {
    return "Circle";
}

// Реалізація класу RightTriangle
RightTriangle::RightTriangle(double b, double h) : base(b), height(h) {}

double RightTriangle::area() const {
    return 0.5 * base * height;
}

const char* RightTriangle::getType() const {
    return "Right Triangle";
}

// Реалізація класу Trapezoid
Trapezoid::Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}

double Trapezoid::area() const {
    return 0.5 * (base1 + base2) * height;
}

const char* Trapezoid::getType() const {
    return "Trapezoid";
}
