// Integer.cpp
#include "Integer.h"

// ����������� �� �������������
Integer::Integer() : value1(0), value2(0) {}

// ���������������� �����������
Integer::Integer(int val1, int val2) : value1(val1), value2(val2) {}

// ����������� ���������
Integer::Integer(const Integer& other) : value1(other.value1), value2(other.value2) {}

// ����������
Integer::~Integer() {}

// �������
int Integer::getValue1() const {
    return value1;
}

int Integer::getValue2() const {
    return value2;
}

// �������
void Integer::setValue1(int val) {
    value1 = val;
}

void Integer::setValue2(int val) {
    value2 = val;
}

// �������� ���������
Integer& Integer::operator=(const Integer& other) {
    if (this != &other) {
        value1 = other.value1;
        value2 = other.value2;
    }
    return *this;
}

// �������� ���������� �� �����
Integer::operator string() const {
    return "Value1: " + to_string(value1) + ", Value2: " + to_string(value2);
}

// ���������� ��������� (�������� value1)
Integer& Integer::operator++() {
    ++value1;
    return *this;
}

// ����������� ��������� (�������� value2)
Integer Integer::operator++(int) {
    Integer temp(*this);
    value2++;
    return temp;
}

// �������� �������� �����
Integer operator-(const Integer& obj) {
    return Integer(-obj.value1, -obj.value2);
}

// �������� �������� ��������� (Integer + Integer)
Integer operator+(const Integer& lhs, const Integer& rhs) {
    return Integer(lhs.value1 + rhs.value1, lhs.value2 + rhs.value2);
}

// �������� �������� ��������� (Integer + int)
Integer operator+(const Integer& lhs, int rhs) {
    return Integer(lhs.value1 + rhs, lhs.value2 + rhs);
}

// �������� �������� ��������� (int + Integer)
Integer operator+(int lhs, const Integer& rhs) {
    return Integer(lhs + rhs.value1, lhs + rhs.value2);
}

// ��������� �������� ������
ostream& operator<<(ostream& os, const Integer& obj) {
    os << "Value1: " << obj.value1 << ", Value2: " << obj.value2;
    return os;
}

// ��������� �������� ��������
istream& operator>>(istream& is, Integer& obj) {
    cout << "Enter value1: ";
    is >> obj.value1;
    cout << "Enter value2: ";
    is >> obj.value2;
    return is;
}
