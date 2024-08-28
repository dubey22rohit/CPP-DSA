#include <iostream>
using namespace std;

long long sumOfSeries(long long n) {
  if (n == 0) {
    return 0;
  }
  return sumOfSeries(n - 1) + (n * n * n);
}

int main() { return 0; }