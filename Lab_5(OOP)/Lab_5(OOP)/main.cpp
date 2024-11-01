#include <iostream>
#include "Car.h"
#include "Lorry.h"

using namespace std;

int main() {
    Car car;
    car.input();
    cout << "Car: " << car.toString() << endl;

    Lorry lorry;
    lorry.input();
    
    // Тестування методів пере-присвоєння
    Car car2 = car; // Копіювання car
    cout << "Copied Car: " << car2.toString() << endl;

    Lorry lorry2 = lorry; // Копіювання lorry
    cout << "Copied Lorry: " << lorry2.toString() << endl;

    // Зміна потужності
    car2.setPower(300);
    cout << "Updated Power of Copied Car: " << car2.toString() << endl;

    // Зміна вантажопідйомності
    lorry2.setPayload(2000);
    cout << "Updated Payload of Copied Lorry: " << lorry2.toString() << endl;

    return 0;
}
