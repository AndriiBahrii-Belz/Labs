#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6_2rec/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestfindLargestOddElementRecursive)
		{
			// Arrange
			const int size = 5;
			int arr[size] = { 1, 2, 3, 4, 5 };

			// Act
			int result = findLargestOddElementRecursive(arr, size, 1);

			// Assert
			Assert::AreEqual(5, result);
		}
	};
}
