// Integer.cpp
#include "Integer.h"

// Конструктор за замовчуванням
Integer::Integer() : value1(0), value2(0) {}

// Параметризований конструктор
Integer::Integer(int val1, int val2) : value1(val1), value2(val2) {}

// Конструктор копіювання
Integer::Integer(const Integer& other) : value1(other.value1), value2(other.value2) {}

// Деструктор
Integer::~Integer() {}

// Геттери
int Integer::getValue1() const {
    return value1;
}

int Integer::getValue2() const {
    return value2;
}

// Сеттери
void Integer::setValue1(int val) {
    value1 = val;
}

void Integer::setValue2(int val) {
    value2 = val;
}

// Оператор присвоєння
Integer& Integer::operator=(const Integer& other) {
    if (this != &other) {
        value1 = other.value1;
        value2 = other.value2;
    }
    return *this;
}

// Оператор приведення до рядка
Integer::operator string() const {
    return "Value1: " + to_string(value1) + ", Value2: " + to_string(value2);
}

// Префіксний інкремент (модифікує value1)
Integer& Integer::operator++() {
    ++value1;
    return *this;
}

// Постфіксний інкремент (модифікує value2)
Integer Integer::operator++(int) {
    Integer temp(*this);
    value2++;
    return temp;
}

// Оператор унарного мінуса
Integer operator-(const Integer& obj) {
    return Integer(-obj.value1, -obj.value2);
}

// Бінарний оператор додавання (Integer + Integer)
Integer operator+(const Integer& lhs, const Integer& rhs) {
    return Integer(lhs.value1 + rhs.value1, lhs.value2 + rhs.value2);
}

// Бінарний оператор додавання (Integer + int)
Integer operator+(const Integer& lhs, int rhs) {
    return Integer(lhs.value1 + rhs, lhs.value2 + rhs);
}

// Бінарний оператор додавання (int + Integer)
Integer operator+(int lhs, const Integer& rhs) {
    return Integer(lhs + rhs.value1, lhs + rhs.value2);
}

// Потоковий оператор виводу
ostream& operator<<(ostream& os, const Integer& obj) {
    os << "Value1: " << obj.value1 << ", Value2: " << obj.value2;
    return os;
}

// Потоковий оператор введення
istream& operator>>(istream& is, Integer& obj) {
    cout << "Enter value1: ";
    is >> obj.value1;
    cout << "Enter value2: ";
    is >> obj.value2;
    return is;
}
