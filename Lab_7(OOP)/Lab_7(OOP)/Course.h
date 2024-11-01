#pragma once
#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
public:
    std::string courseName;
    int hours;
    int studentCount;
    double averageGrade;

    // Конструктор
    Course(std::string name, int hrs, int count, double avg);
};

// Функції для роботи з курсами
Course* findHighestAverageGrade(Course courses[], int size);
void sortCoursesByHours(Course courses[], int size);
void printCoursesWithMoreThan30Students(Course courses[], int size);

#endif // COURSE_H
