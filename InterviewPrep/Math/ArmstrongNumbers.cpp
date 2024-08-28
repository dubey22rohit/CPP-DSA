#include <iostream>
using namespace std;

bool isArmstrong(int x) {
  int numDigits = (1 + log10(x));
  int num = 0;
  int ox = x;
  while (x != 0) {
    int rem = x % 10;
    num += pow(rem, numDigits);
    x /= 10;
  }

  return ox == num;
}

int main() {
  cout << isArmstrong(371);
  return 0;
}