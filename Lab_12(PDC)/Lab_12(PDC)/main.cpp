#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>
#include <fstream> // Для роботи з файлами

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    void dijkstra(int start, int end);
    void dijkstraAll(int start);
    const vector<vector<pair<int, int>>>& getAdjacencyList() const; // Getter method

private:
    int vertices;
    vector<vector<pair<int, int>>> adj; // Список сусідства: (сосід, вага)
};

// Implement the getter method
const vector<vector<pair<int, int>>>& Graph::getAdjacencyList() const {
    return adj;
}

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adj.resize(vertices);
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].emplace_back(v, weight);
    adj[v].emplace_back(u, weight); // Для ненаправленого графа
}

void Graph::dijkstra(int start, int end) {
    vector<int> dist(vertices, INT_MAX);
    vector<int> parent(vertices, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }

    // Виведення найкоротшого маршруту
    cout << "Найкоротша відстань від " << start << " до " << end << ": " << dist[end] << endl;

    // Виведення шляху
    cout << "Маршрут: ";
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}

void Graph::dijkstraAll(int start) {
    vector<int> dist(vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    // Виведення результатів
    cout << "Найкоротші відстані від " << start << " до всіх вершин:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "Вершина " << i << ": " << (dist[i] == INT_MAX ? "нескінченність" : to_string(dist[i])) << endl;
    }
}

int main() {
    ifstream inputFile("C:\\Users\\andri\\Desktop\\Lab_11.txt"); // Відкриваємо файл для читання
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 1; // Завершення програми з кодом помилки
    }

    int vertices, edges;
    inputFile >> vertices >> edges; // Зчитування кількості вершин та ребер
    Graph graph(vertices);

    cout << "Зчитування ребер з файлу:" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        inputFile >> u >> v >> weight; // Зчитування ребер
        graph.addEdge(u, v, weight);
        cout << "Ребро: " << u << " - " << v << " (вага: " << weight << ")" << endl;
    }

    inputFile.close(); // Закриваємо файл

    int start, end;
    cout << "Введіть вершини для знаходження маршруту (start, end): ";
    cin >> start >> end;
    graph.dijkstra(start, end);

    cout << "Введіть вершину для знаходження відстаней до всіх вершин: ";
    cin >> start;
    graph.dijkstraAll(start);

    return 0;
}
