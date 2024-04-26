#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_3REC/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCreateListRecursive)
		{
			// Arrange
			int values[] = { 1, 2, 3, 4, 5 };
			int size = sizeof(values) / sizeof(values[0]);
			int duplicateValue = 0;

			// Act
			Node* head = createListRecursive(values, size, duplicateValue);

			// Assert
			Assert::IsNotNull(head);

			// Cleanup
			deleteListRecursive(head);
		}
	};
}
