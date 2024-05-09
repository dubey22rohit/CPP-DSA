#include <iostream>
#include <vector>
using namespace std;

string getKey(string s) {
    vector<int> count(26);
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
    }

    string key = "";
    for (int i = 0; i < 26; i++) {
        key.append(to_string(count[i] + 'a'));
    }

    return key;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < strs.size(); i++) {
        string key = getKey(strs[i]);
        mp[key].push_back(strs[i]);
    }

    unordered_map<string, vector<string>>::iterator it = mp.begin();
    vector<vector<string>> ans;
    while (it != mp.end()) {
        ans.push_back(it->second);
        it++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        strs.push_back(s);
    }

    vector<vector<string>> ans = groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}