#ifndef LORRY_H
#define LORRY_H

#include "Car.h"

class Lorry {
private:
    Car& car; // Зміна на посилання
    double loadCapacity;

public:
    Lorry(Car& car, double loadCapacity); // Зміна конструктора
    void changeLoadCapacity(double newLoadCapacity);
    void reassignCarBrand(const std::string& newBrand);
    void displayInfo() const;
};

#endif
