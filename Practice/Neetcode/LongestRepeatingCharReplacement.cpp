#include <iostream>
#include <vector>
using namespace std;

int characterReplacement(string s, int k) {
  vector<int> count(26);
  int i = 0, j = 0, maxe = 0, result = 0;
  while (j < s.size()) {
    count[s[j] - 'A']++;
    maxe = max(maxe, count[s[j] - 'A']);
    if (j - i + 1 - maxe > k) {
      count[s[i] - 'A']--;
      i++;
    }
    result = max(result, j - i + 1);
    j++;
  }
  return result;
}

int main() {
  string s;
  getline(cin, s);
  int k;
  cin >> k;

  cout << characterReplacement(s, k);

  return 0;
}
