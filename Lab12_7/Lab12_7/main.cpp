#include <iostream>
#include <string>
using namespace std;

// Структура для представлення абітурієнта
struct Applicant {
    string surname;
    float certificateScore;
    string documentType;
    Applicant* next;
};

// Функція для додавання абітурієнта до списку
void addApplicant(Applicant*& head, string surname, float certificateScore, string documentType) {
    Applicant* newApplicant = new Applicant;
    newApplicant->surname = surname;
    newApplicant->certificateScore = certificateScore;
    newApplicant->documentType = documentType;
    newApplicant->next = head;
    head = newApplicant;
}

// Функція для виведення списку абітурієнтів
void printApplicants(Applicant* head) {
    cout << "Список абітурієнтів:\n";
    while (head != nullptr) {
        cout << "Прізвище: " << head->surname << ", Бал сертифікату: " << head->certificateScore << ", Тип документу: " << head->documentType << endl;
        head = head->next;
    }
}

// Функція для створення списку абітурієнтів, що рекомендовані до зарахування
Applicant* recommendedApplicants(Applicant* head, float passingScore) {
    Applicant* recommendedHead = nullptr;
    while (head != nullptr) {
        if (head->certificateScore >= passingScore) {
            addApplicant(recommendedHead, head->surname, head->certificateScore, head->documentType);
        }
        head = head->next;
    }
    return recommendedHead;
}

int main() {
    Applicant* head = nullptr; // Початок списку абітурієнтів

    // Додавання даних абітурієнтів
    addApplicant(head, "Петров", 90.5, "оригінал");
    addApplicant(head, "Іванов", 85.3, "дублікат");
    addApplicant(head, "Сидоров", 78.9, "оригінал");
    addApplicant(head, "Коваленко", 92.7, "оригінал");
    addApplicant(head, "Савченко", 88.2, "дублікат");
    addApplicant(head, "Ковальчук", 79.6, "оригінал");
    addApplicant(head, "Петренко", 86.4, "дублікат");
    addApplicant(head, "Мельник", 91.8, "оригінал");
    addApplicant(head, "Семенова", 83.7, "дублікат");
    addApplicant(head, "Ковалев", 89.1, "оригінал");

    // Виведення вхідного списку
    printApplicants(head);

    // Додавання абітурієнтів користувачем
    char addMore;
    do {
        string surname, documentType;
        float certificateScore;
        cout << "Додати абітурієнта? (y/n):";
        cin >> addMore;
        if (addMore == 'y' || addMore == 'Y') {
            cout << "Додати нового абітурієнта:\n";
            cout << "Прізвище: ";
            cin >> surname;
            cout << "Бал сертифікату: ";
            cin >> certificateScore;
            cout << "Тип документу: ";
            cin >> documentType;
            addApplicant(head, surname, certificateScore, documentType);
        }else {
            break;
        }
        cout << "Чи бажаєте додати іншого абітурієнта? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    // Введення прохідного балу
    float passingScore;
    cout << "Введіть прохідний бал: ";
    cin >> passingScore;

    // Створення списку абітурієнтів, що рекомендовані до зарахування
    Applicant* recommendedHead = recommendedApplicants(head, passingScore);

    // Виведення списку рекомендованих абітурієнтів
    cout << "\nСписок рекомендованих абітурієнтів:\n";
    printApplicants(recommendedHead);

    return 0;
}
