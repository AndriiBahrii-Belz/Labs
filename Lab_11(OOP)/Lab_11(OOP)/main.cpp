#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include "Curve.h"
#include "Curve.cpp"

int main() {
    std::vector<std::unique_ptr<Curve>> curves; // Вектор унікальних вказівників на Curve

    int choice;
    std::cout << "Виберіть тип кривої (1 - Пряма, 2 - Еліпс, 3 - Гіпербола): ";
    std::cin >> choice;

    double a, b, x;

    // Введення параметрів для обраної кривої
    switch (choice) {
    case 1: // Пряма
        std::cout << "Введіть коефіцієнти a і b для прямої (y = ax + b): ";
        std::cin >> a >> b;
        curves.push_back(std::make_unique<Line>(a, b));
        break;
    case 2: // Еліпс
        std::cout << "Введіть півосі a і b для еліпса (x^2/a^2 + y^2/b^2 = 1): ";
        std::cin >> a >> b;
        curves.push_back(std::make_unique<Ellipse>(a, b));
        break;
    case 3: // Гіпербола
        std::cout << "Введіть півосі a і b для гіперболи (x^2/a^2 - y^2/b^2 = 1): ";
        std::cin >> a >> b;
        curves.push_back(std::make_unique<Hyperbola>(a, b));
        break;
    default:
        std::cerr << "Невірний вибір!" << std::endl;
        return 1; // Вихід з програми з помилкою
    }

    std::cout << "Введіть значення x: ";
    std::cin >> x;

    // Обчислюємо і виводимо результат
    for (const auto& curve : curves) {
        std::cout << "Тип: " << typeid(*curve).name() << ", y(" << x << ") = " << curve->calculateY(x) << std::endl;
    }

    return 0;
}
