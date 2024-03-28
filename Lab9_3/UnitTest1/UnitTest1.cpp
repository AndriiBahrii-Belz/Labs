#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9_3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{

    public:
        TEST_METHOD(TestAddStudent)
        {
            vector<Student> students;
            Student testStudent;
            testStudent.lastName = "Doe";
            testStudent.initials = "J.";
            testStudent.grades[0] = 5;
            testStudent.grades[1] = 4;
            testStudent.grades[2] = 3;
            testStudent.grades[3] = 5;
            testStudent.grades[4] = 4;

            addStudent(students);

            Assert::AreEqual(students.size(), (size_t)1); // Перевірка, чи доданий студент
            Assert::AreEqual(students[0].lastName, testStudent.lastName); // Перевірка прізвища
            Assert::AreEqual(students[0].initials, testStudent.initials); // Перевірка ініціалів
            for (int i = 0; i < 5; ++i) {
                Assert::AreEqual(students[0].grades[i], testStudent.grades[i]); // Перевірка оцінок
            }
        }
    };
}
