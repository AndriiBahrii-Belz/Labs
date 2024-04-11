#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "..\Lab10_3\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestReadDataFromFile)
        {
            // Створюємо тестовий файл з даними
            string filename = "test_data.txt";
            ofstream testFile(filename);
            if (testFile.is_open()) {
                testFile << "Doe J.D. 5 5 5 5 5" << endl;
                testFile.close();
            }
            else {
                Assert::Fail(L"Не вдалося створити тестовий файл.");
            }

            // Тепер спробуємо прочитати дані з цього файлу
            vector<Student> students;
            readDataFromFile(filename, students);
            Assert::AreNotEqual(static_cast<size_t>(0), students.size());

            // Видаляємо тестовий файл після виконання тесту
            remove(filename.c_str());
        }
	};
}
