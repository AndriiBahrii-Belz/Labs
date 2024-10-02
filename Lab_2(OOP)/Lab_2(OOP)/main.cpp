#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    // Create instances of Complex
    Complex c1; // Default constructor
    cout << "Enter the first complex number:" << endl;
    c1.Read(); // Input values for the first complex number
    c1.Display(); // Display the first complex number

    Complex c2; // Default constructor
    cout << "Enter the second complex number:" << endl;
    c2.Read(); // Input values for the second complex number
    c2.Display(); // Display the second complex number

    // Demonstrating addition
    Complex c3 = c1.add(c2);
    cout << "Sum: " << c3.toString() << endl;

    // Demonstrating multiplication
    Complex c4 = c1.mul(c2);
    cout << "Product: " << c4.toString() << endl;

    // Demonstrating comparison
    if (c1.equ(c2)) {
        cout << "The complex numbers are equal." << endl;
    }
    else {
        cout << "The complex numbers are not equal." << endl;
    }

    return 0;
}
