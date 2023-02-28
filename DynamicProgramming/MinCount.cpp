#include <cmath>
#include <iostream>
using namespace std;

// given n, find the minimum number of digits required, whose sum of squares
// give n.
//  eg : 10 = 3^2 + 1^2

bool checkWhole(int n) {
    if (ceil(n) == floor(n)) {
        return true;
    }
    return false;
}

int minCount(int n) {
    int orig = n;
    int count = 0;
    while (orig > 0) {
        while (!checkWhole(sqrt(orig))) {
            orig--;
            n--;
        }
        int diff = orig - n;
        orig = diff;
        count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int ans = minCount(n);
    cout << "ans: " << ans;
    return 0;
}