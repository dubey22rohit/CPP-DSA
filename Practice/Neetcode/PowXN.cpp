#include <iostream>
using namespace std;

double myPow(double x, int n) {
  long exponent = abs(n);
  double curr = x;
  double result = 1.0;

  for (long i = exponent; i > 0; i /= 2) {
    if (i % 2 == 1) {
      result *= curr;
    }
    curr *= curr;
  }

  if (n < 0) {
    return 1.0 / result;
  }

  return result;
}

int main() {
  double ans = myPow(2.1, 10);
  cout << ans;
}
