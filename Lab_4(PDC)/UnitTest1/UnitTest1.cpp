#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
        TEST_METHOD(TestNextPermutation)
        {
            // Test case for nextPermutation
            vector<int> perm = { 1, 2, 3 };
            bool hasNext = nextPermutation(perm);
            Assert::IsTrue(hasNext);
            Assert::AreEqual(perm[0], 1);
            Assert::AreEqual(perm[1], 3);
            Assert::AreEqual(perm[2], 2); // next permutation should be 1, 3, 2

            hasNext = nextPermutation(perm);
            Assert::IsTrue(hasNext);
            Assert::AreEqual(perm[0], 2);
            Assert::AreEqual(perm[1], 1);
            Assert::AreEqual(perm[2], 3); // next permutation should be 2, 1, 3

            hasNext = nextPermutation(perm);
            Assert::IsTrue(hasNext);
            Assert::AreEqual(perm[0], 2);
            Assert::AreEqual(perm[1], 3);
            Assert::AreEqual(perm[2], 1); // next permutation should be 2, 3, 1

            hasNext = nextPermutation(perm);
            Assert::IsTrue(hasNext);
            Assert::AreEqual(perm[0], 3);
            Assert::AreEqual(perm[1], 1);
            Assert::AreEqual(perm[2], 2); // next permutation should be 3, 1, 2

            hasNext = nextPermutation(perm);
            Assert::IsTrue(hasNext);
            Assert::AreEqual(perm[0], 3);
            Assert::AreEqual(perm[1], 2);
            Assert::AreEqual(perm[2], 1); // next permutation should be 3, 2, 1

            hasNext = nextPermutation(perm);
            Assert::IsFalse(hasNext); // No more permutations
        }

        TEST_METHOD(TestGenerateCombinations)
        {
            // Test case for combinations
            std::ostringstream output;

            // Redirect cout to a string stream
            std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf());

            generateCombinations(4, 2); // Generate combinations of 4 choose 2

            // Restore original cout
            std::cout.rdbuf(originalCout);

            std::string expectedOutput = "12\n13\n14\n23\n24\n34\n";
            Assert::AreEqual(expectedOutput, output.str());
        }
	};
}
