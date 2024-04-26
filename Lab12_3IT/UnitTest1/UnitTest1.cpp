#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_3IT/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCreateListWithDuplicates)
		{
			// Arrange
			int values[] = { 1, 2, 3, 4, 5 }; // вхідний масив
			int size = sizeof(values) / sizeof(values[0]); // розмір масиву
			int duplicateValue = 0; // значення для дублювання

			// Act
			Node* head = createList(values, size, duplicateValue);

			// Assert
			Node* current = head;
			int i = 0;
			while (current != nullptr && i < size) {
				Assert::AreEqual(values[i], current->data); // перевірка значення елемента з вхідного масиву
				current = current->next;
				if (current != nullptr) {
					Assert::AreEqual(duplicateValue, current->data); // перевірка значення елемента, який є дублікатом
					current = current->next;
				}
				i++;
			}

			// Cleanup
			deleteList(head);
		}
	};
}
