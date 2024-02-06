#include <iostream>
#include <vector>
using namespace std;

bool checkPermutation(vector<int> &count) {
  for (int i = 0; i < 26; ++i) {
    if (count[i] != 0) {
      return false;
    }
  }
  return true;
}

bool checkInclusion(string s1, string s2) {
  int m = s1.size();
  int n = s2.size();

  if (m > n) {
    return false;
  }

  vector<int> count(26);

  for (int i = 0; i < m; i++) {
    count[s1[i] - 'a']++;
    count[s2[i] - 'a']--;
  }

  if (checkPermutation(count)) {
    return true;
  }

  for (int i = m; i < n; i++) {
    count[s2[i] - 'a']--;
    count[s2[i - m] - 'a']++;
    if (checkPermutation(count)) {
      return true;
    }
  }
  return false;
}

int main() { return 0; }
