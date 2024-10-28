#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <Windows.h>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void BFS(int startVertex);

private:
    int vertices; // Кількість вершин
    vector<vector<int>> adj; // Список суміжності
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adj.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // Оскільки граф неорієнтований
}

void Graph::BFS(int startVertex) {
    vector<bool> visited(vertices, false);
    queue<int> q;
    vector<int> bfsNumbers(vertices, -1);
    int bfsCounter = 0;

    q.push(startVertex);
    visited[startVertex] = true;

    cout << left << setw(15) << "Поточна вершина" << setw(15) << " BFS Номер" << " Вміст черги" << endl;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Присвоюємо номер BFS
        if (bfsNumbers[current] == -1) {
            bfsNumbers[current] = bfsCounter++;
        }

        // Виводимо дані
        cout << left << setw(17) << current
            << setw(15) << bfsNumbers[current]
            << " {";

        // Виводимо вміст черги
        queue<int> temp = q; // Копіюємо чергу для відображення
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "}" << endl;

        // Обходимо сусідів
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inFile("C:\\Users\\andri\\Desktop\\Lab_6(1).txt");
    if (!inFile) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    int vertices, edges;
    inFile >> vertices >> edges;
    Graph graph(vertices);

    // Зчитування ребер
    for (int i = 0; i < edges; i++) {
        int v, w;
        inFile >> v >> w;
        graph.addEdge(v - 1, w - 1); // Зменшуємо значення на 1 для нумерації з 0
    }

    inFile.close();

    int startVertex;
    cout << "Введіть початкову вершину (1 до " << vertices << "): ";
    cin >> startVertex;
    startVertex--; // Зменшуємо значення на 1 для нумерації з 0

    graph.BFS(startVertex);

    return 0;
}