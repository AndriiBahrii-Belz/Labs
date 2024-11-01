#pragma once
// B1.h
#ifndef B1_H
#define B1_H

#include <iostream>

class B1 {
private:
    int b1;

public:
    B1(int value) : b1(value) {}
    virtual ~B1() {}

    virtual void show() const {
        std::cout << "Class: B1, Value: " << b1 << std::endl;
    }
};

#endif // B1_H
