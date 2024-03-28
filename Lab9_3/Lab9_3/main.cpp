#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string lastName;
    string initials;
    int grades[5];
};

// Функція для додавання студента до списку
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter last name: ";
    cin >> newStudent.lastName;
    cout << "Enter initials: ";
    cin >> newStudent.initials;
    cout << "Enter grades for 5 subjects: ";
    for (int i = 0; i < 5; ++i) {
        cin >> newStudent.grades[i];
    }
    students.push_back(newStudent);
}

// Функція для вилучення студента із списку за прізвищем
void removeStudent(vector<Student>& students, const string& lastName) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->lastName == lastName) {
            students.erase(it);
            break;
        }
    }
}

// Функція для редагування інформації про студента за прізвищем
void editStudent(vector<Student>& students, const string& lastName) {
    for (auto& student : students) {
        if (student.lastName == lastName) {
            cout << "Enter new last name: ";
            cin >> student.lastName;
            cout << "Enter new initials: ";
            cin >> student.initials;
            cout << "Enter new grades for 5 subjects: ";
            for (int i = 0; i < 5; ++i) {
                cin >> student.grades[i];
            }
            break;
        }
    }
}

// Функція для зчитування списку студентів із файлу
void readStudentsFromFile(vector<Student>& students, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        students.clear(); // Очистимо поточний список перед зчитуванням
        while (!file.eof()) {
            Student student;
            file >> student.lastName >> student.initials;
            for (int i = 0; i < 5; ++i) {
                file >> student.grades[i];
            }
            students.push_back(student);
        }
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

// Функція для запису списку студентів у файл
void writeStudentsToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.lastName << " " << student.initials << " ";
            for (int i = 0; i < 5; ++i) {
                file << student.grades[i] << " ";
            }
            file << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

// Функція для отримання списку всіх студентів
void getAllStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << student.lastName << " " << student.initials << endl;
    }
}

// Функція для отримання списку студентів з оцінками "5"
void getStudentsWithFives(const vector<Student>& students) {
    for (const auto& student : students) {
        bool allFives = true;
        for (int i = 0; i < 5; ++i) {
            if (student.grades[i] != 5) {
                allFives = false;
                break;
            }
        }
        if (allFives) {
            cout << student.lastName << " " << student.initials << endl;
        }
    }
}

// Функція для отримання списку студентів з трійками
void getStudentsWithThrees(const vector<Student>& students) {
    for (const auto& student : students) {
        for (int i = 0; i < 5; ++i) {
            if (student.grades[i] == 3) {
                cout << student.lastName << " " << student.initials << endl;
                break;
            }
        }
    }
}

// Функція для отримання списку студентів з двійками (без більше однієї двійки)
void getStudentsWithTwos(const vector<Student>& students) {
    for (const auto& student : students) {
        int countTwos = 0;
        for (int i = 0; i < 5; ++i) {
            if (student.grades[i] == 2) {
                countTwos++;
                if (countTwos > 1) {
                    break;
                }
            }
        }
        if (countTwos == 1) {
            cout << student.lastName << " " << student.initials << endl;
        }
    }
}

int main() {
    vector<Student> students;
    string filename;

    cout << "Enter filename: ";
    cin >> filename;

    readStudentsFromFile(students, filename);

    // Взаємодія з користувачем через меню
    int choice;
    do {
        cout << "\n1. Add student\n";
        cout << "2. Remove student\n";
        cout << "3. Edit student\n";
        cout << "4. Get list of all students\n";
        cout << "5. Get list of students with all '5' grades\n";
        cout << "6. Get list of students with '3' grades\n";
        cout << "7. Get list of students with only one '2' grade\n";
        cout << "8. Save and exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2: {
            string lastName;
            cout << "Enter last name of the student to remove: ";
            cin >> lastName;
            removeStudent(students, lastName);
            break;
        }
        case 3: {
            string lastName;
            cout << "Enter last name of the student to edit: ";
            cin >> lastName;
            editStudent(students, lastName);
            break;
        }
        case 4:
            getAllStudents(students);
            break;
        case 5:
            getStudentsWithFives(students);
            break;
        case 6:
            getStudentsWithThrees(students);
            break;
        case 7:
            getStudentsWithTwos(students);
            break;
        case 8:
            writeStudentsToFile(students, filename);
            cout << "Data saved successfully. Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 8);

    return 0;
}
