#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdexcept>

// Exception classes
class InvalidTriangleException {}; // Empty exception class
class DetailedInvalidTriangleException; // Forward declaration
class DerivedInvalidTriangleException;

// Function declarations
double calculateAreaNoException(double a, double b, double c);
double calculateAreaWithThrow(double a, double b, double c) throw();
double calculateAreaWithStandardException(double a, double b, double c);
double calculateAreaWithCustomEmptyException(double a, double b, double c);
double calculateAreaWithDetailedException(double a, double b, double c);
double calculateAreaWithDerivedException(double a, double b, double c);

#endif // TRIANGLE_H
