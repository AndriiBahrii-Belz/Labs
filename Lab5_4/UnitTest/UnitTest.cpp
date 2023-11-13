#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_4/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int K = 2;
			int N = 6;
			double expected = 0.0;
			for (int i = K; i <= N; i++) {
				expected += (sin(i) * cos(i)) / (1.0 + pow(sin(i), 2));
			}
			Assert::AreEqual(S0(K, N), expected);

			int i = K;
			Assert::AreEqual(S1(K, N, i), expected);

			i = N;
			Assert::AreEqual(S2(K, N, i), expected);

			i = K;
			double t = 0.0;
			Assert::AreEqual(S3(K, N, i, t), expected);

			i = N;
			t = 0.0;
			Assert::AreEqual(S4(K, N, i, t), expected);
		}
	};
}
