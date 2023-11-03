#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_0/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int f;
			f = sum(6, 4, 2);
			Assert::AreEqual(f, 12);
		}
	};
}
