#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201 - 100;
    }
}

void printArray(const int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << setw(4);
    }
    cout << endl;
}

int countPositiveElements(const int arr[], const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            ++count;
        }
    }
    cout << "Number of positive elements in array: " << count << endl;
    return count;
}

template <typename T>
int countPositiveElementsT(const vector<T>& arr) {
    int count = 0;
    for (const auto& element : arr) {
        if (element > 0) {
            ++count;
        }
    }
    cout << "Number of positive elements in vector <T>: " << count << endl;
    return count;
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

    fillArray(arr, size);
    printArray(arr, size);

    int result = countPositiveElements(arr, size);

    vector<int> vec(arr, arr + size);
    int resultVector = countPositiveElementsT(vec);

    delete[] arr;

    return 0;
}
