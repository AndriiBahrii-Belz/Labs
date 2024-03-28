#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> // для функції std::sort та std::binary_search
#include <vector>    // для використання векторів
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

// Функція для порівняння студентів за спеціальністю, курсом та прізвищем
bool compareStudents(const Student& a, const Student& b) {
    if (a.specialty != b.specialty)
        return a.specialty < b.specialty;
    if (a.course != b.course)
        return a.course < b.course;
    return a.lastName < b.lastName;
}

// Функція для створення індексного масиву
vector<int> createIndex(const vector<Student>& students) {
    vector<int> index(students.size());
    for (int i = 0; i < students.size(); ++i) {
        index[i] = i;
    }
    sort(index.begin(), index.end(), [&students](int a, int b) {
        return compareStudents(students[a], students[b]);
        });
    return index;
}

// Функція для бінарного пошуку студента за прізвищем на певній спеціальності та курсі
bool binarySearchStudent(const vector<Student>& students, const string& lastName, const string& specialty, int course) {
    Student target;
    target.lastName = lastName;
    target.specialty = specialty;
    target.course = course;

    auto it = lower_bound(students.begin(), students.end(), target, compareStudents);

    return (it != students.end() && it->lastName == lastName && it->specialty == specialty && it->course == course);
}

int main() {
    int n; // кількість студентів
    cout << "Введіть кількість студентів: ";
    cin >> n;

    // Створення вектора студентів
    vector<Student> students(n);

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

    // Сортування студентів за допомогою функції std::sort
    sort(students.begin(), students.end(), compareStudents);

    // Виведення заголовка таблиці
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "| No. | Прізвище      | Курс | Спеціальність     | Фізика | Математика | Додаткова оцінка |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    // Виведення відсортованого масиву
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

    // Створення індексного масиву
    vector<int> index = createIndex(students);

    // Виведення заголовка таблиці для індексного масиву
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "| No. | Прізвище      | Курс | Спеціальність     | Фізика | Математика | Додаткова оцінка |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    // Виведення масиву через індексний масив
    for (int i = 0; i < n; ++i) {
        int idx = index[i];
        cout << "| " << setw(3) << i + 1 << " | " << setw(13) << students[idx].lastName << " | " << setw(4) << students[idx].course << " | " << setw(16) << students[idx].specialty << " | " << setw(6) << students[idx].physicsGrade << " | " << setw(10) << students[idx].mathGrade << " | ";

        // Виведення третьої оцінки залежно від спеціальності
        if (students[idx].specialty == "Програмування") {
            cout << setw(16) << students[idx].thirdGrade.programming;
        }
        else if (students[idx].specialty == "Інформатика") {
            cout << setw(16) << students[idx].thirdGrade.numericalMethods;
        }
        else {
            cout << setw(16) << students[idx].thirdGrade.pedagogy;
        }

        cout << " |" << endl;
    }

    cout << "-------------------------------------------------------------------------------------------" << endl;

    // Пошук студента за прізвищем на певній спеціальності та курсі
    string searchLastName;
    string searchSpecialty;
    int searchCourse;
    cout << "\nВведіть прізвище, спеціальність та курс для пошуку студента: ";
    cin >> searchLastName >> searchSpecialty >> searchCourse;

    bool found = binarySearchStudent(students, searchLastName, searchSpecialty, searchCourse);
    if (found) {
        cout << "Студент з прізвищем " << searchLastName << " на спеціальності " << searchSpecialty << " на " << searchCourse << " курсі знайдений." << endl;
    }
    else {
        cout << "Студент не знайдений." << endl;
    }
    return 0;
}
