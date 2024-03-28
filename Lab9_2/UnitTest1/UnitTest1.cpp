#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9_2/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        // Тест для функції compareStudents
        TEST_METHOD(TestCompareStudents)
        {
            // Arrange
            Student s1, s2;
            s1.lastName = "Smith";
            s1.course = 2;
            s1.specialty = "Computer Science";

            s2.lastName = "Johnson";
            s2.course = 3;
            s2.specialty = "Computer Science";

            // Act
            bool result = compareStudents(s1, s2);

            // Assert
            Assert::IsTrue(result); // Очікуємо, що студент s1 буде перед студентом s2 через прізвище
        }

        // Тест для функції binarySearchStudent
        TEST_METHOD(TestBinarySearchStudent)
        {
            // Arrange
            vector<Student> students;
            Student s1, s2;
            s1.lastName = "Smith";
            s1.specialty = "Computer Science";
            s1.course = 2;

            s2.lastName = "Johnson";
            s2.specialty = "Computer Science";
            s2.course = 3;

            students.push_back(s1);
            students.push_back(s2);

            // Act
            bool result = binarySearchStudent(students, "Johnson", "Computer Science", 3);

            // Assert
            Assert::IsTrue(result); // Очікуємо, що студент s2 буде знайдений
        }
	};
}
