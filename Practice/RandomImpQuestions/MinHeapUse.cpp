#include <iostream>

#include "MinHeap.h"
using namespace std;

int main() {
    MinHeap *h = new MinHeap();
    h->insert(10);
    h->insert(20);
    h->insert(30);
    h->insert(40);
    h->insert(5);
    h->insert(1);

    cout << "size: " << h->getSize() << endl;
    cout << "empty: " << h->isEmpty() << endl;

    cout << "Remove: " << h->remove() << endl;
    cout << "Remove: " << h->remove() << endl;
    cout << "Remove: " << h->remove() << endl;
    cout << "Remove: " << h->remove() << endl;
    cout << "Remove: " << h->remove() << endl;

    return 0;
}