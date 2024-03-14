#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool ContainsPairs(const char* s) {
    int len = strlen(s);
    for (int i = 0; i < len - 1; ++i) {
        if ((s[i] == 'n' && s[i + 1] == 'o') ||
            (s[i] == 'o' && s[i + 1] == 'n')) {
            return true;
        }
    }
    return false;
}

char* Change(char* s) {
    char* t = new char[strlen(s) * 3 + 1];
    int pos = 0;
    t[0] = '\0';
    while (char* p = strstr(s + pos, "no")) {
        strncat(t, s + pos, p - (s + pos));
        strcat(t, "***");
        pos = p - s + 2;
    }
    strcat(t, s + pos);
    strcpy(s, t);
    delete[] t;
    return s;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    if (ContainsPairs(str)) {
        cout << "String contains pairs of 'no' or 'on'." << endl;
        cout << "Modified string: " << Change(str) << endl;
    }
    else {
        cout << "String does not contain pairs of 'no' or 'on'." << endl;
    }
    return 0;
}
