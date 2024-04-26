#include <iostream>
#include <Windows.h>
using namespace std;

// Структура, що представляє вузол двунаправленого списку
struct Node {
    int data;     // Дані вузла
    Node* prev;   // Вказівник на попередній вузол
    Node* next;   // Вказівник на наступний вузол
};

// Функція для створення двунаправленого списку на основі масиву значень (рекурсивна версія)
Node* createListRecursive(int values[], int size, int duplicateValue, Node* head = nullptr, Node* tail = nullptr, int index = 0) {
    if (index == size) // Базовий випадок: коли всі елементи масиву були додані до списку
        return head;

    // Створення нового вузла
    Node* newNode = new Node();
    newNode->data = values[index];
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // Створення другого вузла з заданим значенням
    Node* duplicateNode = new Node();
    duplicateNode->data = duplicateValue;
    duplicateNode->prev = nullptr;
    duplicateNode->next = nullptr;

    if (head == nullptr) { // Якщо це перший вузол, встановлюємо його як початок і кінець списку
        head = newNode;
        tail = newNode;
    }
    else { // Інакше, додаємо новий вузол в кінець списку
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Додавання другого вузла з заданим значенням
    tail->next = duplicateNode;
    duplicateNode->prev = tail;
    tail = duplicateNode;

    // Рекурсивний виклик для додавання наступного елементу масиву до списку
    return createListRecursive(values, size, duplicateValue, head, tail, index + 1);
}

// Функція для виведення значень усіх вузлів у списку (рекурсивна версія)
void printListRecursive(Node* current) {
    if (current == nullptr) { // Базовий випадок: якщо поточний вузол пустий, завершуємо рекурсію
        cout << endl;
        return;
    }

    // Виводимо значення поточного вузла
    cout << current->data << " ";

    // Рекурсивно виводимо наступні вузли
    printListRecursive(current->next);
}

// Функція для видалення всього списку та звільнення пам'яті (рекурсивна версія)
void deleteListRecursive(Node* current) {
    if (current == nullptr) // Базовий випадок: якщо поточний вузол пустий, завершуємо рекурсію
        return;

    // Рекурсивно видаляємо наступні вузли
    deleteListRecursive(current->next);

    // Звільняємо пам'ять, що була виділена для поточного вузла
    delete current;
}

int main() {

    int values[] = { 1, 2, 3, 4, 5 };  // Масив значень для створення списку
    int size = sizeof(values) / sizeof(values[0]);  // Розмір масиву
    int duplicateValue = 0; // Значення для дублювання

    Node* head = createListRecursive(values, size, duplicateValue);  // Створення двунаправленого списку

    cout << "Список елементів:" << endl;
    printListRecursive(head);  // Виведення елементів списку

    deleteListRecursive(head);  // Видалення списку та звільнення пам'яті

    return 0;
}