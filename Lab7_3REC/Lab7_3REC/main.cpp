#include <iostream>
#include <iomanip>
#include <time.h>
#include <unordered_map>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Input(int** a, const int rowCount, const int colCount, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int Part1_Count(int** a, const int rowCount, const int colCount, int i, int count);
void Part2_MaxRepeat(int** a, const int rowCount, const int colCount, int i, int j, int current, int& maxRepeat, int& maxNumber, int x, int y, int repeatCount);

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

    Input(a, rowCount, colCount, 0, 0);
    Print(a, rowCount, colCount, 0, 0);

    int count = Part1_Count(a, rowCount, colCount, 0, 0);
    cout << "Number of rows without zero elements: " << count << endl;

    int maxRepeat = 0;
    int maxNumber = 0;
    Part2_MaxRepeat(a, rowCount, colCount, 0, 0, a[0][0], maxRepeat, maxNumber, 0, 0, 0);
    if (maxRepeat > 1) {
        cout << "Max number repeated more than once: " << maxNumber << " (Repeated " << maxRepeat << " times)" << endl;
    }
    else {
        cout << "No number repeated more than once." << endl;
    }

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    if (i == rowCount)
        return;
    if (j == colCount) {
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
        return;
    }
    a[i][j] = Low + rand() % (High - Low + 1);
    Create(a, rowCount, colCount, Low, High, i, j + 1);
}

void Input(int** a, const int rowCount, const int colCount, int i, int j) {
    if (i == rowCount)
        return;
    if (j == colCount) {
        Input(a, rowCount, colCount, i + 1, 0);
        return;
    }
    cout << "a[" << i << "][" << j << "] = ";
    cin >> a[i][j];
    Input(a, rowCount, colCount, i, j + 1);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j) {
    if (i == rowCount)
        return;
    if (j == colCount) {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);
        return;
    }
    cout << setw(4) << a[i][j];
    Print(a, rowCount, colCount, i, j + 1);
}

int Part1_Count(int** a, const int rowCount, const int colCount, int i, int count) {
    if (i == rowCount)
        return count;
    bool hasZero = false;
    for (int j = 0; j < colCount; ++j) {
        if (a[i][j] == 0) {
            hasZero = true;
            break;
        }
    }
    return Part1_Count(a, rowCount, colCount, i + 1, count + (!hasZero));
}

void Part2_MaxRepeat(int** a, const int rowCount, const int colCount, int i, int j, int current, int& maxRepeat, int& maxNumber, int x, int y, int repeatCount) {
    if (i == rowCount) {
        if (repeatCount > maxRepeat || (repeatCount == maxRepeat && current > maxNumber)) {
            maxRepeat = repeatCount;
            maxNumber = current;
        }
        return;
    }
    if (j == colCount) {
        Part2_MaxRepeat(a, rowCount, colCount, i + 1, 0, current, maxRepeat, maxNumber, x, y, repeatCount);
        return;
    }
    if (a[i][j] == current)
        repeatCount++;
    Part2_MaxRepeat(a, rowCount, colCount, i, j + 1, current, maxRepeat, maxNumber, x, y, repeatCount);
}
