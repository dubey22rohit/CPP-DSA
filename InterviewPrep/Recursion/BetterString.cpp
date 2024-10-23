#include <iostream>
#include <unordered_map>
using namespace std;

// https://www.geeksforgeeks.org/problems/better-string/

// Passed 1010/1116, need to optimize further.
void dfs(string s, string curr, int index, unordered_map<string, int>& hm) {
  hm[curr]++;
  for (int i = index; i < s.size(); i++) {
    curr.push_back(s[i]);
    dfs(s, curr, i + 1, hm);
    curr.pop_back();
  }
}
int getSubsequencesCount(string s) {
  string curr;
  unordered_map<string, int> hm;
  dfs(s, curr, 0, hm);
  return hm.size();
}

string betterString(string str1, string str2) {
  int size1 = getSubsequencesCount(str1);
  int size2 = getSubsequencesCount(str2);

  if (size2 > size1) {
    return str2;
  }
  return str1;
}

int main() { return 0; }