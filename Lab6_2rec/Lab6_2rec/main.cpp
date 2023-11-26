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

int findLargestOddElementRecursive(const int a[], int n, int index = 0, int largestOdd = -1) {
    if (index == n) {
        return largestOdd;
    }

    if (a[index] % 2 != 0 && (largestOdd == -1 || a[index] > largestOdd)) {
        largestOdd = a[index];
    }

    return findLargestOddElementRecursive(a, n, index + 1, largestOdd);
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

        int result = findLargestOddElementRecursive(array, n);

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
