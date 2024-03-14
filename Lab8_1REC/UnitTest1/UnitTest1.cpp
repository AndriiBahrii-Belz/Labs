#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8_1REC/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(CountTest)
        {
            const char* str = "nonono";
            int count = Count(str, 0);
            Assert::AreEqual(3, count);
        }

        TEST_METHOD(ChangeTest)
        {
            const char* str = "nonono";
            char dest[20]; // Змінна призначена для зберігання результату зміни
            char* modified = Change(str, dest, 0);
            Assert::AreEqual("***", modified); // Перевіряємо, чи змінений рядок правильно
        }
    };
   }