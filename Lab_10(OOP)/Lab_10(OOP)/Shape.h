#pragma once
#ifndef SHAPE_H
#define SHAPE_H

// Абстрактний базовий клас
class Shape {
public:
    virtual double area() const = 0; // Віртуальна функція для обчислення площі
    virtual const char* getType() const = 0; // Функція для отримання типу фігури
    virtual ~Shape() {} // Віртуальний деструктор
};

// Похідний клас: Прямокутник
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);
    double area() const override;
    const char* getType() const override;
};

// Похідний клас: Коло
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    double area() const override;
    const char* getType() const override;
};

// Похідний клас: Прямокутний трикутник
class RightTriangle : public Shape {
private:
    double base;
    double height;

public:
    RightTriangle(double b, double h);
    double area() const override;
    const char* getType() const override;
};

// Похідний клас: Трапеція
class Trapezoid : public Shape {
private:
    double base1;
    double base2;
    double height;

public:
    Trapezoid(double b1, double b2, double h);
    double area() const override;
    const char* getType() const override;
};

#endif // SHAPE_H
