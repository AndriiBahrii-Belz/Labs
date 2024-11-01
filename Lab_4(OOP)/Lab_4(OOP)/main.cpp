// main.cpp
#include <iostream>
#include "Integer.h"

using namespace std;

int main() {
    // Демонстрація різних способів створення об'єктів
    Integer a; // Конструктор за замовчуванням
    Integer b(10, 20); // Параметризований конструктор
    Integer c = b; // Конструктор копіювання

    // Вивід початкових значень
    cout << "Object a (default): " << a << endl;
    cout << "Object b (initialized): " << b << endl;
    cout << "Object c (copy of b): " << c << endl;

    // Введення значень з клавіатури
    cin >> a;
    cout << "After input, object a: " << a << endl;

    // Присвоєння
    a = b;
    cout << "After assignment a = b: " << a << endl;

    // Операція приведення до рядка
    string str = static_cast<string>(b);
    cout << "String representation of b: " << str << endl;

    // Використання операції +
    Integer d = b + c;
    cout << "d = b + c: " << d << endl;

    Integer e = b + 5;
    cout << "e = b + 5: " << e << endl;

    Integer f = 15 + c;
    cout << "f = 15 + c: " << f << endl;

    // Використання оператора унарного мінуса
    Integer g = -b;
    cout << "g = -b: " << g << endl;

    // Використання операторів інкременту
    cout << "\nBefore increment:\n" << b << endl;
    ++b; // Префіксний інкремент (модифікує value1)
    cout << "After prefix increment (++b): " << b << endl;

    b++; // Постфіксний інкремент (модифікує value2)
    cout << "After postfix increment (b++): " << b << endl;

    // Створення масиву об'єктів
    Integer arr[3];
    cout << "\nEnter values for the array of objects:\n";
    for (int i = 0; i < 3; ++i) {
        cin >> arr[i];
    }

    cout << "Contents of the array of objects:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }

    return 0;
}
