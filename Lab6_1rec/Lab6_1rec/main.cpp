#include <iostream>
#include <cstdlib>
#include <ctime>

void fillArray(int r[], int index = 0) {
    if (index < 23) {
        r[index] = rand() % 65 + 4;
        fillArray(r, index + 1);
    }
}

void printArray(const int r[], int index = 0) {
    if (index < 23) {
        std::cout << r[index] << " ";
        printArray(r, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

void processArrayRecursive(int r[], int index, int& count, int& sum) {
    if (index < 23) {
        if (!(r[index] % 2 == 0 || r[index] % 13 == 0)) {
            count++;
            sum += r[index];
            r[index] = 0;
        }
        processArrayRecursive(r, index + 1, count, sum);
    }
}

void processArray(int r[], int& count, int& sum) {
    count = 0;
    sum = 0;
    processArrayRecursive(r, 0, count, sum);
}

int main() {
    std::srand(std::time(0));

    int myArray[23];
    int count, sum;

    fillArray(myArray);
    std::cout << "Original Array: ";
    printArray(myArray);

    processArray(myArray, count, sum);
    std::cout << "Count of elements satisfying the criteria: " << count << std::endl;
    std::cout << "Sum of elements satisfying the criteria: " << sum << std::endl;
    std::cout << "Modified Array: ";
    printArray(myArray);

    return 0;
}