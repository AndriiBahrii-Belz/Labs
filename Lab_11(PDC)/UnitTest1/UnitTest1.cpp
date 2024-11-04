#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11(PDC)/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FloydWarshallTests
{
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

    TEST_CLASS(FloydWarshallTests)
    {
    public:

        TEST_METHOD(TestDistanceMatrix)
        {
            int n = 4;
            vector<vector<int>> dist(n, vector<int>(n, INF));
            vector<vector<int>> next(n, vector<int>(n, -1));

            // Initialize distance and next matrices
            for (int i = 0; i < n; ++i) {
                dist[i][i] = 0;
                next[i][i] = i;
            }

            // Add edges
            dist[0][1] = 3;
            next[0][1] = 1;

            dist[1][2] = 1;
            next[1][2] = 2;

            dist[0][2] = 4;
            next[0][2] = 2;

            dist[2][3] = 2;
            next[2][3] = 3;

            // Apply Floyd-Warshall
            floydWarshall(dist, next, n);

            // Test distance from 0 to 3
            Assert::AreEqual(6, dist[0][3]);
            // Test distance from 0 to 1
            Assert::AreEqual(3, dist[0][1]);
            // Test distance from 1 to 2
            Assert::AreEqual(1, dist[1][2]);
            // Test distance from 2 to 3
            Assert::AreEqual(2, dist[2][3]);
            // Test distance from 0 to itself
            Assert::AreEqual(0, dist[0][0]);
        }

        TEST_METHOD(TestPathReconstruction)
        {
            int n = 4;
            vector<vector<int>> dist(n, vector<int>(n, INF));
            vector<vector<int>> next(n, vector<int>(n, -1));

            // Initialize distance and next matrices
            for (int i = 0; i < n; ++i) {
                dist[i][i] = 0;
                next[i][i] = i;
            }

            // Add edges
            dist[0][1] = 3;
            next[0][1] = 1;

            dist[1][2] = 1;
            next[1][2] = 2;

            dist[2][3] = 2;
            next[2][3] = 3;

            // Apply Floyd-Warshall
            floydWarshall(dist, next, n);

            // Test path from 0 to 3
            vector<int> path = reconstructPath(0, 3, next);
            vector<int> expectedPath = { 0, 1, 2, 3 };
            Assert::IsTrue(path == expectedPath);

            // Test path from 1 to 2
            path = reconstructPath(1, 2, next);
            expectedPath = { 1, 2 };
            Assert::IsTrue(path == expectedPath);

            // Test path with no connection
            path = reconstructPath(3, 0, next);
            Assert::IsTrue(path.empty());
        }
	};
}
