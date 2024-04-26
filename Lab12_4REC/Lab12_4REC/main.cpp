#include <iostream>

using namespace std;

// Структура елемента списку
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Клас для кільцевого однонаправленого списку
class CircularLinkedList {
private:
    Node* head; // Початок списку

    // Допоміжна функція для додавання елемента в кінець списку (рекурсивний варіант)
    void appendRecursive(Node* currentNode, int val) {
        if (currentNode->next == head) {
            currentNode->next = new Node(val);
            currentNode->next->next = head;
        }
        else {
            appendRecursive(currentNode->next, val);
        }
    }

    // Допоміжна функція для перевірки, чи елементи списку впорядковані за неспаданням (рекурсивний варіант)
    bool isSortedRecursive(Node* current) {
        if (current->next == head) {
            return true;
        }
        if (current->data > current->next->data) {
            return false;
        }
        return isSortedRecursive(current->next);
    }

public:
    // Конструктор за замовчуванням
    CircularLinkedList() : head(nullptr) {}

    // Додати елемент в кінець списку
    void append(int val) {
        if (head == nullptr) {
            head = new Node(val);
            head->next = head; // Зробити список кільцевим
        }
        else {
            appendRecursive(head, val);
        }
    }

    // Перевірити, чи елементи списку впорядковані за неспаданням
    bool isSorted() {
        if (head == nullptr || head->next == head) {
            return true; // Список порожній або має лише один елемент, тому вважаємо його впорядкованим
        }
        return isSortedRecursive(head);
    }

    // Вивести значення всіх елементів у списку
    void printList() {
        if (head == nullptr) {
            cout << "Список порожній" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList myList;

    // Додавання елементів у список
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(2);

    // Вивід списку
    cout << "Список: ";
    myList.printList();

    // Перевірка, чи елементи впорядковані за неспаданням
    if (myList.isSorted()) {
        cout << "Елементи списку впорядковані за зростанням" << endl;
    }
    else {
        cout << "Елементи списку НЕ впорядковані за зростанням" << endl;
    }

    return 0;
}
