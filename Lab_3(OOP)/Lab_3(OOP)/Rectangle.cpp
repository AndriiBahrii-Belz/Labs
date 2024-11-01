#include "Rectangle.h"

Rectangle::Rectangle() {
    height = 0;
    width = 0;
}

Rectangle::Rectangle(double h, double w) {
    height = h;
    width = w;
}

// ��������� ������������ ���������
Rectangle::Rectangle(const Rectangle& other) {
    height = other.height;
    width = other.width;
}

Rectangle::~Rectangle() { }

void Rectangle::SetHeight(double h) {
    height = h;
}

void Rectangle::SetWidth(double w) {
    width = w;
}

double Rectangle::GetHeight() const {
    return height;
}

double Rectangle::GetWidth() const {
    return width;
}

double Rectangle::area() const {
    return height * width;
}

double Rectangle::perimeter() const {
    return 2 * (height + width);
}