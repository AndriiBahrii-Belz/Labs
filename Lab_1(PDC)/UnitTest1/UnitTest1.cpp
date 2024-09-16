#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        // Тест для функції імплікації
        TEST_METHOD(TestImplication)
        {
            Assert::AreEqual(implication(true, true), true);
            Assert::AreEqual(implication(true, false), false);
            Assert::AreEqual(implication(false, true), true);
            Assert::AreEqual(implication(false, false), true);
        }

        // Тест для порозрядної операції OR
        TEST_METHOD(TestBitwiseOR)
        {
            string a = "1100011100";
            string b = "1010101110";
            string expected_or = "1110111110";

            string result_or = "";
            for (int i = 0; i < a.length(); i++) {
                result_or += (a[i] == '1' || b[i] == '1') ? '1' : '0';
            }

            Assert::AreEqual(expected_or, result_or);
        }

        // Тест для порозрядної операції AND
        TEST_METHOD(TestBitwiseAND)
        {
            string a = "1100011100";
            string b = "1010101110";
            string expected_and = "1000001100";

            string result_and = "";
            for (int i = 0; i < a.length(); i++) {
                result_and += (a[i] == '1' && b[i] == '1') ? '1' : '0';
            }

            Assert::AreEqual(expected_and, result_and);
        }

        // Тест для порозрядної операції XOR
        TEST_METHOD(TestBitwiseXOR)
        {
            string a = "1100011100";
            string b = "1010101110";
            string expected_xor = "0110110010";

            string result_xor = "";
            for (int i = 0; i < a.length(); i++) {
                result_xor += (a[i] != b[i]) ? '1' : '0';
            }

            Assert::AreEqual(expected_xor, result_xor);
        }

        // Тест для еквівалентності
        TEST_METHOD(TestEquivalence)
        {
            bool p = true, q = false;
            bool expected = false;  // Еквівалентність (p <-> q) для true та false має бути false
            bool result = implication(p, q) && implication(q, p);

            Assert::AreEqual(expected, result);
        }

        // Тест для кон'юнкції (AND)
        TEST_METHOD(TestConjunction)
        {
            bool p = true, q = false;
            bool expected = false;  // Кон'юнкція true AND false має бути false
            bool result = p && q;

            Assert::AreEqual(expected, result);
        }

        // Тест для диз'юнкції (OR)
        TEST_METHOD(TestDisjunction)
        {
            bool p = true, q = false;
            bool expected = true;  // Диз'юнкція true OR false має бути true
            bool result = p || q;

            Assert::AreEqual(expected, result);
        }

        // Тест для альтернативного "або" (XOR)
        TEST_METHOD(TestXOR)
        {
            bool p = true, q = false;
            bool expected = true;  // Альтернативне "або" для true та false має бути true
            bool result = p != q;

            Assert::AreEqual(expected, result);
        }

	};
}
