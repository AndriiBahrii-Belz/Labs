#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include "Pair.h"

class Fraction : public Pair {
public:
    // Конструктор
    Fraction(int wholePart = 0, int fractionalPart = 0);

    // Метод для отримання цілої частини
    int getWholePart() const;

    // Метод для отримання дробової частини
    int getFractionalPart() const;

    // Порівняння дробів
    bool operator>(const Fraction& other) const;

    // Операції вводу та виводу
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);
};

#endif // FRACTION_H
