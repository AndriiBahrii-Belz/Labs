#include "Lorry.h"

Lorry::Lorry() : car(), payload(0) {}

Lorry::Lorry(const string& brand, int cylinders, int power, int payload)
    : car(brand, cylinders, power), payload(payload) {}

Lorry::Lorry(const Lorry& other) : car(other.car), payload(other.payload) {}

Lorry::~Lorry() {}

// Методи доступу
int Lorry::getPayload() const { return payload; }
void Lorry::setPayload(int payload) { this->payload = payload; }

// Метод введення з клавіатури
void Lorry::input() {
    car.input(); // Виклик input() для об'єкта car
    cout << "Enter payload: ";
    cin >> payload;
}

string Lorry::toString() const {
    return car.toString() + ", Payload: " + to_string(payload);
}

Lorry& Lorry::operator=(const Lorry& other) {
    if (this != &other) {
        car = other.car;
        payload = other.payload;
    }
    return *this;
}
