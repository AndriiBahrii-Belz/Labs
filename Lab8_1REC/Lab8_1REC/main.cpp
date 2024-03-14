#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(const char* str, int i) {
    if (strlen(str) < 2)
        return 0;

    if (str[i + 1] != '\0') {
        if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n'))
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    }
    else {
        return 0;
    }
}

char* Change(const char* str, char* dest, int i) {
    if (str[i + 2] != '\0') {
        if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n')) {
            strcat(dest, "***");
            return Change(str, dest, i + 2);
        }
        else {
            strncat(dest, &str[i], 1);
            return Change(str, dest, i + 1);
        }
    }
    else {
        strcat(dest, &str[i]);
        return dest;
    }
}

int main() {
    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH + 1];
    cout << "Enter string:" << endl;
    cin.getline(str, MAX_LENGTH);

    char* dest = new char[strlen(str) * 3 + 1];
    dest[0] = '\0';

    cout << "String contained " << Count(str, 0) << " pairs of 'no' or 'on'" << endl;

    char* modified = Change(str, dest, 0);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << modified << endl;

    delete[] dest;
    return 0;
}
