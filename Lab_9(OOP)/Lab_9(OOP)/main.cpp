// main.cpp
#include <iostream>
#include "D1.h"
#include "D2.h"
#include "D3.h"

int main() {
    D1 d1(1, 15);
    D2 d2(2, 25);
    D3 d3(3, 40);

    std::cout << "Size of D1: " << sizeof(d1) << std::endl;
    std::cout << "Size of D2: " << sizeof(d2) << std::endl;
    std::cout << "Size of D3: " << sizeof(d3) << std::endl;

    d1.show();
    d2.show();
    d3.show();

    return 0;
}
