#include <iostream>
using namespace std;

int reverse(int x) {
    int rx = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if ((rx > INT_MAX / 10) || (rx == INT_MAX / 10 && pop > 7)) {
            return 0;
        }
        if ((rx < INT_MIN / 10) || (rx == INT_MIN / 10 && pop < -8)) {
            return 0;
        }
        rx = (rx * 10) + pop;
    }
    return rx;
}

int main() {
    int n;
    cin >> n;
    printf("Reverse of %d is %d", n, reverse(n));
    return 0;
}