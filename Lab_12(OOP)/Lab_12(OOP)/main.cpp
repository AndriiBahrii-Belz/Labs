#include "triangle.h"
#include "custom_exceptions.h"
#include <iostream>
#include <exception>

using namespace std;

// Custom terminate and unexpected handlers
void customTerminate() {
    cerr << "No handler found for exception, terminating.\n";
    abort();
}

void customUnexpected() {
    cerr << "Unexpected exception, aborting.\n";
    abort();
}

int main() {
    set_terminate(customTerminate);
    set_unexpected(customUnexpected);

    double a, b, c;

    // Prompt user to enter the triangle sides
    cout << "Enter the lengths of the three sides of the triangle:\n";
    cout << "Side a: ";
    cin >> a;
    cout << "Side b: ";
    cin >> b;
    cout << "Side c: ";
    cin >> c;

    try {
        cout << "Area (no exception spec): " << calculateAreaNoException(a, b, c) << "\n";
        cout << "Area (throw() spec): " << calculateAreaWithThrow(a, b, c) << "\n";
        cout << "Area (standard exception): " << calculateAreaWithStandardException(a, b, c) << "\n";
        cout << "Area (custom empty exception): " << calculateAreaWithCustomEmptyException(a, b, c) << "\n";
        cout << "Area (detailed exception): " << calculateAreaWithDetailedException(a, b, c) << "\n";
        cout << "Area (derived exception): " << calculateAreaWithDerivedException(a, b, c) << "\n";
    }
    catch (const char* msg) {
        cerr << "Caught exception: " << msg << "\n";
    }
    catch (const invalid_argument& e) {
        cerr << "Caught std::invalid_argument: " << e.what() << "\n";
    }
    catch (const InvalidTriangleException&) {
        cerr << "Caught InvalidTriangleException.\n";
    }
    catch (const DetailedInvalidTriangleException& e) {
        cerr << "Caught DetailedInvalidTriangleException with sides: " << e.a << ", " << e.b << ", " << e.c << "\n";
    }
    catch (const DerivedInvalidTriangleException& e) {
        cerr << "Caught DerivedInvalidTriangleException with sides: " << e.a << ", " << e.b << ", " << e.c << "\n";
    }
    catch (...) {
        cerr << "Caught unknown exception.\n";
    }

    return 0;
}
