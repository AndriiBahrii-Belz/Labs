#pragma once
// D2.h
#ifndef D2_H
#define D2_H

#include "B2.h" // Необхідно створити клас B2, щоб використовувати його

class D2 : private B2 {
private:
    int d2;

public:
    D2(int valueB2, int valueD2) : B2(valueB2), d2(valueD2) {}
    ~D2() {}

    void show() const override {
        B2::show();
        std::cout << "Class: D2, Value: " << d2 << std::endl;
    }
};

#endif // D2_H
