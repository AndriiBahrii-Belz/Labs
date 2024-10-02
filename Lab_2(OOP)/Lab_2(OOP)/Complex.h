#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>

using namespace std;

class Complex {
private:
    double x; // Real part
    double y; // Imaginary part

public:
    // Constructors
    Complex() : x(0), y(0) {} // Default constructor
    Complex(double real, double imag) : x(real), y(imag) {} // Parameterized constructor

    // Access methods
    double getReal() const { return x; }
    double getImaginary() const { return y; }
    void setReal(double real) { x = real; }
    void setImaginary(double imag) { y = imag; }

    // Initialization method
    void Init(double real, double imag) {
        x = real;
        y = imag;
    }

    // Input method
    void Read() {
        cout << "Enter the real part: ";
        cin >> x;
        cout << "Enter the imaginary part: ";
        cin >> y;
    }

    // Output method
    void Display() const {
        cout << "(" << x << ", " << y << "i)" << endl;
    }

    // Method to convert to string
    string toString() const {
        return "(" + to_string(x) + ", " + to_string(y) + "i)";
    }

    // Addition method
    Complex add(const Complex& other) const {
        return Complex(x + other.x, y + other.y);
    }

    // Multiplication method
    Complex mul(const Complex& other) const {
        return Complex(x * other.x - y * other.y, x * other.y + y * other.x);
    }

    // Comparison method
    bool equ(const Complex& other) const {
        return (x == other.x) && (y == other.y);
    }
};

#endif // COMPLEX_H
