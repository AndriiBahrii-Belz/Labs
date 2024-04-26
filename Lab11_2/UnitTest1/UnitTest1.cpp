#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab11_2\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        // Тест для функції calculatePercentageAboveFourPointFive
        TEST_METHOD(TestCalculatePercentageAboveFourPointFive)
        {
            // Arrange
            vector<Student> students = {
                {"Surname1", 1, "Specialty1", 4.6, 4.7, 4.8},
                {"Surname2", 2, "Specialty2", 4.2, 4.3, 4.4},
                {"Surname3", 3, "Specialty3", 4.5, 4.5, 4.5},
                {"Surname4", 4, "Specialty4", 4.8, 4.8, 4.8},
                {"Surname5", 5, "Specialty5", 4.0, 4.0, 4.0}
            };

            // Act
            double percentage = calculatePercentageAboveFourPointFive(students);

            // Assert
            Assert::AreEqual(40.0, percentage); // Очікуємо, що 60% студентів мають середній бал більший за 4.5
        }
	};
}
