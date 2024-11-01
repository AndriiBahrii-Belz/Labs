#include "Pair.h"

// Конструктор
Pair::Pair(int f, int s) : first(f), second(s) {}

// Методи отримання значень полів
int Pair::getFirst() const { return first; }
int Pair::getSecond() const { return second; }

// Методи встановлення значень полів
void Pair::setFirst(int f) { first = f; }
void Pair::setSecond(int s) { second = s; }

// Операція для приведення типу до рядка
Pair::operator std::string() const {
    return "(" + std::to_string(first) + ", " + std::to_string(second) + ")";
}

// Метод порівняння
bool Pair::operator>(const Pair& other) const {
    return (first > other.first) || (first == other.first && second > other.second);
}

// Операції вводу та виводу
std::ostream& operator<<(std::ostream& os, const Pair& p) {
    os << static_cast<std::string>(p);
    return os;
}

std::istream& operator>>(std::istream& is, Pair& p) {
    is >> p.first >> p.second;
    return is;
}
