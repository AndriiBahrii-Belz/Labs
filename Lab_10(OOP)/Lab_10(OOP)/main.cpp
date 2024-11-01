#include <iostream>
#include <vector>
#include "shape.h"

int main() {
    // Створюємо масив вказівників на базовий клас
    std::vector<Shape*> shapes;

    // Додаємо різні об'єкти
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(4.0));
    shapes.push_back(new RightTriangle(3.0, 4.0));
    shapes.push_back(new Trapezoid(3.0, 5.0, 4.0));

    // Виводимо площі та типи фігур
    for (const auto& shape : shapes) {
        std::cout << "Type: " << shape->getType() << ", Area: " << shape->area() << std::endl;
    }

    // Звільняємо пам'ять
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
