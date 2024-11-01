#include "custom_exceptions.h"
using namespace std;

DetailedInvalidTriangleException::DetailedInvalidTriangleException(double sideA, double sideB, double sideC)
    : a(sideA), b(sideB), c(sideC) {}

DerivedInvalidTriangleException::DerivedInvalidTriangleException(double sideA, double sideB, double sideC)
    : runtime_error("Invalid triangle sides"), a(sideA), b(sideB), c(sideC) {}
