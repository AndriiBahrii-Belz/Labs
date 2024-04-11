#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "..\Lab10_4\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{

	TEST_CLASS(UnitTest1)
	{
	public:
        // Тест для функції filterWords
        TEST_METHOD(TestFilterWords)
        {
            // Створення тестового вектора слів
            vector<string> words = { "apple", "banana", "pear", "kiwi" };

            // Визначення мінімальної довжини слова
            int minLength = 5;

            // Очікуваний результат після фільтрації
            vector<string> expectedFilteredWords = { "apple", "banana" };

            // Виклик функції filterWords
            vector<string> filteredWords = filterWords(words, minLength);

            // Перевірка, чи результат відповідає очікуваному
            Assert::IsTrue(filteredWords == expectedFilteredWords);
        }

        // Тест для функції readDataFromFile
        TEST_METHOD(TestReadDataFromFile)
        {
            // Створення тестового файлу
            string testFileName = "testFile.txt";
            ofstream testFile(testFileName);
            testFile << "apple banana pear kiwi";
            testFile.close();

            // Очікуваний результат після зчитування з тестового файлу
            vector<string> expectedWords = { "apple", "banana", "pear", "kiwi" };

            // Виклик функції readDataFromFile
            vector<string> words = readDataFromFile(testFileName);

            // Перевірка, чи результат відповідає очікуваному
            Assert::IsTrue(words == expectedWords);

            // Видалення тестового файлу
            remove(testFileName.c_str());
        }
	};
}
