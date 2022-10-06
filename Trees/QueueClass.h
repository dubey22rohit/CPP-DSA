#include <iostream>
using namespace std;

class BTNode {
   public:
    BTNode* lchild;
    int data;
    BTNode* rchild;
};

class Queue {
   private:
    int front;
    int rear;
    int size;
    BTNode** Q;

   public:
    Queue() {
        front = rear = -1;
        size = 10;
        Q = new BTNode*[size];
    }
    Queue(int size) {
        front = rear = -1;
        this->size = size;
        Q = new BTNode*[this->size];
    }
    void enqueue(BTNode* x);
    BTNode* dequeue();
    bool isEmpty();
    void Display();
};

void Queue::enqueue(BTNode* x) {
    if ((rear + 1) % size == front) {
        printf("Queue is full");
        return;
    }
    rear = (rear + 1) % size;
    Q[rear] = x;
}

BTNode* Queue::dequeue() {
    if (front == rear) {
        printf("Queue is empty");
        return NULL;
    }

    front = (front + 1) % size;
    BTNode* out = Q[front];
    return out;
}

void Queue::Display() {
    for (int i = front + 1; i <= rear; i++) {
        cout << Q[i] << " ";
    }
    printf("\n");
}

bool Queue::isEmpty() { return front == rear; }