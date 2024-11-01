#pragma once
// D1.h
#ifndef D1_H
#define D1_H

#include "B1.h"

class D1 : private B1 {
private:
    int d1;

public:
    D1(int valueB1, int valueD1) : B1(valueB1), d1(valueD1) {}
    ~D1() {}

    void show() const override {
        B1::show();
        std::cout << "Class: D1, Value: " << d1 << std::endl;
    }
};

#endif // D1_H
