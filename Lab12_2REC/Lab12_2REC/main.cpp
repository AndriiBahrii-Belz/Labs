#include <iostream> 
#include <Windows.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int countOddValuesRecursive(Node* current) {
    if (current == nullptr) // Базовий випадок: якщо поточний вузол пустий, повертаємо 0
        return 0;

    // Рекурсивно обчислюємо кількість непарних елементів у підсписку, починаючи з наступного вузла
    int count = (current->data % 2 != 0) + countOddValuesRecursive(current->next);
    return count;
}

void createListRecursive(Node*& head, Node*& tail, int values[], int size, int index = 0) {
    if (index == size) // Базовий випадок: коли всі елементи масиву були додані до списку
        return;

    // Створення нового вузла та додавання його до списку
    Node* newNode = new Node();
    newNode->data = values[index];
    newNode->next = nullptr;

    if (head == nullptr) { // Якщо це перший вузол, встановлюємо його як початок і кінець списку
        head = newNode;
        tail = newNode;
    }
    else { // Інакше, додаємо новий вузол в кінець списку
        tail->next = newNode;
        tail = newNode;
    }

    // Рекурсивно викликаємо функцію для додавання наступного елементу масиву до списку
    createListRecursive(head, tail, values, size, index + 1);
}

void printListRecursive(Node* current) {
    if (current == nullptr) { // Базовий випадок: якщо поточний вузол пустий, завершуємо рекурсію
        cout << endl;
        return;
    }

    // Виводимо значення поточного вузла та рекурсивно виводимо наступні вузли
    cout << current->data << " ";
    printListRecursive(current->next);
}

int main() {
    int values[] = { 10, 5, 4, 13, 20, 23, 30, 37 };
    int size = sizeof(values) / sizeof(values[0]);

    Node* head = nullptr;
    Node* tail = nullptr;

    createListRecursive(head, tail, values, size);

    cout << "Список елементів:" << endl;
    printListRecursive(head);

    int oddCount = countOddValuesRecursive(head);
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
