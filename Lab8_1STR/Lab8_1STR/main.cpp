#include <iostream>
#include <string>
using namespace std;

int Count(const string s)
{
    int k = 0;
    size_t pos = 0;
    while ((pos = s.find("no", pos)) != string::npos)
    {
        pos++;
        k++;
    }
    pos = 0;
    while ((pos = s.find("on", pos)) != string::npos)
    {
        pos++;
        k++;
    }
    return k;
}

string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find("no", pos)) != string::npos)
    {
        s.replace(pos, 2, "***");
        pos += 3;
    }
    pos = 0;
    while ((pos = s.find("on", pos)) != string::npos)
    {
        s.replace(pos, 2, "***");
        pos += 3;
    }
    return s;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "String contained " << Count(str) << " pairs of 'no' or 'on'" << endl;
    string dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
