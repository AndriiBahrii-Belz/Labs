#ifndef LORRY_H
#define LORRY_H

#include "Car.h"
using namespace std;

class Lorry {
public:
    // Конструктори
    Lorry();
    Lorry(const string& brand, int cylinders, int power, int payload);
    Lorry(const Lorry& other);

    // Деструктор
    ~Lorry();

    // Методи доступу
    int getPayload() const;
    void setPayload(int payload);

    // Метод введення даних з клавіатури
    void input();

    string toString() const;

    // Перевантаження оператора присвоєння
    Lorry& operator=(const Lorry& other);

private:
    Car car;          // Об'єкт Car
    int payload;      // Вантажопідйомність
};

#endif
