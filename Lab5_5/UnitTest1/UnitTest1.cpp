#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_5/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Тест 1: Перевірка на правильність для вартості відправлення 0.
			Assert::AreEqual(countWays(0, 1, 2, 3, 1, 0), 1);

			// Тест 2: Перевірка на правильність для вартості відправлення 5 з марками 1, 2, 3.
			Assert::AreEqual(countWays(5, 1, 2, 3, 1, 0), 13);

			// Тест 3: Перевірка на правильність для вартості відправлення 10 з марками 1, 2, 3.
			Assert::AreEqual(countWays(10, 1, 2, 3, 1, 0), 274);
		}
	};
}
