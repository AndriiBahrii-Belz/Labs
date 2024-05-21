#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

// Функція для зчитування стеку з файлу
void readStackFromFile(stack<int>& s, const string& filename) {
    ifstream file(filename);
    int num;
    while (file >> num) {
        s.push(num);
    }
    file.close();
}

// Функція для копіювання групи елементів стеку в новий стек
stack<int> copyGroup(stack<int>& s, int n) {
    stack<int> newStack;
    for (int i = 0; i < n && !s.empty(); ++i) {
        newStack.push(s.top());
        s.pop();
    }
    return newStack;
}

// Функція для вилучення групи елементів з верху стеку
void removeGroup(stack<int>& s, int m) {
    for (int i = 0; i < m && !s.empty(); ++i) {
        s.pop();
    }
}

// Функція для виведення стеку на екран
void printStack(stack<int>& s) {
    stack<int> temp;
    while (!s.empty()) {
        cout << s.top() << " ";
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

int main() {
    stack<int> originalStack;
    string filename = "C:\\Users\\andri\\Desktop\\Stack.txt"; // Ім'я файлу з даними
    readStackFromFile(originalStack, filename);

    int n, m;
    cout << "Enter the values of n and m: ";
    cin >> n >> m;

    stack<int> copiedStack = copyGroup(originalStack, n);

    cout << "Original Stack: ";
    printStack(originalStack);

    removeGroup(copiedStack, m);

    cout << "Copied Stack: ";
    printStack(copiedStack);

    return 0;
}
