#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//* https://leetcode.com/problems/group-anagrams/description/
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
    unordered_map<string, vector<string>> hm;
    for (int i = 0; i < strs.size(); i++) {
        string key = getKey(strs[i]);
        hm[key].push_back(strs[i]);
    }

    unordered_map<string, vector<string>>::iterator it = hm.begin();
    vector<vector<string>> ans;
    while (it != hm.end()) {
        ans.push_back(it->second);
        ++it;
    }
    return ans;
}

int main() { return 0; }