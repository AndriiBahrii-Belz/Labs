#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8_1CHAR/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(ContainsPairsTest)
        {
            // Arrange
            const char* str1 = "nonono";
            const char* str2 = "hello";

            // Act
            bool result1 = ContainsPairs(str1);
            bool result2 = ContainsPairs(str2);

            // Assert
            Assert::IsTrue(result1); // ����������, �� ������� ��������� ������� ���� 'no' ��� 'on' � ������� �����
            Assert::IsFalse(result2); // ����������, �� ������� ��������� ������� ��������� ��� 'no' ��� 'on' � ������� �����
        }

        TEST_METHOD(ChangeTest)
        {
            // Arrange
            char str1[] = "nonono";
            char str2[] = "hello";

            // Act
            char* result1 = Change(str1);
            char* result2 = Change(str2);

            // Assert
            Assert::AreEqual("*********", result1); // ����������, �� ������� ��������� ����� ������ �����
            Assert::AreEqual("hello", result2); // ����������, �� ������� ��������� �������� ������� ��� ��� 'no' ��� 'on'
        }
	};
}
