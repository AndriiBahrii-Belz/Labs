#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <iomanip>
#include <Windows.h>

using namespace std;

class Graph {
private:
    int V; // Кількість вершин
    vector<vector<int>> adj; // Список суміжності

public:
    Graph(int V) : V(V), adj(V + 1) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // оскільки граф неорієнтований
    }

    void DFS(int start) {
        vector<bool> visited(V + 1, false);
        stack<int> s;
        vector<int> dfsNum(V + 1, -1);
        int dfsCount = 0;

        s.push(start);
        visited[start] = true;

        cout << setw(10) << "Вершина" << setw(10) << "DFS-номер" << setw(10) << "Стек" << endl;

        while (!s.empty()) {
            int current = s.top();
            s.pop();
            dfsNum[current] = ++dfsCount;

            // Виводимо інформацію про поточну ітерацію
            cout << setw(10) << current << setw(10) << dfsNum[current] << setw(10);

            // Виводимо вміст стека
            stack<int> temp = s;
            vector<int> stackContent;
            while (!temp.empty()) {
                stackContent.push_back(temp.top());
                temp.pop();
            }
            for (int i = stackContent.size() - 1; i >= 0; --i) {
                cout << stackContent[i] << " ";
            }
            cout << endl;

            // Додаємо сусідів в стек
            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("C:\\Users\\andri\\Desktop\\Lab_6(1).txt");
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл." << endl;
        return 1;
    }

    int V;
    inputFile >> V;

    Graph graph(V);
    for (int i = 1; i <= V; ++i) {
        int neighbor;
        while (inputFile >> neighbor) {
            graph.addEdge(i, neighbor);
            if (inputFile.peek() == '\n') break; // Кінець рядка
        }
    }
    inputFile.close();

    int startVertex;
    cout << "Введіть початкову вершину: ";
    cin >> startVertex;

    cout << "Результат обходу графу (DFS):" << endl;
    graph.DFS(startVertex);

    return 0;
}
