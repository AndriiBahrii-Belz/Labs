#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Заповнення Масиву
void fillArrayRandom(double arr[], int size, int index = 0) {
    if (index == size) {
        return;
    }

    arr[index] = rand() % 100 - 50;
    fillArrayRandom(arr, size, index + 1);
}

// Вивід Масиву
void printArray(const double arr[], int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }

    cout << setw(4) << arr[index] << " ";
    printArray(arr, size, index + 1);
}

// Добуток від'ємних елементів масиву
double productNegativeElements(const double arr[], int size, int index = 0) {
    if (index == size) {
        return 1.0;
    }

    double negProduct = (arr[index] < 0) ? arr[index] : 1.0;
    return negProduct * productNegativeElements(arr, size, index + 1);
}

// Сума додатніх елементів Масиву
double sumPositiveElementsBeforeMax(const double arr[], int size, int index = 0, double maxElement = 0) {
    if (index == size) {
        return 0.0;
    }

    if (arr[index] > maxElement) {
        maxElement = arr[index];
    }

    double posSum = (arr[index] > 0) ? arr[index] : 0.0;
    return posSum + sumPositiveElementsBeforeMax(arr, size, index + 1, maxElement);
}

// Рекурсивна функція для обертання парних елементів
void reverseEvenElementsRecursive(double arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    if (static_cast<int>(arr[start]) % 2 != 0) {
        reverseEvenElementsRecursive(arr, start + 1, end);
        return;
    }

    if (static_cast<int>(arr[end]) % 2 != 0) {
        reverseEvenElementsRecursive(arr, start, end - 1);
        return;
    }

    std::swap(arr[start], arr[end]);
    reverseEvenElementsRecursive(arr, start + 1, end - 1);
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

    reverseEvenElementsRecursive(arr, 0, n - 1);

    printArray(arr, n);

    delete[] arr;

    return 0;
}
