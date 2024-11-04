#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

void floydWarshall(vector<vector<int>>& dist, vector<vector<int>>& next, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

vector<int> reconstructPath(int u, int v, const vector<vector<int>>& next) {
    if (next[u][v] == -1) return {}; // No path exists
    vector<int> path = { u };
    while (u != v) {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

void printDistanceMatrix(const vector<vector<int>>& dist, int n) {
    cout << "Distance matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void saveDistanceMatrixToFile(const vector<vector<int>>& dist, int n, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    outputFile << "Distance matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                outputFile << "INF ";
            else
                outputFile << dist[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile.close();
    cout << "Distance matrix saved to " << filename << endl;
}

int main() {
    ifstream inputFile("C:\\Users\\andri\\Desktop\\Lab_11.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m; // n: number of vertices, m: number of edges

    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> next(n, vector<int>(n, -1));

    // Initialize distance and next matrices
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    // Read edges from the input file
    for (int i = 0; i < m; ++i) {
        int v, u, w;
        inputFile >> v >> u >> w;
        dist[v][u] = w;
        next[v][u] = u;
    }
    inputFile.close();

    // Run Floyd-Warshall algorithm
    floydWarshall(dist, next, n);

    // Output the distance matrix
    printDistanceMatrix(dist, n);

    // Optionally, save the distance matrix to a file
    string saveToFile;
    cout << "Do you want to save the distance matrix to a file? (yes/no): ";
    cin >> saveToFile;
    if (saveToFile == "yes") {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;
        saveDistanceMatrixToFile(dist, n, filename);
    }

    // Query for shortest path between specific vertices
    int start, end;
    cout << "Enter start and end vertices for the shortest path: ";
    cin >> start >> end;

    if (start < 0 || start >= n || end < 0 || end >= n) {
        cout << "Invalid vertices. Please enter vertices between 0 and " << n - 1 << "." << endl;
        return 1;
    }

    vector<int> path = reconstructPath(start, end, next);
    if (path.empty()) {
        cout << "No path exists from " << start << " to " << end << "." << endl;
    }
    else {
        cout << "Shortest path from " << start << " to " << end << ": ";
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
        cout << "Distance: " << dist[start][end] << endl;
    }

    return 0;
}
