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

public:
    // Конструктор за замовчуванням
    CircularLinkedList() : head(nullptr) {}

    // Додати елемент в кінець списку
    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Зробити список кільцевим
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Зробити список кільцевим
        }
    }

    // Перевірити, чи елементи списку впорядковані за неспаданням
    bool isSorted() {
        if (head == nullptr || head->next == head) {
            return true; // Список порожній або має лише один елемент, тому вважаємо його впорядкованим
        }
        Node* current = head;
        do {
            if (current->data > current->next->data) {
                return false; // Пара сусідніх елементів не впорядкована за неспаданням
            }
            current = current->next;
        } while (current->next != head);
        return true; // Усі пари сусідніх елементів впорядковані за неспаданням
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
