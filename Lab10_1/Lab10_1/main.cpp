#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countNeighborPairs(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу " << filename << endl;
        return -1;
    }

    char prev_char = '\0';
    char current_char;
    int pair_count = 0;

    while (file.get(current_char)) {
        if ((prev_char == 'n' && (current_char == 'o' || current_char == 'n')) ||
            (prev_char == 'o' && (current_char == 'n' || current_char == 'o'))) {
            pair_count++;
        }

        prev_char = current_char;
    }

    file.close();
    return pair_count;
}

int main() {
    string filename = "C:\\Users\\andri\\source\\repos\\Lab10_1\\Lab10_1.txt";
    int pairs_found = countNeighborPairs(filename);
    if (pairs_found >= 0) {
        cout << "У файлі знайдено " << pairs_found << " пар сусідніх букв 'no' або 'on'." << endl;
    }
    else {
        cout << "Не вдалося відкрити файл." << endl;
    }

    return 0;
}
