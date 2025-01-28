#include <iostream>
using namespace std;

// https://leetcode.com/problems/largest-odd-number-in-string/
string largestOddNumber(string num) {
  int i = num.size() - 1;
  while (i >= 0) {
    int dig = num[i] - '0';
    if (dig % 2 == 1) {
      return num.substr(0, i + 1);
    }
    i--;
  }
  return "";
}

int main() {
  cout << largestOddNumber("4206");
  return 0;
}