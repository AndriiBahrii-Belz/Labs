#include "Lorry.h"
#include <iostream>

Lorry::Lorry(Car& car, double loadCapacity)
    : car(car), loadCapacity(loadCapacity) {} // Використання посилання

void Lorry::changeLoadCapacity(double newLoadCapacity) {
    loadCapacity = newLoadCapacity;
}

void Lorry::reassignCarBrand(const std::string& newBrand) {
    car.reassignBrand(newBrand);
}

void Lorry::displayInfo() const {
    car.displayInfo(); // Виводимо інформацію про машину
    std::cout << "Вантажопідйомність: " << loadCapacity << " кг" << std::endl;
}
