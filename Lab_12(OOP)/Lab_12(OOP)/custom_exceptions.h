#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <stdexcept>

class DetailedInvalidTriangleException {
public:
    double a, b, c;
    DetailedInvalidTriangleException(double sideA, double sideB, double sideC);
};

class DerivedInvalidTriangleException : public std::runtime_error {
public:
    double a, b, c;
    DerivedInvalidTriangleException(double sideA, double sideB, double sideC);
};

#endif // CUSTOM_EXCEPTIONS_H
