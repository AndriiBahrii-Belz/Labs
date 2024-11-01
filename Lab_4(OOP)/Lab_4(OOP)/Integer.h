// Integer.h
#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include <string>

using namespace std;

class Integer {
private:
    int value1;
    int value2;

public:
    // ������������
    Integer();                         // ����������� �� �������������
    Integer(int val1, int val2);      // ���������������� �����������
    Integer(const Integer& other);     // ����������� ���������

    // ����������
    ~Integer();

    // ������ ������� (�������)
    int getValue1() const;
    int getValue2() const;

    // ������ ������� (�������)
    void setValue1(int val);
    void setValue2(int val);

    // �������� ���������
    Integer& operator=(const Integer& other);

    // �������� ���������� �� �����
    operator string() const;

    // ���������� ���������
    Integer& operator++(); // ����������

    // ����������� ���������
    Integer operator++(int); // �����������

    // �������� �������� �����
    friend Integer operator-(const Integer& obj);

    // ������ ��������� ���������
    friend Integer operator+(const Integer& lhs, const Integer& rhs);
    friend Integer operator+(const Integer& lhs, int rhs);
    friend Integer operator+(int lhs, const Integer& rhs);

    // ������� ���������
    friend ostream& operator<<(ostream& os, const Integer& obj);
    friend istream& operator>>(istream& is, Integer& obj);
};

#endif // INTEGER_H
