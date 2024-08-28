#include <iostream>
using namespace std;

// Given a number n. Count the number of digits in n which evenly divide n.
// Return an integer, total number of digits of n which divides n evenly.

// Note : -Evenly divides means whether n is divisible by a digit
// i.e.leaves a remainder 0 when divided.

int evenlyDivides(int N) {
  int originalNum = N;
  int count = 0;
  while (N > 0) {
    int rem = N % 10;
    if (rem != 0 && originalNum % rem == 0) {
      count++;
    }
    N /= 10;
  }
  return count;
}

int countDigits(int N) {
  int count = 0;
  while (N > 0) {
    count++;
    N /= 10;
  }
  return count;
}

int countDigitsOptimized(int N) {
  // Log of 10, basically means that how many times can a number be divided by
  // 10;
  // log10(900) is approx 3.9 , we do 1 + log10(N) and take the ceil
  return (1 + log10(N));
}

int main() {
  cout << evenlyDivides(2272);
  return 0;
}