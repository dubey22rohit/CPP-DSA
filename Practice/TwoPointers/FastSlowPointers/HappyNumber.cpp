#include <iostream>
using namespace std;

// Happy Number (medium)
int getPow(int n) {
  int sum = 0;
  while (n > 0) {
    int rem = n % 10;
    sum += rem * rem;
    n /= 10;
  }
  return sum;
}

// TC: O(logN): read about it, it is not as straight forward
bool isHappy(int n) {
  int slow = n, fast = getPow(n);
  while (slow != fast) {
    slow = getPow(slow);
    fast = getPow(getPow(fast));
  }
  return fast == 1;
}

int main() {
  cout << isHappy(19) << endl;
  cout << isHappy(23) << endl;
  cout << isHappy(12) << endl;
  return 0;
}
