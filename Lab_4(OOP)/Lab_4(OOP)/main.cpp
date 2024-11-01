// main.cpp
#include <iostream>
#include "Integer.h"

using namespace std;

int main() {
    // ������������ ����� ������� ��������� ��'����
    Integer a; // ����������� �� �������������
    Integer b(10, 20); // ���������������� �����������
    Integer c = b; // ����������� ���������

    // ���� ���������� �������
    cout << "Object a (default): " << a << endl;
    cout << "Object b (initialized): " << b << endl;
    cout << "Object c (copy of b): " << c << endl;

    // �������� ������� � ���������
    cin >> a;
    cout << "After input, object a: " << a << endl;

    // ���������
    a = b;
    cout << "After assignment a = b: " << a << endl;

    // �������� ���������� �� �����
    string str = static_cast<string>(b);
    cout << "String representation of b: " << str << endl;

    // ������������ �������� +
    Integer d = b + c;
    cout << "d = b + c: " << d << endl;

    Integer e = b + 5;
    cout << "e = b + 5: " << e << endl;

    Integer f = 15 + c;
    cout << "f = 15 + c: " << f << endl;

    // ������������ ��������� �������� �����
    Integer g = -b;
    cout << "g = -b: " << g << endl;

    // ������������ ��������� ����������
    cout << "\nBefore increment:\n" << b << endl;
    ++b; // ���������� ��������� (�������� value1)
    cout << "After prefix increment (++b): " << b << endl;

    b++; // ����������� ��������� (�������� value2)
    cout << "After postfix increment (b++): " << b << endl;

    // ��������� ������ ��'����
    Integer arr[3];
    cout << "\nEnter values for the array of objects:\n";
    for (int i = 0; i < 3; ++i) {
        cin >> arr[i];
    }

    cout << "Contents of the array of objects:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }

    return 0;
}
