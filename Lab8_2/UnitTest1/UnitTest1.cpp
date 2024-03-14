#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8_2/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestMaxDigitsInSequence)
        {
            // Test cases
            Assert::AreEqual((size_t)6, MaxDigitsInSequence("abc123456def")); // Expected result: 3 (for "123")
            Assert::AreEqual((size_t)9, MaxDigitsInSequence("123456789")); // Expected result: 4 (for "1234")
            Assert::AreEqual((size_t)0, MaxDigitsInSequence("abcdefg")); // Expected result: 1 (no digits)
            Assert::AreEqual((size_t)0, MaxDigitsInSequence("")); // Expected result: 0 (empty string)
            Assert::AreEqual((size_t)2, MaxDigitsInSequence("12a34b56c")); // Expected result: 3 (for "123")
        }
	};
}
