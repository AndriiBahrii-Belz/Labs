#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9(PDC)/main.cpp"
#include <Windows.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:


            // Метод для зчитування графу з файлу
            std::vector<std::vector<int>> readGraph(const std::string& filename) {
                std::ifstream file(filename);
                int vertices, edges;
                file >> vertices >> edges;

                std::vector<std::vector<int>> graph(vertices + 1); // +1 для 1-індексації
                for (int i = 0; i < edges; i++) {
                    int v, w;
                    file >> v >> w;
                    graph[v].push_back(w);
                    graph[w].push_back(v);
                }
                return graph;
            }

            TEST_METHOD(TestReadGraph)
            {
                std::string filename = "test_graph.txt";
                std::ofstream file(filename);
                file << "5 4\n1 2\n1 3\n3 4\n4 5\n";
                file.close();

                std::vector<std::vector<int>> graph = readGraph(filename);
                Assert::AreEqual(size_t(6), graph.size());
                Assert::AreEqual(2, (int)graph[1].size());
                Assert::AreEqual(2, graph[1][0]);
                Assert::AreEqual(3, graph[1][1]);
            }
	};
}
