#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int findLargestOddElement(int a[], int n) {
    int largestOdd = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 != 0 && a[i] > largestOdd) {
            largestOdd = a[i];
        }
    }

    return largestOdd;
}

int main() {
    int n;

    cout << "Array Size = ";
    cin >> n;

    int* a = new int[n];

    srand(time(0));

    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
    }

    cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    int result = findLargestOddElement(a, n);
    if (result != INT_MIN) {
        cout << "The largest odd element = " << result << endl;
    }
    else {
        cout << "The array does not contain odd elements." << endl;
    }

    delete[] a;

    return 0;
}
