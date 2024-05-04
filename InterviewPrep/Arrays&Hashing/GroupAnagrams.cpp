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

int main() {
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

  return 0;
}