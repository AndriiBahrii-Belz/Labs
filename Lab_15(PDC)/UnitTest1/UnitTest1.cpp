#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_15(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    // Функція для підрахунку рішень
    int countSolutions(vector<int>& positions, int currentRow, int n) {
        if (currentRow == n) {
            return 1; // Знайдено одне рішення
        }

        int solutionsCount = 0;

        for (int col = 0; col < n; col++) {
            if (isSafe(positions, currentRow, col)) {
                positions[currentRow] = col; // Змінюємо позицію
                solutionsCount += countSolutions(positions, currentRow + 1, n);
                positions[currentRow] = -1; // Скидаємо позицію
            }
        }

        return solutionsCount;
    }

    TEST_CLASS(NQueensTests)
    {
    public:

        TEST_METHOD(TestValidPlacement)
        {
            const int n = 4;
            vector<int> positions(n, -1);
            int solutionsCount = countSolutions(positions, 0, n);
            Assert::AreEqual(2, solutionsCount); // Маємо 2 рішення для 4 ферзів
        }

        TEST_METHOD(TestInvalidPlacement)
        {
            const int n = 3;
            vector<int> positions(n, -1);
            int solutionsCount = countSolutions(positions, 0, n);
            Assert::AreEqual(0, solutionsCount); // Немає рішень для 3 ферзів
        }

        TEST_METHOD(TestEightQueens)
        {
            const int n = 8;
            vector<int> positions(n, -1);
            int solutionsCount = countSolutions(positions, 0, n);
            Assert::IsTrue(solutionsCount > 0); // Має бути більше 0 рішень для 8 ферзів
        }
	};
}
