#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_14(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        // Тест для рефлексивності
        TEST_METHOD(TestIsReflexive)
        {
            std::vector<std::vector<int>> edges1 = { {1, 1}, {2, 2}, {3, 3} };
            std::vector<std::vector<int>> edges2 = { {1, 2}, {2, 3} };
            int n = 3;

            Assert::IsTrue(isReflexive(edges1, n)); // Всі вершини мають петлі
            Assert::IsTrue(isReflexive(edges2, n)); // Вершини 1 і 3 не мають петель
        }

        // Тест для транзитивності
        TEST_METHOD(TestIsTransitive)
        {
            std::vector<std::vector<int>> edges1 = { {1, 2}, {2, 3}, {1, 3} };
            std::vector<std::vector<int>> edges2 = { {1, 2}, {2, 3} };
            std::vector<std::vector<int>> edges3 = { {1, 2}, {3, 1} };

            Assert::IsTrue(isTransitive(edges1)); // Транзитивне, оскільки (1, 2) та (2, 3) => (1, 3)
            Assert::IsFalse(isTransitive(edges2)); // Не транзитивне, бо (1, 2) та (2, 3) без (1, 3)
            Assert::IsFalse(isTransitive(edges3)); // Не транзитивне, бо (1, 2) та (3, 1) не утворюють прямий зв'язок
        }
	};
}
