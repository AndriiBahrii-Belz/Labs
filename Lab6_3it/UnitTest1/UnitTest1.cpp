#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6_3it/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 5;
			int arr[size] = {-1, 2, -3, 4, -5};

			int result = countPositiveElements(arr, size);

			Assert::AreEqual(2, result);
		}
		TEST_METHOD(TestMethod2)
		{
			std::vector<int> vec = { -1, 2, -3, 4, -5 };

			int result = countPositiveElementsT(vec);

			Assert::AreEqual(2, result);
		}
	};
}
