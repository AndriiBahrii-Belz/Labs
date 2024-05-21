#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab12_5\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestStackManipulation)
        {
            stack<int> originalStack;
            string filename = "C:\\Users\\andri\\Desktop\\Stack.txt"; // Ім'я файлу з даними
            readStackFromFile(originalStack, filename);

            int n = 3;
            int m = 1;

            stack<int> copiedStack = copyGroup(originalStack, n);

            removeGroup(copiedStack, m);

            Assert::AreEqual(37, copiedStack.top()); // Перевірка, що вершина стеку містить правильне значення після видалення елементів
            copiedStack.pop();
            Assert::AreEqual(39, copiedStack.top()); // Перевірка, що наступна за вершиною стеку містить правильне значення після видалення елементів
        }
	};
}
