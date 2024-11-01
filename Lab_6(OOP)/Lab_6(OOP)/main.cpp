#include "Car.h"
#include "Lorry.h"
#include <iostream>
#include <string>

int main() {
    std::string brand;
    int cylinders;
    double power;

    // Введення даних для автомобіля
    std::cout << "Введіть торгову марку автомобіля: ";
    std::getline(std::cin, brand);
    std::cout << "Введіть кількість циліндрів: ";
    std::cin >> cylinders;
    std::cout << "Введіть потужність (кВт): ";
    std::cin >> power;

    // Створення об'єкта класу Car
    Car myCar(brand, cylinders, power);
    myCar.displayInfo();

    double loadCapacity;

    // Введення даних для вантажівки
    std::cout << "Введіть вантажопідйомність вантажівки (кг): ";
    std::cin >> loadCapacity;

    // Створення об'єкта класу Lorry
    Lorry myLorry(myCar, loadCapacity);
    myLorry.displayInfo();

    // Зміна параметрів
    double newPower;
    std::cout << "Введіть нову потужність автомобіля (кВт): ";
    std::cin >> newPower;
    myCar.changePower(newPower);

    std::string newBrand;
    std::cout << "Введіть нову торгову марку автомобіля: ";
    std::cin.ignore(); // Ігноруємо символ нового рядка після попереднього введення
    std::getline(std::cin, newBrand);
    myLorry.reassignCarBrand(newBrand);

    double newLoadCapacity;
    std::cout << "Введіть нову вантажопідйомність вантажівки (кг): ";
    std::cin >> newLoadCapacity;
    myLorry.changeLoadCapacity(newLoadCapacity);

    // Вивід оновленої інформації
    std::cout << "\nОновлена інформація про вантажівку:" << std::endl;
    myLorry.displayInfo();  // Виводимо оновлену інформацію про вантажівку

    // Вивід оновленої інформації про автомобіль
    std::cout << "\nОновлена інформація про автомобіль:" << std::endl;
    myCar.displayInfo();  // Виводимо оновлену інформацію про автомобіль

    return 0;
}
