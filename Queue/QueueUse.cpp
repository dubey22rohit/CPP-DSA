#include <iostream>

#include "QueueClass.h"
using namespace std;

int main() {
    QueueClass q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.Display();
    printf("%d\n", q.dequeue());
    printf("%d\n", q.dequeue());
    q.Display();

    return 0;
}