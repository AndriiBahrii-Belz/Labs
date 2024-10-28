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
        cerr << "�������: �� ������� ������� ���� " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // ������� ������� ������ � �����
    int edgeCount;
    file >> vertexCount >> edgeCount;

    // ���������� ������� ��������
    graph.resize(vertexCount, vector<int>(vertexCount, 0));

    int u, v;
    for (int i = 0; i < edgeCount; ++i) {
        file >> u >> v; // ������� ���� ������
        graph[u - 1][v - 1] = 1; // � ����� � �������������� �������
        graph[v - 1][u - 1] = 1; // ��� �������������� �����
    }

    file.close();
    return graph;
}

void calculateDegrees(const vector<vector<int>>& graph) {
    int vertices = graph.size();
    if (vertices == 0) {
        cerr << "�������: ���� �������." << endl;
        return;
    }

    vector<int> degree(vertices, 0);

    // �������� ������ ������ �� �����
    cout << "������ ������ �����:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (graph[i][j] != 0) {
                degree[i]++;
            }
        }

        // �������� ������ � �����
        cout << "������� " << i + 1 << ": " << degree[i] << " (�����: ";
        bool hasNeighbors = false;
        for (int j = 0; j < vertices; ++j) {
            if (graph[i][j] != 0) {
                cout << j + 1 << " "; // +1 ��� ���������� ������
                hasNeighbors = true;
            }
        }
        if (!hasNeighbors) {
            cout << "����";
        }
        cout << ")\n";
    }

    // ���������� ���������� �����
    bool isHomogeneous = true;
    int firstDegree = degree[0];
    for (int i = 1; i < vertices; ++i) {
        if (degree[i] != firstDegree) {
            isHomogeneous = false;
            break;
        }
    }

    if (isHomogeneous) {
        cout << "���� � ��������� � �������� ����������: " << firstDegree << endl;
    }
    else {
        cout << "���� �� � ���������." << endl;
    }
}

void findPendantAndIsolatedVertices(const vector<vector<int>>& graph) {
    int vertices = graph.size();
    if (vertices == 0) {
        cerr << "�������: ���� �������." << endl;
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
            pendantVertices.push_back(i + 1); // +1 ��� ���������� ������
        }
        else if (degree[i] == 0) {
            isolatedVertices.push_back(i + 1);
        }
    }

    cout << "������ �������: ";
    if (pendantVertices.empty()) {
        cout << "����\n";
    }
    else {
        for (int vertex : pendantVertices) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    cout << "��������� �������: ";
    if (isolatedVertices.empty()) {
        cout << "����\n";
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

    // ������� ���� �� ����� ������������� � ���
    string filename = "C:\\Users\\andri\\Desktop\\Lab_6(1).txt"; // ������ ��� ���� �� ���

    int vertexCount;
    vector<vector<int>> graph = readGraph(filename, vertexCount);

    cout << "\n�������� 1: ���������� ������� ������ �����.\n";
    calculateDegrees(graph);

    cout << "\n�������� 2: ���������� ������� �� ����������� ������ �����.\n";
    findPendantAndIsolatedVertices(graph);

    return 0;
}
