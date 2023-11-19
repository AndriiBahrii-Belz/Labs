#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6_1rec/main.cpp"

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

            TEST_METHOD(TestRecursiveProcessArray)
            {
                int myArray[23] = { 51, 18, 61, 54, 38, 52, 64, 53, 46, 15, 33, 52, 11, 58, 65, 66, 65, 65, 20, 11, 42, 28, 29 };
                int count = 0, sum = 0;

                processArrayRecursive(myArray, 0, count, sum);

                Assert::AreEqual(8, count);
                Assert::AreEqual(264, sum);

                for (int i = 0; i < 23; ++i) {
                    if (!(myArray[i] % 2 == 0 || myArray[i] % 13 == 0)) {
                        Assert::AreEqual(0, myArray[i]);
                    }
                }
            }
	};      
}
