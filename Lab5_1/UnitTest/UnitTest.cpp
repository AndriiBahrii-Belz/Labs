#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_1/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//Arrange
			double a = 2.0;
			double b = 4.0;
			double expected = pow(a, 2) - pow(b, 2);
			//Act
			double actual = h(a, b);
			//Assert
			Assert::AreEqual(expected, actual);
		}
	};
}
