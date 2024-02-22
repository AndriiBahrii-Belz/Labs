#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_1/Main.cpp"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(CreateTest)
        {
            const int rowCount = 8;
            const int colCount = 7;
            const int Low = -21;
            const int High = 18;

            int** testMatrix = new int* [rowCount];
            for (int i = 0; i < rowCount; ++i)
                testMatrix[i] = new int[colCount];

            Create(testMatrix, rowCount, colCount, Low, High);

            for (int i = 0; i < rowCount; ++i)
                for (int j = 0; j < colCount; ++j)
                    Assert::IsTrue(testMatrix[i][j] >= Low && testMatrix[i][j] <= High);

            for (int i = 0; i < rowCount; ++i)
                delete[] testMatrix[i];
            delete[] testMatrix;
        }
        TEST_METHOD(SortTest)
        {
            const int rowCount = 8;
            const int colCount = 7;

            int** testMatrix = new int* [rowCount];
            for (int i = 0; i < rowCount; ++i)
                testMatrix[i] = new int[colCount];

            int initialArray[] = { 5, 4, 3, 2, 1, 10, 5,
                                   10, 9, 8, 7, 6, 11, 5,
                                   1, 1, 1, 1, 1, 12, 5,
                                   10, 10, 10, 10, 10, 13, 5,
                                   5, 5, 5, 5, 5, 14, 5,
                                   5, 5, 5, 5, 5, 15, 5,
                                   5, 5, 5, 5, 5, 16, 5,
                                   5, 5, 5, 5, 5, 17, 5 };

            for (int i = 0; i < rowCount; ++i)
                for (int j = 0; j < colCount; ++j)
                    testMatrix[i][j] = initialArray[i * colCount + j];

            Sort(testMatrix, rowCount, colCount);

            for (int i = 0; i < rowCount - 1; ++i)
                Assert::IsTrue(testMatrix[i][0] >= testMatrix[i + 1][0]);

            for (int i = 0; i < rowCount - 1; ++i)
            {
                if (testMatrix[i][0] == testMatrix[i + 1][0])
                {
                    Assert::IsTrue(testMatrix[i][1] >= testMatrix[i + 1][1]);
                }
            }

            for (int i = 0; i < rowCount - 1; ++i)
            {
                if (testMatrix[i][0] == testMatrix[i + 1][0] && testMatrix[i][1] == testMatrix[i + 1][1])
                {
                    Assert::IsTrue(testMatrix[i][3] <= testMatrix[i + 1][3]);
                }
            }

            for (int i = 0; i < rowCount; ++i)
                delete[] testMatrix[i];
            delete[] testMatrix;
        }
    };
}
