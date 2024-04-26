#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

enum Specialization { COMPUTER_SCIENCE, INFORMATICS, MATH_ECONOMICS, PHYSICS_INFORMATICS, LABOR_TRAINING };

union Grade {
    int programming;
    int numerical_methods;
    int pedagogy;
};

struct Student {
    string surname;
    int course;
    Specialization specialization;
    int physics_grade;
    int math_grade;
    Grade additional_grade;
};

void CreateStudents(Student* students, const int N);
void PrintStudents(const Student* students, const int N);
void p_sort(Student* S, int N);
int* i_sort(Student* S, const int N);
void i_print(Student* S, int* I, const int N);
bool b_search(Student* S, const int N, const string surname, const Specialization specialization, const int course);

int main() {
    int MenuItem;
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    Student* students = new Student[N];

    do {
        cout << "Choose an action:" << endl;
        cout << " 1 - Enter information about students" << endl;
        cout << " 2 - Display information about students" << endl;
        cout << " 3 - Sort information physically" << endl;
        cout << " 4 - Sort information index-wise" << endl;
        cout << " 5 - Search for a student" << endl;
        cout << " 0 - Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> MenuItem;
        cout << endl;

        switch (MenuItem) {
        case 1:
            CreateStudents(students, N);
            break;
        case 2:
            PrintStudents(students, N);
            break;
        case 3:
            p_sort(students, N);
            cout << "Information sorted physically." << endl;
            break;
        case 4: {
            int* indexArray = i_sort(students, N);
            i_print(students, indexArray, N);
            delete[] indexArray;
            break;
        }
        case 5: {
            string searchSurname;
            int searchSpecialization;
            int searchCourse;

            cout << "Enter student's surname to search: ";
            cin >> searchSurname;
            cout << "Enter student's specialization (0 - Computer Science, 1 - Informatics, 2 - Math and Economics, 3 - Physics and Informatics, 4 - Labor Training): ";
            cin >> searchSpecialization;
            cout << "Enter student's course to search: ";
            cin >> searchCourse;

            bool found = b_search(students, N, searchSurname, static_cast<Specialization>(searchSpecialization), searchCourse);
            if (found)
                cout << "Student found!" << endl << endl;
            else
                cout << "Student not found!" << endl << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (MenuItem != 0);

    delete[] students;
    return 0;
}

void CreateStudents(Student* students, const int N) {
    for (int i = 0; i < N; ++i) {
        cout << "Student #" << i + 1 << ":\n";
        cout << "Surname: ";
        cin >> students[i].surname;
        cout << "Course: ";
        cin >> students[i].course;
        cout << "Specialization (0 - Computer Science, 1 - Informatics, 2 - Math and Economics, 3 - Physics and Informatics, 4 - Labor Training): ";
        int specialization;
        cin >> specialization;
        students[i].specialization = static_cast<Specialization>(specialization);
        cout << "Grade in Physics: ";
        cin >> students[i].physics_grade;
        cout << "Grade in Mathematics: ";
        cin >> students[i].math_grade;

        switch (students[i].specialization) {
        case COMPUTER_SCIENCE:
            cout << "Programming grade: ";
            cin >> students[i].additional_grade.programming;
            break;
        case INFORMATICS:
            cout << "Numerical methods grade: ";
            cin >> students[i].additional_grade.numerical_methods;
            break;
        default:
            cout << "Pedagogy grade: ";
            cin >> students[i].additional_grade.pedagogy;
            break;
        }
        cout << endl;
    }
}

void PrintStudents(const Student* students, const int N) {
    cout << "========================================================================================================" << endl;
    cout << "| # | Surname       | Course | Specialization               | Physics | Mathematics | Additional Grade |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "| " << setw(1) << right << i + 1 << " | ";
        cout << setw(13) << left << students[i].surname << " | ";
        cout << setw(6) << right << students[i].course << " | ";

        switch (students[i].specialization) {
        case COMPUTER_SCIENCE:
            cout << setw(28) << left << "Computer Science" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.programming << " |" << endl;
            break;
        case INFORMATICS:
            cout << setw(28) << left << "Informatics" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.numerical_methods << " |" << endl;
            break;
        case MATH_ECONOMICS:
            cout << setw(28) << left << "Math and Economics" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.pedagogy << " |" << endl;
            break;
        case PHYSICS_INFORMATICS:
            cout << setw(28) << left << "Physics and Informatics" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.numerical_methods << " |" << endl;
            break;
        case LABOR_TRAINING:
            cout << setw(28) << left << "Labor Training" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.pedagogy << " |" << endl;
            break;
        }
    }
    cout << "========================================================================================================" << endl << endl;
}

void p_sort(Student* S, const int N) {
    Student temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (S[j].specialization > S[j + 1].specialization ||
                (S[j].specialization == S[j + 1].specialization && S[j].course > S[j + 1].course) ||
                (S[j].specialization == S[j + 1].specialization && S[j].course == S[j + 1].course && S[j].surname > S[j + 1].surname)) {
                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }
}

int* i_sort(Student* S, const int N) {
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (S[I[j]].specialization > S[I[j + 1]].specialization ||
                (S[I[j]].specialization == S[I[j + 1]].specialization && S[I[j]].course > S[I[j + 1]].course) ||
                (S[I[j]].specialization == S[I[j + 1]].specialization && S[I[j]].course == S[I[j + 1]].course && S[I[j]].surname > S[I[j + 1]].surname)) {
                int temp = I[j];
                I[j] = I[j + 1];
                I[j + 1] = temp;
            }
        }
    }
    return I;
}

void i_print(Student* S, int* I, const int N) {
    cout << "==========================================================================================================" << endl;
    cout << "|  # |   Surname      |  Course |      Specialization      |  Physics |  Mathematics |  Additional Grade |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(15) << left << S[I[i]].surname;
        cout << "| " << setw(8) << right << S[I[i]].course;
        cout << "| " << setw(25) << left << S[I[i]].specialization;
        cout << "| " << setw(9) << right << S[I[i]].physics_grade;
        cout << "| " << setw(13) << right << S[I[i]].math_grade;
        cout << "| " << setw(18) << right << S[I[i]].additional_grade.programming << "|" << endl;
    }
    cout << "==========================================================================================================" << endl << endl;
}

bool b_search(Student* S, const int N, const string surname, const Specialization specialization, const int course) {
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if ((S[m].surname == surname && S[m].specialization == specialization && S[m].course == course)) {
            return true;
        }

        if ((S[m].course < course) ||
            (S[m].course == course && S[m].specialization < specialization) ||
            (S[m].course == course && S[m].specialization == specialization && S[m].surname < surname)) {
            L = m + 1;
        }
        else {
            R = m - 1;
        }
    } while (L <= R);

    return false;
}