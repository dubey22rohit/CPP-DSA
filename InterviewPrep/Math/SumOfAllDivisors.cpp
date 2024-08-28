#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

long long sumOfDivisors(int N) {
  long long sum = 0;
  for (int i = 1; i <= N; ++i) {
    sum += (i * (N / i));
  }
  return sum;
}

int main() {
  cout << sumOfDivisors(4);
  return 0;
}