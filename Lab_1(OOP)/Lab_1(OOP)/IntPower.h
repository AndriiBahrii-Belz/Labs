#ifndef INTPower_H
#define INTPower_H

#include <iostream>
#include <stdexcept>
#include <cmath> // Для pow()

using namespace std;

class IntPower {
private:
    double first; // дійсне ненульове число
    int second;   // ціле число, показник степені

public:
    // Методи доступу
    double getFirst() const;
    int getSecond() const;

    // Методи запису
    void setFirst(double value);
    void setSecond(int value);

    // Метод ініціалізації
    void Init(double f, int s);

    // Метод введення з клавіатури
    void Read();

    // Метод виведення на екран
    void Display() const;

    // Метод піднесення до степеня
    double power() const;
};

#endif // INTPower_H
