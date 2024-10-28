#include <iostream>
#include <vector>

using namespace std;

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

unsigned long long arrangements(int n, int r) {
    return factorial(n) / factorial(n - r);
}

vector<vector<unsigned long long>> stirling_second_kind(int n) {
    vector<vector<unsigned long long>> S(n + 1, vector<unsigned long long>(n + 1, 0));

    S[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            S[i][j] = j * S[i - 1][j] + S[i - 1][j - 1];
        }
    }

    return S;
}

vector<unsigned long long> bell_numbers(int n) {
    vector<vector<unsigned long long>> S = stirling_second_kind(n);
    vector<unsigned long long> B(n + 1, 0);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            B[i] += S[i][j];
        }
    }

    return B;
}

int main() {
    // Task 1: Calculate arrangements A(n, r) for n = 9, r = 4
    int n_arrangements = 9, r_arrangements = 4;
    cout << "1. Number of arrangements without repetitions A(" << n_arrangements << ", " << r_arrangements << ") = "
        << arrangements(n_arrangements, r_arrangements) << endl;

    // Task 2: Build table for Stirling numbers and Bell numbers for n = i + 5, where i = 7
    int i = 7;
    int n_stirling = i + 5; // n = 12

    vector<vector<unsigned long long>> stirling = stirling_second_kind(n_stirling);

    cout << "2. Table of Stirling numbers of the second kind for n = " << n_stirling << ":" << endl;
    for (int j = 0; j <= n_stirling; ++j) {
        for (int k = 0; k <= j; ++k) {
            cout << stirling[j][k] << "\t";
        }
        cout << endl;
    }

    vector<unsigned long long> bell = bell_numbers(n_stirling);

    cout << "Bell numbers for n = " << n_stirling << ":" << endl;
    for (int j = 0; j <= n_stirling; ++j) {
        cout << "B(" << j << ") = " << bell[j] << endl;
    }

    return 0;
}
