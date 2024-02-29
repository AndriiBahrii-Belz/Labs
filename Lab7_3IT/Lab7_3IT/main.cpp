#include <iostream>
#include <iomanip>
#include <time.h>
#include <unordered_map>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int Part1_Count(int** a, const int rowCount, const int colCount);
void Part2_MaxRepeat(int** a, const int rowCount, const int colCount);

int main() {
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int count = Part1_Count(a, rowCount, colCount);
    cout << "Number of rows without zero elements: " << count << endl;

    Part2_MaxRepeat(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int Part1_Count(int** a, const int rowCount, const int colCount) {
    int count = 0;
    for (int i = 0; i < rowCount; ++i) {
        bool hasZero = false;
        for (int j = 0; j < colCount; ++j) {
            if (a[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero)
            ++count;
    }
    return count;
}

void Part2_MaxRepeat(int** a, const int rowCount, const int colCount) {
    int maxRepeat = 0;
    int maxNumber = 0;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            int current = a[i][j];
            int repeatCount = 0;
            for (int x = 0; x < rowCount; ++x) {
                for (int y = 0; y < colCount; ++y) {
                    if (a[x][y] == current)
                        ++repeatCount;
                }
            }
            if (repeatCount > maxRepeat || (repeatCount == maxRepeat && current > maxNumber)) {
                maxRepeat = repeatCount;
                maxNumber = current;
            }
        }
    }
    if (maxRepeat > 1) {
        cout << "Max number repeated more than once: " << maxNumber << " (Repeated " << maxRepeat << " times)" << endl;
    }
    else {
        cout << "No number repeated more than once." << endl;
    }
}

