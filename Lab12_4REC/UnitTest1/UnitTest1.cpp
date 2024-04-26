#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_4REC/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        // Тест для перевірки методу isSorted()
        TEST_METHOD(IsSortedTest)
        {
            CircularLinkedList myList;

            // Створюємо впорядкований за неспаданням список
            myList.append(1);
            myList.append(2);
            myList.append(3);
            myList.append(4);
            Assert::IsTrue(myList.isSorted()); // Очікуємо, що список впорядкований за неспаданням

            // Додаємо елемент, щоб порушити порядок
            myList.append(0);
            Assert::IsFalse(myList.isSorted()); // Очікуємо, що список НЕ впорядкований за неспаданням
        }
	};
}
