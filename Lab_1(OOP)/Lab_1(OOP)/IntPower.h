#ifndef INTPower_H
#define INTPower_H

#include <iostream>
#include <stdexcept>
#include <cmath> // ��� pow()

using namespace std;

class IntPower {
private:
    double first; // ����� ��������� �����
    int second;   // ���� �����, �������� ������

public:
    // ������ �������
    double getFirst() const;
    int getSecond() const;

    // ������ ������
    void setFirst(double value);
    void setSecond(int value);

    // ����� �����������
    void Init(double f, int s);

    // ����� �������� � ���������
    void Read();

    // ����� ��������� �� �����
    void Display() const;

    // ����� ��������� �� �������
    double power() const;
};

#endif // INTPower_H
