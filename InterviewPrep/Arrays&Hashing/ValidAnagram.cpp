#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  unordered_map<int, int> shm;
  unordered_map<int, int> thm;

  for (int i = 0; i < s.size(); ++i) {
    shm[s[i]]++;
    thm[t[i]]++;
  }

  for (int i = 0; i < shm.size(); ++i) {
    if (shm[i] != thm[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  string s = "anagram", t = "nagaram";
  cout << isAnagram(s, t);
  return 0;
}