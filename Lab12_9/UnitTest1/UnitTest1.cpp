#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_9/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestInsert)
        {
            BinarySearchTree bst;
            bst.addOrderedElement(50);
            bst.addOrderedElement(30);
            bst.addOrderedElement(70);
            bst.addOrderedElement(20);

            // Perform inorder traversal to check if elements are inserted correctly
            stringstream ss;
            streambuf* oldCout = cout.rdbuf(ss.rdbuf());
            bst.display();
            cout.rdbuf(oldCout);

            string expected = "Binary Search Tree (Inorder Traversal): 20 30 50 70 \n";
            Assert::AreEqual(expected, ss.str());
        }

        TEST_METHOD(TestRemove)
        {
            BinarySearchTree bst;
            bst.addOrderedElement(50);
            bst.addOrderedElement(30);
            bst.addOrderedElement(70);
            bst.addOrderedElement(20);
            bst.removeLeafNode();

            // Perform inorder traversal to check if leaf node is removed correctly
            stringstream ss;
            streambuf* oldCout = cout.rdbuf(ss.rdbuf());
            bst.display();
            cout.rdbuf(oldCout);

            string expected = "Binary Search Tree (Inorder Traversal): 30 50 \n";
            Assert::AreEqual(expected, ss.str());
        }
	};
}
