#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
    double height, width;

    // �������� ��� ������� ������������
    cout << "Enter height for the first rectangle: ";
    cin >> height;
    cout << "Enter width for the first rectangle: ";
    cin >> width;

    Rectangle rect1(height, width);

    cout << "Rectangle 1: Height = " << rect1.GetHeight() << ", Width = " << rect1.GetWidth() << endl;
    cout << "Area: " << rect1.area() << endl;
    cout << "Perimeter: " << rect1.perimeter() << endl;

    // �������� ��� ������� ������������
    cout << "Enter height for the second rectangle: ";
    cin >> height;
    cout << "Enter width for the second rectangle: ";
    cin >> width;

    Rectangle rect2(height, width);

    cout << "Rectangle 2: Height = " << rect2.GetHeight() << ", Width = " << rect2.GetWidth() << endl;
    cout << "Area: " << rect2.area() << endl;
    cout << "Perimeter: " << rect2.perimeter() << endl;

    // ������������ ������������ ���������
    Rectangle rect4 = rect1;  // ��������� ��ﳿ ������� ������������
    cout << "Copy of Rectangle 1: Height = " << rect4.GetHeight() << ", Width = " << rect4.GetWidth() << endl;

    return 0;
}
