#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11_4/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
        TEST_METHOD(TestListPerfectStudents)
        {
            vector<Student> students;

            Student perfectStudent;
            perfectStudent.surname = "Perfect";
            perfectStudent.initials = "P.";
            perfectStudent.grades[0] = 5;
            perfectStudent.grades[1] = 5;
            perfectStudent.grades[2] = 5;
            perfectStudent.grades[3] = 5;
            perfectStudent.grades[4] = 5;
            students.push_back(perfectStudent);

            Student imperfectStudent;
            imperfectStudent.surname = "Imperfect";
            imperfectStudent.initials = "I.";
            imperfectStudent.grades[0] = 4;
            imperfectStudent.grades[1] = 5;
            imperfectStudent.grades[2] = 3;
            imperfectStudent.grades[3] = 5;
            imperfectStudent.grades[4] = 5;
            students.push_back(imperfectStudent);

            stringstream expectedOutput;
            expectedOutput << "List of students with all '5' grades:" << endl;
            expectedOutput << "Perfect P." << endl;

            stringstream outputStream;
            streambuf* oldCoutBuffer = cout.rdbuf(outputStream.rdbuf()); // Redirect cout to stringstream
            ListPerfectStudents(students);
            cout.rdbuf(oldCoutBuffer); // Restore cout

            Assert::AreEqual(expectedOutput.str(), outputStream.str());
        }
	};
}
