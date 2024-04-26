#include <iostream>
using namespace std;

struct Elem
{
    Elem* link1;
    Elem* link2;
    int info;
};

int main()
{
    Elem* p = new Elem; // Створення вузла 'p'
    p->info = 0; // Вузол 'p' має значення 0
    p->link1 = nullptr; // 'link1' вказує в нікуди (nullptr)

    p->link2 = new Elem; // Вузол 'p' вказує на вузол 1 через 'link2'
    p->link2->info = 1; // Вузол 1
    p->link2->link1 = new Elem; // Вузол 1 вказує на вузол 2 через 'link1'
    p->link2->link1->info = 2; // Вузол 2
    p->link2->link1->link1 = nullptr; // 'link1' вузла 2 вказує в нікуди (nullptr)
    p->link2->link1->link2 = nullptr; // 'link2' вузла 2 вказує в нікуди (nullptr)

    p->link2->link2 = nullptr; // 'link2' вузла 1 вказує в нікуди (nullptr)

    // Знищення вузлів
    delete p->link2->link1; // Знищення вузла 2
    delete p->link2; // Знищення вузла 1
    delete p; // Знищення вузла 'p'

    return 0;
}