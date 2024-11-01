// Integer.h
#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include <string>

using namespace std;

class Integer {
private:
    int value1;
    int value2;

public:
    // Конструктори
    Integer();                         // Конструктор за замовчуванням
    Integer(int val1, int val2);      // Параметризований конструктор
    Integer(const Integer& other);     // Конструктор копіювання

    // Деструктор
    ~Integer();

    // Методи доступу (геттери)
    int getValue1() const;
    int getValue2() const;

    // Методи доступу (сеттери)
    void setValue1(int val);
    void setValue2(int val);

    // Оператор присвоєння
    Integer& operator=(const Integer& other);

    // Оператор приведення до рядка
    operator string() const;

    // Префіксний інкремент
    Integer& operator++(); // Префіксний

    // Постфіксний інкремент
    Integer operator++(int); // Постфіксний

    // Оператор унарного мінуса
    friend Integer operator-(const Integer& obj);

    // Бінарні оператори додавання
    friend Integer operator+(const Integer& lhs, const Integer& rhs);
    friend Integer operator+(const Integer& lhs, int rhs);
    friend Integer operator+(int lhs, const Integer& rhs);

    // Потокові оператори
    friend ostream& operator<<(ostream& os, const Integer& obj);
    friend istream& operator>>(istream& is, Integer& obj);
};

#endif // INTEGER_H
