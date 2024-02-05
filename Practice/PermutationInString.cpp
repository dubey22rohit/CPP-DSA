#include <iostream>
#include <vector>
using namespace std;

// incomplete
bool isPermutation(vector<int> &count) {
  for (int i = 0; i < 26; i++) {
    if (count[i] != 0) {
      return false;
    }
  }
  return true;
}

bool checkInclusion(string s1, string s2) {
  vector<int> count(26, 0);
  for (auto c : s1) {
    count[c - 'a']++;
  }
  int i = 0, j = 0;
  while (i < s2.size()) {
    if (count[s2[i] - 'a'] != 0) {
      count[s2[i] - 'a']--;
      j = i + 1;
      break;
    }
    i++;
  }

  while (j < s2.size()) {
    if (count[s2[j] - 'a'] == 0) {
      if (isPermutation(count)) {
        return true;
      }
    }
    j++;
  }

  return false;
}

int main() { return 0; }
