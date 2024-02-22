#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, const int n, const int Low, const int High, int i, int j);
void Print(int** a, const int n, int i, int j);
bool SearchMaxEven(int** a, const int n, int& maxEven, int i, int j);
void SwapMaxEvenOnDiagonal(int** a, const int n, int i, int maxI, int maxJ, int curRow);

int main() {
    srand(time(NULL));
    int Low = 2;
    int High = 30;
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High, 0, 0);
    cout << "Initial matrix:" << endl;
    Print(a, n, 0, 0);

    int maxEven = -1;
    if (SearchMaxEven(a, n, maxEven, 0, 0)) {
        cout << "Max even: " << maxEven << endl;
        SwapMaxEvenOnDiagonal(a, n, 0, -1, -1, 0);
        cout << "Matrix after swapping:" << endl;
        Print(a, n, 0, 0);
    }
    else {
        cout << "There are no even elements in the matrix." << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int n, const int Low, const int High, int i, int j) {
    if (i < n) {
        if (j < n) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, n, Low, High, i, j + 1);
        }
        else {
            Create(a, n, Low, High, i + 1, 0);
        }
    }
}

void Print(int** a, const int n, int i, int j) {
    if (i < n) {
        if (j < n) {
            cout << setw(4) << a[i][j];
            Print(a, n, i, j + 1);
        }
        else {
            cout << endl;
            Print(a, n, i + 1, 0);
        }
    }
}

bool SearchMaxEven(int** a, const int n, int& maxEven, int i, int j) {
    if (i < n) {
        if (j < n) {
            if (a[i][j] % 2 == 0 && (maxEven == -1 || a[i][j] > maxEven)) {
                maxEven = a[i][j];
            }
            return SearchMaxEven(a, n, maxEven, i, j + 1);
        }
        else {
            return SearchMaxEven(a, n, maxEven, i + 1, 0);
        }
    }
    return maxEven != -1;
}

void SwapMaxEvenOnDiagonal(int** a, const int n, int i, int maxI, int maxJ, int curRow) {
    if (curRow < n) {
        if (i < n) {
            if (a[curRow][i] % 2 == 0 && (maxI == -1 || a[curRow][i] > a[maxI][maxJ])) {
                maxI = curRow;
                maxJ = i;
            }
            SwapMaxEvenOnDiagonal(a, n, i + 1, maxI, maxJ, curRow);
        }
        else {
            if (maxI != -1 && maxJ != -1) {
                int temp = a[curRow][curRow];
                a[curRow][curRow] = a[maxI][maxJ];
                a[maxI][maxJ] = temp;
            }
            SwapMaxEvenOnDiagonal(a, n, 0, -1, -1, curRow + 1);
        }
    }
}
