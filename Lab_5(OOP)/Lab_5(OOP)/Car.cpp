#include "Car.h"

Car::Car() : brand("Unknown"), cylinders(0), power(0) {}

Car::Car(const string& brand, int cylinders, int power)
    : brand(brand), cylinders(cylinders), power(power) {}

Car::Car(const Car& other)
    : brand(other.brand), cylinders(other.cylinders), power(other.power) {}

Car::~Car() {}

// Методи доступу
string Car::getBrand() const { return brand; }
int Car::getCylinders() const { return cylinders; }
int Car::getPower() const { return power; }

void Car::setBrand(const string& brand) { this->brand = brand; }
void Car::setCylinders(int cylinders) { this->cylinders = cylinders; }
void Car::setPower(int power) { this->power = power; }

// Метод введення з клавіатури
void Car::input() {
    cout << "Enter car brand: ";
    cin >> brand;
    cout << "Enter number of cylinders: ";
    cin >> cylinders;
    cout << "Enter power: ";
    cin >> power;
}

string Car::toString() const {
    return "Brand: " + brand + ", Cylinders: " + to_string(cylinders) + ", Power: " + to_string(power);
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        brand = other.brand;
        cylinders = other.cylinders;
        power = other.power;
    }
    return *this;
}
