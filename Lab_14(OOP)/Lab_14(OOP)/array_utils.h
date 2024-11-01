#pragma once
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

// Array functions
vector<int> createArray(int n);
void printArray(const vector<int>& arr);
void swapMaxMin(vector<int>& arr);

// List functions
list<int> createList(int n);
void printList(const list<int>& lst);
void swapMaxMin(list<int>& lst);

// Unordered Set functions
unordered_set<int> createUnorderedSet(int n);
void printUnorderedSet(const unordered_set<int>& st);
void swapMaxMin(unordered_set<int>& st);
