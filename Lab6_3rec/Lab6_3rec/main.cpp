#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void fillArrayRecursive(int arr[], int size, int index = 0) {
    if (index == size) {
        return;
    }

    arr[index] = rand() % 201 - 100;
    fillArrayRecursive(arr, size, index + 1);
}

void printArrayRecursive(const int arr[], int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }

    cout << arr[index] << setw(4);
    printArrayRecursive(arr, size, index + 1);
}

int countPositiveElementsRecursive(const int arr[], int size, int index = 0) {
    if (index == size) {
        return 0;
    }

    int count = (arr[index] > 0) ? 1 : 0;
    return count + countPositiveElementsRecursive(arr, size, index + 1);
}

template <typename T>
int countPositiveElementsT(const vector<T>& arr, int index = 0) {
    if (index == arr.size()) {
        return 0;
    }

    int count = (arr[index] > 0) ? 1 : 0;
    return count + countPositiveElementsT(arr, index + 1);
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cerr << "Invalid array size\n";
        return 1;
    }

    int* arr = new int[size];

    fillArrayRecursive(arr, size);
    printArrayRecursive(arr, size);

    int result = countPositiveElementsRecursive(arr, size);
    cout << "Number of positive elements in array (recursive): " << result << endl;

    vector<int> vec(arr, arr + size);
    int resultVector = countPositiveElementsT(vec);
    cout << "Number of positive elements in vector <T> (recursive): " << resultVector << endl;

    delete[] arr;

    return 0;
}
