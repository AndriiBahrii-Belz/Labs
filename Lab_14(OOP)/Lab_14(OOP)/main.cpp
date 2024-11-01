// main.cpp
#include <iostream>
#include <list>
#include <unordered_set>
#include "array_utils.h"

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Вектор
    vector<int> arr = createArray(n);
    cout << "Array before swapping max and min: ";
    printArray(arr);
    swapMaxMin(arr);
    cout << "Array after swapping max and min: ";
    printArray(arr);

    // Список
    list<int> lst = createList(n);
    cout << "\nList before swapping max and min: ";
    printList(lst);
    swapMaxMin(lst);
    cout << "List after swapping max and min: ";
    printList(lst);

    // Множина (непосортована)
    unordered_set<int> st = createUnorderedSet(n);
    cout << "\nUnordered Set before swapping max and min: ";
    printUnorderedSet(st);
    swapMaxMin(st);
    cout << "Unordered Set after swapping max and min: ";
    printUnorderedSet(st);

    return 0;
}
