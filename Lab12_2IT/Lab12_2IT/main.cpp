#include <iostream> 
#include <Windows.h>
using namespace std;

struct Node { // Оголошення структури Node
    int data; // Поле для збереження даних
    Node* next; // Вказівник на наступний елемент
};

int countOddValues(Node* head) { // Функція для підрахунку кількості елементів з непарними значеннями
    int count = 0; // Ініціалізація лічильника непарних значень

    Node* current = head; // Покажчик current на початок списку

    while (current != nullptr) { // Проходження по усіх вузлах списку
        if (current->data % 2 != 0) { // Перевірка, чи значення поточного елемента є непарним
            count++; // Якщо так, збільшення лічильника
        }
        current = current->next; // Перехід до наступного вузла
    }

    return count; // Повернення кількості елементів з непарними значеннями
}

void createList(Node*& head, Node*& tail, int values[], int size) { // Функція для створення списку з масиву значень
    head = nullptr; // Ініціалізація початкового та кінцевого вузла як nullptr
    tail = nullptr;

    for (int i = 0; i < size; i++) { // Проходження по усім елементам масиву
        Node* newNode = new Node(); // 1 Створення нового вузла
        newNode->data = values[i]; // 2 Присвоєння значення вузлу з масиву
        newNode->next = nullptr; // 3 Ініціалізація вказівника на наступний вузол як nullptr

        if (head == nullptr) { // Якщо список порожній
            head = newNode; // Встановлення початкового вузла
            tail = newNode; // Встановлення кінцевого вузла
        }
        else { // Якщо список не порожній
            tail->next = newNode; // Додавання нового вузла після кінцевого вузла
            tail = newNode; // Оновлення кінцевого вузла
        }
    }
}

void printList(Node* head) { // Функція для виведення списку на екран
    Node* current = head; // Покажчик current на початок списку

    while (current != nullptr) { // Проходження по усіх вузлах списку
        cout << current->data << " "; // Виведення значення поточного вузла
        current = current->next; // Перехід до наступного вузла
    }

    cout << endl; // Виведення символу нового рядка після виведення всього списку
}


int main() {
    int values[] = { 10, 5, 4, 13, 20, 23, 30, 37 }; // Значення для створення списку
    int size = sizeof(values) / sizeof(values[0]); // Розмір масиву

    Node* head = nullptr; // Початковий вузол
    Node* tail = nullptr; // Кінцевий вузол

    createList(head, tail, values, size); // Створення списку

    cout << "Список елементів:" << endl;
    printList(head);

    int oddCount = countOddValues(head); // Отримання кількості елементів з непарними значеннями
    cout << "Кількість елементів з непарними значеннями: " << oddCount << endl;

    // Видалення списку
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}