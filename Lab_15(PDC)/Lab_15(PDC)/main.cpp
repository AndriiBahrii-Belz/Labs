#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int>& positions, int currentRow, int column) {
    for (int row = 0; row < currentRow; row++) {
        // Перевіряємо, чи ферзі не в одному стовпчику та чи не знаходяться на діагоналях
        if (positions[row] == column ||
            positions[row] - row == column - currentRow ||
            positions[row] + row == column + currentRow) {
            return false;
        }
    }
    return true;
}

void placeQueens(vector<int>& positions, int currentRow, int n) {
    if (currentRow == n) {
        // Виводимо рішення
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (positions[row] == col) {
                    cout << " F "; // Ферзь
                }
                else {
                    cout << " . "; // Пусте поле
                }
            }
            cout << endl;
        }
        cout << endl; // Розділюємо різні рішення
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(positions, currentRow, col)) {
            positions[currentRow] = col;
            placeQueens(positions, currentRow + 1, n);
            // positions[currentRow] = -1; // Необхідно для очищення, якщо потрібно
        }
    }
}

int main() {
    int n;
    cout << "Введіть кількість ферзів (n): ";
    cin >> n;

    // Перевіряємо, чи n є натуральним числом
    if (n <= 0) {
        cout << "Будь ласка, введіть натуральне число." << endl;
        return 1;
    }

    vector<int> positions(n, -1); // Позиції ферзів на шахівниці
    placeQueens(positions, 0, n);

    return 0;
}
