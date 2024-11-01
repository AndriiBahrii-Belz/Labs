#include "Fraction.h"

// Конструктор
Fraction::Fraction(int wholePart, int fractionalPart)
    : Pair(wholePart, fractionalPart) {}

// Метод для отримання цілої частини
int Fraction::getWholePart() const { return getFirst(); }

// Метод для отримання дробової частини
int Fraction::getFractionalPart() const { return getSecond(); }

// Порівняння дробів
bool Fraction::operator>(const Fraction& other) const {
    return static_cast<Pair>(*this) > static_cast<Pair>(other);
}

// Операції вводу та виводу
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << static_cast<std::string>(f);
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
    int whole, fractional;
    is >> whole >> fractional;
    f.setFirst(whole);
    f.setSecond(fractional);
    return is;
}
