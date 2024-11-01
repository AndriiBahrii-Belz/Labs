#include "triangle.h"
#include "custom_exceptions.h"
#include <cmath>

using namespace std;

double calculateAreaNoException(double a, double b, double c) {
    double p = (a + b + c) / 2;
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        throw "Invalid triangle sides (no exception specification).";
    }
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double calculateAreaWithThrow(double a, double b, double c) throw() {
    double p = (a + b + c) / 2;
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        throw;
    }
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double calculateAreaWithStandardException(double a, double b, double c) {
    double p = (a + b + c) / 2;
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        throw invalid_argument("Invalid triangle sides.");
    }
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double calculateAreaWithCustomEmptyException(double a, double b, double c) {
    double p = (a + b + c) / 2;
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        throw InvalidTriangleException();
    }
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double calculateAreaWithDetailedException(double a, double b, double c) {
    double p = (a + b + c) / 2;
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        throw DetailedInvalidTriangleException(a, b, c);
    }
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double calculateAreaWithDerivedException(double a, double b, double c) {
    double p = (a + b + c) / 2;
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        throw DerivedInvalidTriangleException(a, b, c);
    }
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
