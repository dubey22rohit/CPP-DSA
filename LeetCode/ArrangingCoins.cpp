#include <iostream>
using namespace std;

// https://leetcode.com/problems/arranging-coins/description/

int arrangeCoins(int n) {
    int numStairs = 0, steps = n;
    for (int i = 1; i <= n; i++) {
        if (steps - i < 0) {
            break;
        }
        steps -= i;
        numStairs++;
    }
    return numStairs;
}

int main() {
    int n;
    cin >> n;
    cout << arrangeCoins(n);
    return 0;
}