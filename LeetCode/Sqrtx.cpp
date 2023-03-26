#include <iostream>
using namespace std;

/**
 * *Optimized solution
 * *runtime 0ms (beats 100%)
 * *memory 5.9mb (beats 62.81%)
 */
int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }
    int first = 1, last = x;
    while (first <= last) {
        int mid = first + (last - first) / 2;
        // mid * mid throws runtime error
        if (mid == x / mid) {
            return mid;
        } else if (mid > x / mid) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return last;
}

int main() {
    int ans = mySqrt(144);
    cout << ans;
    return 0;
}