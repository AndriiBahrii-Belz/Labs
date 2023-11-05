#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x = 2.0;
			double expected = cos(x / 2) / (1 + pow(sin(x), 2));

			double actual = f(x);

			Assert::AreEqual(expected, actual, 0.00001);
		}
	};
}
