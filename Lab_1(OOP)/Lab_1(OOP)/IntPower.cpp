#include "IntPower.h"

// ����� ������� ��� ���� first
double IntPower::getFirst() const {
    return first;
}

// ����� ������� ��� ���� second
int IntPower::getSecond() const {
    return second;
}

// ����� ������ ��� ���� first
void IntPower::setFirst(double value) {
    if (value == 0) {
        throw invalid_argument("first must be a non-zero value.");
    }
    first = value;
}

// ����� ������ ��� ���� second
void IntPower::setSecond(int value) {
    second = value;
}

// ����� �����������
void IntPower::Init(double f, int s) {
    setFirst(f);
    setSecond(s);
}

// ����� �������� � ���������
void IntPower::Read() {
    cout << "Enter a non-zero value for first: ";
    cin >> first;
    if (first == 0) {
        throw invalid_argument("first must be a non-zero value.");
    }
    cout << "Enter an integer value for second: ";
    cin >> second;
}

// ����� ��������� �� �����
void IntPower::Display() const {
    cout << "first: " << first << ", second: " << second << endl;
}

// ����� ��������� �� �������
double IntPower::power() const {
    return pow(first, second);
}
