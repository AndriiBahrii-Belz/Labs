#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestDFS) {
            // Arrange
            Graph graph(5); // Create a graph with 5 vertices
            graph.addEdge(1, 2);
            graph.addEdge(1, 3);
            graph.addEdge(2, 4);
            graph.addEdge(3, 5);

            // Act
            std::ostringstream oss; // Use ostringstream to capture console output
            std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf()); // Redirect cout

            graph.DFS(1); // Start DFS from vertex 1

            std::cout.rdbuf(oldCoutBuffer); // Restore cout buffer

            // Assert
            std::string output = oss.str();
            Assert::IsTrue(output.find("Вершина") != std::string::npos); // Check for headers
            Assert::IsTrue(output.find("1") != std::string::npos); // Check if vertex 1 is visited
            Assert::IsTrue(output.find("2") != std::string::npos); // Check if vertex 2 is visited
            Assert::IsTrue(output.find("3") != std::string::npos); // Check if vertex 3 is visited
            Assert::IsTrue(output.find("4") != std::string::npos); // Check if vertex 4 is visited
            Assert::IsTrue(output.find("5") != std::string::npos); // Check if vertex 5 is visited
        }
	};
}
