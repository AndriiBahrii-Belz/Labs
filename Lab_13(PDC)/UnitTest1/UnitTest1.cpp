#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_13(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestGraphColoring)
        {
            // Тест 1: простий граф 2-визначений
            Graph graph1(3);
            graph1.addEdge(0, 1);
            graph1.addEdge(1, 2);
            graph1.addEdge(0, 2);

            // Визначення кількості кольорів
            // Вершини: 0 (колір 0), 1 (колір 1), 2 (колір 0)
            // Очікувана кількість кольорів: 2
            graph1.graphColoring(); // Викликаємо метод

            // Тест 2: граф без ребер
            Graph graph2(4);
            // Немає ребер, отже, всі можуть бути одного кольору
            graph2.graphColoring(); // Очікувана кількість кольорів: 1

            // Тест 3: граф з 5 вершинами
            Graph graph3(5);
            graph3.addEdge(0, 1);
            graph3.addEdge(1, 2);
            graph3.addEdge(2, 3);
            graph3.addEdge(3, 4);
            graph3.addEdge(4, 0);

            // Кількість кольорів у циклі з 5 вершин (червоний, зелений, синій)
            // Очікувана кількість кольорів: 3
            graph3.graphColoring();
        }
	};
}
