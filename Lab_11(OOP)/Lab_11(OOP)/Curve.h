#pragma once
#ifndef CURVE_H
#define CURVE_H

class Curve {
public:
    virtual ~Curve() {} // Віртуальний деструктор
    virtual double calculateY(double x) const = 0; // Абстрактний метод
};

#endif // CURVE_H
