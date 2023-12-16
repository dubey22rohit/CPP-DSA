#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> s;
    vector<int> ans(temperatures.size());
    for (int i = 0; i < temperatures.size(); i++) {
        int cd = i, ct = temperatures[i];
        while (!s.empty() && s.top().second < ct) {
            int pd = s.top().first;
            s.pop();
            ans[pd] = cd - pd;
        }
        s.push({cd, ct});
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