#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestReadGraph)
        {
            // Тест на зчитування графу з файлу
            int vertexCount;
            vector<vector<int>> graph = readGraph("C:\\Users\\andri\\Desktop\\Lab_6(1).txt", vertexCount);

            // Перевіряємо, чи зчитані правильні дані
            Assert::AreEqual(4, vertexCount); // Перевіряємо кількість вершин
            Assert::AreEqual(1, graph[0][1]); // Вершина 1 має зв'язок з вершиною 2
            Assert::AreEqual(1, graph[1][2]); // Вершина 2 має зв'язок з вершиною 3
            Assert::AreEqual(1, graph[2][3]); // Вершина 3 має зв'язок з вершиною 4
            Assert::AreEqual(0, graph[3][0]); // Вершина 4 не має зв'язку з вершиною 1
        }

        TEST_METHOD(TestCalculateDegrees)
        {
            // Тест на обчислення ступенів
            vector<vector<int>> graph = {
                {0, 1, 0, 1},
                {1, 0, 1, 0},
                {0, 1, 0, 1},
                {1, 0, 1, 0}
            };

            vector<int> expectedDegrees = { 2, 2, 2, 2 }; // Очікувані ступені
            vector<int> actualDegrees(4, 0);

            // Обчислюємо ступені
            for (int i = 0; i < graph.size(); ++i) {
                for (int j = 0; j < graph[i].size(); ++j) {
                    if (graph[i][j] != 0) {
                        actualDegrees[i]++;
                    }
                }
            }

            for (int i = 0; i < expectedDegrees.size(); i++) {
                Assert::AreEqual(expectedDegrees[i], actualDegrees[i]);
            }
        }

        TEST_METHOD(TestFindPendantAndIsolatedVertices)
        {
            // Тест на знаходження висячих та ізольованих вершин
            vector<vector<int>> graph = {
                {0, 1, 0, 0},
                {1, 0, 1, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            };

            vector<int> expectedPendant = { 1 }; // Вершина 1 висячі
            vector<int> expectedIsolated = { 4 }; // Вершина 4 ізольована

            vector<int> actualPendant;
            vector<int> actualIsolated;
            vector<int> degree(4, 0);

            for (int i = 0; i < graph.size(); ++i) {
                for (int j = 0; j < graph[i].size(); ++j) {
                    if (graph[i][j] != 0) {
                        degree[i]++;
                    }
                }
                if (degree[i] == 1) {
                    actualPendant.push_back(i + 1); // +1 для коректного виводу
                }
                else if (degree[i] == 0) {
                    actualIsolated.push_back(i + 1);
                }
            }

            for (size_t i = 0; i < expectedPendant.size(); i++) {
                Assert::AreEqual(expectedPendant[i], actualPendant[i]);
            }

            for (size_t i = 0; i < expectedIsolated.size(); i++) {
                Assert::AreEqual(expectedIsolated[i], actualIsolated[i]);
            }
        }
	};
}
