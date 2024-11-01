#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
using namespace std;

class Car {
public:
    // Конструктори
    Car();
    Car(const string& brand, int cylinders, int power);
    Car(const Car& other);

    // Деструктор
    ~Car();

    // Методи доступу
    string getBrand() const;
    int getCylinders() const;
    int getPower() const;

    void setBrand(const string& brand);
    void setCylinders(int cylinders);
    void setPower(int power);

    // Метод введення з клавіатури
    void input();

    // Метод приведення типу до рядка
    string toString() const;

    // Перевантаження оператора присвоєння
    Car& operator=(const Car& other);

private:
    string brand;       // Торгова марка
    int cylinders;      // Кількість циліндрів
    int power;          // Потужність
};

#endif
