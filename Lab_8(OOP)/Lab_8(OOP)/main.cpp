#include <iostream>
#include "Pair.h"
#include "Fraction.h"

int main() {
    Pair p1, p2;
    std::cout << "Введіть першу пару (first second): ";
    std::cin >> p1;
    std::cout << "Введіть другу пару (first second): ";
    std::cin >> p2;

    std::cout << "Перша пара: " << p1 << std::endl;
    std::cout << "Друга пара: " << p2 << std::endl;

    if (p1 > p2) {
        std::cout << "Перша пара більша за другу." << std::endl;
    }
    else {
        std::cout << "Друга пара більша або рівна першій." << std::endl;
    }

    Fraction f1, f2;
    std::cout << "Введіть перший дріб (ціла частина дробова частина): ";
    std::cin >> f1;
    std::cout << "Введіть другий дріб (ціла частина дробова частина): ";
    std::cin >> f2;

    std::cout << "Перший дріб: " << f1 << std::endl;
    std::cout << "Другий дріб: " << f2 << std::endl;

    if (f1 > f2) {
        std::cout << "Перший дріб більший за другий." << std::endl;
    }
    else {
        std::cout << "Другий дріб більший або рівний першому." << std::endl;
    }

    return 0;
}
