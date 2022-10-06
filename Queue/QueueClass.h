#include <iostream>
using namespace std;

class QueueClass {
   private:
    int front;
    int rear;
    int size;
    int *Q;

   public:
    QueueClass() {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    QueueClass(int size) {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();
};

void QueueClass::enqueue(int x) {
    if ((rear + 1) % size == front) {
        printf("Queue is full");
        return;
    }
    rear = (rear + 1) % size;
    Q[rear] = x;
}

int QueueClass::dequeue() {
    if (front == rear) {
        printf("Queue is empty");
        return -1;
    }
    int out = Q[front + 1];
    front = (front + 1) % size;
    return out;
}

void QueueClass::Display() {
    for (int i = front + 1; i <= rear; i++) {
        printf("%d ", Q[i]);
    }
    cout << "\n";
}