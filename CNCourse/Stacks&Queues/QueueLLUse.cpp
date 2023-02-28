#include <iostream>
using namespace std;
#include "../LinkedList/CommonFunctions.cpp"
#include "QueueUsingLL.cpp"
int main() {
    QueueUsingLL q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front : " << q.getFront() << endl;
    cout << "Is Empty :" << q.isEmpty() << endl;
    cout << "Size : " << q.getSize() << endl;

    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;

    q.enqueue(70);
    q.enqueue(80);

    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;

    cout << "Front : " << q.getFront() << endl;
    cout << "Is Empty :" << q.isEmpty() << endl;
    cout << "Size :" << q.getSize() << endl;
}