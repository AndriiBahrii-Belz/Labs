#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function to fill the array with random numbers
void fillArrayRandom(double arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 - 50;
    }
}

// Function to print the array
void printArray(const double arr[], int size) {
    cout << "Array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << setw(4) << arr[i] << " ";
    }
    cout << endl;
}

// Function to calculate the product of negative elements in the array
double productNegativeElements(const double arr[], int size) {
    double negProduct = 1.0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            negProduct *= arr[i];
        }
    }
    return negProduct;
}

// Function to calculate the sum of positive elements before the maximum
double sumPositiveElementsBeforeMax(const double arr[], int size) {
    double maxElement = arr[0];
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
    }

    double posSum = 0.0;
    for (int i = 0; i < maxIndex; ++i) {
        if (arr[i] > 0) {
            posSum += arr[i];
        }
    }
    return posSum;
}

// Function to reverse the order of even elements in the array
void reverseEvenElements(double arr[], int size) {
    for (int i = 0, j = size - 1; i < j;) {
        // Check if arr[i] is even
        if (static_cast<int>(arr[i]) % 2 == 0) {
            ++i;
            continue;
        }

        // Check if arr[j] is even
        if (static_cast<int>(arr[j]) % 2 == 0) {
            --j;
            continue;
        }

        // Swap arr[i] and arr[j] if both are not even
        swap(arr[i], arr[j]);
        ++i;
        --j;
    }
}

int main() {
    int n;
    cout << "Array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size (should be greater than 0)" << endl;
        return 1;
    }

    srand(time(nullptr));

    double* arr = new double[n];

    fillArrayRandom(arr, n);

    printArray(arr, n);

    double negProduct = productNegativeElements(arr, n);
    cout << "Product(N): " << negProduct << endl;

    double posSum = sumPositiveElementsBeforeMax(arr, n);
    cout << "Sum(BM): " << posSum << endl;

    reverseEvenElements(arr, n);

    printArray(arr, n);

    delete[] arr;

    return 0;
}
