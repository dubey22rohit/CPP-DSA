#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {}

int main() {
    int n;
    cin >> n;

    vector<int> height(n);

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        height.push_back(a);
    }

    int trappedWater = trap(height);
    cout << trappedWater;

    return 0;
}