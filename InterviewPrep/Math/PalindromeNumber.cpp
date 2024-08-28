#include <iostream>
using namespace std;

// https://leetcode.com/problems/palindrome-number/
bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }
  int origx = x;
  long long revd = 0;
  while (x > 0) {
    int rem = x % 10;
    revd = (revd * 10) + rem;
    x /= 10;
  }
  return origx == revd;
}
int main() {
  cout << isPalindrome(121);
  return 0;
}