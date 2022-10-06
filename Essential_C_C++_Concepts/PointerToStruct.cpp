#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    struct Rectangle r = {10, 5};
    cout << r.length << endl;
    cout << r.breadth << endl;

    struct Rectangle *p = &r;
    cout << p->length << endl;
    cout << p->breadth << endl;

    // Making a struct in Heap
    struct Rectangle *q;

    // q = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    q = new Rectangle;
    q->length = 15;
    q->breadth = 7;

    cout << q->length << " " << q->breadth << endl;

    return 0;
}