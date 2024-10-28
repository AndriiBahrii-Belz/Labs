#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#define NOMINMAX
#include <windows.h>

using namespace std;

const int INF = numeric_limits<int>::max();

void readGraph(const string& filename, vector<vector<int>>& matrix, int& n, int& m) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }
    infile >> n >> m;
    cout << "Reading graph with " << n << " nodes and " << m << " edges." << endl;
    matrix.assign(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        matrix[i][i] = 0;
    }
    int v, u, w;
    for (int i = 0; i < m; ++i) {
        infile >> v >> u >> w;
        cout << "Reading edge " << v << " -> " << u << " with weight " << w << endl;
        if (v >= 0 && v < n && u >= 0 && u < n) {
            matrix[v][u] = w;
        }
        else {
            cerr << "Індекс вершини поза межами допустимого діапазону!" << endl;
        }
    }
    infile.close();
}

void printMatrix(const string& outputFile, const vector<vector<int>>& matrix, int n) {
    ofstream outfile(outputFile);
    if (!outfile.is_open()) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }
    cout << "Матриця ваг:" << endl;
    outfile << "Матриця ваг:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INF) {
                cout << "INF" << "\t";
                outfile << "INF" << "\t";
            }
            else {
                cout << matrix[i][j] << "\t";
                outfile << matrix[i][j] << "\t";
            }
        }
        cout << endl;
        outfile << endl;
    }
    outfile.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inputFile = "C:\\Users\\andri\\Desktop\\Lab_10(1).txt";
    string outputFile = "C:\\Users\\andri\\Desktop\\Lab_10(2).txt";
    vector<vector<int>> weightMatrix;
    int n, m;

    readGraph(inputFile, weightMatrix, n, m);
    printMatrix(outputFile, weightMatrix, n);

    return 0;
}
