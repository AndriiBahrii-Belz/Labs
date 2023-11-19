#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6_1it/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

            TEST_METHOD(TestFillArray)
            {
                int myArray[23];
                fillArray(myArray);

                for (int i = 0; i < 23; ++i) {
                    Assert::IsTrue(myArray[i] >= 4 && myArray[i] <= 68);
                }
            }

            TEST_METHOD(TestProcessArray)
            {
                int myArray[23] = { 11, 64, 12, 40, 67, 11, 40, 34, 46, 36, 20, 44, 68, 16, 23, 4, 21, 22, 23, 43, 45, 11, 15 };
                int count, sum;

                processArray(myArray, count, sum);

                Assert::AreEqual(10, count);
                Assert::AreEqual(270, sum);

                for (int i = 0; i < 23; ++i) {
                    if (!(myArray[i] % 2 == 0 || myArray[i] % 13 == 0)) {
                        Assert::AreEqual(0, myArray[i]);
                    }
                }
            }
	};
}
