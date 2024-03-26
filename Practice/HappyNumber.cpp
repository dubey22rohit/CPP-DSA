#include <iostream>
using namespace std;

int getPow(int n) {
  int sum = 0;
  while (n > 0) {
    int rem = n % 10;
    sum += rem * rem;
    n /= 10;
  }
  return sum;
}

bool isHappy(int n) {
  int slow = n;
  int fast = getPow(n);

  while (slow != fast && fast != 1) {
    slow = getPow(slow);
    fast = getPow(getPow(fast));
  }
  return fast == 1;
}

int main() { cout << isHappy(19); }
