#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_3REC/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
        // Тест для функції Create
        TEST_METHOD(TestCreate)
        {
            const int rowCount = 3;
            const int colCount = 3;
            const int Low = -17;
            const int High = 15;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            Create(a, rowCount, colCount, Low, High, 0, 0);

            // Перевірка, чи всі елементи матриці знаходяться у відповідному діапазоні
            bool isInRange = true;
            for (int i = 0; i < rowCount; ++i) {
                for (int j = 0; j < colCount; ++j) {
                    if (a[i][j] < Low || a[i][j] > High) {
                        isInRange = false;
                        break;
                    }
                }
            }
            Assert::IsTrue(isInRange);

            // Очищення пам'яті
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }

        // Тест для функції Part1_Count
        TEST_METHOD(TestPart1_Count)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Заповнення матриці таким чином, щоб кожен рядок містив принаймні один нуль
            a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
            a[1][0] = 4; a[1][1] = 0; a[1][2] = 6;
            a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

            int count = Part1_Count(a, rowCount, colCount, 0, 0);

            Assert::AreEqual(count, 2);

            // Очищення пам'яті
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }

        // Тест для функції Part2_MaxRepeat
        TEST_METHOD(TestPart2_MaxRepeat)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Заповнення матриці для тестування
            a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
            a[1][0] = 4; a[1][1] = 4; a[1][2] = 6;
            a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

            int maxRepeat = 0;
            int maxNumber = 0;
            Part2_MaxRepeat(a, rowCount, colCount ,0, 0, a[0][0], maxRepeat, maxNumber, 0, 0, 0);

            Assert::AreEqual(maxRepeat, 1);
            Assert::AreEqual(maxNumber, 1);

            // Очищення пам'яті
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
	};
}
