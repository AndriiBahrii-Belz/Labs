#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_2IT/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
			TEST_METHOD(TestCreateFunction)
			{
				const int n = 3;
				const int Low = 2;
				const int High = 10;
				int** a = new int* [n];
				for (int i = 0; i < n; i++)
					a[i] = new int[n];

				Create(a, n, Low, High);

				// Перевірка, що всі елементи матриці знаходяться в заданому діапазоні
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
					}
				}

				for (int i = 0; i < n; i++)
					delete[] a[i];
				delete[] a;
			}

			TEST_METHOD(TestSearchMaxEvenFunction)
			{
				const int n = 3;
				int** a = new int* [n];
				for (int i = 0; i < n; i++)
					a[i] = new int[n];

				// Заповнюємо матрицю заздалегідь відомими значеннями
				a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
				a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
				a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

				int maxEven;
				bool result = SearchMaxEven(a, n, maxEven);

				Assert::IsTrue(result);
				Assert::AreEqual(maxEven, 8);

				for (int i = 0; i < n; i++)
					delete[] a[i];
				delete[] a;
			}

			TEST_METHOD(TestSwapMaxEvenOnDiagonalFunction)
			{
				const int n = 3;
				int** a = new int* [n];
				for (int i = 0; i < n; i++)
					a[i] = new int[n];

				// Заповнюємо матрицю заздалегідь відомими значеннями
				a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
				a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
				a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

				SwapMaxEvenOnDiagonal(a, n);

				// Перевірка, що максимальне парне значення було переставлене на діагональ
				Assert::AreEqual(a[0][0], 2);
				Assert::AreEqual(a[1][1], 5);
				Assert::AreEqual(a[2][2], 8);

				for (int i = 0; i < n; i++)
					delete[] a[i];
				delete[] a;
			}
		};
	}

