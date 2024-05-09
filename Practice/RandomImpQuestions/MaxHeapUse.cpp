#include <iostream>

#include "MaxHeap.h"
using namespace std;

int main() {
    MaxHeap *h = new MaxHeap();

    cout << "size: " << h->size() << endl;
    cout << "empty: " << h->isEmpty() << endl;

    h->insert(50);
    h->insert(20);
    h->insert(30);
    h->insert(9);
    h->insert(12);
    h->insert(60);
    h->insert(250);

    cout << "size: " << h->size() << endl;
    cout << "empty: " << h->isEmpty() << endl;
    cout << "max: " << h->getMax() << endl;

    while (!h->isEmpty()) {
        cout << "max: " << h->getMax() << endl;
        cout << h->remove() << endl;
    }

    return 0;
}