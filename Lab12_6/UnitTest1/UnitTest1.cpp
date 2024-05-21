#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_6/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        TEST_METHOD(TestSelectMessagesWithPriority)
        {
            // Create a queue with sample messages
            queue<Message> messages;
            Message msg1{ "Message 1", 3 };
            Message msg2{ "Message 2", 1 };
            Message msg3{ "Message 3", 5 };
            Message msg4{ "Message 4", 2 };
            messages.push(msg1);
            messages.push(msg2);
            messages.push(msg3);
            messages.push(msg4);

            // Call the selectMessagesWithPriority function
            int priority = 3;
            queue<Message> selectedMessages = selectMessagesWithPriority(messages, priority);

            // Check if the selected messages have the correct priority
            while (!selectedMessages.empty()) {
                Assert::IsTrue(selectedMessages.front().priority == priority);
                selectedMessages.pop();
            }
        }
	};
}
