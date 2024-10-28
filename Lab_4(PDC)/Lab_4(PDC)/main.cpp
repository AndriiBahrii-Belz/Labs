#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to print a permutation
void printPermutation(const vector<int>& permutation) {
    for (int num : permutation) {
        cout << num;
    }
    cout << endl;
}

// Function to generate the next permutation
bool nextPermutation(vector<int>& permutation) {
    int n = permutation.size();
    int i = n - 2;

    // Find the largest i such that permutation[i] < permutation[i + 1]
    while (i >= 0 && permutation[i] >= permutation[i + 1]) {
        i--;
    }

    if (i < 0) {
        return false; // No more permutations available
    }

    // Find the largest j such that permutation[i] < permutation[j]
    int j = n - 1;
    while (permutation[j] <= permutation[i]) {
        j--;
    }

    // Swap permutation[i] and permutation[j]
    swap(permutation[i], permutation[j]);

    // Reverse the sequence from i + 1 to the end
    reverse(permutation.begin() + i + 1, permutation.end());
    return true; // Next permutation is successfully generated
}

// Function to print a combination
void printCombination(const vector<int>& combination) {
    for (int num : combination) {
        cout << num;
    }
    cout << endl;
}

// Function to generate r-combinations
void generateCombinations(int n, int r) {
    vector<int> combination(r);

    // Initialize the first combination
    for (int i = 0; i < r; ++i) {
        combination[i] = i + 1;
    }

    printCombination(combination);

    while (true) {
        int i;
        for (i = r - 1; i >= 0 && combination[i] == n - r + i + 1; --i);

        if (i < 0) {
            break; // All combinations have been generated
        }

        combination[i]++;

        for (int j = i + 1; j < r; ++j) {
            combination[j] = combination[j - 1] + 1;
        }

        printCombination(combination);
    }
}

int main() {
    // Part for permutations
    int n;
    cout << "Enter a natural number n for permutations: ";
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1; // Initialize the first permutation
    }

    // Print the first permutation
    printPermutation(permutation);

    // Generate and print the next permutations
    while (nextPermutation(permutation)) {
        printPermutation(permutation);
    }

    // Part for combinations
    int r;
    cout << "Enter a natural number n and a non-negative integer r (r ≤ n): ";
    cin >> n >> r;

    if (r > n) {
        cout << "Error: r cannot be greater than n." << endl;
        return 1;
    }

    generateCombinations(n, r);

    return 0;
}
