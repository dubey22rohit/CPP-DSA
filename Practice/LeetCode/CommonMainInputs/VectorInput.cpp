#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> input(n);

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        input.push_back(a);
    }
    return 0;
}