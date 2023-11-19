#include <iostream>
#include <cstdlib>
#include <ctime>

void fillArray(int r[]) {
    for (int i = 0; i < 23; ++i) {
        r[i] = rand() % 65 + 4;
    }
}

void printArray(const int r[]) {
    for (int i = 0; i < 23; ++i) {
        std::cout << r[i] << " ";
    }
    std::cout << std::endl;
}

void processArray(int r[], int& count, int& sum) {
    count = 0;
    sum = 0;

    for (int i = 0; i < 23; ++i) {
        if (!(r[i] % 2 == 0 || r[i] % 13 == 0)) {
            count++;
            sum += r[i];
            r[i] = 0;
        }
    }
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