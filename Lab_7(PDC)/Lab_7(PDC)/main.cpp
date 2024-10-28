#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <Windows.h>

using namespace std;

vector<vector<int>> readGraph(const string& filename, int& vertexCount) {
    ifstream file(filename);
    vector<vector<int>> graph;

    if (!file.is_open()) {
        cerr << "Помилка: Не вдалося відкрити файл " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // Зчитуємо кількість вершин і ребер
    int edgeCount;
    file >> vertexCount >> edgeCount;

    // Ініціалізуємо матрицю суміжності
    graph.resize(vertexCount, vector<int>(vertexCount, 0));

    int u, v;
    for (int i = 0; i < edgeCount; ++i) {
        file >> u >> v; // Зчитуємо пару вершин
        graph[u - 1][v - 1] = 1; // В графі з ненаправленими ребрами
        graph[v - 1][u - 1] = 1; // Для ненаправленого графа
    }

    file.close();
    return graph;
}

void calculateDegrees(const vector<vector<int>>& graph) {
    int vertices = graph.size();
    if (vertices == 0) {
        cerr << "Помилка: Граф порожній." << endl;
        return;
    }

    vector<int> degree(vertices, 0);

    // Виводимо ступені вершин та сусідів
    cout << "Степені вершин графу:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (graph[i][j] != 0) {
                degree[i]++;
            }
        }

        // Виводимо ступінь і сусідів
        cout << "Вершина " << i + 1 << ": " << degree[i] << " (Сусіди: ";
        bool hasNeighbors = false;
        for (int j = 0; j < vertices; ++j) {
            if (graph[i][j] != 0) {
                cout << j + 1 << " "; // +1 для коректного виводу
                hasNeighbors = true;
            }
        }
        if (!hasNeighbors) {
            cout << "немає";
        }
        cout << ")\n";
    }

    // Перевіряємо однорідність графу
    bool isHomogeneous = true;
    int firstDegree = degree[0];
    for (int i = 1; i < vertices; ++i) {
        if (degree[i] != firstDegree) {
            isHomogeneous = false;
            break;
        }
    }

    if (isHomogeneous) {
        cout << "Граф є однорідним з степенем однорідності: " << firstDegree << endl;
    }
    else {
        cout << "Граф не є однорідним." << endl;
    }
}

void findPendantAndIsolatedVertices(const vector<vector<int>>& graph) {
    int vertices = graph.size();
    if (vertices == 0) {
        cerr << "Помилка: Граф порожній." << endl;
        return;
    }

    vector<int> degree(vertices, 0);
    vector<int> pendantVertices;
    vector<int> isolatedVertices;

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (graph[i][j] != 0) {
                degree[i]++;
            }
        }
        if (degree[i] == 1) {
            pendantVertices.push_back(i + 1); // +1 для коректного виводу
        }
        else if (degree[i] == 0) {
            isolatedVertices.push_back(i + 1);
        }
    }

    cout << "Висячі вершини: ";
    if (pendantVertices.empty()) {
        cout << "Немає\n";
    }
    else {
        for (int vertex : pendantVertices) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    cout << "Ізольовані вершини: ";
    if (isolatedVertices.empty()) {
        cout << "Немає\n";
    }
    else {
        for (int vertex : isolatedVertices) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Вказуємо шлях до файлу безпосередньо в коді
    string filename = "C:\\Users\\andri\\Desktop\\Lab_6(1).txt"; // Замініть цей шлях на ваш

    int vertexCount;
    vector<vector<int>> graph = readGraph(filename, vertexCount);

    cout << "\nЗавдання 1: Визначення степенів вершин графу.\n";
    calculateDegrees(graph);

    cout << "\nЗавдання 2: Визначення висячих та ізольованих вершин графу.\n";
    findPendantAndIsolatedVertices(graph);

    return 0;
}
