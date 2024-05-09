#include <iostream>
#include <vector>
using namespace std;

bool check(int cows, long long positions[], int n, long long dist) {
    int count = 1;
    long long last_pos = positions[0];
    for (int i = 1; i < n; i++) {
        if (positions[i] - last_pos >= dist) {
            last_pos = positions[i];
            count++;
        }
        if (cows == count) {
            return true;
        }
    }
    return false;
}

// TC : O(nlog(dist))
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;

        long long positions[n];
        for (size_t i = 0; i < n; i++) {
            cin >> positions[i];
        }
        sort(positions, positions + n);
        long long start = 0;
        long long end = positions[n - 1] - positions[0];
        long long ans = -1;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (check(c, positions, n, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        cout << "Max distance bw cows: " << ans;
    }

    return 0;
}