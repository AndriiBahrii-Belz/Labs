#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <functional> // Для використання std::greater у пріоритетній черзі
#include <random>
#include <string>

using namespace std;

// Структура для зберігання повідомлення та його пріоритету
struct Message {
    string text;
    int priority;
};

// Функція для зчитування повідомлень з файлу та їх пріоритетів
queue<Message> readMessagesFromFile(const string& filename) {
    ifstream file(filename);
    queue<Message> messages;
    string line;
    while (getline(file, line)) {
        Message msg;
        msg.text = line;
        // Генеруємо випадковий пріоритет від 1 до 10
        msg.priority = rand() % 10 + 1;
        messages.push(msg);
    }
    file.close();
    return messages;
}

// Функція для виводу черги повідомлень на екран
void printQueue(const queue<Message>& messages) {
    queue<Message> temp = messages;
    while (!temp.empty()) {
        Message msg = temp.front();
        cout << "Text: " << msg.text << ", Priority: " << msg.priority << endl;
        temp.pop();
    }
}

// Функція для перебудови черги повідомлень відповідно до пріоритетів
queue<Message> reorderQueue(queue<Message> messages) {
    priority_queue<Message, vector<Message>, function<bool(const Message&, const Message&)>> pq([](const Message& a, const Message& b) { return a.priority < b.priority; });
    while (!messages.empty()) {
        pq.push(messages.front());
        messages.pop();
    }
    queue<Message> reorderedQueue;
    while (!pq.empty()) {
        reorderedQueue.push(pq.top());
        pq.pop();
    }
    return reorderedQueue;
}

// Функція для вибору елементів із заданим пріоритетом
queue<Message> selectMessagesWithPriority(queue<Message> messages, int priority) {
    queue<Message> selectedMessages;
    while (!messages.empty()) {
        if (messages.front().priority == priority) {
            selectedMessages.push(messages.front());
        }
        messages.pop();
    }
    return selectedMessages;
}

int main() {
    // Читаємо повідомлення з файлу та їх пріоритети
    queue<Message> messages = readMessagesFromFile("C:\\Users\\andri\\Desktop\\Queue.txt");

    // Виводимо початкову чергу повідомлень
    cout << "Initial Queue:" << endl;
    printQueue(messages);

    // Перебудовуємо чергу повідомлень за пріоритетами
    queue<Message> reorderedMessages = reorderQueue(messages);

    // Виводимо перебудовану чергу повідомлень
    cout << "\nReordered Queue:" << endl;
    printQueue(reorderedMessages);

    // Вибираємо елементи з певним пріоритетом (наприклад, пріоритет 5)
    int selectedPriority = 5;
    queue<Message> selectedMessages = selectMessagesWithPriority(messages, selectedPriority);

    // Виводимо вибрані повідомлення
    cout << "\nSelected Messages with Priority " << selectedPriority << ":" << endl;
    printQueue(selectedMessages);

    return 0;
}
