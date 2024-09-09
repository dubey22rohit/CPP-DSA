#include <iostream>
using namespace std;

int getSum(int n) {
  if (n <= 0) {
    return 0;
  }
  return n + getSum(n - 1);
}

void printSum(int n, int sum) {
  if (n <= 0) {
    cout << sum;
    return;
  }
  printSum(n - 1, sum + n);
}

int main() {
  cout << getSum(5) << endl;
  printSum(5, 0);
  return 0;
}