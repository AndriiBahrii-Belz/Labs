#include <iostream>
#include <algorithm> // Для std::min_element та std::max_element
#include <cstdlib>   // Для rand() та srand()
#include <ctime>     // Для time()

using namespace std;

template <typename T>
class Array {
private:
    T* arr;        // Вказівник на масив
    size_t size;   // Розмір масиву

public:
    Array(size_t s);   // Конструктор
    ~Array();          // Деструктор

    void fillArrayRandom();  // Метод для заповнення масиву випадковими значеннями
    void printArray() const; // Метод для виведення масиву
    T difference() const; // Метод для обчислення різниці між макс. і мін. значеннями
};

// Реалізація методів класу

// Конструктор
template <typename T>
Array<T>::Array(size_t s) : size(s) {
    arr = new T[size];
}

// Деструктор
template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

// Метод для заповнення масиву випадковими значеннями
template <typename T>
void Array<T>::fillArrayRandom() {
    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел
    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Випадкові числа від 0 до 99
    }
}

// Метод для виведення масиву
template <typename T>
void Array<T>::printArray() const {
    cout << "Елементи масиву: ";
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Метод для обчислення різниці між максимальним і мінімальним значеннями
template <typename T>
T Array<T>::difference() const {
    T minVal = *std::min_element(arr, arr + size);
    T maxVal = *std::max_element(arr, arr + size);
    return maxVal - minVal;
}

// Основна функція
int main() {
    size_t n;

    // Введення розміру масиву
    cout << "Введіть розмір масиву: ";
    cin >> n;

    // Створення інстанції шаблону класу Array для типу int
    Array<int> intArray(n);

    // Заповнення масиву випадковими значеннями
    intArray.fillArrayRandom();

    // Виведення елементів масиву
    intArray.printArray();

    // Обчислення та виведення різниці
    cout << "Різниця між максимальним і мінімальним значеннями: " << intArray.difference() << endl;

    return 0;
}
