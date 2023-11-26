#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime> 

using namespace std;

void fillArrayRandom(int a[], int n) {
    cout << "Array elements (random): ";
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
        cout << setw(3) << a[i] << " ";
    }
    cout << "\n";
}

void printArray(const int a[], int n) {
    cout << "Array elements: ";
    for (int i = 0; i < n; ++i) {
        cout << setw(2) << a[i] << " ";
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

int findLargestOddElement(const int a[], int n) {
    int largestOdd = -1;

    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 != 0 && (largestOdd == -1 || a[i] > largestOdd)) {
            largestOdd = a[i];
        }
    }

    return largestOdd;
}

int main() {
    const int maxSize = 100;
    int array[maxSize];
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    if (n > 0 && n <= maxSize) {
        srand(time(nullptr));

        fillArrayRandom(array, n);
        printArray(array, n);

        int result = findLargestOddElement(array, n);

        if (result != -1) {
            cout << "Largest odd element: " << result << "\n";
        }
        else {
            cout << "No odd elements in the array.\n";
        }
    }
    else {
        cout << "Invalid array size.\n";
    }

    return 0;
}
