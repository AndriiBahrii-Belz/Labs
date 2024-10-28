#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestTask1)
        {
            // Перенаправляємо стандартний потік виводу в буфер
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            // Виконуємо task1
            task1();

            // Відновлюємо потік
            std::cout.rdbuf(oldCout);

            // Очікуваний результат
            std::string expectedOutput =
                "Завдання 1: Множина A x C x A:\n"
                "{a, 0, a}\n{a, 0, b}\n{a, 0, c}\n"
                "{a, 1, a}\n{a, 1, b}\n{a, 1, c}\n"
                "{b, 0, a}\n{b, 0, b}\n{b, 0, c}\n"
                "{b, 1, a}\n{b, 1, b}\n{b, 1, c}\n"
                "{c, 0, a}\n{c, 0, b}\n{c, 0, c}\n"
                "{c, 1, a}\n{c, 1, b}\n{c, 1, c}\n\n";

            // Порівнюємо вміст буфера з очікуваним результатом
            Assert::AreEqual(expectedOutput, buffer.str(), L"Результат task1() не співпадає з очікуваним");
        }

        TEST_METHOD(TestTask2)
        {
            // Перенаправляємо стандартний потік виводу в буфер
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            // Виконуємо task2
            task2();

            // Відновлюємо потік
            std::cout.rdbuf(oldCout);

            // Очікуваний результат
            std::string expectedOutput =
                "Завдання 2: Множина A: 00011011\n"
                "Множина B: 00100110\n"
                "A \\ (A ? B): Множина A без елементів, які є в A ? B: 00011001\n"
                "A ? B: Об'єднання множин A та B: 00111111\n"
                "A \\ B: Множина A без елементів, які є в B: 00011001\n"
                "A ? B: Симетрична різниця множин A та B: 00111101\n";

            // Порівнюємо вміст буфера з очікуваним результатом
            Assert::AreEqual(expectedOutput, buffer.str(), L"Результат task2() не співпадає з очікуваним");
        }
	};
}
