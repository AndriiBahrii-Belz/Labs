#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Об'єднання для третьої оцінки
union ThirdGrade {
    int programming;        // оцінка з програмування
    int numericalMethods;   // оцінка з чисельних методів
    int pedagogy;           // оцінка з педагогіки
};

// Структура для інформації про студента
struct Student {
    string lastName;        // прізвище
    int course;             // курс
    string specialty;       // спеціальність
    int physicsGrade;       // оцінка з фізики
    int mathGrade;          // оцінка з математики
    ThirdGrade thirdGrade;  // об'єднання для третьої оцінки
};

// Обчислення середнього балу студента
float calculateAverage(const Student& student) {
    float sum = student.physicsGrade + student.mathGrade;
    if (student.specialty == "Програмування") {
        sum += student.thirdGrade.programming;
    }
    else if (student.specialty == "Інформатика") {
        sum += student.thirdGrade.numericalMethods;
    }
    else {
        sum += student.thirdGrade.pedagogy;
    }
    return sum / 3.0f;
}

int main() {
    int n; // кількість студентів
    cout << "Введіть кількість студентів: ";
    cin >> n;

    // Створення динамічного масиву структур
    Student* students = new Student[n];

    // Введення даних про студентів
    for (int i = 0; i < n; ++i) {
        cout << "Студент #" << i + 1 << endl;
        cout << "Прізвище: ";
        cin >> students[i].lastName;
        cout << "Курс: ";
        cin >> students[i].course;
        cout << "Спеціальність: ";
        cin >> students[i].specialty;
        cout << "Оцінка з фізики: ";
        cin >> students[i].physicsGrade;
        cout << "Оцінка з математики: ";
        cin >> students[i].mathGrade;

        // Введення третьої оцінки залежно від спеціальності
        if (students[i].specialty == "Програмування") {
            cout << "Оцінка з програмування: ";
            cin >> students[i].thirdGrade.programming;
        }
        else if (students[i].specialty == "Інформатика") {
            cout << "Оцінка з чисельних методів: ";
            cin >> students[i].thirdGrade.numericalMethods;
        }
        else {
            cout << "Оцінка з педагогіки: ";
            cin >> students[i].thirdGrade.pedagogy;
        }
    }

    // Виведення заголовка таблиці
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "| No. | Прізвище      | Курс | Спеціальність     | Фізика | Математика | Додаткова оцінка |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    // Виведення даних про студентів
    for (int i = 0; i < n; ++i) {
        cout << "| " << setw(3) << i + 1 << " | " << setw(13) << students[i].lastName << " | " << setw(4) << students[i].course << " | " << setw(16) << students[i].specialty << " | " << setw(6) << students[i].physicsGrade << " | " << setw(10) << students[i].mathGrade << " | ";

        // Виведення третьої оцінки залежно від спеціальності
        if (students[i].specialty == "Програмування") {
            cout << setw(16) << students[i].thirdGrade.programming;
        }
        else if (students[i].specialty == "Інформатика") {
            cout << setw(16) << students[i].thirdGrade.numericalMethods;
        }
        else {
            cout << setw(16) << students[i].thirdGrade.pedagogy;
        }

        cout << " |" << endl;
    }

    cout << "-------------------------------------------------------------------------------------------" << endl;

    // Виведення прізвищ студентів, які вчаться на "відмінно"
    cout << "Прізвища студентів, які вчаться на 'відмінно':" << endl;
    for (int i = 0; i < n; ++i) {
        if (students[i].physicsGrade == 5 && students[i].mathGrade == 5) {
            if (students[i].specialty == "Програмування" && students[i].thirdGrade.programming == 5) {
                cout << students[i].lastName << endl;
            }
            else if (students[i].specialty == "Інформатика" && students[i].thirdGrade.numericalMethods == 5) {
                cout << students[i].lastName << endl;
            }
            else if (students[i].thirdGrade.pedagogy == 5) {
                cout << students[i].lastName << endl;
            }
        }
    }

    // Обчислення проценту студентів з середнім балом більше 4.5
    int countAbove4_5 = 0;
    for (int i = 0; i < n; ++i) {
        float average = calculateAverage(students[i]);
        if (average > 4.5) {
            countAbove4_5++;
        }
    }
    float percentAbove4_5 = (static_cast<float>(countAbove4_5) / n) * 100;
    cout << "Процент студентів з середнім балом більше 4.5: " << percentAbove4_5 << "%" << endl;

    // Звільнення пам'яті, що була виділена для масиву структур
    delete[] students;

    return 0;
}