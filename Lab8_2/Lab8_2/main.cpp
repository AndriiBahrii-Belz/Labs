#include <iostream>
#include <string>
using namespace std;

size_t MaxDigitsInSequence(const string s)
{
    size_t maxDigits = 0;
    size_t currentDigits = 0;

    for (char c : s) {
        if (isdigit(c)) {
            currentDigits++;
            if (currentDigits > maxDigits) {
                maxDigits = currentDigits;
            }
        }
        else {
            currentDigits = 0;
        }
    }

    return maxDigits;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "Maximum number of digits in sequence: " << MaxDigitsInSequence(str) << endl;
    return 0;
}
