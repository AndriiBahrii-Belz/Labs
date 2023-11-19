#include<iostream>
using namespace std;

int countWays(int m, int x, int y, int z, int depth, int level) {
    // Виведення рівня рекурсії та глибини.
    cout << "Depth: " << m << ", Level: " << level << endl;

    if (m == 0) {
        // Якщо вартість відправлення нульова, то є один спосіб - не сплачувати нічого.
        return 1;
    }

    if (m < 0) {
        // Якщо вартість відправлення від'ємна, то немає способу сплатити.
        return 0;
    }

    // Використовуємо рекурентне співвідношення для чисел Фібоначчі.
    return countWays(m - x, x, y, z, depth + 1, level) +
        countWays(m - y, x, y, z, depth + 1, level + 1) +
        countWays(m - z, x, y, z, depth + 1, level + 2);
}

int main() {
    int x, y, z, m;

    // Введення значень x, y, z та m з клавіатури.
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "z = ";
    cin >> z;
    cout << "m = ";
    cin >> m;

    // Виклик рекурсивної функції та виведення результату.
    cout << "Ways = " << countWays(m, x, y, z, 1, 0) << endl;

    return 0;
}
