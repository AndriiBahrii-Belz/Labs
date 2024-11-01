#include "array_utils.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>

// Вектор
vector<int> createArray(int n) {
    vector<int> arr;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    for (int i = 0; i < n; ++i) {
        arr.push_back(dist(gen));
    }
    return arr;
}

void printArray(const vector<int>& arr) {
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void swapMaxMin(vector<int>& arr) {
    int maxIndex = distance(arr.begin(), max_element(arr.begin(), arr.end()));
    int minIndex = distance(arr.begin(), min_element(arr.begin(), arr.end()));
    swap(arr[maxIndex], arr[minIndex]);
}

// Список
list<int> createList(int n) {
    list<int> lst;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    for (int i = 0; i < n; ++i) {
        lst.push_back(dist(gen));
    }
    return lst;
}

void printList(const list<int>& lst) {
    copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void swapMaxMin(list<int>& lst) {
    auto maxIt = max_element(lst.begin(), lst.end());
    auto minIt = min_element(lst.begin(), lst.end());
    if (maxIt != minIt) {
        iter_swap(maxIt, minIt);
    }
}

// Множина (непосортована)
unordered_set<int> createUnorderedSet(int n) {
    unordered_set<int> st;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    while (st.size() < n) {
        st.insert(dist(gen));
    }
    return st;
}

void printUnorderedSet(const unordered_set<int>& st) {
    for (const auto& elem : st) {
        cout << elem << " ";
    }
    cout << endl;
}

void swapMaxMin(unordered_set<int>& st) {
    if (st.size() < 2) return; // No swap if fewer than 2 elements

    auto maxIt = max_element(st.begin(), st.end());
    auto minIt = min_element(st.begin(), st.end());

    int maxVal = *maxIt;
    int minVal = *minIt;

    st.erase(maxIt);
    st.erase(minIt);

    st.insert(minVal);
    st.insert(maxVal);
}
