#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6_2it/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestfindLargestOddElement)
		{
			// Arrange
			const int size = 5;
			int a[size] = { 1, 2, 3, 4, 5 };

			// Act
			int result = findLargestOddElement(a, size);

			// Assert
			Assert::AreEqual(5, result);
		}
	};
}
