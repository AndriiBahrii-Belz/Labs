#include <iostream>
#include "IntPower.h"

using namespace std;

// ������� ������� ��� ��������� ��'���� IntPower
IntPower makeIntPower(double first, int second) {
    IntPower obj;
    obj.Init(first, second);
    return obj;
}

int main() {
    try {
        double first;
        int second;

        // �������� �������
        cout << "Enter a non-zero value for first: ";
        cin >> first;
        cout << "Enter an integer value for second: ";
        cin >> second;

        // ��������� ��'����
        IntPower obj;
        obj.Init(first, second);

        // ��������� �������
        obj.Display();

        // ���������� �������
        double result = obj.power();
        cout << "Result of " << first << " raised to the power of " << second << " is: " << result << endl;

    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
