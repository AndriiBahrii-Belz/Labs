#pragma once
#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string brand;
    int cylinders;
    double power;

public:
    Car(const std::string& brand, int cylinders, double power);
    void changePower(double newPower);
    void reassignBrand(const std::string& newBrand);
    void displayInfo() const;
};

#endif
