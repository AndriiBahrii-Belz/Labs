#pragma once
#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>

class Pair {
private:
    int first;  // Перше число
    int second; // Друге число

public:
    // Конструктор
    Pair(int f = 0, int s = 0);

    // Методи отримання значень полів
    int getFirst() const;
    int getSecond() const;

    // Методи встановлення значень полів
    void setFirst(int f);
    void setSecond(int s);

    // Операція для приведення типу до рядка
    operator std::string() const;

    // Метод порівняння
    bool operator>(const Pair& other) const;

    // Операції вводу та виводу
    friend std::ostream& operator<<(std::ostream& os, const Pair& p);
    friend std::istream& operator>>(std::istream& is, Pair& p);
};

#endif // PAIR_H
