#include <iostream>
#include <unordered_map>
using namespace std;

// Permutation in a String (hard)
bool findPermutation(const string &str, const string &pattern) {
  int ws = 0, matched = 0;
  unordered_map<char, int> hm;
  for (char c : pattern) {
    hm[c]++;
  }

  for (int we = 0; we < str.length(); ++we) {
    char rc = str[we];
    if (hm.find(rc) != hm.end()) {
      hm[rc]--;
      if (hm[rc] == 0) {
        matched++;
      }
    }

    if (matched == (int)hm.size()) {
      return true;
    }

    if (we >= pattern.size() - 1) {
      char lc = str[ws++];
      if (hm.find(lc) != hm.end()) {
        if (hm[lc] == 0) {
          matched--;
        }
        hm[lc]++;
      }
    }
  }
  return false;
}
int main() {
  string str, pattern;
  getline(cin, str);
  getline(cin, pattern);

  cout << findPermutation(str, pattern);
}
