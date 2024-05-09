#include <iostream>
using namespace std;

void fun1(int x) {
    // Tail recursion
    if (x > 0) {
        cout << x << " ";
        fun1(x - 1);
    }
}

void fun2(int x) {
    // Head recursion
    if (x > 0) {
        fun2(x - 1);
        cout << x << " ";
    }
}

int main() {
    int x = 3;
    cout << "fun1 :";
    fun1(4);  // 4 3 2 1 : Switch on light bulb first(perform action, print
              // here), then goto next room(fun call)
    cout << endl << "fun2 : ";
    fun2(4);  // 1 2 3 4 : Goto next room, then switch on the light bulb
}