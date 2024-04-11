#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string lastName;
    string initials;
    int marks[5];
};

// Функція для додавання нового студента до списку
void addStudent(vector<Student>& students) {
    Student student;
    cout << "Введіть прізвище студента: ";
    cin >> student.lastName;
    cout << "Введіть ініціали: ";
    cin.ignore(); // Очистити символ нового рядка з буфера вводу
    getline(cin, student.initials); // Використати getline для зчитування ініціалів
    cout << "Введіть оцінки з 5 предметів: ";
    for (int i = 0; i < 5; ++i) {
        cin >> student.marks[i];
    }
    cout << "Введений студент: " << student.lastName << " " << student.initials << " ";
    for (int i = 0; i < 5; ++i) {
        cout << student.marks[i] << " ";
    }
    cout << endl;
    students.push_back(student);
}

// Функція для зчитування даних з файлу
void readDataFromFile(const string& filename, vector<Student>& students) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Невдалось відкрити файл: " << filename << endl;
        return;
    }

    students.clear(); // Очищаємо список перед зчитуванням даних з файлу

    Student student;
    while (file >> student.lastName >> student.initials) {
        for (int i = 0; i < 5; ++i) {
            file >> student.marks[i];
        }
        students.push_back(student);
    }

    file.close();
}

// Функція для запису даних у файл
void writeDataToFile(const string& filename, const vector<Student>& students) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Невдалось відкрити файл: " << filename << endl;
        return;
    }

    for (const auto& student : students) {
        file << student.lastName << " " << student.initials << " ";
        for (int i = 0; i < 5; ++i) {
            file << student.marks[i] << " ";
        }
        file << "\n";
    }

    file.close();
}

// Функція для виведення списку всіх студентів
void printAllStudents(const vector<Student>& students) {
    cout << "Всі студенти:" << endl;
    for (const auto& student : students) {
        cout << student.lastName << " " << student.initials << endl;
    }
}

// Функція для виведення списку студентів з оцінкою "5" на всіх предметах
void printStudentsWithAllFives(const vector<Student>& students) {
    cout << "Студенти-Відмінники:" << endl;
    for (const auto& student : students) {
        bool allFives = true;
        for (int i = 0; i < 5; ++i) {
            if (student.marks[i] != 5) {
                allFives = false;
                break;
            }
        }
        if (allFives) {
            cout << student.lastName << " " << student.initials << endl;
        }
    }
}

// Функція для виведення списку студентів з хоча б однією трійкою
void printStudentsWithThrees(const vector<Student>& students) {
    cout << "Студенти з трійкою:" << endl;
    for (const auto& student : students) {
        for (int i = 0; i < 5; ++i) {
            if (student.marks[i] == 3) {
                cout << student.lastName << " " << student.initials << endl;
                break;
            }
        }
    }
}

// Функція для виведення списку студентів з хоча б однією двійкою
void printStudentsWithAtLeastOneTwo(const vector<Student>& students) {
    cout << "Студенти з 1 двійкою:" << endl;
    for (const auto& student : students) {
        for (int i = 0; i < 5; ++i) {
            if (student.marks[i] == 2) {
                cout << student.lastName << " " << student.initials << endl;
                break;
            }
        }
    }
}

// Функція для виведення списку студентів з більш ніж однією двійкою
void printStudentsWithMoreThanOneTwo(const vector<Student>& students) {
    cout << "Студенти з більше ніж 1 двійкою:" << endl;
    for (const auto& student : students) {
        int countTwos = 0;
        for (int i = 0; i < 5; ++i) {
            if (student.marks[i] == 2) {
                countTwos++;
            }
        }
        if (countTwos > 1) {
            cout << student.lastName << " " << student.initials << endl;
        }
    }
}

// Функція для вилучення даних про студентів з більш ніж однією двійкою
void removeStudentsWithMoreThanOneTwo(vector<Student>& students) {
    students.erase(remove_if(students.begin(), students.end(), [](const Student& student) {
        int countTwos = 0;
        for (int i = 0; i < 5; ++i) {
            if (student.marks[i] == 2) {
                countTwos++;
            }
        }
        return countTwos > 1;
        }), students.end());
}

int main() {
    vector<Student> students;
    string filename;

    cout << "Шлях до файлу: ";
    cin >> filename;

    readDataFromFile(filename, students);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Додати студента\n";
        cout << "2. Всі студенти\n";
        cout << "3. Студенти-Відмінники\n";
        cout << "4. Студенти з трійкою\n";
        cout << "5. Студенти з 1 двійкою\n";
        cout << "6. Студенти з більше ніж 1 двійкою\n";
        cout << "7. Видалити студентів з двома або більше 2\n";
        cout << "8. Завершити роботу\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students);
            writeDataToFile(filename, students); // Записуємо дані у файл після додавання студента
            break;
        case 2:
            if (students.empty()) {
                cout << "Нема студентів.\n";
            }
            else {
                printAllStudents(students);
            }
            break;
        case 3:
            if (students.empty()) {
                cout << "Нема студентів.\n";
            }
            else {
                printStudentsWithAllFives(students);
            }
            break;
        case 4:
            if (students.empty()) {
                cout << "Нема студентів.\n";
            }
            else {
                printStudentsWithThrees(students);
            }
            break;
        case 5:
            if (students.empty()) {
                cout << "Нема студентів.\n";
            }
            else {
                printStudentsWithAtLeastOneTwo(students);
            }
            break;
        case 6:
            if (students.empty()) {
                cout << "Нема студентів.\n";
            }
            else {
                printStudentsWithMoreThanOneTwo(students);
            }
            break;
        case 7:
            if (students.empty()) {
                cout << "Нема студентів.\n";
            }
            else {
                removeStudentsWithMoreThanOneTwo(students);
                writeDataToFile(filename, students); // Записуємо дані у файл після видалення студентів
                cout << "Студентів з двійками-видалено.\n";
            }
            break;
        case 8:
            cout << "Вихід.\n";
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 8);

    return 0;
}