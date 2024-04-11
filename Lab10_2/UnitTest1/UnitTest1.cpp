#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab10_2\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestFindMaxConsecutiveDigits)
		{
			// Створюємо тестовий файл
			std::ofstream file("testfile.txt");
			file << "123abc45de6789fg0";
			file.close();

			// Викликаємо функцію, яку ми хочемо протестувати
			int result = findMaxConsecutiveDigits("testfile.txt");

			// Перевіряємо, чи результат співпадає з очікуваним значенням
			Assert::AreEqual(4, result);
		}
	};
}
