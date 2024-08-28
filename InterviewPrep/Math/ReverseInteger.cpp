#include <iostream>
using namespace std;

// https://leetcode.com/problems/reverse-integer/description/
int reverse(int x) {
  int ans = 0;
  int absx = abs(x);
  while (absx > 0) {
    int rem = absx % 10;
    if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
      return 0;
    }
    ans = (ans * 10) + rem;
    absx /= 10;
  }
  if (x < 0) {
    return -1 * ans;
  }
  return ans;
}

int main() {
  cout << reverse(123);
  return 0;
}