#include<iostream>
using namespace std;

int countWays(int m, int x, int y, int z, int depth, int level) {
    // ��������� ���� ������ �� �������.
    cout << "Depth: " << m << ", Level: " << level << endl;

    if (m == 0) {
        // ���� ������� ����������� �������, �� � ���� ����� - �� ���������� �����.
        return 1;
    }

    if (m < 0) {
        // ���� ������� ����������� ��'����, �� ���� ������� ��������.
        return 0;
    }

    // ������������� ���������� ������������ ��� ����� Գ�������.
    return countWays(m - x, x, y, z, depth + 1, level) +
        countWays(m - y, x, y, z, depth + 1, level + 1) +
        countWays(m - z, x, y, z, depth + 1, level + 2);
}

int main() {
    int x, y, z, m;

    // �������� ������� x, y, z �� m � ���������.
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "z = ";
    cin >> z;
    cout << "m = ";
    cin >> m;

    // ������ ���������� ������� �� ��������� ����������.
    cout << "Ways = " << countWays(m, x, y, z, 1, 0) << endl;

    return 0;
}
