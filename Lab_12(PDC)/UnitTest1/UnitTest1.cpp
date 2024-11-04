#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestAddEdge)
        {
            Graph g(5); // створення графа з 5 вершинами
            g.addEdge(0, 1, 2);
            g.addEdge(1, 2, 3);

            // Перевірка, чи додалися ребра
            Assert::AreEqual(2, g.getAdjacencyList()[0][0].second); // Вага ребра 0-1
            Assert::AreEqual(2, g.getAdjacencyList()[1][0].second); // Вага ребра 1-2
        }

        TEST_METHOD(TestDijkstraShortestPath)
        {
            Graph g(5);
            g.addEdge(0, 1, 10);
            g.addEdge(0, 2, 5);
            g.addEdge(1, 2, 2);
            g.addEdge(1, 3, 1);
            g.addEdge(2, 1, 3);
            g.addEdge(2, 3, 9);
            g.addEdge(3, 4, 2);
            g.addEdge(2, 4, 2);

            // Визначимо довжину найкоротшого шляху з 0 до 4
            std::ostringstream out;
            std::streambuf* originalCoutBuffer = std::cout.rdbuf(out.rdbuf());

            g.dijkstra(0, 4);

            std::cout.rdbuf(originalCoutBuffer); // Відновлюємо стандартний вихід

            // Перевіряємо, чи правильний вихід (можете налаштувати під ваш формат)
            std::string output = out.str();
            Assert::IsTrue(output.find("Найкоротша відстань від 0 до 4: 7") != std::string::npos);
            Assert::IsTrue(output.find("Маршрут: 0 2 4") != std::string::npos);
        }

        TEST_METHOD(TestDijkstraAllDistances)
        {
            Graph g(3);
            g.addEdge(0, 1, 1);
            g.addEdge(1, 2, 2);
            g.addEdge(0, 2, 4);

            std::ostringstream out;
            std::streambuf* originalCoutBuffer = std::cout.rdbuf(out.rdbuf());

            g.dijkstraAll(0);

            std::cout.rdbuf(originalCoutBuffer); // Відновлюємо стандартний вихід

            // Перевіряємо, чи правильний вихід
            std::string output = out.str();
            Assert::IsTrue(output.find("Вершина 0: 0") != std::string::npos);
            Assert::IsTrue(output.find("Вершина 1: 1") != std::string::npos);
            Assert::IsTrue(output.find("Вершина 2: 3") != std::string::npos); // Зверніть увагу на правильне значення
        }
	};
}
