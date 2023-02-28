#include <iostream>

#include "QueueUsingArray.cpp"
using namespace std;

int main() {
    QueueUsingArray<int> *q = new QueueUsingArray<int>(5);
    for (size_t i = 1; i <= 5; i++) {
        q->enqueue(i * 10);
    }

    cout << "Front: " << q->top() << endl;
    cout << "Size: " << q->getSize() << endl;
    cout << "Is Empty: " << q->isEmpty() << endl;
    cout << "deleting: " << q->dequeue() << endl;
    cout << "deleting: " << q->dequeue() << endl;
    cout << "deleting: " << q->dequeue() << endl;
    cout << "deleting: " << q->dequeue() << endl;
    cout << "deleting: " << q->dequeue() << endl;
    cout << "deleting: " << q->dequeue() << endl;
    return 0;
}