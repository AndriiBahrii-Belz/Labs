#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** c, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** c, const int rowCount, const int colCount);
void Sort(int** c, const int rowCount, const int colCount);
void Change(int** c, const int row1, const int row2, const int colCount);
void Calc(int** c, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int Low = -21;
    const int High = 18;
    const int rowCount = 8;
    const int colCount = 7;

    int** c = new int* [rowCount];
    for (int i = 0; i < rowCount; ++i)
        c[i] = new int[colCount];

    Create(c, rowCount, colCount, Low, High);
    Print(c, rowCount, colCount);
    Sort(c, rowCount, colCount);
    Print(c, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(c, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(c, rowCount, colCount);

    for (int i = 0; i < rowCount; ++i)
        delete[] c[i];
    delete[] c;

    return 0;
}

void Create(int** c, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; ++i)
        for (int j = 0; j < colCount; ++j)
            c[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** c, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
            cout << setw(4) << c[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** c, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; ++i0)
        for (int i1 = 0; i1 < rowCount - i0 - 1; ++i1)
            if (c[i1][0] < c[i1 + 1][0] ||
                (c[i1][0] == c[i1 + 1][0] && c[i1][1] < c[i1 + 1][1]) ||
                (c[i1][0] == c[i1 + 1][0] && c[i1][1] == c[i1 + 1][1] && c[i1][3] > c[i1 + 1][3]) ||
                (c[i1][0] == c[i1 + 1][0] && c[i1][1] == c[i1 + 1][1] && c[i1][3] == c[i1 + 1][3] && c[i1][6] < c[i1 + 1][6]))
                Change(c, i1, i1 + 1, colCount);
}

void Change(int** c, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; ++j)
    {
        tmp = c[row1][j];
        c[row1][j] = c[row2][j];
        c[row2][j] = tmp;
    }
}

void Calc(int** c, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; ++i)
        for (int j = 0; j < colCount; ++j)
            if (c[i][j] % 2 == 0 || !(c[i][j] > 0))
            {
                S += c[i][j];
                k++;
                c[i][j] = 0;
            }
}