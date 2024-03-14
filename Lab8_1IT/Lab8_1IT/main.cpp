#include <iostream>
#include <cstring>
using namespace std;

int Count(const char* str) {
    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len - 1; ++i) {
        if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n')) {
            count++;
        }
    }
    return count;
}

char* Change(const char* str) {
    int len = strlen(str);
    char* result = new char[len * 3 + 1]; // Максимальна можлива довжина результуючого рядка (кожну пару "no" будемо замінювати на "***")
    int result_index = 0;

    for (int i = 0; i < len - 1; ++i) {
        if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n')) {
            result[result_index++] = '*';
            result[result_index++] = '*';
            result[result_index++] = '*';
            i++; // пропускаємо наступний символ, оскільки вже обробили пару "no"
        }
        else {
            result[result_index++] = str[i];
        }
    }
    // Додаємо останній символ, якщо довжина рядка не парна
    if (len % 2 != 0) {
        result[result_index++] = str[len - 1];
    }
    result[result_index] = '\0'; // Додаємо завершуючий нуль-символ

    return result;
}

int main() {
    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH + 1];
    cout << "Enter string:" << endl;
    cin.getline(str, MAX_LENGTH);

    int count = Count(str);
    cout << "String contained " << count << " groups of 'no' or 'on'" << endl;

    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // Звільняємо пам'ять, щоб уникнути витоку
    return 0;
}
