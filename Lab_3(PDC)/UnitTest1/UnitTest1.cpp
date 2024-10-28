#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestFactorial)
        {
            Assert::AreEqual((unsigned long long)1, factorial(0));
            Assert::AreEqual((unsigned long long)1, factorial(1));
            Assert::AreEqual((unsigned long long)2, factorial(2));
            Assert::AreEqual((unsigned long long)6, factorial(3));
            Assert::AreEqual((unsigned long long)24, factorial(4));
            Assert::AreEqual((unsigned long long)120, factorial(5));
            Assert::AreEqual((unsigned long long)720, factorial(6));
            Assert::AreEqual((unsigned long long)5040, factorial(7));
            Assert::AreEqual((unsigned long long)40320, factorial(8));
            Assert::AreEqual((unsigned long long)362880, factorial(9));
        }

        TEST_METHOD(TestArrangements)
        {
            Assert::AreEqual((unsigned long long)3024, arrangements(9, 4)); // 9 * 8 * 7 * 6
            Assert::AreEqual((unsigned long long)60, arrangements(5, 3)); // 5 * 4 * 3
            Assert::AreEqual((unsigned long long)24, arrangements(4, 5));   // More r than n
        }

        TEST_METHOD(TestStirlingSecondKind)
        {
            vector<vector<unsigned long long>> stirling = stirling_second_kind(5);
            Assert::AreEqual((unsigned long long)1, stirling[0][0]); // S(0,0) = 1
            Assert::AreEqual((unsigned long long)1, stirling[1][1]); // S(1,1) = 1
            Assert::AreEqual((unsigned long long)1, stirling[2][1]); // S(2,1) = 1
            Assert::AreEqual((unsigned long long)3, stirling[3][2]); // S(3,2) = 3
            Assert::AreEqual((unsigned long long)25, stirling[5][3]); // S(5,3) = 25
        }

        TEST_METHOD(TestBellNumbers)
        {
            vector<unsigned long long> bell = bell_numbers(5);
            Assert::AreEqual((unsigned long long)1, bell[0]); // B(0) = 1
            Assert::AreEqual((unsigned long long)1, bell[1]); // B(1) = 1
            Assert::AreEqual((unsigned long long)2, bell[2]); // B(2) = 2
            Assert::AreEqual((unsigned long long)5, bell[3]); // B(3) = 5
            Assert::AreEqual((unsigned long long)52, bell[5]); // B(5) = 52
        }
	};
}
