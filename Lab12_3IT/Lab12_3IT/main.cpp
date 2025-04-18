#include <iostream>
#include <Windows.h>
using namespace std;

// Структура, що представляє вузол двунаправленого списку
struct Node {
    int data;     // Дані вузла
    Node* prev;   // Вказівник на попередній вузол
    Node* next;   // Вказівник на наступний вузол
};

// Функція для створення двунаправленого списку на основі масиву значень
Node* createList(int values[], int size, int duplicateValue) {
    Node* head = nullptr;  // Початковий вузол
    Node* tail = nullptr;  // Кінцевий вузол

    // Прохід по масиву значень
    for (int i = 0; i < size; i++) {
        // Створення нового вузла
        Node* newNode = new Node(); // 1
        newNode->data = values[i];  // 2 Присвоєння значення вузлу
        newNode->prev = nullptr;    // 3 Початкове значення вказівника на попередній вузол
        newNode->next = nullptr;    // 4 Початкове значення вказівника на наступний вузол

        // Створення другого вузла з заданим значенням
        Node* duplicateNode = new Node();
        duplicateNode->data = duplicateValue;
        duplicateNode->prev = nullptr;
        duplicateNode->next = nullptr;

        // Перевірка, чи це перший вузол у списку
        if (head == nullptr) {
            head = newNode;  //5 Якщо так, то встановлення його як початкового та кінцевого вузла
            tail = newNode; //6
        }
        else {
            tail->next = newNode;  // Додавання нового вузла після кінцевого вузла
            newNode->prev = tail;  // Встановлення посилання на попередній вузол для нового вузла
            tail = newNode;        // Встановлення нового вузла як кінцевого
        }

        // Додавання другого вузла з заданим значенням
        tail->next = duplicateNode;
        duplicateNode->prev = tail;
        tail = duplicateNode;
    }

    return head;  // Повернення посилання на початковий вузол
}

// Функція для виведення значень усіх вузлів у списку
void printList(Node* head) {
    Node* current = head;  // Початковий вузол

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        cout << current->data << " ";  // Виведення значення поточного вузла
        current = current->next;       // Перехід до наступного вузла
    }

    cout << endl;  // Виведення символу нового рядка в кінці списку
}

// Функція для видалення всього списку та звільнення пам'яті
void deleteList(Node* head) {
    Node* current = head;  // Початковий вузол

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        Node* temp = current;      // Тимчасовий вказівник на поточний вузол
        current = current->next;   // Перехід до наступного вузла
        delete temp;               // Звільнення пам'яті, що була виділена для поточного вузла
    }
}

int main() {

    int values[] = { 1, 2, 3, 4, 5 };  // Масив значень для створення списку
    int size = sizeof(values) / sizeof(values[0]);  // Розмір масиву
    int duplicateValue = 6; // Значення для дублювання

    Node* head = createList(values, size, duplicateValue);  // Створення двунаправленого списку

    cout << "Список елементів:" << endl;
    printList(head);  // Виведення елементів списку

    deleteList(head);  // Видалення списку та звільнення пам'яті

    return 0;
}
