#include <iostream>
#include "Course.h"

int main() {
    // Створення масиву з 7 курсів
    Course courses[] = {
        Course("Математика", 40, 35, 4.5),
        Course("Фізика", 30, 28, 3.8),
        Course("Програмування", 50, 65, 4.9),
        Course("Хімія", 25, 32, 4.2),
        Course("Біологія", 35, 22, 3.9),
        Course("Економіка", 50, 40, 4.6),
        Course("Історія", 20, 60, 3.5)
    };

    // Пошук курсу з найбільшим середнім балом
    Course* highest = findHighestAverageGrade(courses, 7);
    std::cout << "Курс з найбільшим середнім балом: " << highest->courseName
        << " з середнім балом: " << highest->averageGrade << "\n";

    // Сортування курсів за кількістю годин
    sortCoursesByHours(courses, 7);
    std::cout << "\nСортовані курси за кількістю годин:\n";
    for (int i = 0; i < 7; ++i) {
        std::cout << courses[i].courseName << " - Години: " << courses[i].hours << "\n";
    }

    // Виведення курсів з кількістю студентів більше 30
    printCoursesWithMoreThan30Students(courses, 7);

    return 0;
}
