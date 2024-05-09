#include <iostream>
using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
}

void Create(struct Queue *q,int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void Enqueue(struct Queue *q, int x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
}

int Dequeue(struct Queue *q) {
    int x = -1;
    if (q->front == q->rear) {
        printf("Queue is empty");
        return x;
    }
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
    return x;
}

int main() { return 0; }