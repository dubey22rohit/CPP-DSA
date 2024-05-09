#include <iostream>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
  unordered_map<char, int> tmap;
  for (auto tch : t) {
    tmap[tch]++;
  }

  int minStart = 0;
  int minLength = INT_MAX;
  int counter = t.size();
  int i = 0, j = 0;

  while (j < s.length()) {
    if (tmap[s[j]] > 0) {
      counter--;
    }
    tmap[s[j]]--;
    j++;

    while (counter == 0) {
      if ((j - i) < minLength) {
        minStart = i;
        minLength = j - i;
      }

      tmap[s[i]]++;
      if (tmap[s[i]] > 0) {
        counter++;
      }
      i++;
    }
  }

  if (minLength != INT_MAX) {
    return s.substr(minStart, minLength);
  }

  return "";
}

int main() {
  string s, t;
  getline(cin, s);
  getline(cin, t);

  string ans = minWindow(s, t);
  cout << ans;
  return 0;
}
