#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string getKey(string str) {
  vector<int> count(26);
  for (char s : str) {
    count[s - 'a']++;
  }

  string key = "";
  for (int c : count) {
    key.append(to_string(c + 'a'));
  }

  return key;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> hm;
  for (string s : strs) {
    string key = getKey(s);
    hm[key].push_back(s);
  }

  vector<vector<string>> ans;
  unordered_map<string, vector<string>>::iterator it = hm.begin();
  while (it != hm.end()) {
    ans.push_back(it->second);
    ++it;
  }
  return ans;
}

vector<vector<string>> groupAnagramsOp(vector<string>& strs) {
  unordered_map<string, int> hm;
  vector<vector<string>> ans;
  for (int i = 0; i < strs.size(); ++i) {
    string tmp = strs[i];
    sort(tmp.begin(), tmp.end());
    if (hm.find(tmp) != hm.end()) {
      ans[hm[tmp]].push_back(strs[i]);
    } else {
      hm[tmp] = ans.size();
      ans.push_back({strs[i]});
    }
  }
  return ans;
}

int main() {
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> ans = groupAnagrams(strs);
  vector<vector<string>> ansOp = groupAnagramsOp(strs);
  for (auto sarr : ans) {
    for (auto s : sarr) {
      cout << s << ", ";
    }
    cout << "\n";
  }

  cout << "\nOp:\n";

  for (auto sarr : ansOp) {
    for (auto s : sarr) {
      cout << s << ", ";
    }
    cout << "\n";
  }
  return 0;
}