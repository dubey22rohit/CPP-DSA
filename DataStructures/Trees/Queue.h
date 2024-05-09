#include <iostream>
using namespace std;

struct BTreeNode {
    struct BTreeNode *lchild;
    int data;
    struct BTreeNode *rchild;
};

struct Queue {
    int size;
    int front;
    int rear;
    BTreeNode **Q;
};

void Create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (BTreeNode **)malloc(q->size * sizeof(BTreeNode *));
}

void Enqueue(struct Queue *q, BTreeNode *x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
}

BTreeNode *Dequeue(struct Queue *q) {
    BTreeNode *x = NULL;
    if (q->front == q->rear) {
        printf("Queue is empty");
        return x;
    }
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
    return x;
}

int isEmpty(struct Queue *q) { return q->front == q->rear; }
