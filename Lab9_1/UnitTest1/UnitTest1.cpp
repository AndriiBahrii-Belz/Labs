#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9_1/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        // Test case for calculateAverage function
        TEST_METHOD(TestCalculateAverage)
        {
            Student student;
            student.physicsGrade = 4;
            student.mathGrade = 3;
            student.thirdGrade.programming = 5;
            student.specialty = "Програмування";
            Assert::AreEqual(calculateAverage(student), 4.0f); // Modify the expected value according to your calculation
        }

        // Test case for calculateAverage function with different input
        TEST_METHOD(TestCalculateAverageDifferentInput)
        {
            Student student;
            student.physicsGrade = 5;
            student.mathGrade = 5;
            student.thirdGrade.programming = 5;
            student.specialty = "Інформатика";
            Assert::AreEqual(calculateAverage(student), 5.0f); // Modify the expected value according to your calculation
        }

        // Test case for checking the percentage of students with average grade above 4.5
        TEST_METHOD(TestPercentageAbove4_5)
        {
            // Assuming you have calculated the percentage correctly manually
            float expectedPercentage = (1.0f / 3) * 100; // Modify the expected value according to your calculation

            Student students[3];
            students[0].physicsGrade = 5;
            students[0].mathGrade = 5;
            students[0].thirdGrade.programming = 5;
            students[1].physicsGrade = 4;
            students[1].mathGrade = 4;
            students[1].thirdGrade.programming = 4;
            students[2].physicsGrade = 3;
            students[2].mathGrade = 3;
            students[2].thirdGrade.programming = 3;

            int countAbove4_5 = 0;
            for (int i = 0; i < 3; ++i) { // Assuming n is 3 for this test
                float average = calculateAverage(students[i]);
                if (average > 4.5) {
                    countAbove4_5++;
                }
            }
            float percentAbove4_5 = (static_cast<float>(countAbove4_5) / 3) * 100;

            // Check if the calculated percentage matches the expected percentage within a tolerance of 0.01
            Assert::AreEqual(expectedPercentage, percentAbove4_5, 0.01f);
        }
	};
}
