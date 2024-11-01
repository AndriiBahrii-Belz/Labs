#include "Car.h"
#include <iostream>

Car::Car(const std::string& brand, int cylinders, double power)
    : brand(brand), cylinders(cylinders), power(power) {}

void Car::changePower(double newPower) {
    power = newPower;
}

void Car::reassignBrand(const std::string& newBrand) {
    brand = newBrand;
}

void Car::displayInfo() const {
    std::cout << "Марка: " << brand << ", Циліндри: " << cylinders
        << ", Потужність: " << power << " кВт" << std::endl;
}
