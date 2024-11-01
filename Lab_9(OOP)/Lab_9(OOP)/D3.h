#pragma once
// D3.h
#ifndef D3_H
#define D3_H

#include "B1.h"

class D3 : public B1 {
private:
    int d3;

public:
    D3(int valueB1, int valueD3) : B1(valueB1), d3(valueD3) {}
    ~D3() {}

    void show() const override {
        B1::show();
        std::cout << "Class: D3, Value: " << d3 << std::endl;
    }
};

#endif // D3_H
