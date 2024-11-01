#pragma once
#include <iostream>
#include <string>
using namespace std;

class Rectangle {
    double height, width;

public:
    Rectangle();                          // ����������� �� �������������
    Rectangle(double, double);            // ���������������� �����������
    Rectangle(const Rectangle& other);    // ����������� ���������
    ~Rectangle();                         // ����������

    void SetHeight(double);
    void SetWidth(double);
    double GetHeight() const;
    double GetWidth() const;

    double area() const;
    double perimeter() const;

};
