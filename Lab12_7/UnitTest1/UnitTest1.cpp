#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_7/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestAddApplicant)
        {
            Applicant* head = nullptr;
            addApplicant(head, "Петров", 90.5, "оригінал");
            addApplicant(head, "Іванов", 85.3, "дублікат");

            // Перевірка, чи абітурієнтів було додано до списку
            Assert::IsNotNull(head);
            Assert::AreEqual(head->surname, std::string("Іванов"));
            Assert::AreEqual(head->certificateScore, 85.3f);
            Assert::AreEqual(head->documentType, std::string("дублікат"));

            // Перевірка наступного елемента
            Assert::IsNotNull(head->next);
            Assert::AreEqual(head->next->surname, std::string("Петров"));
            Assert::AreEqual(head->next->certificateScore, 90.5f);
            Assert::AreEqual(head->next->documentType, std::string("оригінал"));
        }
	};
}
