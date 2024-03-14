#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8_1STR/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(CountTest)
        {
            // Arrange
            const string str1 = "nonono";
            const string str2 = "hello";

            // Act
            int result1 = Count(str1);
            int result2 = Count(str2);

            // Assert
            Assert::AreEqual(5, result1); // Перевіряємо, чи функція правильно обчислює кількість пар 'no' або 'on' у першому рядку
            Assert::AreEqual(0, result2); // Перевіряємо, чи функція правильно обчислює кількість пар 'no' або 'on' у другому рядку
        }

        TEST_METHOD(ChangeTest)
        {
            // Arrange
            string str1 = "nonono";
            string str2 = "hello";

            // Act
            string result1 = Change(str1);
            string result2 = Change(str2);

            // Assert
            Assert::AreEqual("*********", result1.c_str()); // Перевіряємо, чи функція правильно змінює перший рядок
            Assert::AreEqual("hello", result2.c_str()); // Перевіряємо, чи функція правильно обробляє випадок без пар 'no' або 'on'
        }
	};
}
