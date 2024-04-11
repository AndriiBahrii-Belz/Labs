#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab11_1\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCreateDataFile)
        {
            // Arrange
            string filename = "test_data.txt";

            // Act
            createDataFile(filename);

            // Assert
            ifstream file(filename);
            Assert::IsTrue(file.good(), L"Data file creation failed."); // Перевіряємо, чи був створений файл
            file.close();
        }

        TEST_METHOD(TestRewriteData)
        {
            // Arrange
            string inputFilename = "test_input.txt";
            string outputFilename = "test_output.txt";
            createDataFile(inputFilename); // Створюємо вхідний файл

            // Act
            rewriteData(inputFilename, outputFilename); // Викликаємо функцію для переписування даних

            // Assert
            ifstream outputFile(outputFilename);
            if (outputFile.is_open()) {
                string expectedData = "informatics"; // Очікуваний вміст файлу
                string actualData;
                outputFile >> actualData;
                Assert::AreEqual(expectedData, actualData, L"Incorrect data rewritten to output file."); // Перевіряємо, чи співпадають очікувані та отримані дані
                outputFile.close();
            }
            else {
                Assert::Fail(L"Failed to open output file."); // Якщо вихідний файл не вдалося відкрити, то тест не пройдений
            }
        }
	};
}
