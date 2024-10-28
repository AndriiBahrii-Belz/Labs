#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
                TEST_METHOD(TestReadGraph)
                {
                    vector<vector<int>> matrix;
                    int n, m;
                    string filename = "test_graph.txt";

                    // Create a test file
                    ofstream outfile(filename);
                    outfile << "3 3\n0 1 4\n1 2 5\n2 0 3\n";
                    outfile.close();

                    // Call readGraph
                    readGraph(filename, matrix, n, m);

                    // Test assertions
                    Assert::AreEqual(3, n);
                    Assert::AreEqual(3, m);
                    Assert::AreEqual(0, matrix[0][0]);
                    Assert::AreEqual(4, matrix[0][1]);
                    Assert::AreEqual(INF, matrix[0][2]);
                    Assert::AreEqual(0, matrix[1][1]);
                    Assert::AreEqual(5, matrix[1][2]);
                    Assert::AreEqual(3, matrix[2][0]);
                    Assert::AreEqual(0, matrix[2][2]);
                }

                TEST_METHOD(TestPrintMatrix)
                {
                    vector<vector<int>> matrix = {
                        {0, 4, INF},
                        {INF, 0, 5},
                        {3, INF, 0}
                    };
                    int n = 3;
                    string outputFile = "test_output.txt";

                    // Call printMatrix
                    printMatrix(outputFile, matrix, n);

                    // Read the output file
                    ifstream infile(outputFile);
                    string line;
                    getline(infile, line); // Skip header line
                    getline(infile, line);
                    Assert::AreEqual("0\t4\tINF\t", line.c_str());
                    getline(infile, line);
                    Assert::AreEqual("INF\t0\t5\t", line.c_str());
                    getline(infile, line);
                    Assert::AreEqual("3\tINF\t0\t", line.c_str());
                    infile.close();
                }

	};
}
