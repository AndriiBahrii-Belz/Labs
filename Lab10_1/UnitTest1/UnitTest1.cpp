#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab10_1\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCountNeighborPairs)
        {
            // Створюємо тестовий файл з вмістом "hello on monday"
            std::ofstream testFile("test.txt");
            testFile << "hello on monday";
            testFile.close();

            // Перевіряємо, чи функція countNeighborPairs правильно підраховує пари
            Assert::AreEqual(2, countNeighborPairs("test.txt"));

            // Видаляємо тестовий файл після виконання тесту
            std::remove("test.txt");
        }
	};
}
