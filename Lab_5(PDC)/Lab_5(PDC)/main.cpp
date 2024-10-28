#include <iostream>
#include <set>
#include <bitset>
#include <Windows.h>
using namespace std;

void task1() {
    set<char> A = { 'a', 'b', 'c' };
    set<int> C = { 0, 1 };
    cout << "Завдання 1: Множина A x C x A:" << endl;

    for (char a1 : A) {
        for (int c : C) {
            for (char a2 : A) {
                cout << "{" << a1 << ", " << c << ", " << a2 << "}" << endl;
            }
        }
    }
    cout << endl;
}

void task2() {
    int n = 8;
    bitset<8> A;
    bitset<8> B;
    A.set(0);
    A.set(1);
    A.set(3);
    A.set(4);
    B.set(1);
    B.set(2);
    B.set(5);

    cout << "Завдання 2: Множина A: " << A << endl;
    cout << "Множина B: " << B << endl;

    bitset<8> intersection = A & B;
    bitset<8> differenceA = A & ~intersection;
    bitset<8> unionSet = A | B;
    bitset<8> differenceB = A & ~B;
    bitset<8> symmetricDifference = A ^ B;

    cout << "A \\ (A ∩ B): Множина A без елементів, які є в A ∩ B: " << differenceA << endl;
    cout << "A ∪ B: Об'єднання множин A та B: " << unionSet << endl;
    cout << "A \\ B: Множина A без елементів, які є в B: " << differenceB << endl;
    cout << "A ⊕ B: Симетрична різниця множин A та B: " << symmetricDifference << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    task1();
    task2();
    return 0;
}
