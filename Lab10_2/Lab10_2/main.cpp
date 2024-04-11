#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int findMaxConsecutiveDigits(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу" << endl;
        return -1;
    }

    int maxConsecutiveDigits = 0;
    int currentConsecutiveDigits = 0;
    char ch;

    while (file.get(ch)) {
        if (ch >= '0' && ch <= '9') {
            currentConsecutiveDigits++;
            maxConsecutiveDigits = max(maxConsecutiveDigits, currentConsecutiveDigits);
        }
        else {
            currentConsecutiveDigits = 0;
        }
    }

    file.close();
    return maxConsecutiveDigits;
}

int main() {
    string filename = "C:\\Users\\andri\\source\\repos\\Lab10_2\\Lab10_2.txt";
    int maxConsecutiveDigits = findMaxConsecutiveDigits(filename);
    if (maxConsecutiveDigits == -1) {
        return 1;
    }
    cout << "Найбільша кількість цифр, розташованих поспіль: " << maxConsecutiveDigits << endl;
    return 0;
}
