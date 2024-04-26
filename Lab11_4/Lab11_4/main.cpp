#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    string surname;
    string initials;
    int grades[5];

    Student() : grades{} {} // Ініціалізувати всі елементи масиву grades нулями
};

void Create(vector<Student>& students);
void Print(const vector<Student>& students);
void AddStudent(vector<Student>& students);
void DeleteStudent(vector<Student>& students);
void EditStudent(vector<Student>& students);
void ListPerfectStudents(const vector<Student>& students);
void ListStudentsWithThrees(const vector<Student>& students);
void ListStudentsWithTwos(const vector<Student>& students);

int main()
{
    vector<Student> students;

    int MenuItem;

    while (true)
    {
        cout << "Choose an action:" << endl;
        cout << " 1 - Create a list of students" << endl;
        cout << " 2 - Display the list of students" << endl;
        cout << " 3 - Add a student" << endl;
        cout << " 4 - Delete a student" << endl;
        cout << " 5 - Edit student information" << endl;
        cout << " 6 - List of students with all '5' grades" << endl;
        cout << " 7 - List of students with '3' grades" << endl;
        cout << " 8 - List of students with '2' grades (no more than one '2')" << endl;
        cout << " 0 - Exit the program" << endl;
        cout << "Enter: ";
        cin >> MenuItem;
        cout << endl;

        switch (MenuItem)
        {
        case 1:
            Create(students);
            break;
        case 2:
            Print(students);
            break;
        case 3:
            AddStudent(students);
            break;
        case 4:
            DeleteStudent(students);
            break;
        case 5:
            EditStudent(students);
            break;
        case 6:
            ListPerfectStudents(students);
            break;
        case 7:
            ListStudentsWithThrees(students);
            break;
        case 8:
            ListStudentsWithTwos(students);
            break;
        }

        if (MenuItem == 0)
            break;
    }

    return 0;
}

void Create(vector<Student>& students)
{
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    students.resize(N);

    for (int i = 0; i < N; i++)
    {
        cout << "Student number: " << i + 1 << endl;
        cout << "Surname: ";
        cin >> students[i].surname;
        cout << "Initials: ";
        cin >> students[i].initials;
        cout << "Grades for 5 subjects: ";
        for (int j = 0; j < 5; j++)
        {
            cin >> students[i].grades[j];
        }
        cout << endl;
    }
}

void Print(const vector<Student>& students)
{
    cout << "===================================================================================================" << endl;
    cout << "| № |   Surname   |  Initials  |   Grades   |   Grades   |   Grades   |   Grades   |   Grades   |" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;

    for (size_t i = 0; i < students.size(); i++)
    {
        cout << "|" << setw(4) << right << i + 1 << " ";
        cout << "|" << setw(12) << left << students[i].surname;
        cout << "|" << setw(11) << left << students[i].initials;
        for (int j = 0; j < 5; j++)
        {
            cout << "|" << setw(11) << left << students[i].grades[j];
        }
        cout << setw(6) << "|" << endl;
    }
    cout << "===================================================================================================" << endl << endl;
}

void AddStudent(vector<Student>& students)
{
    Student newStudent;

    cout << "Enter the information for the new student:" << endl;
    cout << "Surname: ";
    cin >> newStudent.surname;
    cout << "Initials: ";
    cin >> newStudent.initials;
    cout << "Grades for 5 subjects: ";
    for (int j = 0; j < 5; j++)
    {
        cin >> newStudent.grades[j];
    }
    students.push_back(newStudent);
}

void DeleteStudent(vector<Student>& students)
{
    int index;
    cout << "Enter the index of the student to delete: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(students.size()))
    {
        students.erase(students.begin() + index - 1);
    }
    else
    {
        cout << "Invalid index!" << endl;
    }
}

void EditStudent(vector<Student>& students)
{
    int index;
    cout << "Enter the index of the student to edit: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(students.size()))
    {
        cout << "Enter the new information for the student:" << endl;
        cout << "Surname: ";
        cin >> students[index - 1].surname;
        cout << "Initials: ";
        cin >> students[index - 1].initials;
        cout << "Grades for 5 subjects: ";
        for (int j = 0; j < 5; j++)
        {
            cin >> students[index - 1].grades[j];
        }
    }
    else
    {
        cout << "Invalid index!" << endl;
    }
}

void ListPerfectStudents(const vector<Student>& students)
{
    cout << "List of students with all '5' grades:" << endl;
    for (const auto& student : students)
    {
        if (all_of(begin(student.grades), end(student.grades), [](int grade) { return grade == 5; }))
        {
            cout << student.surname << " " << student.initials << endl;
        }
    }
}

void ListStudentsWithThrees(const vector<Student>& students)
{
    cout << "List of students with '3' grades:" << endl;
    for (const auto& student : students)
    {
        if (any_of(begin(student.grades), end(student.grades), [](int grade) { return grade == 3; }))
        {
            cout << student.surname << " " << student.initials << endl;
        }
    }
}

void ListStudentsWithTwos(const vector<Student>& students)
{
    cout << "List of students with '2' grades (no more than one '2'):" << endl;
    for (const auto& student : students)
    {
        if (count(begin(student.grades), end(student.grades), 2) == 1 &&
            all_of(begin(student.grades), end(student.grades), [](int grade) { return grade >= 2; }))
        {
            cout << student.surname << " " << student.initials << endl;
        }
    }
}