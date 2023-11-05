#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_2/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x = 1.0;
			double eps = 0.00000001;
			int n = 0;
			double s = 0;
			double expected = cos(x);
			double actual = S(x, eps, n, s);
			Assert::AreEqual(expected, actual, eps);
		}
	};
}
