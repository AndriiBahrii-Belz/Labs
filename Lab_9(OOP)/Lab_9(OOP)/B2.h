#pragma once
// B2.h
#ifndef B2_H
#define B2_H

#include <iostream>

class B2 {
private:
    int b2;

public:
    B2(int value) : b2(value) {}
    virtual ~B2() {}

    virtual void show() const {
        std::cout << "Class: B2, Value: " << b2 << std::endl;
    }
};

#endif // B2_H
