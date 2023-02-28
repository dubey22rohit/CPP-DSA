#include <iostream>
using namespace std;
#include "../LinkedList/CommonFunctions.cpp"
#include "QueueUsingArray.cpp"
int main() {
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    
    cout << "Front : " << q.frontele() << endl;
    cout << "Is Empty :" << q.isEmpty() << endl;
    cout << "Size : " << q.getSize() << endl;
    q.printQueue();

    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;

    q.enqueue(70);
    q.enqueue(80);

    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;
    cout << "Dequeue :" << q.dequeue() << endl;

    cout << "Front : " << q.frontele() << endl;
    cout << "Is Empty :" << q.isEmpty() << endl;
    cout << "Size :" << q.getSize() << endl;
};