#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestLogicalFunction)
        {
            // Тестуємо всі можливі комбінації p, q, r
            Assert::AreEqual(logicalFunction(0, 0, 0), 0); // 0 XOR (0 AND 0) = 0
            Assert::AreEqual(logicalFunction(0, 0, 1), 0); // 0 XOR (0 AND 1) = 0
            Assert::AreEqual(logicalFunction(0, 1, 0), 0); // 0 XOR (1 AND 0) = 0
            Assert::AreEqual(logicalFunction(0, 1, 1), 1); // 0 XOR (1 AND 1) = 1
            Assert::AreEqual(logicalFunction(1, 0, 0), 1); // 1 XOR (0 AND 0) = 1
            Assert::AreEqual(logicalFunction(1, 0, 1), 1); // 1 XOR (0 AND 1) = 1
            Assert::AreEqual(logicalFunction(1, 1, 0), 1); // 1 XOR (1 AND 0) = 1
            Assert::AreEqual(logicalFunction(1, 1, 1), 0); // 1 XOR (1 AND 1) = 0
        }
	};
}
