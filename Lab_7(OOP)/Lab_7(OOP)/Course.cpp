#include "Course.h"
#include <iostream>
#include <algorithm>

// Конструктор
Course::Course(std::string name, int hrs, int count, double avg)
    : courseName(name), hours(hrs), studentCount(count), averageGrade(avg) {}

// Функція для пошуку курсу з найбільшим середнім балом
Course* findHighestAverageGrade(Course courses[], int size) {
    Course* highest = &courses[0];
    for (int i = 1; i < size; ++i) {
        if (courses[i].averageGrade > highest->averageGrade) {
            highest = &courses[i];
        }
    }
    return highest;
}

// Функція для сортування курсів за кількістю годин у порядку спадання
void sortCoursesByHours(Course courses[], int size) {
    std::sort(courses, courses + size, [](const Course& a, const Course& b) {
        return a.hours > b.hours;
        });
}

// Функція для виведення курсів з кількістю студентів більше 30
void printCoursesWithMoreThan30Students(Course courses[], int size) {
    std::cout << "Курси з кількістю студентів більше 30:\n";
    for (int i = 0; i < size; ++i) {
        if (courses[i].studentCount > 30) {
            std::cout << courses[i].courseName << " - Студенти: " << courses[i].studentCount
                << ", Години: " << courses[i].hours << ", Середній бал: " << courses[i].averageGrade << "\n";
        }
    }
}
