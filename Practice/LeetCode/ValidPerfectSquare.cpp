#include <cmath>
#include <iostream>
using namespace std;

bool isPerfectSquare(int num) {
    if (num == 0) {
        return true;
    }
    int first = 1, last = num;
    while (first <= last) {
        float mid = first + (last - first) / 2;
        if (mid == num / mid) {
            return true;
        } else if (mid > num / mid) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    bool ans = isPerfectSquare(n);
    cout << ans;
    return 0;
}