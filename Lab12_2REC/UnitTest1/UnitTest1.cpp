#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_2REC/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(countOddValuesRecursiveTest)
        {
            Node* head = nullptr;
            Node* tail = nullptr;
            int values[] = { 10, 5, 4, 13, 20, 23, 30, 37 };
            int size = sizeof(values) / sizeof(values[0]);

            createListRecursive(head, tail, values, size);

            int result = countOddValuesRecursive(head);

            Assert::AreEqual(4, result); // Очікуємо 4 непарні значення

            // Видалення списку
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
	};
}
