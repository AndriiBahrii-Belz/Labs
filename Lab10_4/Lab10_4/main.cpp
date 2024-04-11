#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Функція для зчитування імені файлу від користувача
string getFileName() {
    string fileName;
    cout << "Введіть ім'я файлу: ";
    cin >> fileName;
    return fileName;
}

// Функція для зчитування даних з файлу
vector<string> readDataFromFile(const string& fileName) {
    vector<string> words;
    ifstream file(fileName);
    if (file.is_open()) {
        string word;
        while (file >> word) {
            words.push_back(word);
        }
        file.close();
    }
    else {
        cerr << "Помилка відкриття файлу!" << endl;
    }
    return words;
}

// Функція для фільтрації слів за довжиною
vector<string> filterWords(const vector<string>& words, int minLength) {
    vector<string> filteredWords;
    for (const string& word : words) {
        if (word.length() >= minLength) {
            filteredWords.push_back(word);
        }
    }
    return filteredWords;
}

// Функція для запису відфільтрованих слів у файл та підрахунку їх кількості
void writeFilteredWordsToFile(const vector<string>& filteredWords, const string& fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (const string& word : filteredWords) {
            file << word << " ";
        }
        file << "\n";
        file << "Кількість вилучених слів: " << filteredWords.size() << endl;
        file.close();
        cout << "Результати записано у файл." << endl;
    }
    else {
        cerr << "Помилка відкриття файлу для запису!" << endl;
    }
}

int main() {
    // Зчитування імені файлу
    string fileName = getFileName();

    // Зчитування даних з файлу
    vector<string> words = readDataFromFile(fileName);

    // Перевірка, чи файл успішно зчитано
    if (!words.empty()) {
        // Запит користувача на мінімальну довжину слова
        int minLength;
        cout << "Введіть мінімальну довжину слова: ";
        cin >> minLength;

        // Фільтрація слів за довжиною
        vector<string> filteredWords = filterWords(words, minLength);

        // Запис відфільтрованих слів у файл та підрахунок кількості
        writeFilteredWordsToFile(filteredWords, fileName);
    }

    return 0;
} 