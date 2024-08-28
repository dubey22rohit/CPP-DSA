#include <iostream>
using namespace std;

void printAllDivisors(int x) {
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      cout << i << ", ";
      if ((x / i) != i) {
        cout << (x / i) << ", ";
      }
    }
  }
}

int main() {
  printAllDivisors(36);
  return 0;
}