#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// Функція для перевірки рефлексивності
bool isReflexive(const vector<vector<int>>& edges, int n) {
    unordered_set<int> vertices;
    for (const auto& edge : edges) {
        vertices.insert(edge[0]); // початкова вершина
        vertices.insert(edge[1]); // кінцева вершина
    }
    for (int i = 1; i <= n; ++i) {
        if (vertices.find(i) == vertices.end()) {
            return false; // якщо якась вершина відсутня, граф не рефлексивний
        }
    }
    return true; // всі вершини присутні
}

// Функція для перевірки транзитивності
bool isTransitive(const vector<vector<int>>& edges) {
    unordered_set<string> edgeSet;
    for (const auto& edge : edges) {
        edgeSet.insert(to_string(edge[0]) + "-" + to_string(edge[1]));
    }

    for (const auto& edge1 : edges) {
        for (const auto& edge2 : edges) {
            if (edge1[1] == edge2[0]) { // якщо кінцева вершина першого ребра збігається з початковою другого
                string combinedEdge = to_string(edge1[0]) + "-" + to_string(edge2[1]);
                if (edgeSet.find(combinedEdge) == edgeSet.end()) {
                    return false; // якщо комбіноване ребро не існує, граф не транзитивний
                }
            }
        }
    }
    return true; // всі необхідні ребра існують
}

int main() {
    ifstream inputFile("C:\\Users\\andri\\Desktop\\Lab_14.txt"); // відкриваємо файл для читання
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m; // читаємо кількість вершин і ребер

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        inputFile >> edges[i][0] >> edges[i][1]; // читаємо ребра
    }

    inputFile.close(); // закриваємо файл

    // Перевірка на рефлексивність
    if (isReflexive(edges, n)) {
        cout << "Граф є рефлексивним.\n";
    }
    else {
        cout << "Граф не є рефлексивним.\n";
    }

    // Перевірка на транзитивність
    if (isTransitive(edges)) {
        cout << "Граф є транзитивним.\n";
    }
    else {
        cout << "Граф не є транзитивним.\n";
    }

    return 0;
}
