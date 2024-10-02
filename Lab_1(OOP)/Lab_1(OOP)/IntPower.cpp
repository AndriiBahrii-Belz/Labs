#include "IntPower.h"

// Метод доступу для поля first
double IntPower::getFirst() const {
    return first;
}

// Метод доступу для поля second
int IntPower::getSecond() const {
    return second;
}

// Метод запису для поля first
void IntPower::setFirst(double value) {
    if (value == 0) {
        throw invalid_argument("first must be a non-zero value.");
    }
    first = value;
}

// Метод запису для поля second
void IntPower::setSecond(int value) {
    second = value;
}

// Метод ініціалізації
void IntPower::Init(double f, int s) {
    setFirst(f);
    setSecond(s);
}

// Метод введення з клавіатури
void IntPower::Read() {
    cout << "Enter a non-zero value for first: ";
    cin >> first;
    if (first == 0) {
        throw invalid_argument("first must be a non-zero value.");
    }
    cout << "Enter an integer value for second: ";
    cin >> second;
}

// Метод виведення на екран
void IntPower::Display() const {
    cout << "first: " << first << ", second: " << second << endl;
}

// Метод піднесення до степеня
double IntPower::power() const {
    return pow(first, second);
}
