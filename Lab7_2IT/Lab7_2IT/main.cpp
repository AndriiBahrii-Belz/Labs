#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
bool SearchMaxEven(int** a, const int n, int& maxEven);
void SwapMaxEvenOnDiagonal(int** a, const int n);

int main() {
    srand(time(NULL));
    int Low = 2;
    int High = 30;
    int n;
    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    int maxEven;
    if (SearchMaxEven(a, n, maxEven))
        cout << "max even = " << maxEven << endl;
    else
        cout << "there are no even elements" << endl;

    SwapMaxEvenOnDiagonal(a, n);

    cout << "Matrix after swapping:" << endl;
    Print(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool SearchMaxEven(int** a, const int n, int& maxEven) {
    int maxVal = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0 && a[i][j] > maxVal) {
                maxVal = a[i][j];
            }
        }
    }
    if (maxVal == -1)
        return false;
    maxEven = maxVal;
    return true;
}

void SwapMaxEvenOnDiagonal(int** a, const int n) {
    for (int i = 0; i < n; i += 2) {
        int maxIndex = -1;
        int maxVal = -1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0 && a[i][j] > maxVal) {
                maxVal = a[i][j];
                maxIndex = j;
            }
        }
        if (maxIndex != -1) {
            int temp = a[i][i];
            a[i][i] = a[i][maxIndex];
            a[i][maxIndex] = temp;
        }
    }
}
