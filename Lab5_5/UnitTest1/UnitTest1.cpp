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
			// ���� 1: �������� �� ����������� ��� ������� ����������� 0.
			Assert::AreEqual(countWays(0, 1, 2, 3, 1, 0), 1);

			// ���� 2: �������� �� ����������� ��� ������� ����������� 5 � ������� 1, 2, 3.
			Assert::AreEqual(countWays(5, 1, 2, 3, 1, 0), 13);

			// ���� 3: �������� �� ����������� ��� ������� ����������� 10 � ������� 1, 2, 3.
			Assert::AreEqual(countWays(10, 1, 2, 3, 1, 0), 274);
		}
	};
}
