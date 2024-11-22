#include <iostream>
using namespace std;

// https://leetcode.com/problems/string-to-integer-atoi/

int myAtoi(string s) {
  int idx = 0;
  long result = 0;
  int sign = 1;

  while (idx < s.size() && s[idx] == ' ') {
    idx++;
  }
  if (s[idx] == '-') {
    sign = -1;
    idx++;
  } else if (s[idx] == '+') {
    idx++;
  }

  while (idx < s.size()) {
    if (s[idx] >= '0' && s[idx] <= '9') {
      result = result * 10 + (s[idx] - '0');
      if (result > INT_MAX && sign == -1)
        return INT_MIN;
      else if (result > INT_MAX && sign == 1)
        return INT_MAX;
      idx++;
    } else {
      return (result * sign);
    }
  }

  return (result * sign);
}
int main() {
  string s;
  getline(cin, s);
  cout << myAtoi(s);
  return 0;
}