#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    string ans = "";
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    for (int i = 0; i < first.size(); i++) {
        if (first[i] != last[i]) {
            break;
        }
        ans += first[i];
    }
    return ans;
}

int main() {
    vector<string> ip;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ip.push_back(s);
    }

    string ans = longestCommonPrefix(ip);
    for (int i = 0; i < ans.length(); i++) {
        cout << ans[i];
    }

    return 0;
}