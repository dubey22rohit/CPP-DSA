#include <iostream>
using namespace std;

struct Rect {
    int length;
    int breadth;
};

void funByValue(struct Rect r) {
    r.length = 200;  // Won't be reflected in main as struct is passed by value;
    cout << "Length : " << r.length << endl
         << "Breadth : " << r.breadth << endl;
}

void funByAddress(struct Rect *pr) {
    pr->length =
        200;  // Will modify the actual struct as it is passed by address;
    pr->breadth = 150;
    cout << "Length : " << pr->length << endl
         << "Breadth : " << pr->breadth << endl;
}

struct Rect *funReturningStruct() {
    // Created in heap;
    struct Rect *rp;
    rp = new Rect;

    rp->length = 135;
    rp->breadth = 225;

    return rp;
}

int main() {
    struct Rect r = {10, 5};
    cout << "Original values in main :\n";
    printf("Length: %d \nBreadth: %d\n", r.length, r.breadth);

    cout << "After funByValue\n";
    funByValue(r);
    printf("Length: %d \nBreadth: %d\n", r.length, r.breadth);

    cout << "After funByAddress\n";
    funByAddress(&r);
    printf("Length: %d \nBreadth: %d\n", r.length, r.breadth);

    struct Rect *prtR = funReturningStruct();

    cout << "Length : " << prtR->length << "Breadth : " << prtR->breadth
         << endl;

    return 0;
}
