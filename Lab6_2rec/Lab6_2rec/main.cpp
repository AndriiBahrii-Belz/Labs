#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int findLargestOddElementRecursive(int a[], int n, int largestOdd) {
    if (n == 0) {
        return largestOdd;
    }

    if (a[n - 1] % 2 != 0 && a[n - 1] > largestOdd) {
        largestOdd = a[n - 1];
    }

    return findLargestOddElementRecursive(a, n - 1, largestOdd);
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

    int result = findLargestOddElementRecursive(a, n, INT_MIN);

    if (result != INT_MIN) {
        cout << "The largest odd element = " << result << endl;
    }
    else {
        cout << "The array does not contain odd elements." << endl;
    }

    delete[] a;

    return 0;
}
