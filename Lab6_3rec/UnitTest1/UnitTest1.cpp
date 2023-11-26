#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6_3rec/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod)
		{
			// Arrange
			const int size = 5;
			int arr[size] = { 1, -2, 3, -4, 5 };

			// Act
			int result = countPositiveElementsRecursive(arr, size, 0);

			// Assert
			Assert::AreEqual(3, result);
		}

		TEST_METHOD(TestMethodT)
		{
			// Arrange
			std::vector<int> vec = { 1, -2, 3, -4, 5 };

			// Act
			int result = countPositiveElementsT(vec, 0);

			// Assert
			Assert::AreEqual(3, result);
		}
	};
}
