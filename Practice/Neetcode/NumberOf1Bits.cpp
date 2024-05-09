#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
  int c = 0;
  while (n > 0) {
    c++;
    n &= n - 1;
  }
  return c;
}

int main() {
  cout << hammingWeight(00000000000000000000000010000000);
  return 0;
}
