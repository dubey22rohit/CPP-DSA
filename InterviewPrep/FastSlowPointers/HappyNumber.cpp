#include <iostream>
using namespace std;

// Any number will be called a happy number if, after repeatedly replacing it
// with a number equal to the sum of the square of all of its digits, leads us
// to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead,
// they will be stuck in a cycle of numbers which does not include ‘1’.

int getPow(int n) {
  int sum = 0;
  while (n > 0) {
    int rem = n % 10;
    sum += rem * rem;
    n /= 10;
  }
  return sum;
}

static bool findHappy(int num) {
  int slow = num, fast = getPow(num);
  while (slow != fast) {
    slow = getPow(slow);
    fast = getPow(getPow(fast));
  }
  return fast == 1;
}

int main() {
  cout << findHappy(23) << endl;
  cout << findHappy(12) << endl;
  return 0;
}