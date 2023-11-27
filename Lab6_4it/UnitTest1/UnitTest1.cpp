#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6_4it/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(ProductNegativeElementsTest)
        {
            const int size = 5;
            double arr[size] = { -2.0, 3.0, -4.0, 5.0, -6.0 };

            double result = productNegativeElements(arr, size);

            Assert::AreEqual(-48.0, result, L"Product of negative elements is incorrect");
        }

        TEST_METHOD(SumPositiveElementsBeforeMaxTest)
        {
            const int size = 6;
            double arr[size] = { 2.0, -1.0, 4.0, 3.0, 6.0, 5.0 };

            double result = sumPositiveElementsBeforeMax(arr, size);

            Assert::AreEqual(9.0, result, L"Sum of positive elements before max is incorrect");
        }

        TEST_METHOD(ReverseEvenElementsTest)
        {
            const int size = 6;
            double arr[size] = { 2.0, -1.0, 4.0, 3.0, 6.0, 5.0 };

            reverseEvenElements(arr, size);

            double expected[size] = { 2.0, 5.0, 4.0, 3.0, 6.0, -1.0 };
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(expected[i], arr[i], L"Reverse of even elements is incorrect");
            }
        }
	};
}