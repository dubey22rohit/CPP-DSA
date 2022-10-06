#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
    char x;  // Is only 1 byte, butt still will take 4 bytes because it is
             // easier for machines to allocate 4 bytes
    // Buying 1 single tablet is difficult, buying a strip is easier
    // This is called padding.
    // Hence instead of 9 bytes(theoretically) it takes 12 bytes
};
// struct Rectangle {
//     int length;
//     int breadth;
// } r1, r2, r3;//Declaration + Initialization

int main() {
    struct Rectangle r1 = {4, 2};  // Local only to the main function
    r1.breadth = 10;
    r1.length = 15;
    printf("%lu\n", sizeof(r1));  // long unsigned
    printf("%d\n", r1.length * r1.breadth);
}