#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V; // Кількість вершин
    vector<vector<int>> adj; // Список сусідів

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Для неорієнтованого графа
    }

    void graphColoring() {
        vector<int> result(V, -1); // Відповідь (кольори для вершин)
        result[0] = 0; // Перша вершина отримує перший колір

        // В масиві, що буде зберігати використані кольори
        vector<bool> usedColors(V, false);

        for (int u = 1; u < V; u++) {
            // Відзначити кольори сусідів
            for (int neighbor : adj[u]) {
                if (result[neighbor] != -1) {
                    usedColors[result[neighbor]] = true;
                }
            }

            // Знайти перший доступний колір
            int color;
            for (color = 0; color < V; color++) {
                if (!usedColors[color]) {
                    break;
                }
            }
            result[u] = color; // Призначити колір до вершини

            // Скинути використані кольори для наступної вершини
            fill(usedColors.begin(), usedColors.end(), false);
        }

        // Виводимо результат
        int maxColor = *max_element(result.begin(), result.end());
        cout << "Мінімальна кількість кольорів: " << maxColor + 1 << endl;
        cout << "Кольори вершин:" << endl;
        for (int u = 0; u < V; u++) {
            cout << "Вершина " << u << " -> Колір " << result[u] << endl;
        }
    }
};

int main() {
    ifstream inputFile("C:\\Users\\andri\\Desktop\\Lab_13.txt");
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    int V, E; // Кількість вершин та ребер
    inputFile >> V >> E;
    Graph graph(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        inputFile >> u >> v; // Зчитуємо ребра
        graph.addEdge(u, v);
    }

    graph.graphColoring(); // Запускаємо алгоритм розфарбування

    return 0;
}
