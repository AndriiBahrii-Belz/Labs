#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8_1IT/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCount)
        {
            // Arrange
            const char* str = "no one knows not";

            // Act
            int count = Count(str);

            // Assert
            Assert::AreEqual(4, count);
        }

        TEST_METHOD(TestChange)
        {
            // Arrange
            const char* str = "no one knows not";

            // Act
            char* result = Change(str);

            // Assert
            Assert::AreEqual("*** ***e k***ws ***", result);

            // Clean up
            delete[] result;
        }
	};
}
