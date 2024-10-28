#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestTask1)
        {
            // ��������������� ����������� ���� ������ � �����
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            // �������� task1
            task1();

            // ³��������� ����
            std::cout.rdbuf(oldCout);

            // ���������� ���������
            std::string expectedOutput =
                "�������� 1: ������� A x C x A:\n"
                "{a, 0, a}\n{a, 0, b}\n{a, 0, c}\n"
                "{a, 1, a}\n{a, 1, b}\n{a, 1, c}\n"
                "{b, 0, a}\n{b, 0, b}\n{b, 0, c}\n"
                "{b, 1, a}\n{b, 1, b}\n{b, 1, c}\n"
                "{c, 0, a}\n{c, 0, b}\n{c, 0, c}\n"
                "{c, 1, a}\n{c, 1, b}\n{c, 1, c}\n\n";

            // ��������� ���� ������ � ���������� �����������
            Assert::AreEqual(expectedOutput, buffer.str(), L"��������� task1() �� ������� � ����������");
        }

        TEST_METHOD(TestTask2)
        {
            // ��������������� ����������� ���� ������ � �����
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            // �������� task2
            task2();

            // ³��������� ����
            std::cout.rdbuf(oldCout);

            // ���������� ���������
            std::string expectedOutput =
                "�������� 2: ������� A: 00011011\n"
                "������� B: 00100110\n"
                "A \\ (A ? B): ������� A ��� ��������, �� � � A ? B: 00011001\n"
                "A ? B: ��'������� ������ A �� B: 00111111\n"
                "A \\ B: ������� A ��� ��������, �� � � B: 00011001\n"
                "A ? B: ���������� ������ ������ A �� B: 00111101\n";

            // ��������� ���� ������ � ���������� �����������
            Assert::AreEqual(expectedOutput, buffer.str(), L"��������� task2() �� ������� � ����������");
        }
	};
}
