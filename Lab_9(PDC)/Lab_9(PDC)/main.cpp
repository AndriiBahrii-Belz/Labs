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
    int vertices; // ʳ������ ������
    vector<vector<int>> adj; // ������ ��������
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adj.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // ������� ���� ������������
}

void Graph::BFS(int startVertex) {
    vector<bool> visited(vertices, false);
    queue<int> q;
    vector<int> bfsNumbers(vertices, -1);
    int bfsCounter = 0;

    q.push(startVertex);
    visited[startVertex] = true;

    cout << left << setw(15) << "������� �������" << setw(15) << " BFS �����" << " ���� �����" << endl;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // ���������� ����� BFS
        if (bfsNumbers[current] == -1) {
            bfsNumbers[current] = bfsCounter++;
        }

        // �������� ���
        cout << left << setw(17) << current
            << setw(15) << bfsNumbers[current]
            << " {";

        // �������� ���� �����
        queue<int> temp = q; // ������� ����� ��� �����������
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "}" << endl;

        // �������� �����
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
        cerr << "�� ������� ������� ����!" << endl;
        return 1;
    }

    int vertices, edges;
    inFile >> vertices >> edges;
    Graph graph(vertices);

    // ���������� �����
    for (int i = 0; i < edges; i++) {
        int v, w;
        inFile >> v >> w;
        graph.addEdge(v - 1, w - 1); // �������� �������� �� 1 ��� ��������� � 0
    }

    inFile.close();

    int startVertex;
    cout << "������ ��������� ������� (1 �� " << vertices << "): ";
    cin >> startVertex;
    startVertex--; // �������� �������� �� 1 ��� ��������� � 0

    graph.BFS(startVertex);

    return 0;
}