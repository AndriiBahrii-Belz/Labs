#include <iostream>
using namespace std;

// Функція для обчислення значення логічної функції
int logicalFunction(int p, int q, int r) {
    return p ^ (q & r);
}

int main() {
    // Виводимо заголовок таблиці істинності
    cout << "p q r | p XOR (q AND r)" << endl;
    cout << "-----------------------" << endl;

    // Проходимо всі можливі значення p, q та r
    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            for (int r = 0; r <= 1; ++r) {
                // Обчислюємо результат
                int result = logicalFunction(p, q, r);

                // Виводимо результат
                cout << p << " " << q << " " << r << " |     " << result << endl;
            }
        }
    }

    return 0;
}
