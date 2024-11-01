#include <cmath>
#include "Curve.h"
#include <iostream>

class Line : public Curve {
private:
    double a, b; // Коефіцієнти
public:
    Line(double a, double b) : a(a), b(b) {}

    double calculateY(double x) const override {
        return a * x + b; // Формула прямої
    }
};

class Ellipse : public Curve {
private:
    double a, b; // Вісь
public:
    Ellipse(double a, double b) : a(a), b(b) {}

    double calculateY(double x) const override {
        return b * sqrt(1 - (x * x) / (a * a)); // Позитивна частина
    }
};

class Hyperbola : public Curve {
private:
    double a, b; // Вісь
public:
    Hyperbola(double a, double b) : a(a), b(b) {}

    double calculateY(double x) const override {
        // Перевірка, чи задовольняє x умові
        if ((x * x) / (a * a) <= 1) {
            std::cerr << "Помилка: x не може бути меншим за " << a << " або більшим за -" << a << " для обчислення гіперболи." << std::endl;
            return 0; // Можна повернути 0 або обробити іншим чином
        }
        return b * sqrt((x * x) / (a * a) - 1); // Позитивна частина
    }
};