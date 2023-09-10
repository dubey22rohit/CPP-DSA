#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> stk;
    vector<int> ans(temperatures.size());
    int days = 0;
    for (auto t : temperatures) {
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> temperatures(n);

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        temperatures.push_back(a);
    }

    vector<int> ans = dailyTemperatures(temperatures);
    for (auto c : ans) {
        cout << c << " ";
    }
    return 0;
}